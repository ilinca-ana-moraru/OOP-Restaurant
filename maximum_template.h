#ifndef TEMA3_MAXIM_TEMPLATE_H
#define TEMA3_MAXIM_TEMPLATE_H

#include <vector>
#include "drink.h"
#include "dish.h"

template <typename t> class Maximum{
private:
    std::vector<t> v;
public:
    Maximum(std::vector<t> v_):v(v_){}
    t FindMax(){
        typename std::vector<t>::iterator i;
        t max = v[0];
        for(i = v.begin() + 1;i!=v.end();i++)
            if(*(i) > max)
                max = *i;
        return max;
    }
};

template <> class Maximum <Drink>{
private:
    std::vector<std::shared_ptr<Drink>> v;
public:
    Maximum(std::vector<std::shared_ptr<Drink>> v_):v(v_){}
    Drink FindMax(){
        Drink max = *v[0];
        for(auto &i :v)
            if(*(i) > max)
                max = *i;
        return max;
    }
};

template <> class Maximum <Dish>{
private:
    std::vector<std::shared_ptr<Dish>> v;
public:
    Maximum(std::vector<std::shared_ptr<Dish>> v_):v(v_){}
    Dish FindMax(){
        Dish max = *v[0];
        for(auto &i :v)
            if(*(i) > max)
                max = *i;
        return max;
    }
};

#endif
