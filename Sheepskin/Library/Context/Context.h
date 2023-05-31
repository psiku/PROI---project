//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//

#ifndef SHEEPSKIN_CONTEXT_H
#define SHEEPSKIN_CONTEXT_H
#include "../Strategies/Strategy/Strategy.h"
#include <memory>
class Context {
private:
    std::unique_ptr<Strategy> current;

public:
    Forecast run();
    void set(std::unique_ptr<Strategy> strategy);
};


#endif //SHEEPSKIN_CONTEXT_H
