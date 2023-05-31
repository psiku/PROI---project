//
// Created by Wiktor Kruszewicz on 11/05/2023.
//

#include "Record.h"

Record::Record(time_t date, double open, double high, double low, double close, int volume) :
        date(date), open(open), high(high), low(low), close(close), volume(volume) {}

double Record::getAverage() const {
    return (open + high + low + close) / 4;
}
