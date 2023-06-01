//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//

#ifndef SHEEPSKIN_VALIDATOR_H
#define SHEEPSKIN_VALIDATOR_H

#include "../Data/Instrument/Instrument/Instrument.h"

// Validator class is responsible for validating data
class Validator {
public:
    // Checks if the instruments border price are valid
    //@param instrument - instrument to be validated
    //@return true if prices are valid, false otherwise
    static bool checkBorderPrices(Instrument& instrument);

    // Checks if the instruments have correct amount of records
    //@param instrument - instrument to be validated
    //@return true if instrument is valid, false otherwise
    static bool checkRecordAmount(Instrument& instrument);

    // Checks if the instruments date is valid
    //@param instrument - instrument to be validated
    //@return true if instrument is valid, false otherwise

    static bool checkPrice(Instrument& instrument);

    // Checks if the instruments dates aren't repeated
    //@param instrument - instrument to be validated
    //@return true if instrument is valid, false otherwise
    static bool checkDateRepetition(Instrument& instrument);

    // Checks if the instruments dates are in correct order
    //@param instrument - instrument to be validated
    //@return true if instrument is valid, false otherwise
    static bool checkDateOrder(Instrument& instrument);

    // Checks all the assumptions for the instrument
    //@param instrument - instrument to be validated
    //@return true if instrument is valid, false otherwise
    static bool validate(Instrument& instrument);

};


#endif //SHEEPSKIN_VALIDATOR_H