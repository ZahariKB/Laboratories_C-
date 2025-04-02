#include <iostream>
#include "Matrix.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "russian");
    int m1, n1;
    cout << "Введите количество строк и количество столбцов первой матрицы! " << endl;
    cin >> m1 >> n1;
    Matrix matrix1(m1, n1);
    cout << "Введите элементы первой матрицы! " << endl;
    cin >> matrix1;
    cout << "Первая матрица: " << endl;
    cout << matrix1 << endl;
    int m2, n2;
    cout << "Введите количество строк и количество столбцов второй матрицы! " << endl;
    cin >> m2 >> n2;
    Matrix matrix2(m2, n2);
    cout << "Введите элементы второй матрицы! " << endl;
    cin >> matrix2;
    cout << "Вторая матрица: " << endl;
    cout << matrix2 << endl;

    if (matrix1.isSymm()) {
        cout << "Первая матрица симметрична!" << endl;
    }
    else {
        cout << "Первая матрица не симметрична! " << endl;
    }

    if (matrix2.isSymm()) {
        cout << "Вторая матрица симметрична!" << endl;
    }
    else {
        cout << "Вторая матрица не симметрична!" << endl;
    }
    cout << endl;
    int M, N;
    cout << "Введите количство строк и столбцов матрицы А! " << endl;
    cin >> M >> N;
    cout << "Матрица, заполненная случайными числами от -5 до 10: " << endl;
    Matrix A(M, N); // Создание матрицы A размерности MxN
    A.fillMatrix(); // Заполнение матрицы A случайными числами

    // Используем конструктор копирования для создания копии матрицы A в матрицу B
    cout << "Копия матрицы А(B): " << endl;
    Matrix B = A;
    
    cout << B << endl;
    try {
        cout << "Выражение F = (A + 5 * B) / 3: " << endl;
        Matrix F = (A + 5 * B) / 3;
        cout << F << endl;
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    int rowsD, columnsD;
    Matrix Z;
    try {
    cout << "Введите количество строк и количество столбцов матрицы D! " << endl;
    cin >> rowsD >> columnsD;
    Matrix D(rowsD, columnsD);                                 // Создаем матрицу D с указанным количеством строк и столбцов
        cout << "Введите элементы матрицы D!" << endl;
        cin >> D;                                              // Перегруженный оператор ввода для матрицы D
        cout << "Выражение Z = D * B: " << endl;
        Z = D * B;                                           
        cout << Z;
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }
    
    try {
        cout << "Выражение G = Z - B: " << endl;
        Matrix G = Z - B;                                    
        cout << G << endl;
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

     /*try {
         Matrix sum = matrix1 + matrix2;
         cout << "Cумма матриц: " << endl;
         cout << sum;

         Matrix ras = matrix1 - matrix2;
         cout << "Разность матриц: " << endl;
         cout << ras;

         Matrix product = matrix1 * matrix2;
         cout << "Произведение матриц:" << endl;
         cout << product;
     }
     catch (const invalid_argument& e) {
         cerr << e.what() << endl;
     }
     try {
         Matrix matrix3 = matrix1;
         matrix3 += matrix2;
         cout << "Третья матрица: " << endl;
         cout << matrix3;
     }
     catch (const invalid_argument& e) {
         cerr << e.what() << endl;
     }

     double chislo1, chislo2;
     try {
         cout << "Введите число, которое будет умножаться на матрицу! " << endl;
         cin >> chislo1;
         Matrix scaledMatrix1 = chislo1 * matrix1;
         cout << "Первая масштабированная матрица (умножается число на матрицу): " << endl;
         cout << scaledMatrix1;
         Matrix scaledMatrix2 = matrix1 * chislo1;
         cout << "Первая масштабированная матрица (умножается матрица на число): " << endl;
         cout << scaledMatrix2;
         cout << "Введите число, на которое будет делиться матрица! " << endl;
         cin >> chislo2;
         Matrix dividedMatrix = matrix1 / chislo2;
         cout << "Разделенная матрица (разделенная на число): " << endl;
         cout << dividedMatrix;
     }
     catch (const invalid_argument& e) {
         cerr << e.what() << endl;
     }
     cout << endl;
     if (matrix1 == matrix2) {
         cout << "Первая матрица равна второй матрице! " << endl;
     }
     else {
         cout << "Первая матрица не равна второй матрице!" << endl;
     }
     cout << endl;
     if (matrix1 != matrix2) {
         cout << "Первая матрица не равна второй матрице!" << endl;
     }
     else {
         cout << "Первая матрица равна второй матрице!" << endl;
     }

     cout << endl;*/
     return 0;
}