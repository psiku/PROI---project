//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_FORECAST_H
#define SHEEPSKIN_FORECAST_H

#include <string>

struct Forecast {
private:
    double riseChance;
    double fallChance;
    double maintenanceChance;

    bool compare(double a, double b) const;
public:
    Forecast(double rise_chance, double fall_chance, double maintance_chance);
    double getRiseChance() const;
    double getFallChance() const;
    double getMaintanceChance() const;

    bool operator==(const Forecast& forecast) const;
};


#endif //SHEEPSKIN_FORECAST_H
