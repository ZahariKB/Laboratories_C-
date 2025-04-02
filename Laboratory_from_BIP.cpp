#include <iostream>
#include <string>
using namespace std;

const static int currentDate = 2024;

struct Employee {
    string fullName;
    int departmentNumber;
    string position;
    int startDate;
    Employee* prev;
    Employee* next;
    int Stage;
};


Employee* head = nullptr;
Employee* tail = nullptr;

void push_back(const string& fullName, int departmentNumber, const string& position, const int startDate) {
    Employee* newEmployee = new Employee{ fullName, departmentNumber, position, startDate, nullptr, nullptr };
    if (head == nullptr) {
        head = newEmployee;
        tail = newEmployee;
    }
    else {
        tail->next = newEmployee;
        newEmployee->prev = tail;
        tail = newEmployee;
    }
}

void push_front(const string& fullName, int departmentNumber, const string& position, const int startDate) {
    Employee* newEmployee = new Employee{ fullName, departmentNumber, position, startDate, nullptr, nullptr };
    if (head != nullptr) {
        head->prev = newEmployee;
        newEmployee->next = head;
        head = newEmployee;
    }
    else {
        tail = newEmployee;
        head = newEmployee;
    }
}

void pop_back() {
    if (tail == NULL)
        throw exception("Невозможно извлечь элемент! Очередь пуста!");
    else if (tail == head) {
        head = NULL;
        tail = NULL;
    }
    else {
        tail = tail->prev;
        tail->next = NULL;
    }
}

void pop_front() {
    if (head == NULL)
        throw exception("Невозможно извлечь элемент! Очередь пуста!");
    else if (head->next == NULL) {
        head = NULL;
        tail = NULL;
    }
    else {
        head = head->next;
        head->prev = NULL;
    }
}

void printEmployeeList() {
    Employee* pers = head;
    while (pers != nullptr) {
        cout << "Полное имя: " << pers->fullName << endl;
        cout << "Номер отдела: " << pers->departmentNumber << endl;
        cout << "Должность: " << pers->position << endl;
        cout << "Стаж работы: " << (currentDate - pers->startDate) << " лет(года)" << endl;
        cout << endl;
        pers = pers->next;
    }
}

void printEmployeeList_2() {
    Employee* pers = tail;
    while (pers != nullptr) {
        cout << "Полное имя: " << pers->fullName << endl;
        cout << "Номер отдела: " << pers->departmentNumber << endl;
        cout << "Должность: " << pers->position << endl;
        cout << "Стаж работы: " << (currentDate - pers->startDate) << " лет(года)" << endl;
        cout << endl;
        pers = pers->prev;
    }
}

int main() {
    try {
        setlocale(LC_ALL, "Russian");
        push_front("Исаков Антон Владимирович", 1, "Менеджер", 2020);
        push_back("Рубцов Иван Константинович", 2, "Инженер", 2018);
        push_front("Одинцова Алиса Олеговна ", 3, "Аналитик", 2019);
        cout << "Вывод листа в прямом порядке: " << endl << endl;
        printEmployeeList();
        cout << "Вывод листа в обратном порядке: " << endl << endl;
        printEmployeeList_2();
    }
    catch (exception& e) {
        cout << e.what() << endl;
        return 0;
    }

    return 0;
}


