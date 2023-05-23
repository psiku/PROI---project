//
// Created by barte on 11.05.2023.
//

#include <string>
#include <utility>


#include "Stock.h"

Stock::Stock(std::string id): Instrument(id) {}

long double Stock::getVolatility(const Record &record) {
    // Średnia odchylenia = (|Cena otwarcia - Średnia arytmetyczna| +
    // |Cena najwyższa - Średnia arytmetyczna| + |Cena najniższa - Średnia arytmetyczna| +
    // |Cena zamknięcia - Średnia arytmetyczna|) / 4
    long double averageValue = record.getAverage();
    long double averageVolatility = (std::abs(record.open - averageValue) + std::abs(record.close - averageValue)
                                     + std::abs(record.low - averageValue) + std::abs(record.high - averageValue));
    return averageVolatility;
};