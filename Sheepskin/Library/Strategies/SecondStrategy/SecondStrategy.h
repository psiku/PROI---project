//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_SECONDSTRATEGY_H
#define SHEEPSKIN_SECONDSTRATEGY_H


#include "../Strategy/Strategy.h"
#include "Stage.h"
#include "Period.h"

class SecondStrategy: public Strategy  {
public:
    explicit SecondStrategy(Instrument* instrument);
    Forecast eval() override;

    std::vector<Period> splitByFibonacci(Instrument* instrument);
    double getPeriodAveragePriceChange(std::vector<Period> periods);
    Stage calculatePeriodStage(Period period);
    double getAverageStage(std::vector<Stage> stages);
};


#endif //SHEEPSKIN_SECONDSTRATEGY_H
