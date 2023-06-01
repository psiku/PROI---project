cmake_minimum_required(VERSION 3.25)
project(Library)

set(CMAKE_CXX_STANDARD 23)


add_library(Library STATIC Data/Instrument/Instrument/Instrument.h Data/Instrument/Instrument/Instrument.cpp Data/Record/Record.h Data/Record/Record.cpp Strategies/FirstStrategy/FirstStrategy.h Strategies/FirstStrategy/FirstStrategy.cpp Strategies/SecondStrategy/SecondStrategy.h Strategies/SecondStrategy/SecondStrategy.cpp Strategies/Strategy/Strategy.h Strategies/Strategy/Strategy.cpp Forecast/Forecast.h Forecast/Forecast.cpp Strategies/ThirdStrategy/ThirdStrategy.h Strategies/ThirdStrategy/ThirdStrategy.cpp Data/Instrument/CryptoCurrency/CryptoCurrency.cpp Data/Instrument/CryptoCurrency/CryptoCurrency.h Data/Instrument/ETF/ETF.cpp Data/Instrument/ETF/ETF.h Data/Instrument/Stock/Stock.cpp Data/Instrument/Stock/Stock.h Data/CSVReader/Mapper/Mapper.h Exceptions/TestException.h Context/Context.h Context/Context.cpp Orchestrator/Orchestrator.h Orchestrator/Orchestrator.cpp Evaluator/Evaluator.h Evaluator/Evaluator.cpp Validator/Validator.cpp Validator/Validator.h Validator/Validator.h Strategies/Strategy/StrategyType.h Data/CSVReader/CSVReader/CSVReader.h Data/CSVReader/CSVReader/CSVReader.cpp Data/CSVReader/CSVResult/CSVResult.h Data/CSVReader/CSVResult/CSVResult.cpp Data/CSVReader/Mapper/Mapper.h  Data/CSVReader/Mapper/Mapper.cpp Data/CSVWriter/CSVWriter.h Data/CSVWriter/CSVWriter.cpp ExceptionHandler/ExceptionHandler.h ExceptionHandler/ExceptionHandler.cpp)

