#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <cstdlib>
#include <iostream>
#include "stl/list.hpp"

template <class T>
class Vector : public List<T> {
private:
    T *items;
    uint64_t length;
    uint64_t max;
public:
    Vector() {
        this->max = 10;
        this->items = (T *)malloc(this->max * sizeof(T *));
    }

    Vector(uint64_t max) {
        this->max = max;
        this->items = (T *)malloc(this->max * sizeof(T *));
    }

    void add(const T& item) override {
        // todo
        if (this->length == this->max) {
            this->max = this->max * 2;
            this->items = (T *)realloc(this->items, this->max * sizeof(T *)); 
        }
        *(this->items + this->length) = item;
        this->length++;
    }

    void clear() override {
        this->length = 0;
        this->max = 10;
        free(items);
    }

    Vector<T>& clone() const {
        // @todo
        Vector<T> *tmp = new Vector<T>();
        for (uint64_t i = 0; i < this->length; i++)
            tmp->add(this->get(i));
        return *tmp;
    }

    bool contains(const T& item) const override {
        // @todo
        for (uint64_t i = 0; i < this->length; i++)
            if (this->get(i) == item)
                return true;
        return false;
    }

    T get(uint64_t index) const override {
        // @todo
        return *(this->items + index);
    }

    bool isEmpty() const override {
        // @todo
        return this->length == 0;
    }

    int64_t indexOf(const T& item) const override {
        // @todo
        for (uint64_t i = 0; i < this->length; i++)
            if (this->get(i) == item)
                return i;
        return -1;
    }

    int64_t lastIndexOf(const T& item) const override {
        // @todo
        for (int64_t i = this->length - 1; i > -1 ; i--)
            if (this->get(i) == item)
                return i;
        return -1;
    }

    void remove(const T& item) override {
        // @todo
    }

    uint64_t size() const override {
        // @todo
        return this->length;
    }

    T *toArray() const override {
        // @todo
        T *tmp = (T *)malloc(this->length * sizeof(T *));

        for (uint64_t i = 0; i < this->length; i++)
            *(tmp + i) = *(this->items + i);

        return tmp;
    }

    ~Vector() {
        free(items);
    }
};

#endif
