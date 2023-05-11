//
// Created by barte on 11.05.2023.
//

#include "FirstStrategy.h"

#include <utility>

FirstStrategy::FirstStrategy(Instrument instrument): Strategy(instrument) {}

StrategyResult FirstStrategy::eval() {
    StrategyResult result(0.5, 0.5);

    return result;
    //
}