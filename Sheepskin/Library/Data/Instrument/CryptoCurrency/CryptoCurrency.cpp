//
// Created by barte on 11.05.2023.
//

#include "CryptoCurrency.h"

CryptoCurrency::CryptoCurrency(std::string id) : Instrument(id) {}

double CryptoCurrency::getVolatility(const Record &record) {
    //Średnia = |((H + L + 2C) / 4) - średnia arytmetyczna)| -> aż będzie mniejsze niż 1
    double averageVolatility = std::abs(((record.high + record.low + 2 * record.close) / 4 ) - record.getAverage());
    while (averageVolatility > 1){
        averageVolatility = averageVolatility / 10;
    };
    return (averageVolatility);
}

double CryptoCurrency::getPrice(const Record &record) {
    return record.close;
}

