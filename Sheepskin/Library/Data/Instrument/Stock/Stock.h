//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_STOCK_H
#define SHEEPSKIN_STOCK_H


#include "../Instrument/Instrument.h"

// Class Stock is a class which contains vector of Records and id of Stock
//it is derived from Instrument
class Stock: public Instrument {
public:
        explicit Stock(std::string id);

        //getPrice method returns price of the Stock, based on the record mean price
        //@param record - record which will be used to calculate price
        //@return price of the Stock
        double getPrice(const Record &record) override;

        //calculateMean method calculates mean of the vector of Records
        //@param record - record which will be used to calculate mean
        //@return mean of the vector of Records
        double calculateMean(const Record &record);
};


#endif //SHEEPSKIN_STOCK_H
