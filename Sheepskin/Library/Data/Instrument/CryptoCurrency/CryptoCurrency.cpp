//
// Created by barte on 11.05.2023.
//

#include "CryptoCurrency.h"

CryptoCurrency::CryptoCurrency(std::string id) : Instrument(id) {}

double CryptoCurrency::getPrice(const Record &record) {
    return record.close;
}

