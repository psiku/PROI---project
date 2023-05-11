//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_FIRSTSTRATEGY_H
#define SHEEPSKIN_FIRSTSTRATEGY_H


#include "../Strategy/Strategy.h"

class FirstStrategy: public Strategy {
public:
    FirstStrategy(Instrument instrument);
    StrategyResult eval();
};


#endif //SHEEPSKIN_FIRSTSTRATEGY_H
