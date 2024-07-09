#pragma once
#include <iostream>
using namespace std; 


class Deque {
private:
    int* arr = new int[capacity];
    int capacity;
    int size;
    int frontIndex;
    int backIndex;
public:
    friend class Iterator;
    friend class Iterator2;
 
    Iterator2* createIterator() const;
  
    Deque() {
        size = 0;
        capacity = 0;
    }

    Deque(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity + 1];
        size = 0;
        frontIndex = 0;
        backIndex = 0;
    }

    Deque(const Deque& other) {
        capacity = other.capacity;
        size = other.size;
        frontIndex = other.frontIndex;
        backIndex = other.backIndex;

        arr = new int[capacity];
        for (int i = 0; i < capacity; ++i) {
            arr[i] = other.arr[i];
        }
    }

    ~Deque() {
        if (this->arr != NULL) {
            delete[] arr;
        }
    }

    Deque& operator=(const Deque& other) {
        if (this != &other) {
            delete[] arr;
            capacity = other.capacity;
            size = other.size;
            frontIndex = other.frontIndex;
            backIndex = other.backIndex;
            arr = new int[capacity];
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
        size = 0;
        delete[] arr;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    bool IsFull() const {
        return size == capacity;
    }

    int Front() const {
        if (frontIndex == 0) {
            throw exception("В начале списка ничего не добавляли!");
        }
        return arr[frontIndex - 1];
    }

    int Back() const {
        return arr[backIndex - 1];
    }

    void PushFront(int value) {
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

    void PushBack(int value) {
        if (IsFull()) {
            cout << "Deque is full, cannot push back." << endl;
            return;
        }
        backIndex++;
        arr[backIndex] = value;
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

    friend ostream& operator<<(ostream& os, const Deque& deque) {
        os << endl << "Deque: " << endl;
        int schet = 0;
        while (schet < deque.size) {
            os << deque.arr[schet] << " ";
            schet++;
        }
        return os;
    }
};

class Iterator {
private:
    const Deque& deque;
    int currentIndex;

public:
    Iterator(const Deque&);
    bool operator!=(const Iterator&);
    bool operator()();
    void operator++();
    int operator*() const;
};

class Iterator2 {
private:
    const Deque* deque;
    int index;
public:
    Iterator2(const Deque* s)
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
    int currentItem()
    {
        return deque->arr[index];
    }
};


Iterator::Iterator(const Deque& d) : deque(d)
{
    currentIndex = 0;
}

bool Iterator::operator()()
{
    return currentIndex != deque.size + 1;
}

bool Iterator::operator!=(const Iterator& other)
{
    return currentIndex != other.currentIndex;
}

void Iterator::operator++()
{
    currentIndex++;
}

int Iterator::operator*() const
{
    return deque.arr[currentIndex];
}

class Iterator2 {
private:
    const Deque* deque;
    int index;
public:
    Iterator2(const Deque* s)
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
    int currentItem()
    {
        return deque->arr[index];
    }
};