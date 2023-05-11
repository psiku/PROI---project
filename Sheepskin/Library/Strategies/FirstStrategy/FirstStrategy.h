//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_FIRSTSTRATEGY_H
#define SHEEPSKIN_FIRSTSTRATEGY_H


#include "../Strategy/Strategy.h"

class FirstStrategy: public Strategy {
public:
    explicit FirstStrategy(Instrument instrument);
    StrategyResult eval() override;
};


#endif //SHEEPSKIN_FIRSTSTRATEGY_H
