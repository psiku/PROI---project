//
// Created by barte on 31.05.2023.
//

#ifndef SHEEPSKIN_NOTENOUGHDATAEXCEPTION_H
#define SHEEPSKIN_NOTENOUGHDATAEXCEPTION_H


#include <exception>

class NotEnoughDataException: public std::exception {
public:
    const char* what() const throw() {
        return "Not enough data provided to calculate strategy result";
    }
};


#endif //SHEEPSKIN_NOTENOUGHDATAEXCEPTION_H
