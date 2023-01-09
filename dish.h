#ifndef DISH_H
#define DISH_H

#include <memory>
#include "product.h"

class Dish: public Product{

private:
    int weight;
    int cooking_time;

public:
    Dish()=default;

    Dish(std::string product_name_, int price_, int weight_, int cooking_time_):
            Product(product_name_, price_), weight(weight_), cooking_time(cooking_time_) {}

    void setWeight(int weight_);

    void setCookingTime(int cooking_time_);

    int getWeight() const;

    int getCookingTime() const;

    Dish& operator=(const Dish &rhs);

    bool operator>(Dish &rhs);

    void print(std::ostream&) const override;

    float pricePerQuantity() override;

    std::shared_ptr<Product> clone() const override;

};
#endif
