#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include "IOstream.h"
#include <memory>

class Product: public Iostream{
private:
    std::string product_name;
    int price;
    int id;

public:
    Product () ;

    Product(std::string product_name_,int price_);

    void setPrice(int price_);

    void setProductName(std::string product_name_);

    int getPrice() const;

    std::string getProductName() const;

    Product& operator=(const Product &rhs);

    virtual float pricePerQuantity() = 0;

    virtual ~Product() = default;

    virtual std::shared_ptr<Product> clone() const = 0;

    void set_id();

    int get_id()const;

};



#endif
