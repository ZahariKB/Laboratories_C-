#include "deque.cpp"
#include<iostream>
using namespace std;

int Count(const Deque& deque, int value) {
    int count = 0;

    Iterator iter(deque);
    for (; iter(); ++iter)
        if (*iter == value)
            ++count;
    return count;
}

int Count2(const Deque& deque, int value) {
    int count = 0;

    Iterator2* iter = deque.createIterator();
    for (iter->first(); !iter->isDone(); iter->next())
        if (iter->currentItem() == value)
            ++count;
    return count;
}

Iterator2* Deque::createIterator() const{
        return new Iterator2(this);
    }

int main()
{
    setlocale(LC_ALL, "Russian");
    try {
        Deque myDeque(6);
        int a, b;
        myDeque.PushFront(3);
        myDeque.PushFront(2);
        myDeque.PushFront(2);
        cout << "Дек после добавления трёх элементов в начало: " << myDeque << endl;
        myDeque.PopFront();
        myDeque.PopFront();
        cout << "Дек после удаления двух элементов из начала: " << myDeque << endl;
        myDeque.PushBack(2);
        myDeque.PushBack(2);
        /*myDeque.Clear();
        return 0;*/
        a = myDeque.Front();
        b = myDeque.Back();
        cout << "Первый элемент, добавленный в начало списка: " << a << endl <<"Первый элемент, добавленный в конец списка: " << b << endl;
        cout << "Дек после добавления двух элементов в конец: " << myDeque << endl;
        cout << myDeque;
        cout << "Количество значений дека, равных заданному (первый способ): " << Count(myDeque, 2) << endl;
        cout << "Количество значений дека, равных заданному (второй способ): " << Count2(myDeque, 2) << endl;
        Deque myDeque2 = myDeque;
        Deque myDeque3(myDeque2);
        cout << endl;
        cout << myDeque3 << myDeque2 << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
        return 0;
    }
    return 0;
}