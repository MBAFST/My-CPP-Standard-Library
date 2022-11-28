#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <cstdlib>
#include <iostream>

template <class T>
class Vector {
private:
    T *items;
    u_int64_t length;
    u_int64_t size;
public:
    Vector() {
        items = (T *)malloc(2 * sizeof(T *));
    }

    Vector(usize size) {
        items = (T *)malloc(size * sizeof(T *));
    }

    void add(T item);
    void add(uint64_t index, T item);
    void addAll(Vector vector);
    void addAll(uint64_t index, Vector vector);
    void clear();
    Vector& clone();
    bool contains(T item);
    T& get(uint64_t index);
    uint64_t indexOf(T item);
    bool isEmpty();
    uint64_t lastIndexOf(T item);
    void remove(T item);
    void removeAll(Vector vector);
    void removeRange(int fromIndex, int toIndex);
    void set(uint64_t index, T item);
    uint64_t size();
    Vector subList(int fromIndex, int toIndex);
    T* toArray();
    static T* toArray(T* items);
    T get(uint64_t index);

    ~Vector() {
        free(items);
    }
};

#endif
