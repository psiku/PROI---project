//
// Created by Wiktor Kruszewicz on 11/05/2023.
//

#ifndef SHEEPSKIN_INSTRUMENT_H
#define SHEEPSKIN_INSTRUMENT_H

#include "../Stock/Stock.h"

#include <string>
#include <vector>

class Instrument {
private:
    std::string id;
    std::vector<Stock> stocks;
public:
    Instrument(std::string id);
};


#endif //SHEEPSKIN_INSTRUMENT_H
