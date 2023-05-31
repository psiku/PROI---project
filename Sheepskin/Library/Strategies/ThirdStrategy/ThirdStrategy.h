//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_THIRDSTRATEGY_H
#define SHEEPSKIN_THIRDSTRATEGY_H


#include "../Strategy/Strategy.h"

class ThirdStrategy: public Strategy {
public:
    ThirdStrategy();
    Evaluation eval();
};


#endif //SHEEPSKIN_THIRDSTRATEGY_H
