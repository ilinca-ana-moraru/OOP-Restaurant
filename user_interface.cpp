#include <iostream>
#include "user_interface.h"
#include "menu.h"
#include "drink.h"
#include "dish.h"
#include "exceptions.h"
#include "maximum_template.h"
#include "facade.h"


void UserInterface::UIStarting() {
    UserInterface* interface = UserInterface::getInterface();
    int action;
    do{
        showOptions();
        std::cin>>action;
        userOptions(action);
    }while(action != 0);
}

void UserInterface::showOptions() {
    std::cout<<"-------------------------------------------------"<< std::endl;
    std::cout << "Type a number for the action you want to make!" << std::endl;
    std::cout << "1 -> add to the menu || 2 -> show the menu || 3 -> show all drinks || 4 -> show all dishes "
              <<"|| 5 -> show price per quantity || 6-> find product by name ||"
                "7 -> find the biggest drink or the biggest dish (quantity) ||"
                " 8 -> duplicate a product || 9 -> show the menu to a customer || 0 -> exit " << std::endl;
}


void UserInterface::userOptions(int action) {
    int size_of_menu = Menu::menuSize(Menu::getProducts());
    std::shared_ptr<Dish> dish_;
    std::shared_ptr<Drink> drink_;
    try {
        switch (action) {
            case 1: {
                int product_type, nr_of_products_to_add;
                std::cout << "Type how many products you want to add to the menu!" << std::endl;
                std::cin >> nr_of_products_to_add;

                for (int i = 0; i < nr_of_products_to_add; i++) {
                    std::cout << "type 1 for adding a drink or 2 for adding a dish!" << std::endl;
                    std::cin >> product_type;
                    if (product_type == 1) {
                        std::cout << "type a product name, price, mililiters and 1 if fizzy, 0 if not fizzy"
                                  << std::endl;
                        std::string product_name_;
                        int price_;
                        int ml_;
                        int status_fizziness_;
                        std::cin >> product_name_ >> price_ >> ml_ >> status_fizziness_;

                        if(product_name_.size() < 3 * sizeof(char))
                            throw InvalidInput();
                        if (price_ <= 0)
                            throw InvalidInput();
                        if (ml_ <= 0)
                            throw InvalidInput();
                        if (status_fizziness_ != 0 && status_fizziness_ != 1)
                            throw InvalidInput();

                        drink_ = std::make_shared<Drink>(product_name_, price_, ml_, status_fizziness_);
                        drink_->set_id();
                        Menu::addProduct(drink_);
                    }

                    else if (product_type == 2) {
                        std::cout << "type a product name, price, grams and cooking time"
                                  << std::endl;
                        std::string product_name_;
                        int price_;
                        int weight_;
                        int cooking_time_;
                        std::cin >> product_name_ >> price_ >> weight_ >> cooking_time_;

                        if(product_name_.size() < 3 * sizeof(char))
                            throw InvalidInput();
                        if (price_ <= 0)
                            throw InvalidInput();
                        if (weight_ <= 0)
                            throw InvalidInput();
                        if (cooking_time_ <= 0)
                            throw InvalidInput();

                        dish_ = std::make_shared<Dish>(product_name_, price_, weight_, cooking_time_);
                        dish_->set_id();
                        Menu::addProduct(dish_);

                    } else
                        throw InvalidInput();
                }
                break;
            }

            case 2: {
                std::cout << "THIS IS OUR MENU :" << std::endl;
                for (int i = 0; i < size_of_menu; i++) {
                    if (typeid(*(Menu::getProduct(i))) == typeid(Drink)) {
                        drink_ = std::dynamic_pointer_cast<Drink>(Menu::getProduct(i));
                        std::cout << *drink_;

                    } else {
                        dish_ = std::dynamic_pointer_cast<Dish>(Menu::getProduct(i));
                        std::cout << *dish_;

                    }
                }

                break;
            }

            case 3: {
                std::cout << "THIS IS OUR DRINK SELECTION :" << std::endl;
                for(auto &prod : Menu::findAllDrinks()){
                   std::cout<<*prod;
                }
                break;
            }

            case 4: {
                std::cout << "THIS IS OUR FOOD SELECTION :" << std::endl;
                for (int i = 0; i < size_of_menu; i++)
                    if (typeid(*(Menu::getProduct(i))) == typeid(Dish)) {
                        dish_ = std::dynamic_pointer_cast<Dish>(Menu::getProduct(i));
                        std::cout << *dish_;

                    }
                break;
            }

            case 5: {
                for (int i = 0; i < size_of_menu; i++) {
                    std::cout << Menu::getProduct(i)->getProductName() << " ";
                    std::cout<<Menu::getProduct(i)->pricePerQuantity()<<" ";
                    if (typeid(*(Menu::getProduct(i))) == typeid(Dish))
                        std::cout << "lei/kilogram" << std::endl;
                    else
                        std::cout << "lei/liter" << std::endl;

                }

                break;
            }

            case 6:{
                std::cout<<"type the product you want to find"<<std::endl;
                std::string name;
                std::cin>>name;
                std::shared_ptr<Product> p = Menu::findProductByName(name);
                if(typeid(*p) == typeid(Drink))
                    //std::shared_ptr<drink> dr = std::dynamic_pointer_cast<drink>(p);
                    std::cout<<(std::dynamic_pointer_cast<Drink>(p));
                else
                    std::cout<<(std::dynamic_pointer_cast<Dish>(p));

                break;
            }

            case 7:{
                std::cout<<"Type 1 if you want to find the biggest drink or 2 if you want to find the biggest dish"<<std::endl;
                int type;
                std::cin>>type;
                if(type == 1){
                    Maximum <Drink> m_drink((Menu::findAllDrinks()));
                    std::cout<<m_drink.FindMax();
                }

                else if(type == 2){
                    Maximum <Dish> m_dish(Menu::findAllDishes());
                    std::cout<<m_dish.FindMax();
                }
                break;
            }

            case 8:{
                std::cout<<"Type the name of the product you want to duplicate"<<std::endl;
                std::string str;
                std::cin>>str;
                std::shared_ptr<Product> aux = Menu::findProductByName(str);
                    Menu::addProduct(aux->clone());
                    break;

            }

            case 9:{
                facade::show_menu();
                break;

            }
            case 0: {
                std::cout<<"exiting ..."<<std::endl;
                break;
            }

            default:
                throw InvalidAction();
                break;
        }
    }
    catch(const InvalidInput &exception){
        std::cout << exception.what()<< std::endl;
    }

}

UserInterface* UserInterface::getInterface() {
    if(interface_ptr== nullptr)
    interface_ptr = new UserInterface;

    return interface_ptr;

}