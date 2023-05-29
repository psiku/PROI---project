//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_STOCK_H
#define SHEEPSKIN_STOCK_H


#include "../Instrument/Instrument.h"


class Stock: public Instrument {
public:
        explicit Stock(std::string id);
        long double getVolatility(const Record &record) override;
        double getPrice(const Record &record) override;
};


#endif //SHEEPSKIN_STOCK_H
