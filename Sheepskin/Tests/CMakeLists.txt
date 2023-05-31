cmake_minimum_required(VERSION 3.24)
project(Tests)

set(CMAKE_CXX_STANDARD 23)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(Tests ExampleTests.cpp StrategyTests.cpp CSVTests.cpp FirstStrategyTest.cpp StockTest.cpp CryptoCurrencyTest.cpp ETFTest.cpp InstrumentTests.cpp)

include_directories(../Library)
target_link_libraries(Tests Library)
target_link_libraries(Tests gtest gtest_main)
