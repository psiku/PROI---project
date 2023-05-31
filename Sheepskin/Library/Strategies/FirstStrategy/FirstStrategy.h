//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_FIRSTSTRATEGY_H
#define SHEEPSKIN_FIRSTSTRATEGY_H


#include "../Strategy/Strategy.h"
#include <cmath>
#include <iomanip>
#include <sstream>

//defines an enumeration called "Price" with three possible states: INCREASE, STILL, and DECREASE.
//The enumeration is used to represent the price movement or change.
//INCREASE indicates a price increase.
//STILL indicates no change in price.
//DECREASE indicates a price decrease.
enum Price {
    INCREASE,
    STILL,
    DECREASE
};


class FirstStrategy: public Strategy {
public:
    explicit FirstStrategy(Instrument* instrument);
    StrategyResult eval() override;                         // returns % of rise, fall or maintance in price of instrument
    std::vector<double> listOfTangens();                   //  calculates the tangents between consecutive records in an instrument's data, and returns vector with these values
    double calculateTangens(const Record& record1, const Record& record2); // calculate the tangens between next two records and returns it
    int lookForChange(std::vector<double> values, int index);     // returns the position in the vector where a change in state has occurred.
    double calculateDifference(int down, int up);                // returns the difference in prices between the last two state changes.
    double sumOfDifference(std::vector<double> tangens);        // returns the sum of all changes in states
    double setPrecision(double value, int precison);           // set precision to precision-th place after the decimal
    double calculateMovingAverage();                          // calculate weighted moving average for Instrument
    std::tuple<int, int, int>getNumberOfStatus(std::vector<double> tangens);   // returns a tuple with information about how many times the price has increased, decreased, and the total number of comparisons
    std::tuple<double, double, double> calculateChances();   // calculates the percentage based on the number of changes, the sumOfDifference, the current trend, and the moving average.
    Price status(double value);                              // returns current status based on tangent value
    Price lastStatus();                                      // returns last state of an Instrument
};


#endif //SHEEPSKIN_FIRSTSTRATEGY_H
