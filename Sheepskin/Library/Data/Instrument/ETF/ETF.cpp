//
// Created by barte on 11.05.2023.
//

#include "ETF.h"

ETF::ETF(std::string id) : Instrument(id) {}

double ETF::getPrice(const Record &record) {
    return record.getAverage();
}

std::string ETF::getType() const {
    return "etf";
}
