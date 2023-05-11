//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_DATA_H
#define SHEEPSKIN_DATA_H

#include <ctime>
#include <string>

class Data {
private:
    time_t date;
    std::string id;
    long double value;
    int volume;
public:
    Data(time_t date, std::string id, long double value, int volume);
};


#endif //SHEEPSKIN_DATA_H
