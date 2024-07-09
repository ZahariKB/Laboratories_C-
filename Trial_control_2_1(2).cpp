#include<iostream>
using namespace std;

const enum Rasa { man = 0, gnom, elf };

enum Sost { norm = 0, paraliz, mertv };

class Person {

protected:

    const int id;
    const Rasa rase;
    string name;
    bool move;
    Sost sostoianie;
    static int next_id;

public:

    Person() : id(next_id++), rase(man) {}

    Person(string name, bool move, Sost sostoianie) : id(next_id++), rase(man) {
        this->name = name;
        this->move = move;
        this->sostoianie = sostoianie;
    }

    Person(const Person& pers) : id(next_id++), rase(man) {
        this->name = pers.name;
        this->move = pers.move;
        this->sostoianie = pers.sostoianie;
        this->next_id = pers.next_id;
        this->sostoianie = pers.sostoianie;
    }

    Person& operator =(const Person& pers)  {
        if (this != &pers) {
            this->name = pers.name;
            this->move = pers.move;
            this->sostoianie = pers.sostoianie;
            this->next_id = pers.next_id;
            this->sostoianie = pers.sostoianie;
        }
        return *this;
    }

    Person& operator <(Person& pers) {
        if (this->name < pers.name) {
            return *this;
        }
    }

    friend ostream& operator <<( ostream& out, const Person& pers) {

        string vanyaloh, realno;

        switch (pers.rase) {
        case man:
            vanyaloh = "Человек";
            break;
        case gnom:
            vanyaloh = "Гномик";
            break;
        case elf:
            vanyaloh = "Эльф";
            break;
        }

        switch (pers.sostoianie) {
        case norm:
            realno = "Нормальное";
            break;
        case paraliz:
            realno = "Парализован";
            break;
        case mertv:
            realno = "Мёртв";
            break;
        }

        out << "Раса персонажа: " << vanyaloh << endl;
        out << "Имя персонажа: " << pers.name << endl;
        out << "Состояние персонажа: " << realno << endl;
        out << "Может двигаться или нет: " << pers.move << endl;
        out << "ID персонажа: " << pers.id << endl << endl;
        return out;

    }

    void set_move(bool move) {
        this->move = move;
    }

    void set_name(string name) {
        this->name = name;
    }

    void set_sost(Sost sostoianie) {
        this->sostoianie = sostoianie;
    }

    int get_id() {
        return id;
    }

    bool get_move() {
        return move;
    }

    string get_name() {
        return name;
    }

    Rasa get_rase() {
        return rase;
    }

    Sost get_sost() {
        return sostoianie;
    }

    ~Person() {}

};
