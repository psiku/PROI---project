//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_STRATEGYRESULT_H
#define SHEEPSKIN_STRATEGYRESULT_H

#include <string>

class StrategyResult {
    std::string id;
    unsigned short decision;
    int volume;
public:
    StrategyResult(std::string id, unsigned short decision, int volume);
};


#endif //SHEEPSKIN_STRATEGYRESULT_H
