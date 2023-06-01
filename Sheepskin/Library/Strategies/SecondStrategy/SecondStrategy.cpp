//
// Created by barte on 11.05.2023.
//

#include <numeric>
#include "SecondStrategy.h"

SecondStrategy::SecondStrategy(Instrument* instrument) : Strategy(instrument) {}


double SecondStrategy::getAverageTimestamp() {
    std::vector<time_t> timestamps;
    std::vector<Record> records = Strategy::getInstrument()->getRecords();
    for(int element = 1; element < records.size(); element ++) {
        timestamps.push_back(records[element].date - records[element - 1].date);
    }

    long count = timestamps.size();
    return (double)std::accumulate(timestamps.begin(), timestamps.end(), 0) / (double)count;
}

std::vector<Period> SecondStrategy::splitByFibonacci() {
    auto step = getAverageTimestamp();
    std::vector<Record> records = Strategy::getInstrument()->getRecords();
    std::vector<Period> periods;

    long first = 1, second = 1;
    long counter = 0;


    long begin = 0;
    while(begin < records.size() && counter < records.size()) {
        long actual = 1;
        if(counter >= 2) {
            long h = second;
            second += first;
            first = h;

            actual = second;
        }

        std::vector<Record> periodRecords;
        long start = begin;
        for(;begin < records.size() && records[begin].date <= records[start].date + (long)ceil(actual * step); begin++) {
            periodRecords.push_back(records[begin]);
        }

        if(periodRecords.size() > 0) periods.emplace_back(periodRecords, actual);

        counter++;
    }

    return periods;
}

double SecondStrategy::getPeriodAveragePriceChange(Period period) {
    long sum, count = 0;
    int counter = 1;

    auto records = period.getRecords();
    for(long element = 1; element < records.size(); element++) {
        double first = Strategy::getInstrument()->getPrice(records[element - 1]);
        double second = Strategy::getInstrument()->getPrice(records[element]);

        sum += counter * (second - first);
        count += counter++;
    }

    return (double)sum / (double)count;
}

Stage SecondStrategy::calculatePeriodStage(Period period) {
    double change = getPeriodAveragePriceChange(period);

    if(std::abs(change) < 0.5) return Stage::Maintaining;
    if(change < 0) return Stage::Falling;
    return Stage::Rising;
}

double SecondStrategy::getAverageStage(std::vector<Period> periods, Stage stage) {
    long sum = 0, count = 0;
    for(auto period : periods) {
        auto periodStage = calculatePeriodStage(period);

        count += period.getWeight();

        if(periodStage != stage) continue;

        sum += period.getWeight();
    }

    return (double)sum / (double)count;
}

Forecast SecondStrategy::eval() {
    auto periods = splitByFibonacci();
    return {getAverageStage(periods, Stage::Falling), getAverageStage(periods, Stage::Maintaining), getAverageStage(periods, Stage::Rising)};
}
