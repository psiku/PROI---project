//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//

#ifndef SHEEPSKIN_EVALUATOR_H
#define SHEEPSKIN_EVALUATOR_H


#include "../Strategies/Strategy/Strategy.h"
#include "../Context/Context.h"

class Evaluator {
public:
    Evaluator() = default;
    void handle(Context* context, Instrument *instrument);
};


#endif //SHEEPSKIN_EVALUATOR_H
