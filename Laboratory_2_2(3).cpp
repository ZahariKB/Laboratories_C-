#include "complex.cpp"
#include "deque.cpp"
using namespace std;

template <typename T>

int Count(const Deque<T>& deque, T value) {
    int count = 0;
    Iterator<T> iter(deque);
    for (; iter(); ++iter) {
        if (*iter == value)
            ++count;
    }
    return count;
}

template<typename T>
int Count2(const Deque<T>& deque, T value) {
    int count = 0;
    Iterator2<T>* iter = deque.CreateIterator();
    for (iter->first(); !iter->isDone(); iter->next()) {
        if (iter->currentItem() == value)
            ++count;
    }
    return count;
}

template <typename T>

Iterator2<T>* Deque<T>::CreateIterator() const {
    return new Iterator2<T>(this);
}


int main()
{
    setlocale(LC_ALL, "Russian");
    Deque<int> deq_2(3);
    int a = 1, b = 2, c = 3;
    deq_2.PushBack(a);
    deq_2.PushBack(a);
    deq_2.PushBack(c);
    cout << "Количество значений дека, равных заданному : " << Count(deq_2, 1) << endl;
    cout << "Количество значений дека, равных заданному : " << Count2(deq_2, 1) << endl;
    /*Deque<complex> deq(3);
    complex c1(1, 2), c2(2, 8), c3(4, 11), c4(1, 2);
    deq.PushBack(c1);
    deq.PushBack(c2);
    deq.PushBack(c3);
    cout << "Дек после добавления трёх элементов в конец: " << deq;
    deq.PopBack();
    deq.PopFront();
    cout << "Дек после удаления одного элемента из начала и удаления одного элемента из конца: " << deq;
    deq.PushFront(c1);
    deq.PushFront(c3);
    cout <<"Дек после добавления двух элементов в начало: " << deq;
    cout << "Количество значений дека, равных заданному : " << Count(deq, c4) << endl;
    cout << "Количество значений дека, равных заданному : " << Count2(deq, c4) << endl;*/
    
    return 0;
}