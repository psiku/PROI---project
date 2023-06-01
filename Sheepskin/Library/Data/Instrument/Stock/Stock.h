//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_STOCK_H
#define SHEEPSKIN_STOCK_H


#include "../Instrument/Instrument.h"


class Stock: public Instrument {
public:
        explicit Stock(std::string id);
        double getVolatility(const Record &record) override;
        double getPrice(const Record &record) override;     // returns calculateMean()
        std::string getType() const override;
        double calculateMean(const Record &record);         // return mean value of 4 prices (high, low, close, open)
};


#endif //SHEEPSKIN_STOCK_H
