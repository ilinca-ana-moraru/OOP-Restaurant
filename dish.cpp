#include <iostream>
#include "product.h"
#include "dish.h"


void Dish::setWeight(int weight_){
    weight = weight_;
}

void Dish::setCookingTime(int cooking_time_) {
    cooking_time = cooking_time_;
}

int Dish::getWeight() const {
    return weight;
}

int Dish::getCookingTime() const {
    return cooking_time;
}

Dish& Dish::operator=(const Dish &rhs){
    this->Product::operator=(rhs);
    weight = rhs.weight;
    cooking_time = rhs.cooking_time;

    return *this;
}

 bool Dish::operator>(Dish &rhs){
    if(weight > rhs.weight)
        return true;
    return false;
}

void Dish::print(std:: ostream&) const{
    std::cout<<"ID: "<<get_id()<<
    " | Product name: "<<getProductName()<<
             " | Price: "<<getPrice()<<" lei | Quantity: "<<getWeight()<<" grams | "
             <<"Cooking time: "<<getCookingTime()<<" minutes.";
    std::cout<<std::endl;
}

float Dish::pricePerQuantity() {
    return getPrice()*1000.0/weight;
}

std::shared_ptr<Product> Dish::clone() const {
    std::shared_ptr<Product> p = std::make_shared<Dish>(getProductName(),getPrice(),getWeight(),getCookingTime() );
    p->set_id();
    return p;
}