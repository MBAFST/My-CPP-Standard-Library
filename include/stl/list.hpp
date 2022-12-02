#ifndef __LIST_HPP__
#define __LIST_HPP__

template <class T>
class List {
public:
    virtual void add(const T& item) = 0;
    // virtual void add(uint64_t index, T item) = 0;
    // virtual void addAll(List list);
    // virtual void addAll(uint64_t index, Vector vector);
    virtual void clear() = 0;
    // virtual List clone() = 0;
    virtual bool contains(const T& item) const = 0;
    virtual T get(uint64_t index) const = 0;
    virtual bool isEmpty() const = 0;
    virtual int64_t indexOf(const T& item) const = 0;
    virtual int64_t lastIndexOf(const T& item) const = 0;
    virtual void remove(const T& item) = 0;
    virtual uint64_t size() const = 0;
    virtual T *toArray() const = 0;
    // void removeAll(Vector vector);
    // void removeRange(int fromIndex, int toIndex);
    // void set(uint64_t index, T item);
    // Vector subList(int fromIndex, int toIndex);
    virtual ~List() = default;

    static T *toArray(const List<T> &list) {
        // @todo
        return nullptr;
    }
};

#endif
