#ifndef MENU_H
#define MENU_H
#include "product.h"
#include "drink.h"
#include "dish.h"
#include <vector>
#include <memory>

class Menu: public Product{
private:
    static std::vector<std::shared_ptr<Product>> products;


public:
    Menu() = delete;

    static void addProduct(std::shared_ptr<Product> product_);

    static int menuSize(std::vector<std::shared_ptr<Product>> products);

    static std::vector<std::shared_ptr<Product>> &getProducts();

    static std::shared_ptr<Product> getProduct( int poz);

    static std::shared_ptr<Product> findProductByName(std::string);

    static std::vector<std::shared_ptr<Drink>> findAllDrinks();

    static std::vector<std::shared_ptr<Dish>> findAllDishes();



};
#endif
