//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//

#include "Evaluator.h"
#include "../Strategies/FirstStrategy/FirstStrategy.h"

void Evaluator::handle(Context *context, Instrument *instrument) {
    context->set(std::make_unique<FirstStrategy>(instrument));
}
