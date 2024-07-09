#include<iostream>
#include<string>
#include "Metodi_maina.h"
using namespace std;

Actor::Actor(const string& str, Amplua amp) : id(next_id++), year_of_birth(1990), surname(surname), amplua(amplua) {};

Actor& Actor::operator=(const Actor& act) {
    if (this != &act) {
        this->amplua = act.amplua;
        this->surname = act.surname;
    }
    return *this;
}

Actor& Actor::operator=(Actor&& act) noexcept {
    if (this != &act) {
        this->amplua = act.amplua;
        this->surname = act.surname;
    }
    return *this;
}

Actor::Actor(Actor&& act) noexcept : amplua(act.amplua), surname(act.surname), id(next_id++), year_of_birth(act.year_of_birth) {
    this->amplua = act.amplua;
    this->surname = act.surname;
}

bool Actor::operator==(const Amplua& amp) {
    return this->amplua == amp;
}

ostream& operator<<(ostream& os, const Actor& act) {
    os << "ID: " << act.id << ", Год рождения: " << act.year_of_birth << ", Фамилия: " << act.surname << ", АМПЛУА: " << act.amplua << ", Количество актёров: " << act.amount_actors << endl;
    return os;
}

void Actor::set_surname(string surname) {
    this->surname = surname;
}

void Actor::set_amplua(Amplua amplua) {
    this->amplua = amplua;
}

string Actor::get_surname() {
    return surname;
}


Amplua Actor::get_amplua() {
    return amplua;
}

Actor::~Actor() {};

