#include "exceptions.h"

const char* InvalidInput::what() const noexcept {
    return "Invalid input.";
}

const char* InvalidAction::what() const noexcept{
    return "Invalid action. Please choose from the options offered.";
}


