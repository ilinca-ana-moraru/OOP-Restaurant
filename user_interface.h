#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <vector>
#include <memory>
#include "product.h"
#include "drink.h"
#include "dish.h"

class UserInterface{
private:
    static UserInterface* interface_ptr;

    UserInterface() = default;

public:

    static UserInterface* getInterface();

    ~UserInterface() = default;

    static void UIStarting();

    static void showOptions();

    static void userOptions(int);




};

#endif
