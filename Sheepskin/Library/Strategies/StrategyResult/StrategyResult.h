//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_STRATEGYRESULT_H
#define SHEEPSKIN_STRATEGYRESULT_H

#include <string>

class StrategyResult {
private:
    double rise_chance;
    double fall_change;
public:
    StrategyResult(double rise_chance, double fall_chance);
};


#endif //SHEEPSKIN_STRATEGYRESULT_H
