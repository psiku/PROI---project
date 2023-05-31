//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//

#include "Validator.h"

bool Validator::checkPrice(Instrument &instrument) {
    for(auto record : instrument){
        if(record.open >= 0 && record.high >= 0 && record.low >= 0 && record.close >= 0){
            return true;
        }
    }
    return false;
}

bool Validator::checkBorderPrices(Instrument &instrument) {
    for(auto record : instrument){
        if(record.high >= record.low){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

bool Validator::checkDateRepetition(Instrument &instrument) {
    std::vector<time_t> dates;
    for(auto record : instrument) {
        dates.push_back(record.date);
    }

    std::sort(dates.begin(), dates.end());
    return std::adjacent_find(dates.begin(), dates.end()) == dates.end();
}

bool Validator::checkDateOrder(Instrument &instrument) {
    std::vector<time_t> dates;
    for(auto record : instrument) {
        dates.push_back(record.date);
    }

    return std::is_sorted(dates.begin(), dates.end());
}

bool Validator::validate(Instrument& instrument) {
    return checkPrice(instrument)
        && checkBorderPrices(instrument)
        && checkDateRepetition(instrument);
}

