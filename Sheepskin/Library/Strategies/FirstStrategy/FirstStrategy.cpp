//
// Created by barte on 11.05.2023.
//

#include "FirstStrategy.h"

#include <utility>

FirstStrategy::FirstStrategy(Instrument instrument): Strategy(instrument) {}

StrategyResult FirstStrategy::eval() {
    StrategyResult result(0.5, 0.5, 0.0);

    return result;
    //
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
    return record1.close - record2.close;
}

long double FirstStrategy::sumOfDifference(std::vector<long double> tangens) {
    //TODO naprawić funkcję, ma zwracać np całkowity wzrost jeśli nie nastąpiła zmiana stanu !!!
    long double sumOfDifference = 0;
    int index = 0;
    int firstChange = lookForChange(tangens, index);

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
