//
// Created by Grzegorz Statkiewicz on 01/06/2023.
//

#ifndef SHEEPSKIN_PERIOD_H
#define SHEEPSKIN_PERIOD_H

#include <vector>
#include "../../Data/Record/Record.h"

struct Period {

private:
    std::vector<Record> records;
    long weight = 0;


public:
    Period(std::vector<Record> records, long weight) : records(records), weight(weight) {}

    time_t to() const {
        return std::max_element(records.begin(), records.end(), [&](const Record& a, const Record& b){ return a.date < b.date; })->date;
    }

    time_t from() const {
        return std::min_element(records.begin(), records.end(), [&](const Record& a, const Record& b){ return a.date < b.date; })->date;
    }

    std::vector<Record> getRecords() const { return records; }
    long getWeight() const { return weight; }
};

#endif //SHEEPSKIN_PERIOD_H
