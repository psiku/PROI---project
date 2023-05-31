//
// Created by barte on 11.05.2023.
//

#include "Forecast.h"

Forecast::Forecast(double rise_chance, double fall_chance, double maintance_chance): riseChance(rise_chance), fallChance(fall_chance), maintenanceChance(maintance_chance) {}

double Forecast::getFallChance() const {
    return fallChance;
}

double Forecast::getRiseChance() const {
    return riseChance;
}

double Forecast::getMaintanceChance() const {
    return maintenanceChance;
};
