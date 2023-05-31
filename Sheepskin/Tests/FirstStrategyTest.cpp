//
// Created by barte on 29.05.2023.
//
//
// Created by Wiktor Kruszewicz on 11/05/2023.
//

#include <gtest/gtest.h>
#include "Strategies/FirstStrategy/FirstStrategy.h"
#include "Data/Instrument/Stock/Stock.h"
#include "Data/Instrument/CryptoCurrency/CryptoCurrency.h"
#include "Data/Instrument/ETF/ETF.h"

TEST(FirstStrategyTest, FirstStrategyGetPriceTest){
    Stock stock("id");
    FirstStrategy strategy(&stock);

    Price value1 = strategy.status((3));
    Price value2 = strategy.status((0));
    Price value3 = strategy.status((-2.34));
    ASSERT_EQ(value1, DECREASE);
    ASSERT_EQ(value2, STILL);
    ASSERT_EQ(value3, INCREASE);
}
TEST(FirstStrategyTest, FirstStrategyLookForChangeTest){
    Stock stock("id");
    FirstStrategy strategy(&stock);
    std::vector<double> tangens = {1.2, 2.3, 0.6, -0.45, -0.22};
    int index = strategy.lookForChange(tangens, 0);
    ASSERT_EQ(index, 2);
}
TEST(FirstStrategyTest, FirstStrategyCalculateTangensForStock){
    Stock stock("id");
    FirstStrategy strategy(&stock);
    Record record1(1647580800,2485.00,2505.00,2470.00,2500.00,2);
    Record record2(1647580860,2495.00,2500.00,2490.00,2495.00,1.5);

    double result = strategy.calculateTangens(record1, record2);

    ASSERT_FLOAT_EQ(result, -0.041669998);
}
TEST(FirstStrategyTest, FirstStrategyTestListOfTangentsForStock) {
    Stock stock("id");
    Record record1(1647580800, 2485.00, 2500.00, 2470.00, 2500.00, 2);
    Record record2(1647580860, 2480.00, 2500.00, 2470.00, 2500.00, 1.5);
    Record record3(1647580920, 2490.00, 2500.00, 2470.00, 2500.00, 1.0);
    Record record4(1647580980, 2490.00, 2500.00, 2470.00, 2500.00, 0.5);
    stock.addRecord(record1);
    stock.addRecord(record2);
    stock.addRecord(record3);
    stock.addRecord(record4);
    FirstStrategy strategy(&stock);
    std::vector<double> result = strategy.listOfTangens();

    ASSERT_FLOAT_EQ(result.at(0), 0.041669998);
    ASSERT_FLOAT_EQ(result.at(1), -0.083329998);
    ASSERT_FLOAT_EQ(result.at(2), 0);
}
TEST(FirstStrategyTest, FirstStrategyCalculateDifferenceCryptocurrency) {
    CryptoCurrency crypto("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2600.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2610.00, 1.5);
    crypto.addRecord(record1);
    crypto.addRecord(record2);
    FirstStrategy strategy(&crypto);
    double result = strategy.calculateDifference(0, 1);

    ASSERT_FLOAT_EQ(result, 10);
}
TEST(FirstStrategyTest, FirstStrategyCalculateDifferenceStock) {
    Stock stock("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2600.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2610.00, 1.5);
    stock.addRecord(record1);
    stock.addRecord(record2);
    FirstStrategy strategy(&stock);
    double result = strategy.calculateDifference(0, 1);

    ASSERT_FLOAT_EQ(result, 60);
}
TEST(FirstStrategyTest, FirstStrategyCalculateDifferenceETF) {
    ETF etf("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2600.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2610.00, 1.5);
    etf.addRecord(record1);
    etf.addRecord(record2);
    FirstStrategy strategy(&etf);
    double result = strategy.calculateDifference(0, 1);

    ASSERT_FLOAT_EQ(result, 47.5);
}
TEST(FirstStrategyTest, FirstStrategyCalculateSumOfDifferenceForStock) {
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
    FirstStrategy strategy(&stock);
    double result = strategy.sumOfDifference(strategy.listOfTangens());

    ASSERT_FLOAT_EQ(result, 120.0);
}
TEST(FirstStrategyTest, FirstStrategyCalculateSumOfDifferenceForETF) {
    ETF etf("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2500.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2510.00, 1.5);
    Record record3(1647580920, 2605.00, 2625.00, 2590.00, 2520.00, 1.0);
    Record record4(1647580980, 2665.00, 2685.00, 2650.00, 2530.00, 0.5);
    Record record5(1647581040, 2725.00, 2745.00, 2710.00, 2540.00, 0.0);
    Record record6(1647581100, 2785.00, 2805.00, 2770.00, 2550.00, -0.5);
    Record record7(1647581160, 2845.00, 2865.00, 2830.00, 2560.00, -1.0);
    etf.addRecord(record1);
    etf.addRecord(record2);
    etf.addRecord(record3);
    etf.addRecord(record6);
    etf.addRecord(record5);
    etf.addRecord(record4);
    etf.addRecord(record7);
    FirstStrategy strategy(&etf);
    double result = strategy.sumOfDifference(strategy.listOfTangens());

    ASSERT_FLOAT_EQ(result, 95.0);
}
TEST(FirstStrategyTest, FirstStrategyCalculateSumOfDifferenceForCryptocurrency) {
    CryptoCurrency crypto("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2500.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2510.00, 1.5);
    Record record3(1647580920, 2605.00, 2625.00, 2590.00, 2520.00, 1.0);
    Record record4(1647580980, 2665.00, 2685.00, 2650.00, 2530.00, 0.5);
    Record record5(1647581040, 2725.00, 2745.00, 2710.00, 2540.00, 0.0);
    Record record6(1647581100, 2785.00, 2805.00, 2770.00, 2550.00, -0.5);
    Record record7(1647581160, 2845.00, 2865.00, 2830.00, 2560.00, -1.0);
    crypto.addRecord(record1);
    crypto.addRecord(record2);
    crypto.addRecord(record3);
    crypto.addRecord(record6);
    crypto.addRecord(record5);
    crypto.addRecord(record4);
    crypto.addRecord(record7);
    FirstStrategy strategy(&crypto);
    double result = strategy.sumOfDifference(strategy.listOfTangens());

    ASSERT_FLOAT_EQ(result, 20.0);
}
TEST(FirstStrategyTest, FirstStrategyCalculateSumOfDifferenceForCryptocurrencyNoSecondChange) {
    CryptoCurrency crypto("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2500.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2510.00, 1.5);
    Record record3(1647580920, 2605.00, 2625.00, 2590.00, 2520.00, 1.0);
    Record record4(1647580980, 2665.00, 2685.00, 2650.00, 2530.00, 0.5);
    Record record5(1647581040, 2725.00, 2745.00, 2710.00, 2520.00, 0.0);
    Record record6(1647581100, 2785.00, 2805.00, 2770.00, 2500.00, -0.5);
    Record record7(1647581160, 2845.00, 2865.00, 2830.00, 2400.00, -1.0);
    crypto.addRecord(record1);
    crypto.addRecord(record2);
    crypto.addRecord(record3);
    crypto.addRecord(record6);
    crypto.addRecord(record5);
    crypto.addRecord(record4);
    crypto.addRecord(record7);
    FirstStrategy strategy(&crypto);
    double result = strategy.sumOfDifference(strategy.listOfTangens());

    ASSERT_FLOAT_EQ(result, -130.0);
}
TEST(FirstStrategyTest, FirstStrategyCalculateSumOfDifferenceIfThereWasNotChangeInState) {
    Stock stock("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2500.00, 2);
    Record record2(1647580860,  2485.00, 2505.00, 2470.00, 2510.00, 2);
    Record record3(1647580920,  2485.00, 2507.00, 2470.00, 2520.00, 2);
    Record record4(1647580980,  2485.00, 2509.00, 2470.00, 2530.00, 2);
    stock.addRecord(record1);
    stock.addRecord(record2);
    stock.addRecord(record3);
    stock.addRecord(record4);
    FirstStrategy strategy(&stock);
    double result = strategy.sumOfDifference(strategy.listOfTangens());

    ASSERT_FLOAT_EQ(result, 4.5);
}
TEST(FirstStrategyTest, FirstStrategyCalculateMovingAverageForStock) {
    Stock stock("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2600.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2610.00, 1.5);
    stock.addRecord(record1);
    stock.addRecord(record2);
    FirstStrategy strategy(&stock);
    double result = strategy.calculateMovingAverage();

    ASSERT_FLOAT_EQ(result, 2515);
}
TEST(FirstStrategyTest, FirstStrategyCalculateMovingAverageForCrypto) {
    CryptoCurrency crypto("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2600.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2610.00, 1.5);
    crypto.addRecord(record1);
    crypto.addRecord(record2);
    FirstStrategy strategy(&crypto);
    double result = strategy.calculateMovingAverage();

    ASSERT_FLOAT_EQ(result, 2603.333);
}
TEST(FirstStrategyTest, FirstStrategyCalculateMovingAverageForETF) {
    ETF etf("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2600.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2610.00, 1.5);
    etf.addRecord(record1);
    etf.addRecord(record2);
    FirstStrategy strategy(&etf);
    double result = strategy.calculateMovingAverage();

    ASSERT_FLOAT_EQ(result, 2530.8333);
}
TEST(FirstStrategyTest, FirstStrategyCheckStatusForStock){
    Stock stock("id");
    Record record1(1647580800, 2485.00, 2500.00, 2470.00, 2500.00, 2);
    Record record2(1647580860, 2480.00, 2500.00, 2470.00, 2500.00, 1.5);
    Record record3(1647580920, 2490.00, 2500.00, 2470.00, 2500.00, 1.0);
    Record record4(1647580980, 2490.00, 2500.00, 2470.00, 2500.00, 0.5);
    stock.addRecord(record1);
    stock.addRecord(record2);
    stock.addRecord(record3);
    stock.addRecord(record4);
    FirstStrategy strategy(&stock);
    std::vector<double> result = strategy.listOfTangens();
    double value1 = result.at(0);
    double value2 = result.at(1);
    double value3 = result.at(2);
    Price price1 = strategy.status(value1);
    Price price2 = strategy.status(value2);
    Price price3 = strategy.status(value3);
    ASSERT_EQ(price1, DECREASE);
    ASSERT_EQ(price3, STILL);
    ASSERT_EQ(price2, INCREASE);
}
TEST(FirstStrategyTest, FirstStrategylastStatusINCREACE){
    Stock stock("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2500.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2510.00, 1.5);
    Record record3(1647580920, 2605.00, 2625.00, 2590.00, 2560.00, 1.0);
    Record record4(1647580980, 2665.00, 2685.00, 2650.00, 2560.00, 0.5);
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
    FirstStrategy strategy(&stock);
    std::vector<double> tangens = strategy.listOfTangens();
    Price price = strategy.lastStatus();

    ASSERT_EQ(price, INCREASE);
}
TEST(FirstStrategyTest, FirstStrategylastStatusDECREASE){
    Stock stock("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2500.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2510.00, 1.5);
    Record record3(1647580920, 2605.00, 2625.00, 2590.00, 2560.00, 1.0);
    Record record4(1647580980, 2725.00, 2755.00, 2720.00, 2550.00, 0.5);
    Record record5(1647581040, 2725.00, 2745.00, 2710.00, 2540.00, 0.0);
    stock.addRecord(record1);
    stock.addRecord(record2);
    stock.addRecord(record3);
    stock.addRecord(record4);
    stock.addRecord(record5);
    FirstStrategy strategy(&stock);
    std::vector<double> tangens = strategy.listOfTangens();
    Price price = strategy.lastStatus();

    ASSERT_EQ(price, DECREASE);
}
TEST(FirstStrategyTest, FirstStrategylastStatusSTILL){
    Stock stock("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2500.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2510.00, 1.5);
    Record record3(1647580920, 2665.00, 2685.00, 2650.00, 2560.00, 1.0);
    Record record4(1647580980, 2665.00, 2685.00, 2650.00, 2560.00, 0.5);
    stock.addRecord(record1);
    stock.addRecord(record2);
    stock.addRecord(record3);
    stock.addRecord(record4);
    FirstStrategy strategy(&stock);
    std::vector<double> tangens = strategy.listOfTangens();
    Price price = strategy.lastStatus();

    ASSERT_EQ(price, STILL);
}
TEST(FirstStrategyTest, FirstStrategyGetNumberOfStatusForStock){
    Stock stock("id");
    Record record1(1647580800, 60, 200, 10, 50, 2);
    Record record2(1647580860, 70, 200, 10, 50, 1.5);
    Record record3(1647580920, 80, 200, 10, 50, 1.0);
    Record record4(1647580980, 90, 200, 10, 50, 0.5);
    Record record5(1647581040, 70, 200, 10, 50, 0.0);
    Record record6(1647581100, 50, 200, 10, 50, -0.5);
    Record record7(1647581160, 50, 200, 10, 50, -1.0);
    stock.addRecord(record1);
    stock.addRecord(record2);
    stock.addRecord(record3);
    stock.addRecord(record4);
    stock.addRecord(record5);
    stock.addRecord(record6);
    stock.addRecord(record7);
    FirstStrategy strategy(&stock);
    std::vector<double> tangens = strategy.listOfTangens();
    std::tuple<int, int, int> status = strategy.getNumberOfStatus(tangens);
    int numChanges = get<0>(status);
    int riseNum = get<1>(status);
    int fallNum = get<2>(status);
    ASSERT_EQ(numChanges, 6);
    ASSERT_EQ(riseNum, 3);
    ASSERT_EQ(fallNum, 2);
}
TEST(FirstStrategyTest, FirstStrategyGetNumberOfStatusForETF) {
    ETF etf("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2500.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2510.00, 1.5);
    Record record3(1647580920, 2605.00, 2625.00, 2590.00, 2560.00, 1.0);
    Record record4(1647580980, 2665.00, 2685.00, 2650.00, 2560.00, 0.5);
    Record record5(1647581040, 2725.00, 2745.00, 2710.00, 2540.00, 0.0);
    Record record6(1647581100, 2785.00, 2805.00, 2770.00, 2550.00, -0.5);
    Record record7(1647581160, 2845.00, 2865.00, 2830.00, 2560.00, -1.0);
    etf.addRecord(record1);
    etf.addRecord(record2);
    etf.addRecord(record3);
    etf.addRecord(record4);
    etf.addRecord(record5);
    etf.addRecord(record6);
    etf.addRecord(record7);
    FirstStrategy strategy(&etf);
    std::vector<double> tangens = strategy.listOfTangens();
    std::tuple<int, int, int> status = strategy.getNumberOfStatus(tangens);
    int numChanges = get<0>(status);
    int riseNum = get<1>(status);
    int fallNum = get<2>(status);
    ASSERT_EQ(numChanges, 6);
    ASSERT_EQ(riseNum, 6);
    ASSERT_EQ(fallNum, 0);
}
TEST(FirstStrategyTest, FirstStrategyGetNumberOfStatusForCrypto) {
    CryptoCurrency crypto("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2500.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2510.00, 1.5);
    Record record3(1647580920, 2605.00, 2625.00, 2590.00, 2560.00, 1.0);
    Record record4(1647580980, 2665.00, 2685.00, 2650.00, 2560.00, 0.5);
    Record record5(1647581040, 2725.00, 2745.00, 2710.00, 2540.00, 0.0);
    Record record6(1647581100, 2785.00, 2805.00, 2770.00, 2540.00, -0.5);
    Record record7(1647581160, 2845.00, 2865.00, 2830.00, 2560.00, -1.0);
    crypto.addRecord(record1);
    crypto.addRecord(record2);
    crypto.addRecord(record3);
    crypto.addRecord(record4);
    crypto.addRecord(record5);
    crypto.addRecord(record6);
    crypto.addRecord(record7);
    FirstStrategy strategy(&crypto);
    std::vector<double> tangens = strategy.listOfTangens();
    std::tuple<int, int, int> status = strategy.getNumberOfStatus(tangens);
    int numChanges = get<0>(status);
    int riseNum = get<1>(status);
    int fallNum = get<2>(status);
    ASSERT_EQ(numChanges, 6);
    ASSERT_EQ(riseNum, 3);
    ASSERT_EQ(fallNum, 1);
}
TEST(FirstStrategyTest, FirstStrategyEvalResultForStock) {
    Stock stock("id");
    Record record1(1647580800,134.50,135.75,133.90,135.25,1000);
    Record record2(1647580860,135.30,135.50,134.80,135.30,500);
    Record record3(1647580920,135.40,135.60,135.10,135.40,750);
    Record record4(1647580980,135.35,135.55,135.00,135.35,800);
    Record record5(1647581040,135.45,135.65,135.25,135.45,1200);
    stock.addRecord(record1);
    stock.addRecord(record2);
    stock.addRecord(record3);
    stock.addRecord(record4);
    stock.addRecord(record5);
    FirstStrategy strategy(&stock);
    StrategyResult result = strategy.eval();

    ASSERT_FLOAT_EQ(result.getFallChance(), 8.33);
    ASSERT_FLOAT_EQ(result.getRiseChance(), 8.39);
    ASSERT_FLOAT_EQ(result.getMaintanceChance(), 83.28);
}
TEST(FirstStrategyTest, FirstStrategyEvalResultForETF) {
    ETF etf("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2600.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2610.00, 1.5);
    Record record3(1647580920, 2605.00, 2625.00, 2590.00, 2620.00, 1.0);
    Record record4(1647580980, 2665.00, 2685.00, 2650.00, 2630.00, 0.5);
    Record record5(1647581040, 2725.00, 2745.00, 2710.00, 2640.00, 0.0);
    Record record6(1647581100, 2785.00, 2805.00, 2770.00, 2650.00, -0.5);
    Record record7(1647581160, 2845.00, 2865.00, 2830.00, 2660.00, -1.0);
    etf.addRecord(record1);
    etf.addRecord(record2);
    etf.addRecord(record3);
    etf.addRecord(record4);
    etf.addRecord(record5);
    etf.addRecord(record6);
    etf.addRecord(record7);
    FirstStrategy strategy(&etf);
    StrategyResult result = strategy.eval();

    ASSERT_FLOAT_EQ(result.getFallChance(), 7.65);
    ASSERT_FLOAT_EQ(result.getRiseChance(), 92.35);
    ASSERT_FLOAT_EQ(result.getMaintanceChance(), 0.0);
}
TEST(FirstStrategyTest, FirstStrategyEvalResultForCrypto) {
    CryptoCurrency crypto("id");
    Record record1(1647580800, 2485.00, 2505.00, 2470.00, 2600.00, 2);
    Record record2(1647580860, 2545.00, 2565.00, 2530.00, 2610.00, 1.5);
    Record record3(1647580920, 2605.00, 2625.00, 2590.00, 2620.00, 1.0);
    Record record4(1647580980, 2665.00, 2685.00, 2650.00, 2630.00, 0.5);
    Record record5(1647581040, 2725.00, 2745.00, 2710.00, 2640.00, 0.0);
    Record record6(1647581100, 2785.00, 2805.00, 2770.00, 2650.00, -0.5);
    Record record7(1647581160, 2845.00, 2865.00, 2830.00, 2660.00, -1.0);
    crypto.addRecord(record1);
    crypto.addRecord(record2);
    crypto.addRecord(record3);
    crypto.addRecord(record4);
    crypto.addRecord(record5);
    crypto.addRecord(record6);
    crypto.addRecord(record7);
    FirstStrategy strategy(&crypto);
    StrategyResult result = strategy.eval();

    ASSERT_FLOAT_EQ(result.getFallChance(), 8.18);
    ASSERT_FLOAT_EQ(result.getRiseChance(), 91.82);
    ASSERT_FLOAT_EQ(result.getMaintanceChance(), 0.0);
}
TEST(FirstStrategyTest, FirstStrategyEvalResultForStockHighMaintanceChance) {
    Stock stock("id");
    Record record1(1647580800,135.45,200,100,135.25,1000);
    Record record2(1647580860,135.45,200,100,135.25,500);
    Record record3(1647580920,135.45,200,100,135.25,750);
    Record record4(1647580980,135.45,200,100,135.25,800);
    Record record5(1647581040,135.45,200,100,135.25,1200);
    stock.addRecord(record1);
    stock.addRecord(record2);
    stock.addRecord(record3);
    stock.addRecord(record4);
    stock.addRecord(record5);
    FirstStrategy strategy(&stock);
    StrategyResult result = strategy.eval();

    ASSERT_FLOAT_EQ(result.getFallChance(), 0);
    ASSERT_FLOAT_EQ(result.getRiseChance(), 7.69);
    ASSERT_FLOAT_EQ(result.getMaintanceChance(), 92.31);
}
TEST(FirstStrategyTest, FirstStrategyGetNumberOfStatusMaintanceforStock){
    Stock stock("id");
    Record record1(1647580800,135.45,200,100,135.25,1000);
    Record record2(1647580860,135.45,200,100,135.25,500);
    Record record3(1647580920,135.45,200,100,135.25,750);
    Record record4(1647580980,135.45,200,100,135.25,800);
    Record record5(1647581040,135.45,200,100,135.25,1200);
    stock.addRecord(record1);
    stock.addRecord(record2);
    stock.addRecord(record3);
    stock.addRecord(record4);
    stock.addRecord(record5);
    FirstStrategy strategy(&stock);
    std::vector<double> tangens = strategy.listOfTangens();
    std::tuple<int, int, int> status = strategy.getNumberOfStatus(tangens);
    int numChanges = get<0>(status);
    int riseNum = get<1>(status);
    int fallNum = get<2>(status);
    ASSERT_EQ(numChanges, 4);
    ASSERT_EQ(riseNum, 0);
    ASSERT_EQ(fallNum, 0);
}
TEST(FirstStrategyTest, FirstStrategyEvalResultForStockHighFallChance) {
    Stock stock("id");
    Record record1(1647580800,135.45,200,100,175.25,1000);
    Record record2(1647580860,130.45,200,100,170.25,500);
    Record record3(1647580920,125.45,200,100,165.25,750);
    Record record4(1647580980,120.45,200,100,160.25,800);
    Record record5(1647581040,100.45,200,100,125.25,1200);
    stock.addRecord(record1);
    stock.addRecord(record2);
    stock.addRecord(record3);
    stock.addRecord(record4);
    stock.addRecord(record5);
    FirstStrategy strategy(&stock);
    StrategyResult result = strategy.eval();

    ASSERT_FLOAT_EQ(result.getFallChance(), 93.5);
    ASSERT_FLOAT_EQ(result.getRiseChance(), 6.5);
    ASSERT_FLOAT_EQ(result.getMaintanceChance(), 0);
}
TEST(FirstStrategyTest, FirstStrategyEvalResultForCryptoHighFallChance) {
    CryptoCurrency crypto("id");
    Record record1(1647580800,135.45,200,100,175.25,1000);
    Record record2(1647580860,130.45,200,100,170.25,500);
    Record record3(1647580920,125.45,200,100,165.25,750);
    Record record4(1647580980,120.45,200,100,160.25,800);
    Record record5(1647581040,100.45,200,100,125.25,1200);
    crypto.addRecord(record1);
    crypto.addRecord(record2);
    crypto.addRecord(record3);
    crypto.addRecord(record4);
    crypto.addRecord(record5);
    FirstStrategy strategy(&crypto);
    StrategyResult result = strategy.eval();

    ASSERT_FLOAT_EQ(result.getFallChance(), 93.75);
    ASSERT_FLOAT_EQ(result.getRiseChance(), 6.25);
    ASSERT_FLOAT_EQ(result.getMaintanceChance(), 0);
}
TEST(FirstStrategyTest, FirstStrategyEvalResultForCryptoHighMaintanceChance) {
    CryptoCurrency crypto("id");
    Record record1(1647580800,135.45,200,100,175.25,1000);
    Record record2(1647580860,130.45,200,100,175.25,500);
    Record record3(1647580920,125.45,200,100,175.25,750);
    Record record4(1647580980,120.45,200,100,175.25,800);
    Record record5(1647581040,100.45,200,100,175.25,1200);
    crypto.addRecord(record1);
    crypto.addRecord(record2);
    crypto.addRecord(record3);
    crypto.addRecord(record4);
    crypto.addRecord(record5);
    FirstStrategy strategy(&crypto);
    StrategyResult result = strategy.eval();

    ASSERT_FLOAT_EQ(result.getFallChance(), 0.0);
    ASSERT_FLOAT_EQ(result.getRiseChance(), 0.0);
    ASSERT_FLOAT_EQ(result.getMaintanceChance(), 100.0);
}