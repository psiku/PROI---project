//
// Created by barte on 11.05.2023.
//

#include "Evaluation.h"

Evaluation::Evaluation(double rise_chance, double fall_chance, double maintance_chance): riseChance(rise_chance), fallChance(fall_chance), maintenanceChance(maintance_chance) {}

double Evaluation::getFallChance() const {
    return fallChance;
}

double Evaluation::getRiseChance() const {
    return riseChance;
}

double Evaluation::getMaintanceChance() const {
    return maintenanceChance;
};
