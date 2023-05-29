//
// Created by barte on 11.05.2023.
//

#include "ETF.h"

ETF::ETF(std::string id) : Instrument(id) {}

long double ETF::getVolatility(const Record &record) {
    //(Fancy Median = (2 * Max + 3 * SecondMax + 4 * SecondMin + 5 * Min) / 14)
    //Volatility = |Close - Fancy Median
    std::vector<long double> values;
    values.push_back(record.high);
    values.push_back(record.low);
    values.push_back(record.close);
    values.push_back(record.open);
    std::sort(values.begin(), values.end()); // sortowanie w porządku rosnącym

    long double averageValue = values.at(3) * 2 + values.at(2)* 3 + values.at(1) + values.at(0) * 5 / 14;
    long double averageVolatility = std::abs(averageValue - record.close);
    return averageVolatility;
}

double ETF::getPrice(const Record &record) {
    return record.getAverage();
}


