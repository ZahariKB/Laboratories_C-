#pragma once
#include<iostream>
using namespace std;
class Money {
private:
	int pound;
	double pense;
	int shilings;
public:
	Money();
	Money(int, int, double);
	Money& operator=(const Money&);
	bool operator==(const Money&) const;
	bool operator<(const Money&) const;
	Money operator+(const Money&) const;
	Money operator-(const Money&) const;
	Money operator-= (const Money&);
	Money operator+=(const Money&);
	Money operator-();
	friend ostream& operator<<(ostream&, Money);
	int getpd() const;
	int getsh() const;
	double pen() const;

};