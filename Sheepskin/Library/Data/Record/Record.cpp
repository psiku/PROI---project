//
// Created by Wiktor Kruszewicz on 11/05/2023.
//

#include "Record.h"

Record::Record(time_t date, long double open, long double high, long double low, long double close, int volume) :
        date(date), open(open), high(high), low(low), close(close), volume(volume) {}

long double Record::getOpen() const {
    return open;
}

long double Record::getHigh() const {
    return high;
}

long double Record::getLow() const {
    return low;
}

long double Record::getClose() const {
    return close;
}

long double Record::getAverage() const {
    return (open + high + low + close) / 4;
}
