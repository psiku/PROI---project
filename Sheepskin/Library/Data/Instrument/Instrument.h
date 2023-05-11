//
// Created by Wiktor Kruszewicz on 11/05/2023.
//

#ifndef SHEEPSKIN_INSTRUMENT_H
#define SHEEPSKIN_INSTRUMENT_H


#include <string>
#include <vector>

#include "../Stock/Stock.h"

class Instrument {
private:
    std::string id;
    std::vector<Stock> stocks;
public:
    Instrument(std::string id);
};


#endif //SHEEPSKIN_INSTRUMENT_H
