//
// Created by barte on 01.06.2023.
//
#include <gtest/gtest.h>
#include <exception>
#include <stdexcept>
#include "ExceptionHandler/ExceptionHandler.h"



TEST(ExceptionHandlerTest, InvalidFormatExceptionTest) {
    ExceptionHandler handler;
    InvalidFormatException ex;

    try {
        throw ex;
    } catch (const std::exception& e) {
        std::stringstream ss;
        ss << "Handling Exception: " << ex.what() << std::endl;
        testing::internal::CaptureStderr();  // Capture output from std::cerr
        handler.handle(e);
        std::string output = testing::internal::GetCapturedStderr();
        EXPECT_EQ(output, ss.str());
    }
}

TEST(ExceptionHandlerTest, NotEnoughDataExceptionTest) {
    ExceptionHandler handler;
    NotEnoughDataException ex;

    try {
        throw ex;
    } catch (const std::exception& e) {
        std::stringstream ss;
        ss << "Handling Exception: " << ex.what() << std::endl;
        testing::internal::CaptureStderr();  // Capture output from std::cerr
        handler.handle(e);
        std::string output = testing::internal::GetCapturedStderr();
        EXPECT_EQ(output, ss.str());
    }
}

TEST(ExceptionHandlerTest, InvalidDataExceptionTest) {
    ExceptionHandler handler;
    InvalidDataException ex;

    try {
        throw ex;
    } catch (const std::exception& e) {
        std::stringstream ss;
        ss << "Handling Exception: " << ex.what() << std::endl;
        testing::internal::CaptureStderr();  // Capture output from std::cerr
        handler.handle(e);
        std::string output = testing::internal::GetCapturedStderr();
        EXPECT_EQ(output, ss.str());
    }
}

TEST(ExceptionHandlerTest, InvalidInstrumentNameExceptionTest) {
    ExceptionHandler handler;
    InvalidInstrumentNameException ex;

    try {
        throw ex;
    } catch (const std::exception& e) {
        std::stringstream ss;
        ss << "Handling Exception: " << ex.what() << std::endl;
        testing::internal::CaptureStderr();  // Capture output from std::cerr
        handler.handle(e);
        std::string output = testing::internal::GetCapturedStderr();
        EXPECT_EQ(output, ss.str());
    }
}

TEST(ExceptionHandlerTest, UnknownExceptionTest) {
    ExceptionHandler handler;
    std::runtime_error ex("Runtime error");

    try {
        throw ex;
    } catch (const std::exception& e) {
        std::stringstream ss;
        ss << "Handling unknown exception: " << ex.what() << std::endl;
        testing::internal::CaptureStderr();  // Capture output from std::cerr
        handler.handle(e);
        std::string output = testing::internal::GetCapturedStderr();
        EXPECT_EQ(output, ss.str());
    }
}