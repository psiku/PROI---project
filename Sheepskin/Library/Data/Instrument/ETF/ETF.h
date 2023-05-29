//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_ETF_H
#define SHEEPSKIN_ETF_H


#include "../Instrument/Instrument.h"

class ETF: public Instrument {
public:
    explicit ETF(std::string id);
    long double getVolatility(const Record &record) override;
    double getPrice(const Record &record) override;
};


#endif //SHEEPSKIN_ETF_H
