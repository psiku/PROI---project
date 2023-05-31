//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_STRATEGY_H
#define SHEEPSKIN_STRATEGY_H


#include "../../Data/Instrument/Instrument/Instrument.h"
#include "../../Evaluation/Evaluation.h"


class Strategy {
private:
    Instrument* instrument;
public:
    Strategy(Instrument* instrument);
    virtual Evaluation eval() = 0;      // virtual function which returns % of rise, fall or maintance in price of instrument
    Instrument* getInstrument();            // returns a pointer to an Instrument object stored in the Strategy class
};



#endif //SHEEPSKIN_STRATEGY_H
