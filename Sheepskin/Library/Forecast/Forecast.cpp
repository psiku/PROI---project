//
// Created by barte on 11.05.2023.
//

#include "Forecast.h"
#include <cmath>

Forecast::Forecast(double rise_chance, double fall_chance, double maintance_chance): riseChance(rise_chance), fallChance(fall_chance), maintenanceChance(maintance_chance) {}

double Forecast::getFallChance() const {
    return fallChance;
}

double Forecast::getRiseChance() const {
    return riseChance;
}

double Forecast::getMaintanceChance() const {
    return maintenanceChance;
}

bool Forecast::compare(double a, double b) const {
    return std::fabs(a - b) < 1e-4;   // compare to 4th place
}

bool Forecast::operator==(const Forecast &forecast) const {
    return compare(fallChance, forecast.getFallChance())
        && compare(riseChance, forecast.getRiseChance())
        && compare(maintenanceChance, forecast.getMaintanceChance());
}
