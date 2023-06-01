//
// Created by barte on 31.05.2023.
//

#ifndef SHEEPSKIN_INVALIDFORMATEXCEPTION_H
#define SHEEPSKIN_INVALIDFORMATEXCEPTION_H

#include <exception>

// Class InvalidFormatException is an exception which is thrown when format of the csv file is invalid
// it is derived from std::exception
class InvalidFormatException: public std::exception {
public:
    const char* what() const throw() {
        return "Wrong format of the csv file";
    }
};

#endif //SHEEPSKIN_INVALIDFORMATEXCEPTION_H
