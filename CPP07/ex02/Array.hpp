#pragma once
#include <stdexcept>
#include <stdexcept>
#include <cstdlib>
#include <ctime> 
#include <iostream>

template<typename T>
class Array {
private:
    T* elements;
    unsigned int n;
public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();
    T &operator[](unsigned int index);
    unsigned int size() const;
};

#include "array.tpp"