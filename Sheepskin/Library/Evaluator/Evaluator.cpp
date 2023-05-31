//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//

#include "Evaluator.h"
#include "../Strategies/FirstStrategy/FirstStrategy.h"
#include "../Strategies/SecondStrategy/SecondStrategy.h"
#include "../Strategies/ThirdStrategy/ThirdStrategy.h"

StrategyType Evaluator::chose(Instrument *instrument) {
    // TODO
    return StrategyType::First;
}

void Evaluator::handle(Context *context, Instrument *instrument) {
    StrategyType strategyType = chose(instrument);
    switch (strategyType) {
        case StrategyType::First:
            context->set(std::make_unique<FirstStrategy>(instrument));
            break;
        case StrategyType::Second:
            context->set(std::make_unique<SecondStrategy>(instrument));
            break;
        case StrategyType::Third:
            context->set(std::make_unique<ThirdStrategy>(instrument));
            break;
    }
}
