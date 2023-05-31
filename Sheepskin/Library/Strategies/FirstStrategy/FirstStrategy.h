//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_FIRSTSTRATEGY_H
#define SHEEPSKIN_FIRSTSTRATEGY_H


#include "../Strategy/Strategy.h"
#include <cmath>
#include <iomanip>
#include <sstream>


enum Price {
    INCREASE,
    STILL,
    DECREASE
};

//Druga implementacja FirstStrategy -> mogą nastąpić ewentualne zmiany po  obgadaniu jej funkcjonalności, oraz ewentualna refaktoryzacja kodu

class FirstStrategy: public Strategy {
public:
    explicit FirstStrategy(Instrument* instrument);
    StrategyResult eval() override;             // zwracać ma wynik w postaci rise_chance, fall_chance, maintance_chance
    std::vector<double> listOfTangens();
    double calculateTangens(const Record& record1, const Record& record2);
    int lookForChange(std::vector<double> values, int index);     // zwraca pozycję w wektorze gdzie nastąpiła zmiana
    double calculateDifference(int down, int up);                // zwraca różnicę w cenach między ostatnimi dwoma zmianami
    double sumOfDifference(std::vector<double> tangens);  // zwraca sumę wszystkich zmian
    double setPrecision(double value, int precison);
    double calculateMovingAverage();
    std::tuple<int, int, int>getNumberOfStatus(std::vector<double> tangens);   // zwraca liczbę ile razy się cena podnosiła, ile malała i ile łacznie się zmieniałą
    std::tuple<double, double, double> calculateChances();                          // oblicza % na podstawie ilości zmian oraz ilości różnicy cen oraz obecnym trendzie
    Price status(double value);                                    // na podstawie wartości tangensa określa czy ceny maleją czy rosną
    Price lastStatus();                                                 // zwraca ostatni stan > czy jest malejący, stały czy rosnący
};


#endif //SHEEPSKIN_FIRSTSTRATEGY_H
