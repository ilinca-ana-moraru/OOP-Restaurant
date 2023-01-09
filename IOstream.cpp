#include "IOstream.h"

std::ostream& operator<<(std::ostream &os, const Iostream &obj) {
    obj.print(os);
    return os;
}

std::ostream& operator<<(std::ostream &os, const Iostream *obj) {
    obj->print(os);
    return os;
}

Iostream::~Iostream() = default;