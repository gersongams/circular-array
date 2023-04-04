#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> {
    void enqueue(T data) {
        this->push_back(data);
    }

    T dequeue() {
        return this->pop_front();
    }

    T front() {
        return (*this)[0];
    }

    T back() {
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