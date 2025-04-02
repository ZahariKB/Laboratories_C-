#include<iostream>
#include "header.h"
using namespace std;

Money::Money() {
    pound = 0;
    shilings = 0;
    pense = 0.0;
}

Money::Money(int pound, int shilings, double pense) {
    this->pound = pound;
    this->shilings = shilings;
    this->pense = pense;
    
        if (shilings >= 20) {
            throw exception("Слишком много шиллингов!!!");
        }
        if (pense >= 12) {
            throw exception("Слишком много пенсов!!!");
        }
        int p = (pense * 100);
        if (p % 25 != 0) {
            throw exception("Пенсы не так введены!!!");
        }
}

Money& Money::operator=(const Money& other) {
    if (this != &other) {
        pound = other.pound;
        shilings = other.shilings;
        pense = other.pense;
    }
    return *this;
}

bool Money::operator==(const Money& other) const {
    if (shilings != other.shilings || pound != other.pound || pense != other.pense) {
        return false;
    }
    return true;
}

bool Money::operator <(const Money& other) const{
    if (pound < other.pound) {
        return true;
        if (shilings < other.shilings) {
            return true;
            if (pense < other.pense) {
                return true;
            }
        }
    }
    return false;
}

Money Money::operator-() {
    pound *= -1;
    shilings *= -1;
    pense *= -1;
    return *this;
}

Money Money::operator+(const Money& other) const {
    double sumpense = pense + other.pense;
    int sumshilings = shilings + other.shilings;
    int sumpounds = pound + other.pound;

    if (sumpense >= 12) {
        sumshilings++;
        sumpense -= 12;
    }
    if (sumshilings >= 20) {
        sumpounds++;
        sumshilings -= 20;
    }
    return Money(sumpounds, sumshilings, sumpense);
}

Money Money::operator-(const Money& other) const {
    return Money(-pound, -shilings, -pense);
}

Money Money::operator+=(const Money& other) {
    *this = *this + other;
    return *this;
}

Money Money::operator-=(const Money& other) {
    *this = *this - other;
    return *this;
}

int Money::getpd() const {
    return pound;
}
int Money::getsh() const {
    return shilings;
}
double Money::pen() const {
    return pense;
}

ostream& operator <<(ostream& out, Money other)  {
    out << "Количество денег: " << other.pound << "pd." << other.shilings << "sh." << other.pense << "p." << endl;
    return out;
}