//
// Created by barte on 29.05.2023.
//
//
// Created by Wiktor Kruszewicz on 11/05/2023.
//

#include <gtest/gtest.h>
#include "Strategies/FirstStrategy/FirstStrategy.h"
#include "Data/Instrument/Stock/Stock.h"

TEST(FirstStrategyTest, FirstStrategyGetPriceTest){
    Stock stock("id");
    FirstStrategy strategy(stock);

    Price value1 = strategy.status((3));
    Price value2 = strategy.status((0));
    Price value3 = strategy.status((-2.34));
    ASSERT_EQ(value1, DECREASE);
    ASSERT_EQ(value2, STILL);
    ASSERT_EQ(value3, INCREASE);
}
TEST(FirstStrategyTest, FirstStrategyLookForChangeTest){
    Stock stock("id");
    FirstStrategy strategy(stock);
    std::vector<long double> tangens = {1.2, 2.3, 0.6, -0.45, -0.22};
    int index = strategy.lookForChange(tangens, 0);
    ASSERT_EQ(index, 2);
}
TEST(FirstStrategyTest, FirstStrategyCalculateTangens){
    Stock stock("id");
    FirstStrategy strategy(stock);
    Record record1(1647580800,2485.00,2505.00,2470.00,2500.00,2);
    Record record2(1647580860,2495.00,2500.00,2490.00,2495.00,1.5);

    long double result = strategy.calculateTangens(record1, record2);

    ASSERT_FLOAT_EQ(result, 0.08333);
}
TEST(FirstStrategyTest, FirstStrategyCalculateSumOfDifference) {
    Stock stock("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2500.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2510.00, 1.5);
    Record record3(1647580920, 2605.00, 2625.00, 2590.00, 2520.00, 1.0);
    Record record4(1647580980, 2665.00, 2685.00, 2650.00, 2530.00, 0.5);
    Record record5(1647581040, 2725.00, 2745.00, 2710.00, 2540.00, 0.0);
    Record record6(1647581100, 2785.00, 2805.00, 2770.00, 2550.00, -0.5);
    Record record7(1647581160, 2845.00, 2865.00, 2830.00, 2560.00, -1.0);
    stock.addRecord(record1);
    stock.addRecord(record2);
    stock.addRecord(record3);
    stock.addRecord(record6);
    stock.addRecord(record5);
    stock.addRecord(record4);
    stock.addRecord(record7);
    FirstStrategy strategy(stock);
    long double result = strategy.sumOfDifference(strategy.listOfTangens());

    ASSERT_FLOAT_EQ(result, 20.0);
}
TEST(FirstStrategyTest, FirstStrategyCalculateSumOfDifferenceIfThereWasNotChangeInState) {
    Stock stock("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2500.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2510.00, 1.5);
    Record record3(1647580920, 2605.00, 2625.00, 2590.00, 2520.00, 1.0);
    Record record4(1647580980, 2665.00, 2685.00, 2650.00, 2530.00, 0.5);
    Record record5(1647581040, 2725.00, 2745.00, 2710.00, 2540.00, 0.0);
    Record record6(1647581100, 2785.00, 2805.00, 2770.00, 2550.00, -0.5);
    Record record7(1647581160, 2845.00, 2865.00, 2830.00, 2560.00, -1.0);
    stock.addRecord(record1);
    stock.addRecord(record2);
    stock.addRecord(record3);
    stock.addRecord(record4);
    stock.addRecord(record5);
    stock.addRecord(record6);
    stock.addRecord(record7);
    FirstStrategy strategy(stock);
    long double result = strategy.sumOfDifference(strategy.listOfTangens());

    ASSERT_FLOAT_EQ(result, 60.0);
}
TEST(FirstStrategyTest, FirstStrategyEvalResult) {
    Stock stock("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2600.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2610.00, 1.5);
    Record record3(1647580920, 2605.00, 2625.00, 2590.00, 2620.00, 1.0);
    Record record4(1647580980, 2665.00, 2685.00, 2650.00, 2630.00, 0.5);
    Record record5(1647581040, 2725.00, 2745.00, 2710.00, 2640.00, 0.0);
    Record record6(1647581100, 2785.00, 2805.00, 2770.00, 2650.00, -0.5);
    Record record7(1647581160, 2845.00, 2865.00, 2830.00, 2660.00, -1.0);
    stock.addRecord(record1);
    stock.addRecord(record2);
    stock.addRecord(record3);
    stock.addRecord(record4);
    stock.addRecord(record5);
    stock.addRecord(record6);
    stock.addRecord(record7);
    FirstStrategy strategy(stock);
    StrategyResult result = strategy.eval();

    ASSERT_FLOAT_EQ(result.getFallChance(), 0.0);
    ASSERT_FLOAT_EQ(result.getRiseChance(), 100.0);
    ASSERT_FLOAT_EQ(result.getMaintanceChance(), 0.0);
}
TEST(FirstStrategyTest, FirstStrategyCalculateMovingAverage) {
    Stock stock("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2600.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2610.00, 1.5);
    Record record3(1647580920, 2605.00, 2625.00, 2590.00, 2620.00, 1.0);
    stock.addRecord(record1);
    stock.addRecord(record2);
    stock.addRecord(record3);
    FirstStrategy strategy(stock);
    long double result = strategy.calculateMovingAverage();

    ASSERT_FLOAT_EQ(result, 2970.0);
}