//
// Created by Wiktor Kruszewicz on 18/05/2023.
//

#ifndef SHEEPSKIN_MAPPER_H
#define SHEEPSKIN_MAPPER_H

#include <string>
#include <vector>
#include <map>

class Mapper {
public:
//    Mapper();
    Mapper() = default;
    std::vector<Instrument*> mapToInstruments(CSVResult);
    template <class T>
    T translate(std::string val);
};
//#include "Mapper.cpp"
//
// Created by Wiktor Kruszewicz on 18/05/2023.
//
#include <iostream>
#include <sstream>
#include <iomanip>
#include <utility>
#include <string>
#include <vector>
#include "../../../../Library/Data/Instrument/ETF/ETF.h"
#include "../../../../Library/Data/Instrument/CryptoCurrency/CryptoCurrency.h"
#include "../../../../Library/Data/Instrument/Stock/Stock.h"
//#include "Mapper.h"

template <>
int Mapper::translate<int>(std::string val) {
    return std::stoi(val);
}

template <>
long double Mapper::translate<long double>(std::string val) {
    return std::stold(val);
}

template <>
double Mapper::translate<double>(std::string val) {
    return std::stod(val);
}

template <>
time_t Mapper::translate<time_t>(std::string val) {
    struct std::tm tm;
    std::istringstream ss(val);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S"); // or just %T in this case
    std::time_t time = mktime(&tm);
    return time;
}

template<>
std::string Mapper::translate<std::string>(std::string val) {
    return val;
}

std::vector<Instrument*> Mapper::mapToInstruments(CSVResult result) {
    std::map<std::string, Instrument*> instruments;

    while(!result.end()) {
        auto row = result.getRow();


        //name,type,datetime,open,high,low,close,volume

        time_t date = translate<time_t>(row[2]);
        double open = translate<double>(row[3]);
        double high = translate<double>(row[4]);
        double low = translate<double>(row[5]);
        double close = translate<double>(row[6]);
        int volume = translate<int>(row[7]);

        Record record(date, open, high, low, close, volume);

        std::string name = translate<std::string>(row[0]);

        if(instruments.find(name) == instruments.end()) {
            std::string type = translate<std::string>(row[1]);

            if(type == "etf") {
                ETF etf(name);
                instruments[name] = &etf;
            }
            else if(type == "stock") {
                Stock stock(name);
                instruments[name] = &stock;
            }
            else if(type == "crypto") {
                CryptoCurrency crypto(name);
                instruments[name] = &crypto;
            }
        }
        instruments[name]->addRecord(record);
    }
    std::vector<Instrument*> res;
    for(const auto& [key, value] : instruments) {
        res.emplace_back(value);
    }

    return res;
}

#endif //SHEEPSKIN_MAPPER_H
