//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//

#include "Validator.h"

bool Validator::checkBorderPrices(Instrument &instrument) {
    return false;
}

bool Validator::checkPrice(Instrument &instrument) {
    return false;
}

bool Validator::checkDateRepetition(Instrument &instrument) {
    std::vector<time_t> dates;
    for(auto record : instrument) {
        dates.push_back(record.date);
    }

    std::sort(dates.begin(), dates.end());
    return std::adjacent_find(dates.begin(), dates.end()) == dates.end();
}

bool Validator::validate(Instrument& instrument) {
    return checkPrice(instrument)
        && checkBorderPrices(instrument)
        && checkDateRepetition(instrument);
}