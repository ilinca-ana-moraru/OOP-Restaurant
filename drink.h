#ifndef DRINK_H
#define DRINK_H
#include <string>
#include <memory>
#include "IOstream.h"
#include "product.h"



class Drink: public Product {

private:
    int ml;
    int status_fizziness;

public:
    Drink() {}

    Drink(std::string product_name_, int price_, int ml_, bool status_fizziness_):
            Product(product_name_,price_), ml(ml_), status_fizziness(status_fizziness_) {}

    void setMl(int ml_);

    void setStatusFizziness(bool status_fizziness_);

    int getMl() const;

    bool getStatusFizziness() const;

    Drink &operator=(Drink const &rhs);

    bool operator>(Drink &rhs);

    void print(std::ostream&) const override;

    float pricePerQuantity() override;

    std::shared_ptr<Product> clone() const override;
};

#endif
