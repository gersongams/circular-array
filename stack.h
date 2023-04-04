#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T> {
    void push(T data) {
        this->push_back(data);
    }

    T pop() {
        return this->pop_back();
    }

    T top() {
        return (*this)[this->size() - 1];
    }

    bool is_empty() {
        return this->is_empty();
    }

    int size() {
        return this->size();
    }

    string to_string() {
        return this->to_string();
    }

    void clear() {
        this->clear();
    }

    bool is_sorted() {
        return this->is_sorted();
    }

    void sort() {
        this->sort();
    }

    void reverse() {
        this->reverse();
    }

    T &operator[](int index) {
        return (*this)[index];
    }

    int next(int index) {
        return this->next(index);
    }

    int prev(int index) {
        return this->prev(index);
    }
};