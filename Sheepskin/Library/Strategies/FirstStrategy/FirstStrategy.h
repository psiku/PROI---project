//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_FIRSTSTRATEGY_H
#define SHEEPSKIN_FIRSTSTRATEGY_H


#include "../Strategy/Strategy.h"
#include <cmath>

class FirstStrategy: public Strategy {
public:
    explicit FirstStrategy(Instrument instrument);
    StrategyResult eval() override;
    long double calculateTangens(const Record& record1, const Record& record2);
    std::vector<long double> listOfTangens();
};


#endif //SHEEPSKIN_FIRSTSTRATEGY_H
