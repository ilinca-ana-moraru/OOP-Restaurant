#include <string>
#include "product.h"
#include "id_generator.h"

Product::Product () {}
Product::Product(std::string product_name_,int price_): price(price_), product_name(product_name_){ }

void Product::setPrice(int price_){
    price = price_;
}

void Product::setProductName(std::string product_name_) {
    product_name = product_name_;
}

int Product::getPrice() const{
    return price;
}

std::string Product::getProductName() const {
    return product_name;
}

Product& Product::operator=(const Product &rhs){
    setProductName(rhs.product_name);
    setPrice(rhs.price);

    return *this;
}

void Product::set_id() {
    id = IdGenerator::get_id();
}

int Product::get_id() const{
    return id;
}

