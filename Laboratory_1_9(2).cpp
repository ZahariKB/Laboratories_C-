#include "matrix.h"
#include <stdexcept>
#include<iostream>
#include<ctime>
using namespace std;

Matrix::Matrix(int rows, int columns) : rows(rows), columns(columns) {
    matr = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        matr[i] = new double[columns];
    }
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), columns(other.columns) {
    matr = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        matr[i] = new double[columns];
        for (int j = 0; j < columns; ++j) {
            matr[i][j] = other.matr[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] matr[i];
    }
    delete[] matr;
}

Matrix::Matrix()
{
    this->rows = 1;
    this->columns = 1;
    matr = new double* [rows];
    for (int i = 0; i < rows; i++)
        matr[i] = new double[columns];
    matr[0][0] = 0;
}
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        for (int i = 0; i < rows; i++)
            delete[] matr[i];
        delete[] matr;
        rows = other.rows;
        columns = other.columns;
        matr = new double* [rows];
        for (int i = 0; i < rows; i++)
            matr[i] = new double[columns];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matr[i][j] = other.matr[i][j];
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    if (rows != other.rows || columns != other.columns) {
        throw invalid_argument("Ошибка! Матрицы должны иметь одинаковые размеры! ");
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matr[i][j] += other.matr[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(double chislo) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matr[i][j] *= chislo;
        }
    }
    return *this;
}

Matrix& Matrix::operator/=(double chislo) {
    if (chislo == 0) {
        throw invalid_argument("Ошибка! Деление на нуль! ");
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matr[i][j] /= chislo;
        }
    }
    return *this;
}

Matrix operator*(double Chislo, const Matrix& matrix) {
    Matrix result(matrix);
    result *= Chislo;
    return result;
}

Matrix operator*(const Matrix& matrix, double Chislo) {
    return Chislo * matrix;
}

Matrix operator/(const Matrix& matrix, double Chislo) {
    if (Chislo == 0) {
        throw invalid_argument("Ошибка! Деление на нуль! ");
    }
    Matrix result(matrix);
    result /= Chislo;
    return result;
}

Matrix operator+(const Matrix& matrix1, const Matrix& matrix2) {
    if (matrix1.rows != matrix2.rows || matrix1.columns != matrix2.columns) {
        throw invalid_argument("Ошибка! Матрицы должны иметь одинаковые размеры! ");
    }
    Matrix result(matrix1);
    result += matrix2;
    return result;
}

Matrix operator-(const Matrix& matrix1, const Matrix& matrix2) {
    if (matrix1.rows != matrix2.rows || matrix1.columns != matrix2.columns) {
        throw invalid_argument("Ошибка! Матрицы должны иметь одинаковые размеры! ");
    }
    Matrix result(matrix1);
    for (int i = 0; i < result.rows; ++i) {
        for (int j = 0; j < result.columns; ++j) {
            result.matr[i][j] -= matrix2.matr[i][j];
        }
    }
    return result;
}

Matrix operator*(const Matrix& matrix1, const Matrix& matrix2) {
    if (matrix1.columns != matrix2.rows) {
        throw invalid_argument("Ошибка! Количество столбцов в первой матрице должно быть равно количеству строк во второй матрице! ");
    }
    int n = matrix1.rows;
    int m = matrix1.columns;
    int p = matrix2.columns;

    Matrix result(n, p);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            result.matr[i][j] = 0;
            for (int k = 0; k < m; ++k) {
                result.matr[i][j] += matrix1.matr[i][k] * matrix2.matr[k][j];
            }
        }
    }
    return result;
}

bool operator==(const Matrix& matrix1, const Matrix& matrix2) {
    if (matrix1.rows != matrix2.rows || matrix1.columns != matrix2.columns) {
        return false;
    }
    for (int i = 0; i < matrix1.rows; ++i) {
        for (int j = 0; j < matrix1.columns; ++j) {
            if (matrix1.matr[i][j] != matrix2.matr[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const Matrix& matrix1, const Matrix& matrix2) {
    return !(matrix1 == matrix2);
}
bool Matrix::isSymm() const {
    if (rows != columns) {
        return false;                                             // Матрица не является квадратной, поэтому не может быть симметричной
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            if (matr[i][j] != matr[j][i]) {
                return false;                                     // Найден элемент, не удовлетворяющий условию симметричности
            }
        }
    }
    return true;                                                  // Все элементы соответствуют условию симметричности
}
void Matrix::fillMatrix() {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matr[i][j] = rand() % 14 - 5; // случайные числа от -5 до 10
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }
}

istream& operator>>(istream& in, Matrix& matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.columns; ++j) {
            in >> matrix.matr[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.columns; ++j) {
            out << matrix.matr[i][j] << " ";
        }
        out << endl;
    }
    return out;
}