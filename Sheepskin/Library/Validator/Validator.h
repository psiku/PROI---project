//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//

#ifndef SHEEPSKIN_VALIDATOR_H
#define SHEEPSKIN_VALIDATOR_H
#include "../Data/Instrument/Instrument/Instrument.h"

class Validator {
public:
    static bool checkBorderPrices(const Record& record);
    static bool validate(const Instrument& instrument);

};


#endif //SHEEPSKIN_VALIDATOR_H
