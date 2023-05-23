//
// Created by Wiktor Kruszewicz on 11/05/2023.
//


#ifndef SHEEPSKIN_RECORD_H
#define SHEEPSKIN_RECORD_H


#include <ctime>

class Record {
public:
    time_t date;
    long double open;
    long double high;
    long double low;
    long double close;
    int volume;
    Record(time_t date, long double open, long double high, long double low, long double close, int volume);
    long double getAverage() const;
};



#endif //SHEEPSKIN_RECORD_H
