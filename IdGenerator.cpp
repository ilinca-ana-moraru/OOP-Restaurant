#include "id_generator.h"


const int IdGenerator::get_id() {
    set_id();
    return id_counter;
}

void IdGenerator::set_id() {
    id_counter++;
}