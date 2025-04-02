#include "ClassFraction.cpp"

int Fraction::next_id = 30;

Fraction::Fraction() : id(++next_id) {
    a = 0;
    b = 1;
}

Fraction::Fraction(int aa = 1, int bb = 1) : id(++next_id) {
    a = aa;
    b = bb;
    toNormal();
}

Fraction::Fraction(const Fraction& f) : id(++next_id) {
    a = f.a;
    b = f.b;
}

void Fraction::operator=(const Fraction& f) {
    a = f.a;
    b = f.b;
    toNormal();
}


bool Fraction::operator>(Fraction f) {
    double q = a / b;
    double w = f.a / f.b;
    return (q > w);
}

bool Fraction::operator<(Fraction f) {
    double q = a / b;
    double w = f.a / f.b;
    return (q < w);
}

bool Fraction::operator>=(Fraction f) {
    double q = a / b;
    double w = f.a / f.b;
    return (q >= w);
}

bool Fraction::operator<=(Fraction f) {
    double q = a / b;
    double w = f.a / f.b;
    return (q <= w);
}

bool Fraction::operator==(Fraction f) {
    return (a == f.a && b == f.b);
}

bool Fraction::operator>(double n) {
    double q = a / b;
    return (q > n);
}

bool Fraction::operator<(double n) {
    double q = a / b;
    return (q < n);
}

bool Fraction::operator>=(double n) {
    double q = a / b;
    return (q >= n);
}

bool Fraction::operator<=(double n) {
    double q = a / b;
    return (q <= n);
}

bool Fraction::operator==(double n) {
    return (a / b == n);
}

Fraction& Fraction::operator++() {
    a += b;
    toNormal();
    return *this;
}

Fraction Fraction::operator++(int n) {
    Fraction q(a, b);
    a += b;
    toNormal();
    return q;
}

Fraction Fraction::operator+=(int n) {
    a += b * n;
    toNormal();
    return *this;
}

Fraction Fraction::operator+=(Fraction f) {
    int n = a * f.b + f.a * b;
    int d = b * f.b;
    a = n;
    b = d;
    toNormal();
    return *this;
}

Fraction& Fraction::operator--() {
    a -= b;
    toNormal();
    return *this;
}

Fraction Fraction::operator--(int n) {
    Fraction q(a, b);
    a -= b;
    toNormal();
    return q;
}

Fraction Fraction::operator-=(int n) {
    a -= b * n;
    toNormal();
    return *this;
}

Fraction Fraction::operator-=(Fraction f) {
    int n = a * f.b - f.a * b;
    int d = b * f.b;
    a = n;
    b = d;
    toNormal();
    return *this;
}

Fraction Fraction::operator*=(int n) {
    a *= n;
    toNormal();
    return *this;
}

Fraction Fraction::operator*=(Fraction f) {
    a *= f.a;
    b *= f.b;
    toNormal();
    return *this;
}

Fraction Fraction::operator/=(int n) {
    if (n != 0) {
        b *= n;
        toNormal();
        return *this;
    }
    else {
        cerr << "Division by zero!";
        a = 0;
        b = 1;
        return *this;
    }
}

Fraction Fraction::operator/=(Fraction f) {
    if (f.a != 0) {
        a *= f.b;
        b *= f.a;
        toNormal();
        return *this;
    }
    else {
        cerr << "Division by zero!";
        a = 0;
        b = 1;
        return *this;
    }
}

Fraction Fraction::operator+(Fraction f) {
    Fraction q(a * f.b + f.a * b, b * f.b);
    return q;
}

Fraction Fraction::operator+(int n) {
    Fraction q((a + (b * n)), b);
    return q;
}

Fraction Fraction::operator-(Fraction f) {
    Fraction q(a * f.b - f.a * b, b * f.b);
    return q;
}

Fraction Fraction::operator-(int n) {
    Fraction q((a - (b * n)), b);
    return q;
}

Fraction Fraction::operator-() {
    if (a == 0) {
        Fraction q(a, b);
        return q;
    }
    else {
        Fraction q(b, a);
        return q;
    }
}

Fraction Fraction::operator*(Fraction f) {
    Fraction q(a * f.a, b * f.b);
    return q;
}

Fraction Fraction::operator*(int n) {
    Fraction q(a * n, b);
    return q;
}

Fraction Fraction::operator/(Fraction f) {
    if (f.a != 0) {
        Fraction q(a * f.b, b * f.a);
        return q;
    }
    else {
        cerr << "Division by zero!";
        Fraction q(0, 1);
        return q;
    }
}

Fraction Fraction::operator/(int n) {
    if (n != 0) {
        Fraction q(a, b * n);
        return q;
    }
    else {
        cerr << "Division by zero!";
        Fraction q(0, 1);
        return q;
    }
}


void Fraction::toNormal() {
    if (a < 0 && b < 0) {
        a = -a;
        b = -b;
    }
    else if (b < 0) {
        a = -a;
        b = -b;
    }
    if (a == 0) {
        //cerr << "Division by zero!";
        b = 1;
    }
    else {
        int nod = greatest_common_divisor(abs(a), abs(b));
        a /= nod;
        b /= nod;
    }
}

unsigned int Fraction::greatest_common_divisor(unsigned int a, unsigned int b) {
    if (a == b)
        return a;
    if (a > b)
        return greatest_common_divisor(a - b, b);
    return greatest_common_divisor(a, b - a);
}

int Fraction::getA() {
    return a;
}

int Fraction::getB() {
    return b;
}

void Fraction::setA(int aa) {
    a = aa;
    toNormal();
}

void Fraction::setB(int bb) {
    b = bb;
    toNormal();
}

int Fraction::getId() {
    return id;
}

double Fraction::getValue() {
    return double(a) / double(b);
}

Fraction operator+(double n, Fraction f) {
    Fraction q(f.getA() + (f.getB() * n), f.getB());
    return q;
}

Fraction operator-(double n, Fraction f) {
    Fraction q = f - n;
    q.a = -q.a;
    return q;
}

Fraction operator*(double n, Fraction f) {
    Fraction q(f.getA() * n, f.getB());
    return q;
}

Fraction operator/(double n, Fraction f) {
    if (f.getA() != 0) {
        Fraction q(f.getB() * n, f.getA());
        return q;
    }
    else {
        cerr << "Division by zero!";
        Fraction q(0, 1);
        return q;
    }
}

ostream& operator<<(ostream& s, const Fraction& f) {
    s << f.a << " / " << f.b;
    return s;
}

istream& operator>> (istream& s, Fraction& f) {
    s >> f.a;
    s >> f.b;
    f.toNormal();
    return s;
}