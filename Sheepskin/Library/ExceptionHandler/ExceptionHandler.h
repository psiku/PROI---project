//
// Created by barte on 01.06.2023.
//

#ifndef SHEEPSKIN_EXCEPTIONHANDLER_H
#define SHEEPSKIN_EXCEPTIONHANDLER_H

#include <iostream>
#include "../Exceptions/InvalidDataException.h"
#include "../Exceptions/InvalidFormatException.h"
#include "../Exceptions/InvalidInstrumentNameException.h"
#include "../Exceptions/NotEnoughDataException.h"


class ExceptionHandler {
public:
    static void handle(const class std::exception &exception);
};


#endif //SHEEPSKIN_EXCEPTIONHANDLER_H
