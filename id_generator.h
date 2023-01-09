#ifndef TEMA3_ID_GENERATOR_H
#define TEMA3_ID_GENERATOR_H

class IdGenerator{
private:
    static int id_counter;
public:
    static const int get_id();
    static void set_id();
};

#endif
