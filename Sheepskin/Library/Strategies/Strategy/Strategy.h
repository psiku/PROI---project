//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_STRATEGY_H
#define SHEEPSKIN_STRATEGY_H


#include "Data/Instrument/Instrument/Instrument.h"
#include "../StrategyResult/StrategyResult.h"

class Strategy {
private:
    Instrument instrument;
public:
    Strategy(Instrument instrument);
    virtual StrategyResult eval() = 0;
};


#endif //SHEEPSKIN_STRATEGY_H
