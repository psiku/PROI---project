//
// Created by barte on 11.05.2023.
//

#include "FirstStrategy.h"

#include <utility>

FirstStrategy::FirstStrategy(Instrument instrument): Strategy(instrument) {}

StrategyResult FirstStrategy::eval() {
    StrategyResult result(0.5, 0.5);

    return result;
    //
}

long double FirstStrategy::calculateTangens(const Record& record1, const Record& record2) {
    // w przyszłości y_value będzie zmieniona na wartość wyliczaną osobno dla strategii
    long double x_value = std::abs(record2.date - record1.date);
    long double y_value = record1.close - record2.close;
    long double tangens = y_value / x_value;
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
