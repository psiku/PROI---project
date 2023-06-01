//
// Created by barte on 11.05.2023.
//

#include <string>
#include <utility>


#include "Stock.h"

Stock::Stock(std::string id): Instrument(id) {}

double Stock::getPrice(const Record &record) {
    return calculateMean(record);
}

double Stock::calculateMean(const Record &record) {
    std::vector<double> values = {record.open, record.high, record.low, record.close};
    std::sort(values.begin(), values.end());

    return (values.at(1) + values.at(2)) / 2;
};
