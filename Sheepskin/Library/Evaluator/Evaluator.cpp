//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//

#include "Evaluator.h"
#include "../Strategies/FirstStrategy/FirstStrategy.h"
#include "../Strategies/SecondStrategy/SecondStrategy.h"
#include "../Strategies/ThirdStrategy/ThirdStrategy.h"

const long shortTermTimeRange = 60 * 60 * 24 * 1;   // day in seconds
const long longTermTimeRange = 60 * 60 * 24 * 7;    // week in seconds

std::vector<long> Evaluator::getTimestamps(Instrument *instrument) {
    std::vector<long> timestamps;
    std::vector<Record> records = instrument->getRecords();
    for(int record = 1; record < records.size(); record++) {
        long timestamp = abs(records[record].date - records[record-1].date);
        timestamps.push_back(timestamp);
    }
    return timestamps;
}

long Evaluator::getTimestampMedian(Instrument *instrument) {
    std::vector<long> timestamps = getTimestamps(instrument);
    std::sort(timestamps.begin(), timestamps.end());

    size_t size = timestamps.size();
    return size % 2 ? timestamps[size / 2] : (timestamps[size/2] + timestamps[size/2 + 1]) / 2;
}

StrategyType Evaluator::chose(Instrument *instrument) {
    long median = getTimestampMedian(instrument);
    if(median <= shortTermTimeRange) return StrategyType::First;
    if(median <= longTermTimeRange) return StrategyType::Second;
    return StrategyType::Third;
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
