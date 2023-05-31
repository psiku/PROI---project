//
// Created by barte on 11.05.2023.
//

#include "FirstStrategy.h"


FirstStrategy::FirstStrategy(Instrument* instrument): Strategy(instrument) {}

StrategyResult FirstStrategy::eval() {

    std::tuple<double, double, double> chances = calculateChances();
    double riseChance = setPrecision(std::get<0>(chances), 2);
    double fallChance = setPrecision(std::get<1>(chances), 2);
    double maintenanceChance = setPrecision(std::get<2>(chances), 2);

    StrategyResult result(riseChance, fallChance, maintenanceChance);

    return result;
}

long double FirstStrategy::calculateTangens(const Record& record1, const Record& record2) {
    long double x_value = std::abs(record2.date - record1.date);
    double value1 = this->getInstrument()->getPrice(record1);
    double value2 = this->getInstrument()->getPrice(record2);
    long double y_value = value1 - value2;
    long double tangens = y_value / x_value;

    tangens = setPrecision(tangens, 5);

    return tangens;
}

std::vector<long double> FirstStrategy::listOfTangens() {
    std::vector<long double> tangents;
    Instrument* instrument = getInstrument();
    Instrument::Iterator it = instrument->begin();
    Instrument::Iterator endIt = instrument->end();

    if (it != endIt) {
        Instrument::Iterator nextIt = it;
        ++nextIt;

        for (; nextIt != endIt; ++it, ++nextIt) {
            const Record& record1 = *it;
            const Record& record2 = *nextIt;
            long double tangent = calculateTangens(record1, record2);
            tangents.push_back(tangent);
        }
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
    auto iter = tangens.begin() + index;
    auto endIter = tangens.end() - 1;

    for (; iter != endIter; ++iter) {
        Price currentStatus = status(*iter);
        Price nextStatus = status(*(iter + 1));
        if (currentStatus != nextStatus) {
            return std::distance(tangens.begin(), iter);
        }
    }

    return -1; // If there is no change, return -1 (continuously increasing/decreasing/maintaining)
}
long double FirstStrategy::calculateDifference(int down, int up) {
    std::vector<Record> records = getInstrument()->getRecords();
    Record record1 = records[down];
    Record record2 = records[up];
    double value1 = this->getInstrument()->getPrice(record1);
    double value2 = this->getInstrument()->getPrice(record2);
    return value2 - value1;
}

long double FirstStrategy::sumOfDifference(std::vector<long double> tangens) {
    long double sumOfDifference = 0;
    int index = 0;
    int firstChange = lookForChange(tangens, index);

    if (firstChange == -1) {
        // Jeśli nie nastąpiła zmiana stanu to zwraca różnicę między pierwszym a ostatnim rekordem
        const std::vector<Record> &records = getInstrument()->getRecords();
        if (!records.empty()) {
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
    std::vector<Record> records = getInstrument()->getRecords();
    if (records.size() >= 2) {
        const Record& record1 = *(std::prev(records.end(), 2)); // Second to last record
        const Record &record2 = records.back();                       // Last record
        long double tangent = calculateTangens(record1, record2);
        return status(tangent);
    }
    return STILL;
}

std::tuple<int, int, int> FirstStrategy::getNumberOfStatus(std::vector<long double> tangents) {
    int numChanges = 0;
    int numIncreases = 0;
    int numDecreases = 0;

    for (const auto& tangent : tangents) {
        Price currentStatus = status(tangent);

        if (currentStatus == INCREASE) {
            ++numIncreases;
        } else if (currentStatus == DECREASE) {
            ++numDecreases;
        }

        ++numChanges;
    }

    return std::make_tuple(numChanges, numIncreases, numDecreases);
}

double FirstStrategy::setPrecision(double value, int precison) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precison) << value;
    value = std::stold(oss.str());
    return value;
}

double FirstStrategy::calculateMovingAverage() {
    std::vector<Record> records = getInstrument()->getRecords();
    int weight = records.size();
    int sumOfWeights = 0;
    double result = 0;
    for(const auto & record : records){
        double value = getInstrument()->getPrice(record) * weight;
        result += value;
        sumOfWeights += weight;
        weight -= 1;
    }
    return result/sumOfWeights;
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

    double lastKnownValue = getInstrument()->getRecords().back().close;

    long double totalDifference = sumOfDifference(tangents) * 100 / lastKnownValue;

    if (numChanges > 0) {
        riseChance = (static_cast<double>(numIncreases) / numChanges) * 100.0;
        fallChance = (static_cast<double>(numDecreases) / numChanges) * 100.0;
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
        maintenanceChance += 10.0;
    }

    double movingAverage = calculateMovingAverage();

    // średnia krocząca wzięta pod uwagę
    if (movingAverage > lastKnownValue) {
        riseChance += 10.0;
    } else if (movingAverage < lastKnownValue) {
        fallChance += 10.0;
    } else {
        maintenanceChance += 10.0;
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
