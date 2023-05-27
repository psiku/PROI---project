//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_FIRSTSTRATEGY_H
#define SHEEPSKIN_FIRSTSTRATEGY_H


#include "../Strategy/Strategy.h"
#include <cmath>


enum Price {
    INCREASE,
    STILL,
    DECREASE
};

class FirstStrategy: public Strategy {
public:
    explicit FirstStrategy(Instrument instrument);
    StrategyResult eval() override;             // zwraca wynik czy będzie rosło
    long double calculateTangens(const Record& record1, const Record& record2);
    std::vector<long double> listOfTangens();
    Price status(long double value);
    int lookForChange(std::vector<long double> values, int index);     // zwraca pozycję w wektorze gdzie nastąpiła zmiana
    long double calculateDifference(int down, int up);       // zwraca różnicę w cenach
    long double sumOfDifference(std::vector<long double> tangens);  // zwracać będzie średnią albo sumę wszystkich zmian
    int calculatePercentage(long double sumOfDifference);          // wylicza procenty na powodzenie
};


#endif //SHEEPSKIN_FIRSTSTRATEGY_H
