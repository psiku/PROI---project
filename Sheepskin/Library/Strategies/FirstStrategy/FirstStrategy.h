//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_FIRSTSTRATEGY_H
#define SHEEPSKIN_FIRSTSTRATEGY_H


#include "../Strategy/Strategy.h"
#include <cmath>
#include <iomanip>
#include <sstream>

// Enum for status of instrument
// INCREASE - price is increasing
// STILL - price is still
// DECREASE - price is decreasing
enum Price {
    INCREASE,
    STILL,
    DECREASE
};

// FirstStrategy class is responsible for calculating the forecast for instrument
class FirstStrategy: public Strategy {
public:
    explicit FirstStrategy(Instrument* instrument);
    // Calculates the forecast for instrument
    //@return Forecast object with calculated forecast
    Forecast eval() override;

    // Calculates list of tangents between consecutive records in an instrument's data, and returns vector with these values
    //@return vector with tangents
    std::vector<double> listOfTangens();

    // Calculates Tangens between two records
    //@param record1 - first record
    //@param record2 - second record
    //@return (double)Tangens between two records
    double calculateTangens(const Record& record1, const Record& record2);

    // Looks for change in vector of tangents
    //@param values - vector of tangents
    //@param index - index of tangent to be checked
    //@return index of change in state vector of tangents
    int lookForChange(std::vector<double> values, int index);

    // Calculates the difference in price between two values
    //@param down - first price
    //@param up - second price
    //@return (double) difference between two prices
    double calculateDifference(int down, int up);

    // Calculates the sum of differences between consecutive tangents
    //@param tangens - vector of tangents
    //@return (double) sum of differences between consecutive tangents
    double sumOfDifference(std::vector<double> tangens);

    // sets precision of double value
    //@param value - value to be set
    //@param precision - precision to be set
    //@return (double) value with set precision
    double setPrecision(double value, int precison);

    // Calculates weighted moving average for instrument
    //@return (double) moving average
    double calculateMovingAverage();

    // Calculates the number of status in instrument
    //Check how many times the status has changed
    //@param tangens - vector of tangents
    //@return tuple with number of each status
    std::tuple<int, int, int>getNumberOfStatus(std::vector<double> tangens);

    // Calculates the status of instrument, based on the value of tangent
    //@param value - value to be checked
    //@return Price enum with status of instrument
    Price status(double value);

    // Calculates the last status of instrument, based on the value of tangent
    Price lastStatus();

    // Calculates the chances of each status
    //@return tuple with chances of each status
    std::tuple<double, double, double> calculateChances();
};


#endif //SHEEPSKIN_FIRSTSTRATEGY_H
