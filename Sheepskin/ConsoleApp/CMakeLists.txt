cmake_minimum_required(VERSION 3.25)
project(ConsoleApp)

set(CMAKE_CXX_STANDARD 23)

add_executable(ConsoleApp main.cpp)


include_directories(../Library)
target_link_libraries(ConsoleApp Library)

