//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_SECONDSTRATEGY_H
#define SHEEPSKIN_SECONDSTRATEGY_H


#include "../Strategy/Strategy.h"

class SecondStrategy: public Strategy  {
public:
    explicit SecondStrategy(Instrument instrument);
    StrategyResult eval();
};


#endif //SHEEPSKIN_SECONDSTRATEGY_H
