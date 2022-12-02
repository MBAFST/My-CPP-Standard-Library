#ifndef __LIST_HPP__
#define __LIST_HPP__

template <class T>
class List {
protected:
    T *items;
    uint64_t length;
    uint64_t max;
public:
    List() {
        this->max = 10;
        this->items = (T *)malloc(this->max * sizeof(T *));
    }

    List(uint64_t max) {
        this->max = max;
        this->items = (T *)malloc(this->max * sizeof(T *));
    }

    virtual void add(const T& item) = 0;
    // virtual void add(uint64_t index, T item) = 0;
    // virtual void addAll(List list);
    // virtual void addAll(uint64_t index, Vector vector);
    
    void clear() {
        this->length = 0;
        this->max = 10;
        free(items);
    }

    // virtual List clone() = 0;
    bool contains(const T& item) const {
        for (uint64_t i = 0; i < this->length; i++)
            if (this->get(i) == item)
                return true;
        return false;
    }

    T get(uint64_t index) const {
        return *(this->items + index);
    }

    bool isEmpty() const {
        return this->length == 0;
    }

    int64_t indexOf(const T& item) const {
        for (uint64_t i = 0; i < this->length; i++)
            if (this->get(i) == item)
                return i;
        return -1;
    }

    int64_t lastIndexOf(const T& item) const {
        for (int64_t i = this->length - 1; i > -1 ; i--)
            if (this->get(i) == item)
                return i;
        return -1;
    }

    virtual void remove(const T& item) = 0;
    
    uint64_t size() const {
        return this->length;
    }

    uint64_t reserved() const {
        return this->max;
    }

    T *toArray() const {
        T *tmp = (T *)malloc(this->length * sizeof(T *));

        for (uint64_t i = 0; i < this->length; i++)
            *(tmp + i) = *(this->items + i);

        return tmp;
    }
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
