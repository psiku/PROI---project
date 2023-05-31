//
// Created by barte on 11.05.2023.
//

#ifndef SHEEPSKIN_EVALUATION_H
#define SHEEPSKIN_EVALUATION_H

#include <string>

class Evaluation {
private:
    double riseChance;
    double fallChance;
    double maintenanceChance;
public:
    Evaluation(double rise_chance, double fall_chance, double maintance_chance);
    double getRiseChance() const;
    double getFallChance() const;
    double getMaintanceChance() const;

};


#endif //SHEEPSKIN_EVALUATION_H
