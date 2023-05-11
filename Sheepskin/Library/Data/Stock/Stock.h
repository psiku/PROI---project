//
// Created by Wiktor Kruszewicz on 11/05/2023.
//

#ifndef SHEEPSKIN_STOCK_H
#define SHEEPSKIN_STOCK_H

#include <ctime>

class Stock {
private:
    time_t date;
    long double value;
    int volume;
public:
    Stock(time_t date, long double value, int volume);
};


#endif //SHEEPSKIN_STOCK_H
