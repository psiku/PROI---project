//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_ETF_H
#define SHEEPSKIN_ETF_H


#include "../Instrument/Instrument.h"


// Class ETF is a class which contains vector of Records and id of ETF
//it is derived from Instrument
class ETF: public Instrument {
public:
    explicit ETF(std::string id);

    double
    getPrice(const Record &record) override;         // returns average value of 4 prices (high, low, close, open)
    std::string getType() const override;

    double getVolatility(const Record &record) override;
    //getPrice method returns price of the ETF, based on the record average price
    //@param record - record which will be used to calculate price
    //@return price of the ETF
};

#endif //SHEEPSKIN_ETF_H
