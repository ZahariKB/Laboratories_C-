#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

class Fraction {
private:
    int a;
    int b;
    static int next_id;
    const int id;
    char name[8];
public:
    Fraction();
    Fraction(int a, int b);
    Fraction(const Fraction&);
    void operator=(const Fraction&);
    bool operator>(Fraction);
    bool operator<(Fraction);
    bool operator>=(Fraction);
    bool operator<=(Fraction);
    bool operator==(Fraction);
    bool operator>(double);
    bool operator<(double);
    bool operator>=(double);
    bool operator<=(double);
    bool operator==(double);
    Fraction& operator++();
    Fraction operator++(int);
    Fraction operator+=(int);
    Fraction operator+=(Fraction);
    Fraction& operator--();
    Fraction operator--(int);
    Fraction operator-=(int);
    Fraction operator-=(Fraction);
    Fraction operator*=(int);
    Fraction operator*=(Fraction);
    Fraction operator/=(int);
    Fraction operator/=(Fraction);
    Fraction operator+(Fraction);
    Fraction operator+(int);
    Fraction operator-(Fraction);
    Fraction operator-(int);
    Fraction operator-();
    Fraction operator*(Fraction);
    Fraction operator*(int);
    Fraction operator/(Fraction);
    Fraction operator/(int);
    void toNormal();
    int getA();
    int getB();
    void setA(int);
    void setB(int);
    int getId();
    double getValue();
    friend Fraction operator+(double, Fraction f);
    friend Fraction operator-(double, Fraction f);
    friend Fraction operator*(double, Fraction f);
    friend Fraction operator/(double, Fraction f);
    friend ostream& operator<<(ostream&, const Fraction&);
    friend istream& operator>> (istream& s, Fraction&);
    unsigned int greatest_common_divisor(unsigned int, unsigned int);
};
