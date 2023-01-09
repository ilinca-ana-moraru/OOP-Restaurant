#include "facade.h"
#include <iostream>
#include "menu.h"

void facade::show_menu() {
    std::cout << "THIS IS OUR DRINK SELECTION :" << std::endl;
    for(auto &prod : Menu::findAllDrinks())
        std::cout<<*prod;

    std::cout << "THIS IS OUR DISH SELECTION :" << std::endl;
    for(auto &prod : Menu::findAllDishes())
        std::cout<<*prod;
}