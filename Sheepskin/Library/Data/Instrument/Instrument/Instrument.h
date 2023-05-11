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
    std::vector<Record> stocks;
public:
    Instrument(std::string id);
};


#endif //SHEEPSKIN_INSTRUMENT_H
