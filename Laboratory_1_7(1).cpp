#include <iostream>

using namespace std;

class Complex {
private:
	double a, b;
public:
	Complex(double c, double d) 
	{
		a = c;
		b = d;
	}
	double GetA()
	{
		return a;
	}
	double GetB()
	{
		return b;
	}
	Complex sum(Complex vtoroe) 
	{
		return Complex(a + vtoroe.a, b + vtoroe.b);
	}
	Complex ras(Complex vtoroe) 
	{
		return Complex(a - vtoroe.a, b - vtoroe.b);
	}
	Complex  umn(Complex vtoroe) 
	{
		return Complex(a * vtoroe.a - b * vtoroe.b, a * vtoroe.b + b * vtoroe.a);
	}
	Complex  del(Complex vtoroe)
	{
		return Complex((((a * vtoroe.a) + (b * vtoroe.b)) / ((vtoroe.a * vtoroe.a) + (vtoroe.b * vtoroe.b))), (((b * vtoroe.a) - (a * vtoroe.b)) / ((vtoroe.a * vtoroe.a) + (vtoroe.b * vtoroe.b))));
	}


	void print() const 
	{
		cout << "(" << a << " + " << b << "i)";
	}
	~ Complex(){};
};


int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c, d;
	cout << "Введите действительную часть первого числа! ";
	cin >> a;
	cout << "Введите мнимую часть первого числа! ";
	cin >> b;
	cout << "Введите действительную часть второго числа! ";
	cin >> c;
	cout << "Введите мнимую часть второго числа! ";
	cin >> d;
	Complex chislo1(a, b);
	Complex chislo2(c, d);

	chislo1.print();
	cout << " + ";
	chislo2.print();
	cout << " = ";
	chislo1.sum(chislo2).print();
	cout << endl;


	chislo1.print();
	cout << " - ";
	chislo2.print();
	cout << " = ";
	chislo1.ras(chislo2).print();
	cout << endl;


	chislo1.print();
	cout << " * ";
	chislo2.print();
	cout << " = ";
	chislo1.umn(chislo2).print();
	cout << endl;

	if (chislo2.GetA() == 0 && chislo2.GetB() == 0) 
	{
		cerr << "Деление на нуль невозможно!";
		return 0;
	}

	chislo1.print();
	cout << " / ";
	chislo2.print();
	cout << " = ";
	chislo1.del(chislo2).print();
}











