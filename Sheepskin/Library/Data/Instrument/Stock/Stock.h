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
        double getVolatility(const Record &record) override;
        double getPrice(const Record &record) override;     // returns calculateMean()
        std::string getType() const override;
        double calculateMean(const Record &record);         // return mean value of 4 prices (high, low, close, open)

        //getPrice method returns price of the Stock, based on the record mean price
        //@param record - record which will be used to calculate price
        //@return price of the Stock
        //calculateMean method calculates mean of the vector of Records
        //@param record - record which will be used to calculate mean
        //@return mean of the vector of Records
};


#endif //SHEEPSKIN_STOCK_H
