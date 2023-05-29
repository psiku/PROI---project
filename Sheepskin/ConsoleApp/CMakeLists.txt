cmake_minimum_required(VERSION 3.25)
project(ConsoleApp)

set(CMAKE_CXX_STANDARD 23)

add_executable(ConsoleApp main.cpp Data/CSVReader/CSVReader/CSVReader.h ../Library/Data/Instrument/Instrument/Instrument.h ../Library/Data/Instrument/Instrument/Instrument.cpp ../Library/Data/Record/Record.cpp ../Library/Data/Record/Record.h ../Library/Strategies/Strategy/Strategy.cpp ../Library/Strategies/Strategy/Strategy.h ../Library/Strategies/FirstStrategy/FirstStrategy.cpp ../Library/Strategies/FirstStrategy/FirstStrategy.h ../Library/Strategies/SecondStrategy/SecondStrategy.cpp ../Library/Strategies/SecondStrategy/SecondStrategy.h ../Library/Strategies/ThirdStrategy/ThirdStrategy.cpp ../Library/Strategies/ThirdStrategy/ThirdStrategy.h ../Library/Strategies/StrategyResult/StrategyResult.cpp ../Library/Strategies/StrategyResult/StrategyResult.h Data/CSVWriter/CSVWriter.cpp ../Library/Evaluation/DecisionEvaluation/DecisionEvaluation.cpp ../Library/Evaluation/DecisionEvaluation/DecisionEvaluation.h ../Library/Evaluation/StrategyEvaluation/StrategyEvaluation.cpp Data/CSVWriter/CSVWriter.h ../Library/Data/Record/Record.cpp Data/CSVReader/CSVResult/CSVResult.h Data/CSVReader/Mapper/Mapper.h)


include_directories(../Library)
target_link_libraries(ConsoleApp Library)

