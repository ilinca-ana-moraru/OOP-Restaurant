#ifndef PROJECT_STREAM_H
#define PROJECT_STREAM_H

#include <ostream>

class Iostream {
protected:
    virtual void print(std::ostream &) const = 0;

    friend std::ostream& operator<<(std::ostream &, const Iostream&);
    friend std::ostream& operator<<(std::ostream &, const Iostream*);

    virtual ~Iostream();
};

#endif
