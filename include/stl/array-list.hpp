#ifndef __ARRAYLIST_HPP__
#define __ARRAYLIST_HPP__

#include <cstdlib>
#include <iostream>
#include "stl/list.hpp"

template <class T>
class ArrayList : public List<T> {
public:
    ArrayList() : List<T>() { };
    ArrayList(uint64_t max) : List<T>(max) { };

    void add(const T& item) override {
        if (this->length == this->max) {
            this->max = static_cast<int>(this->max * 1.5);
            this->items = (T *)realloc(this->items, this->max * sizeof(T *)); 
        }
        *(this->items + this->length) = item;
        this->length++;
    }

    ArrayList<T>& clone() const {
        // @todo
        ArrayList<T> *tmp = new ArrayList<T>();
        for (uint64_t i = 0; i < this->length; i++)
            tmp->add(this->get(i));
        return *tmp;
    }

    void remove(const T& item) override {
        // @todo
    }

    ~ArrayList() {
        free(this->items);
    }
};

#endif
