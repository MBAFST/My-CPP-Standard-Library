#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <cstdlib>
#include <iostream>
#include "stl/list.hpp"

template <class T>
class Vector : public List<T> {
public:
    Vector() : List<T>() { }
    Vector(uint64_t max) : List<T>(max) { }

    void add(const T& item) override {
        if (this->length == this->max) {
            this->max = this->max * 2;
            this->items = (T *)realloc(this->items, this->max * sizeof(T *)); 
        }
        *(this->items + this->length) = item;
        this->length++;
    }

    Vector<T>& clone() const {
        // @todo
        Vector<T> *tmp = new Vector<T>();
        for (uint64_t i = 0; i < this->length; i++)
            tmp->add(this->get(i));
        return *tmp;
    }

    void remove(const T& item) override {
        // @todo
    }

    ~Vector() {
        free(this->items);
    }
};

#endif
