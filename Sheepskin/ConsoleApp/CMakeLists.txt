cmake_minimum_required(VERSION 3.25)
project(ConsoleApp)

set(CMAKE_CXX_STANDARD 23)

add_executable(ConsoleApp main.cpp Data/CSVReader/CSVReader/CSVReader.h  Data/CSVReader/CSVReader/CSVReader.cpp Data/CSVWriter/CSVWriter.cpp Data/CSVWriter/CSVWriter.h Data/CSVReader/CSVResult/CSVResult.h Data/CSVReader/CSVResult/CSVResult.cpp Data/CSVReader/Mapper/Mapper.h Data/CSVReader/Mapper/Mapper.cpp)

include_directories(../Library)
target_link_libraries(ConsoleApp Library)

