//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//

#include "Context.h"

Forecast Context::run() {
    return current->eval();
}

void Context::set(std::unique_ptr<Strategy> strategy) {
    current = std::move(strategy);
}
