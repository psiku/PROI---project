//
// Created by barte on 11.05.2023.
//

#include "FirstStrategy.h"

#include <utility>

FirstStrategy::FirstStrategy(Instrument instrument): Strategy(instrument) {}

StrategyResult FirstStrategy::eval() {

    std::tuple<double, double, double> chances = calculateChances();
    double riseChance = std::get<0>(chances);
    double fallChance = std::get<1>(chances);
    double maintanceChance = std::get<2>(chances);

    StrategyResult result(riseChance, fallChance, maintanceChance);

    return result;
}

long double FirstStrategy::calculateTangens(const Record& record1, const Record& record2) {
    // w przyszłości y_value będzie zmieniona na wartość wyliczaną osobno dla strategii
    long double x_value = std::abs(record2.date - record1.date);
    long double y_value = record1.close - record2.close;
    long double tangens = y_value / x_value;

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(5) << tangens;
    tangens = std::stold(oss.str());

    return tangens;
}

std::vector<long double> FirstStrategy::listOfTangens() {
    std::vector<long double> tangents;
    const std::vector<Record>& records = this->getInstrument().getRecords();

    for (size_t i = 0; i < records.size() - 1; ++i) {
        const Record& record1 = records[i];
        const Record& record2 = records[i + 1];
        long double tangent = calculateTangens(record1, record2);
        tangents.push_back(tangent);
    }
    return tangents;
}

Price FirstStrategy::status(long double value) {
    if (value > 0.0){
        return DECREASE;
    }
    else if (value == 0.0) {
        return STILL;
    }
    else {
        return INCREASE;
    }
}

int FirstStrategy::lookForChange(std::vector<long double> tangens, int index) {
    for (int i = index; i< tangens.size() - 1; i++){
        Price currentStatus = status(tangens[i]);
        Price nextStatus = status(tangens[i+1]);
        if (currentStatus != nextStatus){
            return i;
        }
    }
    return -1; // jeśli nie ma zmiany zwraca -1 -> ciągle rośnie/ ciągle maleje / utrzymuje się
}

long double FirstStrategy::calculateDifference(int down, int up) {
    std::vector<Record> records = this->getInstrument().getRecords();
    Record record1 = records[down];
    Record record2 = records[up];
    return record2.close - record1.close;
}

long double FirstStrategy::sumOfDifference(std::vector<long double> tangens) {
    //TODO naprawić funkcję, ma zwracać np całkowity wzrost jeśli nie nastąpiła zmiana stanu !!!
    long double sumOfDifference = 0;
    int index = 0;
    int firstChange = lookForChange(tangens, index);

    if (firstChange == -1) {
        // Jeśli nie nastąpiła zmiana stanu to zwraca różnicę między pierwszym a ostatnim rekordem
        const std::vector<Record> &records = this->getInstrument().getRecords();
        if (!records.empty()) {
            const Record &firstRecord = records.front();
            const Record &lastRecord = records.back();
            sumOfDifference = calculateDifference(0, records.size() - 1);
        }
    }

    while (firstChange != -1){
        int secondChange = lookForChange(tangens, firstChange + 1);

        if(secondChange != -1){
            sumOfDifference += calculateDifference(firstChange, secondChange);
            index = secondChange + 1;
            firstChange = lookForChange(tangens, index);
        }
        else{
            return sumOfDifference;
        }
    }
    return sumOfDifference;
}

Price FirstStrategy::lastStatus() {
    std::vector<Record> records = this->getInstrument().getRecords();
    size_t numRecords = records.size();
    if (numRecords >= 2) {
        const Record &record1 = records[numRecords - 2]; // Second to last record
        const Record &record2 = records[numRecords - 1]; // Last record
        long double tangent = calculateTangens(record1, record2);
        return status(tangent);
    };
    return STILL;
}

std::tuple<int, int, int> FirstStrategy::getNumberOfStatus(std::vector<long double> tangents) {
    int numChanges = 0;
    int numIncreases = 0;
    int numDecreases = 0;

    for (size_t i = 0; i < tangents.size() - 1; ++i) {
        Price currentStatus = status(tangents[i]);
        Price nextStatus = status(tangents[i + 1]);

        if (currentStatus != nextStatus) {
            ++numChanges;
            if (currentStatus == INCREASE) {
                ++numIncreases;
            } else if (currentStatus == DECREASE) {
                ++numDecreases;
            }
        }
    }
    return std::make_tuple(numChanges, numIncreases, numDecreases);
}

std::tuple<double, double, double> FirstStrategy::calculateChances() {

    double riseChance = 0.0;
    double fallChance = 0.0;
    double maintenanceChance = 0.0;

    std::vector<long double> tangents = listOfTangens();
    std::tuple<int, int, int> changesInState = getNumberOfStatus(tangents);
    int numChanges = std::get<0>(changesInState);
    int numIncreases = std::get<1>(changesInState);
    int numDecreases = std::get<2>(changesInState);

    long double totalDifference = sumOfDifference(tangents) / this->getInstrument().getRecords().back().close;

    if (numChanges > 0) {
        riseChance = static_cast<double>(numIncreases) / numChanges * 100.0;
        fallChance = static_cast<double>(numDecreases) / numChanges * 100.0;
        maintenanceChance = 100.0 - riseChance - fallChance;
    }

    // uwzględnić obecny status
    if (lastStatus() == INCREASE) {
        riseChance += 10.0;
    } else if (lastStatus() == DECREASE) {
        fallChance += 10.0;
    } else {
        maintenanceChance += 10.0;
    }

    // uwzględnić % wzrostów i spadków ceny względem zamykającej
    if (totalDifference > 0.0) {
        riseChance += static_cast<double>(totalDifference);
    } else if (totalDifference < 0.0) {
        fallChance -= static_cast<double>(totalDifference);
    } else {
        maintenanceChance += 1.0;
    }

    // upewnić się że łącznie jest 100%
    double totalChances = riseChance + fallChance + maintenanceChance;
    if (totalChances != 100.0) {
        double adjustmentFactor = 100.0 / totalChances;
        riseChance *= adjustmentFactor;
        fallChance *= adjustmentFactor;
        maintenanceChance *= adjustmentFactor;
    }

    return std::make_tuple(riseChance, fallChance, maintenanceChance);
}
