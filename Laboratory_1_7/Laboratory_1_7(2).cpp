#include <iostream>

using namespace std;

class Complex 
{
private:
    double real;
    double mnimoe;
public:

    Complex(double r, double i) : real(r), mnimoe(i) 
    {
    
    }
    Complex operator + (const Complex& second) 
    {
        return Complex(real + second.real, mnimoe + second.mnimoe);
    }
    Complex operator - (const Complex& second) 
    {
        return Complex(real - second.real, mnimoe - second.mnimoe);
    }
    Complex operator * (const Complex& second) 
    {
        double real1 = (real * second.real) - (mnimoe * second.mnimoe);
        double mnimoe1 = (real * second.mnimoe) + (mnimoe * second.real);
        return Complex(real1, mnimoe1);
    }
    Complex operator / (const Complex& second)
    {
        double real2 = ((real * second.real) + (mnimoe * second.mnimoe)) / ((second.real * second.real) + (second.mnimoe * second.mnimoe));
        double mnimoe2 = ((mnimoe * second.real) - (real * second.mnimoe)) / ((second.real * second.real) + (second.mnimoe * second.mnimoe));
        return Complex(real2, mnimoe2);
    }
    friend ostream& operator<<(ostream& chislo, const Complex& complex) 
    {
        chislo << complex.real << " + " << complex.mnimoe << "i";
        return chislo;
    }
};

int main() 
{
    setlocale(LC_ALL, "Russian");
    int a, b, c, d;
    cout << "Введите действительную и мнимую часть первого числа!" << endl;
    cin >> a >> b;
    cout << "Введите действительную и мнимую часть второго числа!" << endl;
    cin >> c >> d;
    Complex pervoe(a, b);
    Complex vtoroe(c, d);
    Complex sum = pervoe + vtoroe;
    cout << "Сумма комлексных чисел равна: " << sum << endl;
    Complex raz = pervoe - vtoroe;
    cout << "Разность комлпексных чисел равна: " << raz << endl;
    Complex umn = pervoe * vtoroe;
    cout << "Произведение комплексных чисел равна: " << umn << endl;
    Complex del = pervoe / vtoroe;
    if (c == 0 && d == 0)
    {
        cerr << "Деление на нуль невозможно!" << endl;
    }
    else
    {
        cout << "Частное комплексных чисел равна: " << del << endl;
    }
    return 0;
}