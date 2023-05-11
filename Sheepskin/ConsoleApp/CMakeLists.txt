cmake_minimum_required(VERSION 3.25)
project(ConsoleApp)

set(CMAKE_CXX_STANDARD 23)

add_executable(ConsoleApp main.cpp Data/CSVReader/CSVReader.cpp Data/CSVReader/CSVReader.h Data/Data/Data.cpp Data/Data/Data.h Strategies/Strategy/Strategy.cpp Strategies/Strategy/Strategy.h Strategies/FirstStrategy/FirstStrategy.cpp Strategies/FirstStrategy/FirstStrategy.h Strategies/SecondStrategy/SecondStrategy.cpp Strategies/SecondStrategy/SecondStrategy.h Strategies/ThirdStrategy/ThirdStrategy.cpp Strategies/ThirdStrategy/ThirdStrategy.h Strategies/StrategyResult/StrategyResult.cpp Strategies/StrategyResult/StrategyResult.h OutputParser/OutputParser.cpp OutputParser/OutputParser.h InstrumentDecisionEvaluation/InstrumentDecisionEvaluation.cpp InstrumentDecisionEvaluation/InstrumentDecisionEvaluation.h DecisionEvaluation/DecisionEvaluation.cpp DecisionEvaluation/DecisionEvaluation.h)

include_directories(../Library)
target_link_libraries(ConsoleApp Library)

