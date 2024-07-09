#pragma once
#include<iostream>
using namespace std; 

template <typename T>
class Iterator;
template <typename T>
class Iterator2;

template <typename T>

class Deque {
private:
    T* arr = new T[capacity];
    int capacity;
    int size;
    int frontIndex;
    int backIndex;
public:
    friend class Iterator<T>;
    friend class Iterator2<T>;

    Iterator2<T>* CreateIterator() const;

    Deque(int capacity) {
        this->capacity = capacity;
        arr = new T[capacity + 1];
        size = 0;
        frontIndex = 0;
        backIndex = 0;
    }

    Deque(const Deque<T>& other) {
        capacity = other.capacity;
        size = other.size;
        frontIndex = other.frontIndex;
        backIndex = other.backIndex;

        arr = new T[capacity];
        for (int i = 0; i < capacity; ++i) {
            arr[i] = other.arr[i];
        }
    }

    ~Deque() {
        if (this->arr != NULL) {
            delete[] arr;
        }
    }

    Deque& operator=(const Deque<T>& other) {
        if (this != &other) {
            delete[] arr;
            capacity = other.capacity;
            size = other.size;
            frontIndex = other.frontIndex;
            backIndex = other.backIndex;
            arr = new T[capacity];
            for (int i = 0; i < capacity; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    int Size() const {
        return size;
    }

    void Clear() {
        delete[] arr;
        size = 0;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    bool IsFull() const {
        return size == capacity;
    }

    int Front() const {
        return arr[frontIndex - 1];
    }

    int Back() const {
        return arr[backIndex - 1];
    }

    void PushFront(T value) {
        if (IsFull()) {
            cout << "Deque is full, cannot push front." << endl;
            return;
        }
        for (int i = capacity - 1; i >= 0; i--) {
            arr[i + 1] = arr[i];
        }
        arr[0] = value;
        frontIndex++;
        size++;
    }

    void PushBack(T value) {
        if (IsFull()) {
            cout << "Deque is full, cannot push back." << endl;
            return;
        }
        
        arr[backIndex] = value;
        backIndex++;
        size++;
    }

    void PopFront() {
        if (IsEmpty()) {
            cout << "Deque is empty, cannot pop front." << endl;
            return;
        }
        for (int i = 0; i < capacity - 1; i++) {
            arr[i] = arr[i + 1];
        }
        frontIndex--;
        size--;
    }

    void PopBack() {
        if (IsEmpty()) {
            cout << "Deque is empty, cannot pop back." << endl;
            return;
        }
        if (backIndex == 0) {
            backIndex = capacity - 1;
        }
        else {
            backIndex--;
        }
        size--;
    }

    friend ostream& operator<<(ostream& os, const Deque<T>& deque) {
        os << endl << "Deque: " << endl;
        int schet = 0;
        while (schet < deque.size) {
            os << deque.arr[schet];
            schet++;
        }
        return os;
    }
};

template <typename T>

class Iterator {
private:
    const Deque<T>& deque;
    int currentIndex;

public:
    Iterator(const Deque<T>& d) : deque(d)
    {
        currentIndex = 0;
    }

    bool operator()()
    {
        return currentIndex != deque.size;
    }

    bool operator!=(const Iterator<T>& other)
    {
        return currentIndex != other.currentIndex;
    }

    void operator++()
    {
        currentIndex++;
    }

    T operator*()
    {
        return deque.arr[currentIndex];
    }
};

template<typename T>

class Iterator2 {
private:
    const Deque<T>* deque;
    int index;
public:
    Iterator2(const Deque<T>* s)
    {
        deque = s;
    }

    void first()
    {
        index = 0;
    }

    void next()
    {
        index++;
    }

    bool isDone()
    {
        return index == deque->size;
    }

    T currentItem()
    {
        return deque->arr[index];
    }
};