//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//

#include "Validator.h"


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
    return false;
}

bool Validator::validate(Instrument& instrument) {
    return checkPrice(instrument)
        && checkBorderPrices(instrument)
        && checkDateRepetition(instrument);
}

