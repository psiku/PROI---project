//
// Created by Wiktor Kruszewicz on 11/05/2023.
//


#ifndef SHEEPSKIN_RECORD_H
#define SHEEPSKIN_RECORD_H


#include <ctime>

class Record {
public:
    time_t date;
    double open;
    double high;
    double low;
    double close;
    int volume;
    Record(time_t date, double open, double high, double low, double close, int volume);
    double getAverage() const;       // returns average value of 4 prices (high, low, close, open)
};



#endif //SHEEPSKIN_RECORD_H
