//
// Created by barte on 31.05.2023.
//

#ifndef SHEEPSKIN_INVALIDDATAEXCEPTION_H
#define SHEEPSKIN_INVALIDDATAEXCEPTION_H

#include <exception>

class InvalidDataException: public std::exception {
public:
    const char* what() const throw() {
        return "Data provided in file are invalid";
    }
};

#endif //SHEEPSKIN_INVALIDDATAEXCEPTION_H
