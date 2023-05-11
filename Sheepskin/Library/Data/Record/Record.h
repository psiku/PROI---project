//
// Created by Wiktor Kruszewicz on 11/05/2023.
//

#ifndef SHEEPSKIN_STOCK_H
#define SHEEPSKIN_STOCK_H

#include <ctime>

class Record {
private:
    time_t date;
    long double value;
    int volume;
public:
    Record(time_t date, long double value, int volume);
};


#endif //SHEEPSKIN_STOCK_H
