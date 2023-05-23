//
// Created by Wiktor Kruszewicz on 11/05/2023.
//

#ifndef SHEEPSKIN_INSTRUMENT_H
#define SHEEPSKIN_INSTRUMENT_H


#include <string>
#include <vector>
#include "../../Record/Record.h"

#include "../../Record/Record.h"

class Instrument {
private:
    std::string id;
    std::vector<Record> records;
    long double volatility;
public:
    explicit Instrument(std::string id);
    void addRecord(const Record& record);
    virtual long double getVolatility(const Record& record);
};


#endif //SHEEPSKIN_INSTRUMENT_H
