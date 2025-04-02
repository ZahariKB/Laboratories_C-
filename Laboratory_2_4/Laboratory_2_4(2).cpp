#include<string>
#include<vector>
#include<iostream>
using namespace std;

struct SMark
{
    string Subject;                 //предмет
    int mark;                       //оценка
    //конструкторы
    SMark() {
        mark = 0;
        Subject = "Неизвестный предмет";
    }
    SMark(int mark, string subject) {
        this->mark = mark;
        this->Subject = subject;
    }
    friend ostream& operator <<(ostream& OUT, const SMark sm) {
        OUT << " Предмет - " << sm.Subject << endl;
        OUT << " Оценка - " << sm.mark << endl;
        return OUT;
    }
};

class SStudData {
private:
    string name;                     // фамилия
    int ID;                          // номер зачетки
    vector <SMark> marks;            // рез-ты сессии – пустой на момент создания
public:
    //конструкторы,
    SStudData() {
        name = "Неизвестный студент";
        ID = 1;
    }

    SStudData(string name, int ID, vector<SMark> marks) {
        this->name = name;
        this->ID = ID;
        this->marks = marks;
    }

    SStudData(const SStudData& other) {
        this->name = other.name;
        this->ID = other.ID;
        this->marks = other.marks;
    }
    //перегрузка =
    SStudData& operator =(const SStudData& other) {
        if (this != &other) {
            this->name = other.name;
            this->ID = other.ID;
            this->marks = other.marks;
        }
        return *this;
    }
    //перегрузка <<
    friend ostream& operator <<(ostream& out, const SStudData& other) {
        out << "Имя студента: " << other.name << endl;
        out << "Номер зачётки: " << other.ID << endl;
        for (int i = 0; i < other.marks.size(); ++i) {
            out << other.marks[i];
        }
        return out;
    }
    //get - методы,
    string get_name() {
        return name;
    }

    int get_id() {
        return ID;
    }

    vector<SMark> get_marks() {
        return marks;
    }
    //метод для добавления оценки
    void push_mark(const SMark& mark) {
        marks.push_back(mark);
    }
};
