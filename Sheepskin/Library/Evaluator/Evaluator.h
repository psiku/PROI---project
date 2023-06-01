//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//

#ifndef SHEEPSKIN_EVALUATOR_H
#define SHEEPSKIN_EVALUATOR_H

#include "../Context/Context.h"
#include "../Strategies/Strategy/Strategy.h"
#include "../Strategies/Strategy/StrategyType.h"

class Evaluator {
public:
    Evaluator() = default;
    void handle(Context *context, Instrument *instrument);

    static std::vector<long> getTimestamps(Instrument *instrument);
    static long getTimestampMedian(Instrument *instrument);
    static StrategyType chose(Instrument *instrument);
};

#endif  // SHEEPSKIN_EVALUATOR_H
