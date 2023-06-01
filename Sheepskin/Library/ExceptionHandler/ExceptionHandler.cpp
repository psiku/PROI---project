//
// Created by barte on 01.06.2023.
//

#include "ExceptionHandler.h"
#include "../Exceptions/InvalidArgumentsException.h"

void ExceptionHandler::handle(const std::exception &exception) {
    try {
        throw; // Re-throw the exception to catch it with the derived types
    } catch (const InvalidArgumentsException& e) {
        std::cerr << "Handling Exception: " << e.what() << std::endl;
    } catch (const InvalidDataException& e) {
        std::cerr << "Handling Exception: " << e.what() << std::endl;
    } catch (const InvalidInstrumentNameException& e) {
        std::cerr << "Handling Exception: " << e.what() << std::endl;
    } catch (const InvalidFormatException& e) {
        std::cerr << "Handling Exception: " << e.what() << std::endl;
    } catch (const NotEnoughDataException& e) {
        std::cerr << "Handling Exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Handling unknown exception: " << exception.what() << std::endl;
    }
}

