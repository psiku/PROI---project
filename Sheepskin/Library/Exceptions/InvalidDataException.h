//
// Created by barte on 31.05.2023.
//

#ifndef SHEEPSKIN_INVALIDDATAEXCEPTION_H
#define SHEEPSKIN_INVALIDDATAEXCEPTION_H

#include <exception>

// Class InvalidDataException is an exception which is thrown when data provided in file are invalid
// it is derived from std::exception
class InvalidDataException: public std::exception {
public:
    const char* what() const throw() {
        return "Data provided in file are invalid";
    }
};

#endif //SHEEPSKIN_INVALIDDATAEXCEPTION_H
