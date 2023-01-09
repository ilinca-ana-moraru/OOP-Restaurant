#include "product.h"
#include "drink.h"
#include "dish.h"
#include "menu.h"
#include <memory>
#include <vector>
#include <iostream>

std::vector<std::shared_ptr<Product>> Menu::products;

void Menu::addProduct(std::shared_ptr<Product> product_) {
    products.push_back(product_);
}

int Menu::menuSize(std::vector<std::shared_ptr<Product>> products) {
    return products.size();
}


std::vector<std::shared_ptr<Product>> &Menu::getProducts() {
    return products;
}

std::shared_ptr<Product> Menu::getProduct( int poz){
    return products[poz];
}

std::shared_ptr<Product> Menu::findProductByName(std::string name) {
    for(auto &prod : Menu::products){
        if(prod->getProductName() == name)
            return prod;
    }
    return nullptr;
}

std::vector<std::shared_ptr<Drink>> Menu::findAllDrinks() {
    std::vector<std::shared_ptr<Drink>> drinks;
    for(auto &prod : Menu::products){
        if(typeid(*prod) == typeid(Drink))
            drinks.push_back(std::dynamic_pointer_cast<Drink>(prod));
    }
    return drinks;
}

std::vector<std::shared_ptr<Dish>> Menu::findAllDishes() {
    std::vector<std::shared_ptr<Dish>> dishes;
    for(auto &prod : Menu::products){
        if(typeid(*prod) == typeid(Dish))
            dishes.push_back(std::dynamic_pointer_cast<Dish>(prod));
    }
    return dishes;
}