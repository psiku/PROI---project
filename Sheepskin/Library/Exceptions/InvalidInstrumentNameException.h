//
// Created by barte on 31.05.2023.
//

#ifndef SHEEPSKIN_INVALIDINSTRUMENTNAMEEXCEPTION_H
#define SHEEPSKIN_INVALIDINSTRUMENTNAMEEXCEPTION_H

#include <exception>

class InvalidInstrumentNameException: public std::exception {
public:
    const char* what() const throw() {
        return "Invalid instrument name provided";
    }
};

#endif //SHEEPSKIN_INVALIDINSTRUMENTNAMEEXCEPTION_H
