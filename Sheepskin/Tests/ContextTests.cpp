//
// Created by Grzegorz Statkiewicz on 31/05/2023.
//
#include <gtest/gtest.h>
#include "Context/Context.h"

class ExampleStrategy : public Strategy {
public:
    explicit ExampleStrategy(Instrument* instrument) : Strategy(instrument) {}
    Forecast eval() override {
        return { 1,1,1};
    }
};

TEST(ContextTests, SetStrategyTest) {
    Context context;

    context.set(std::make_unique<ExampleStrategy>(nullptr));
    Forecast forecast = context.run();

    ASSERT_TRUE(forecast == Forecast(1,1,1));
}
