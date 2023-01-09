#include <iostream>
#include "drink.h"
#include "product.h"

void Drink::setMl(int ml_) {
    ml = ml_;
}

void Drink::setStatusFizziness(bool status_fizziness_) {
    status_fizziness = status_fizziness_;
}

int Drink::getMl() const {
    return ml;
}

bool Drink::getStatusFizziness() const {
    return status_fizziness;
}


Drink& Drink::operator=(const Drink &rhs) {
    this->Product::operator=(rhs);
    ml = rhs.ml;
    status_fizziness = rhs.status_fizziness;

    return *this;
}

bool Drink::operator>(Drink &rhs) {
    if(ml > rhs.ml)
        return true;
    return false;
}

void Drink::print(std::ostream &os) const{
    std::cout<<"ID: "<<get_id()<<
    " | Product name: "<<getProductName()<<
             " | Price: "<<getPrice()<<" lei | Quantity: "<<getMl()<<" mililiters | ";
    getStatusFizziness() ? std::cout<<"fizzy." : std::cout<<"not fizzy.";
    std::cout<<std::endl;

}

float Drink::pricePerQuantity() {
    return getPrice()*1000.0/ml ;
}

std::shared_ptr<Product> Drink::clone() const {
    std::shared_ptr<Product> p = std::make_shared<Drink>(getProductName(),getPrice(),getMl(),getStatusFizziness() );
    p->set_id();
    return p;
}


