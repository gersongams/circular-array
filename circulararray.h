#include <iostream>

using namespace std;

template<class T>
class CircularArray {
private:
    T *array;
    int capacity;
    int back, front;

public:
    CircularArray(int _capacity = 10);

    virtual ~CircularArray();

    void push_front(T data);

    void push_back(T data);

    void insert(T data, int pos);

    T pop_front();

    T pop_back();

    bool is_full();

    bool is_empty();

    int size();

    void clear();

    T &operator[](int);

    void sort();

    bool is_sorted();

    void reverse();

    string to_string(const string &sep = " ");

private:
    int next(int);

    int prev(int);
};

template<class T>
CircularArray<T>::CircularArray(int _capacity) {
    this->capacity = _capacity;
    this->array = new T[_capacity];
    this->front = this->back = -1;//empty
}

template<class T>
CircularArray<T>::~CircularArray() {
    delete[] this->array;
}

template<class T>
void CircularArray<T>::push_front(T data) {
    if (this->is_full()) {
        throw "The array is full";
    } else if (this->is_empty()) {
        this->front = this->back = 0;
        this->array[this->front] = data;
    } else {
        this->front = this->prev(this->front);
        this->array[this->front] = data;
    }
}

template<class T>
void CircularArray<T>::push_back(T data) {
    if (this->is_full()) {
        throw "The array is full";
    } else if (this->is_empty()) {
        this->front = this->back = 0;
        this->array[this->back] = data;
    } else {
        this->back = this->next(this->back);
        this->array[this->back] = data;
    }
}

template<class T>
void CircularArray<T>::insert(T data, int pos) {
    if (pos < 0 || pos >= this->size()) {
        throw "The position is out of range";
    } else if (this->is_full()) {
        throw "The array is full";
    } else if (this->is_empty()) {
        this->front = this->back = 0;
        this->array[this->front] = data;
    } else {
        int index = this->front;
        for (int i = 0; i < pos; ++i) {
            index = this->next(index);
        }
        if (index == this->front) {
            this->push_front(data);
        } else if (index == this->back) {
            this->push_back(data);
        } else {
            int i = this->back;
            while (i != index) {
                this->array[this->next(i)] = this->array[i];
                i = this->prev(i);
            }
            this->array[index] = data;
            this->back = this->next(this->back);
        }
    }
}

template<class T>
T CircularArray<T>::pop_front() {
    if (this->is_empty()) {
        throw "The array is empty";
    } else {
        T data = this->array[this->front];
        if (this->front == this->back) {
            this->front = this->back = -1;
        } else {
            this->front = this->next(this->front);
        }
        return data;
    }
}

template<class T>
T CircularArray<T>::pop_back() {
    if (this->is_empty()) {
        throw "The array is empty";
    } else {
        T data = this->array[this->back];
        if (this->front == this->back) {
            this->front = this->back = -1;
        } else {
            this->back = this->prev(this->back);
        }
        return data;
    }
}

template<class T>
bool CircularArray<T>::is_full() {
    return this->next(this->back) == this->front;
}

template<class T>
bool CircularArray<T>::is_empty() {
    return this->front == -1;
}

template<class T>
int CircularArray<T>::size() {
    if (this->is_empty()) {
        return 0;
    } else if (this->front <= this->back) {
        return this->back - this->front + 1;
    } else {
        return this->capacity - (this->front - this->back - 1);
    }
}

template<class T>
void CircularArray<T>::clear() {
    this->front = this->back = -1;
}

template<class T>
T &CircularArray<T>::operator[](int index) {
    if (index < 0 || index >= this->size()) {
        throw "The index is out of range";
    } else {
        int i = this->front;
        for (int j = 0; j < index; ++j) {
            i = this->next(i);
        }
        return this->array[i];
    }
}

template<class T>
void CircularArray<T>::sort() {
    if (this->is_empty()) {
        throw "The array is empty";
    } else {
        int i = this->front;
        while (i != this->back) {
            int j = this->next(i);
            while (j != this->next(this->back)) {
                if (this->array[i] > this->array[j]) {
                    T temp = this->array[i];
                    this->array[i] = this->array[j];
                    this->array[j] = temp;
                }
                j = this->next(j);
            }
            i = this->next(i);
        }
    }
}

template<class T>
bool CircularArray<T>::is_sorted() {
    if (this->is_empty()) {
        throw "The array is empty";
    } else {
        for (int i = 0; i < this->size() - 1; ++i) {
            if (this->array[i] > this->array[i + 1]) {
                return false;
            }
        }
        return true;
    }
}

template<class T>
void CircularArray<T>::reverse() {
    if (this->is_empty()) {
        throw "The array is empty";
    } else {
        int left = this->front;
        int right = this->back;

        int count = 0;
        int total_elements = this->size();
        while (count < total_elements / 2) {
            T temp = this->array[left];
            this->array[left] = this->array[right];
            this->array[right] = temp;

            left = this->next(left);
            right = this->prev(right);

            count++;
        }
    }
}

template<class T>
string CircularArray<T>::to_string(const string &separator) {
    if (this->is_empty()) {
        return "";
    } else {
        string str = "";
        int i = this->front;
        while (i != this->back) {
            str += std::to_string(this->array[i]) + " ";
            i = this->next(i);
        }
        str += std::to_string(this->array[i]) + " ";
        return str;
    }
}

template<class T>
int CircularArray<T>::next(int index) {
    return (index + 1) % this->capacity;
}

template<class T>
int CircularArray<T>::prev(int index) {
    return (index - 1 + this->capacity) % this->capacity;
}