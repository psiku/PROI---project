//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_CRYPTOCURRENCY_H
#define SHEEPSKIN_CRYPTOCURRENCY_H


#include "../Instrument/Instrument.h"

// Class CryptoCurrency is a class which contains vector of Records and id of CryptoCurrency
//it is derived from Instrument
class CryptoCurrency: public Instrument {
public:
    explicit CryptoCurrency(std::string id);
    double getVolatility(const Record &record) override;
    double getPrice(const Record &record) override;     // returns close value of record
    std::string getType() const override;

    //getPrice method returns price of the CryptoCurrency, based on the record closing price
    //@param record - record which will be used to calculate price
    //@return price of the CryptoCurrency
};


#endif //SHEEPSKIN_CRYPTOCURRENCY_H
