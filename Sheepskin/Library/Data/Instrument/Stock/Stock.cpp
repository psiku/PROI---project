//
// Created by barte on 11.05.2023.
//

#include <string>
#include <utility>


#include "Stock.h"

Stock::Stock(std::string id): Instrument(id) {}

double Stock::getVolatility(const Record &record) {
    // Średnia odchylenia = (|Cena otwarcia - Średnia arytmetyczna| +
    // |Cena najwyższa - Średnia arytmetyczna| + |Cena najniższa - Średnia arytmetyczna| +
    // |Cena zamknięcia - Średnia arytmetyczna|) / 4
    double averageValue = record.getAverage();
    double averageVolatility = (std::abs(record.open - averageValue) + std::abs(record.close - averageValue)
                                     + std::abs(record.low - averageValue) + std::abs(record.high - averageValue));
    return averageVolatility;
}

double Stock::getPrice(const Record &record) {
    return calculateMean(record);
}

double Stock::calculateMean(const Record &record) {
    std::vector<double> values = {record.open, record.high, record.low, record.close};
    std::sort(values.begin(), values.end());

    return (values.at(1) + values.at(2)) / 2;
};

std::string Stock::getType() const {
    return "stock";
}