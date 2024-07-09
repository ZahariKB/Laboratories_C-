#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;
class Matrix {
private:
    int rows;
    int columns;
    double** matr;

public:
    Matrix(int, int);
    Matrix(const Matrix&);
    Matrix();
    ~Matrix();
    void fillMatrix();
    bool isSymm() const;
    Matrix& operator=(const Matrix&);
    Matrix& operator+=(const Matrix&);
    Matrix& operator*=(double);
    Matrix& operator/=(double);

    friend Matrix operator*(double,const Matrix&);
    friend Matrix operator*(const Matrix&,double);
    friend Matrix operator/(const Matrix&,double);
    friend Matrix operator+(const Matrix&,const Matrix&);
    friend Matrix operator-(const Matrix&,const Matrix&);
    friend Matrix operator*(const Matrix&,const Matrix&);

    friend bool operator==(const Matrix&, const Matrix&);
    friend bool operator!=(const Matrix&, const Matrix&);

    friend istream& operator>>(istream&, Matrix&);
    friend ostream& operator<<(ostream&, const Matrix&);
};
#endif