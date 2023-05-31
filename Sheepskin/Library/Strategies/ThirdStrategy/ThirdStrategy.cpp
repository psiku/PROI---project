//
// Created by barte on 11.05.2023.
//

#include "ThirdStrategy.h"

ThirdStrategy::ThirdStrategy(Instrument *instrument) : Strategy(instrument) {}

Forecast ThirdStrategy::eval() {
    return {0, 0, 0};
}
