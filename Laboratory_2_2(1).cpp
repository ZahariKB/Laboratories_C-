#pragma once 
#include<iostream>
using namespace std;

class complex {
private:
	double real;
	double imag;
public:
	complex() {
		real = 0;
		imag = 0;
	}

	complex(double real, double imag) {
		this->real = real;
		this->imag = imag;
	}

	complex(const complex& c) {
		real = c.real;
		imag = c.imag;
	}

	complex& operator=(const complex& c) {
		if (this != &c) {
			real = c.real;
			imag = c.imag;
		}
		return *this;
	}

	bool operator ==(const complex& c) {
		return real == c.real && imag == c.imag;
	}

	friend ostream& operator<<(ostream& s, const complex& c) {
		s << " Комплексное число: " << c.real << " + " << c.imag << "i" << endl;
		return s;
	}

	~complex() {}
};