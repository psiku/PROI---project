//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_THIRDSTRATEGY_H
#define SHEEPSKIN_THIRDSTRATEGY_H


#include "../Strategy/Strategy.h"

class ThirdStrategy: public Strategy {
public:
    explicit ThirdStrategy(Instrument* instrument);
    Forecast eval() override;
};


#endif //SHEEPSKIN_THIRDSTRATEGY_H
