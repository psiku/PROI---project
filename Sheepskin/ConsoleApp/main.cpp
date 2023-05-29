#include <iostream>
#include "Data/Record/Record.h"
#include "Strategies/FirstStrategy/FirstStrategy.h"
#include "Data/Instrument/Instrument/Instrument.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2500.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2510.00, 1.5);
    Record record3(1647580920, 2605.00, 2625.00, 2590.00, 2520.00, 1.0);
    Record record4(1647580980, 2665.00, 2685.00, 2650.00, 2530.00, 0.5);
    Record record5(1647581040, 2725.00, 2745.00, 2710.00, 2700.00, 0.0);
    Record record6(1647581100, 2785.00, 2805.00, 2770.00, 2740.00, -0.5);
    Record record7(1647581160, 2845.00, 2865.00, 2830.00, 2200.00, -1.0);


// Set the records
    std::vector<Record> records = {record1, record2, record3, record4, record5, record6, record7};
    Instrument instrument("id");
    instrument.addRecord(record1);
    instrument.addRecord(record2);
    instrument.addRecord(record3);
    instrument.addRecord(record4);
    instrument.addRecord(record5);
    instrument.addRecord(record6);
    instrument.addRecord(record7);
    FirstStrategy strategy(instrument);

// Calculate the chances
    std::tuple<double, double, double> chances = strategy.calculateChances();

// Print the output
    double riseChance = std::get<0>(chances);
    double fallChance = std::get<1>(chances);
    double maintenanceChance = std::get<2>(chances);

    std::cout << "Rise chance: " << riseChance << "%" << std::endl;
    std::cout << "Fall chance: " << fallChance << "%" << std::endl;
    std::cout << "Maintenance chance: " << maintenanceChance << "%" << std::endl;

    return 0;
}
