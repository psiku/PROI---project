//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//

#ifndef SHEEPSKIN_VALIDATOR_H
#define SHEEPSKIN_VALIDATOR_H

#include "../Data/Instrument/Instrument/Instrument.h"

class Validator {
public:
    static bool checkBorderPrices(Instrument& instrument);
    static bool checkPrice(Instrument& instrument);
    static bool checkDateRepetition(Instrument& instrument);
    static bool checkDateOrder(Instrument& instrument);
    static bool validate(Instrument& instrument);

};


#endif //SHEEPSKIN_VALIDATOR_H