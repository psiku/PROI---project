//
// Created by Wiktor Kruszewicz on 11/05/2023.
//


#ifndef SHEEPSKIN_RECORD_H
#define SHEEPSKIN_RECORD_H


#include <ctime>

class Record {
private:
    time_t date;
    long double open;
    long double high;
    long double low;
    long double close;
    long double value;
    int volume;
public:
    Record(time_t date, long double open, long double high, long double low, long double close, int volume);
};



#endif //SHEEPSKIN_RECORD_H
