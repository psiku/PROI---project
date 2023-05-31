//
// Created by barte on 11.05.2023.
//

#include "SecondStrategy.h"

SecondStrategy::SecondStrategy(Instrument* instrument) : Strategy(instrument) {}

Forecast SecondStrategy::eval() {
    Forecast result(0.8, 0., 0.0);

    return result;
}
