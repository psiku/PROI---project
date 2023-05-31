//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//

#ifndef SHEEPSKIN_ESTIMATION_H
#define SHEEPSKIN_ESTIMATION_H


#include "../Forecast/Forecast.h"
#include "../Data/Instrument/Instrument/Instrument.h"

struct Estimation {
private:
    Instrument instrument;
    Forecast forecast;
public:
    Estimation(Instrument instrument, Forecast forecast) : instrument(instrument), forecast(forecast) {}

    Instrument getInstrument() const {
        return instrument;
    }

    Forecast getForecast() const {
        return forecast;
    }
};


#endif //SHEEPSKIN_ESTIMATION_H
