//
// Created by barte on 01.06.2023.
//

#include "ExceptionHandler.h"

void ExceptionHandler::handle(const std::exception &exception) {
    try {
        throw; // Re-throw the exception to catch it with the derived types
    } catch (const InvalidDataException& e) {
        std::cout << "Provided data is incorrect: " << e.what() << std::endl;
    } catch (const InvalidInstrumentNameException& e) {
        std::cout << "There is no instrument with this id: " << e.what() << std::endl;
    } catch (const InvalidFormatException& e) {
        std::cout << "Wrong format of the csv file" << e.what() << std::endl;
    } catch (const NotEnoughDataException& e) {
        std::cout << "Not enough information about instrument records: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Handling unknown exception" << std::endl;
    }
}

