////
//// Created by Wiktor Kruszewicz on 11/05/2023.
////
//
//#include <gtest/gtest.h>
//#include "Strategies/FirstStrategy/FirstStrategy.h"
//#include "Data/Instrument/Stock/Stock.h"
//#include "Strategies/SecondStrategy/SecondStrategy.h"
//
//// Testy do zmiany ponieważ zmieniłą się funckja eval w FirstStrategy
////TEST(StrategyTest, FirstStrategyTest) {
////    Stock stock("test");
////    FirstStrategy strategy(stock);
////
////    Evaluation result = strategy.eval();
////    ASSERT_FLOAT_EQ(result.getFallChance(), 0.5);
////    ASSERT_FLOAT_EQ(result.getRiseChance(), 0.5);
////}
//TEST(StrategyTest, SecondStrategyTest) {
//    Stock stock("test");
//    SecondStrategy strategy(stock);
//
//    Evaluation result = strategy.eval();
//    ASSERT_FLOAT_EQ(result.getFallChance(), 0.2);
//    ASSERT_FLOAT_EQ(result.getRiseChance(), 0.8);
//}
////TEST(StrategyTest, BothStrategiesTest) {
////    Stock stock("test");
////    FirstStrategy strategy1(stock);
////    SecondStrategy strategy2(stock);
////    std::vector<Strategy*> vec;
////
////    vec.emplace_back(&strategy1);
////    vec.emplace_back(&strategy2);
////
////
////    ASSERT_FLOAT_EQ(vec[0]->eval().getFallChance(), 0.5);
////    ASSERT_FLOAT_EQ(vec[0]->eval().getRiseChance(), 0.5);
////    ASSERT_FLOAT_EQ(vec[1]->eval().getFallChance(), 0.2);
////    ASSERT_FLOAT_EQ(vec[1]->eval().getRiseChance(), 0.8);
////}
