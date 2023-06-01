//
// Created by barte on 11.05.2023.
//

#include <numeric>
#include "SecondStrategy.h"

SecondStrategy::SecondStrategy(Instrument* instrument) : Strategy(instrument) {}

Forecast SecondStrategy::eval() {
    return {0.8, 0., 0.0};
}


double SecondStrategy::getAverageTimestamp(Instrument *instrument) {
    std::vector<time_t> timestamps;
    std::vector<Record> records = instrument->getRecords();
    for(int element = 1; element < records.size(); element ++) {
        timestamps.push_back(records[element].date - records[element - 1].date);
    }

    long count = timestamps.size();
    return (double)std::accumulate(timestamps.begin(), timestamps.end(), 0) / (double)count;
}

std::vector<Period> SecondStrategy::splitByFibonacci(Instrument *instrument) {
    auto step = getAverageTimestamp(instrument);
    std::vector<Record> records = instrument->getRecords();
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

        if(periodRecords.size() > 0) periods.emplace_back(periodRecords);

        counter++;
    }

    return periods;
}

