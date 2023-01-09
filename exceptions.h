#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>
#include <exception>

class InvalidInput : public std::exception{
public:
    const char* what() const noexcept override;
    InvalidInput() = default;

};

class InvalidAction : public std::exception{
public:
    const char * what() const noexcept override;
    InvalidAction() = default;
};


#endif
