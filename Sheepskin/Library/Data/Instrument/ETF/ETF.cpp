//
// Created by barte on 11.05.2023.
//

#include "ETF.h"

ETF::ETF(std::string id) : Instrument(id) {}

double ETF::getVolatility(const Record &record) {
    return 0.0;
}


