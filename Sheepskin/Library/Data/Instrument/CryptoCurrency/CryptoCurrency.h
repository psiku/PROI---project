//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_CRYPTOCURRENCY_H
#define SHEEPSKIN_CRYPTOCURRENCY_H


#include "../Instrument/Instrument.h"

class CryptoCurrency: public Instrument {
    explicit CryptoCurrency(std::string id);
    long double getVolatility(const Record &record) override;
};


#endif //SHEEPSKIN_CRYPTOCURRENCY_H
