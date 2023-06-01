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

    //getPrice method returns price of the CryptoCurrency, based on the record closing price
    //@param record - record which will be used to calculate price
    //@return price of the CryptoCurrency
    double getPrice(const Record &record) override;

    std::string getType() const;
};


#endif //SHEEPSKIN_CRYPTOCURRENCY_H
