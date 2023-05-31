//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_CRYPTOCURRENCY_H
#define SHEEPSKIN_CRYPTOCURRENCY_H


#include "../Instrument/Instrument.h"

class CryptoCurrency: public Instrument {
public:
    explicit CryptoCurrency(std::string id);
    double getVolatility(const Record &record) override;
    double getPrice(const Record &record) override;
};


#endif //SHEEPSKIN_CRYPTOCURRENCY_H
