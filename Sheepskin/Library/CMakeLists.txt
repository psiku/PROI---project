cmake_minimum_required(VERSION 3.25)
project(Library)

set(CMAKE_CXX_STANDARD 23)

add_library(Library STATIC Data/Instrument/Instrument.cpp Data/Instrument/Instrument.cpp Data/Instrument/Instrument.cpp Data/Stock/Stock.cpp Evaluation/StrategyEvaluation/StrategyEvaluation.cpp Evaluation/DecisionEvaluation/DecisionEvaluation.cpp Strategies/FirstStrategy/FirstStrategy.cpp Strategies/SecondStrategy/SecondStrategy.cpp Strategies/Strategy/Strategy.cpp Strategies/StrategyResult/StrategyResult.cpp Strategies/ThirdStrategy/ThirdStrategy.cpp)
