//
// Created by Wiktor Kruszewicz on 11/05/2023.
//

#include "Instrument.h"

#include <utility>

Instrument::Instrument(std::string id) : id(std::move(id)) {}

void Instrument::addRecord(const Record &record) {
    records.push_back(record);
}

double Instrument::getVolatility(const Record &record) {
    return 0.0;
}

std::vector<Record> Instrument::getRecords() const {
    return records;
}
std::string Instrument::getId() const {
    return id;
}

double Instrument::getPrice(const Record &record) {
    return 0;
}

std::string Instrument::getType() const {
    return "instrument";
}