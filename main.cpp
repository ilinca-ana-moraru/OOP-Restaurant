#include "user_interface.h"
#include "id_generator.h"


UserInterface* UserInterface:: interface_ptr;
int IdGenerator::id_counter = 0;
int main() {

    UserInterface::UIStarting();
    return 0;
}
