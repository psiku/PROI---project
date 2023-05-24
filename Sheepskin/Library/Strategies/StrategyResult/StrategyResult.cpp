//
// Created by barte on 11.05.2023.
//

#include "StrategyResult.h"

StrategyResult::StrategyResult(double rise_chance, double fall_chance, double maintance_chance): rise_chance(rise_chance), fall_chance(fall_chance), maintenance_chance(maintance_chance) {}

double StrategyResult::getFallChance() const {
    return fall_chance;
}

double StrategyResult::getRiseChance() const {
    return rise_chance;
}

double StrategyResult::getMaintanceChance() const {
    return maintenance_chance;
};
