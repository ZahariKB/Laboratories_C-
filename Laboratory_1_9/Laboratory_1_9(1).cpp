#include <iostream>
#include "Matrix.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "russian");
    int m1, n1;
    cout << "������� ���������� ����� � ���������� �������� ������ �������! " << endl;
    cin >> m1 >> n1;
    Matrix matrix1(m1, n1);
    cout << "������� �������� ������ �������! " << endl;
    cin >> matrix1;
    cout << "������ �������: " << endl;
    cout << matrix1 << endl;
    int m2, n2;
    cout << "������� ���������� ����� � ���������� �������� ������ �������! " << endl;
    cin >> m2 >> n2;
    Matrix matrix2(m2, n2);
    cout << "������� �������� ������ �������! " << endl;
    cin >> matrix2;
    cout << "������ �������: " << endl;
    cout << matrix2 << endl;

    if (matrix1.isSymm()) {
        cout << "������ ������� �����������!" << endl;
    }
    else {
        cout << "������ ������� �� �����������! " << endl;
    }

    if (matrix2.isSymm()) {
        cout << "������ ������� �����������!" << endl;
    }
    else {
        cout << "������ ������� �� �����������!" << endl;
    }
    cout << endl;
    int M, N;
    cout << "������� ��������� ����� � �������� ������� �! " << endl;
    cin >> M >> N;
    cout << "�������, ����������� ���������� ������� �� -5 �� 10: " << endl;
    Matrix A(M, N); // �������� ������� A ����������� MxN
    A.fillMatrix(); // ���������� ������� A ���������� �������

    // ���������� ����������� ����������� ��� �������� ����� ������� A � ������� B
    cout << "����� ������� �(B): " << endl;
    Matrix B = A;
    
    cout << B << endl;
    try {
        cout << "��������� F = (A + 5 * B) / 3: " << endl;
        Matrix F = (A + 5 * B) / 3;
        cout << F << endl;
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    int rowsD, columnsD;
    Matrix Z;
    try {
    cout << "������� ���������� ����� � ���������� �������� ������� D! " << endl;
    cin >> rowsD >> columnsD;
    Matrix D(rowsD, columnsD);                                 // ������� ������� D � ��������� ����������� ����� � ��������
        cout << "������� �������� ������� D!" << endl;
        cin >> D;                                              // ������������� �������� ����� ��� ������� D
        cout << "��������� Z = D * B: " << endl;
        Z = D * B;                                           
        cout << Z;
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }
    
    try {
        cout << "��������� G = Z - B: " << endl;
        Matrix G = Z - B;                                    
        cout << G << endl;
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

     /*try {
         Matrix sum = matrix1 + matrix2;
         cout << "C���� ������: " << endl;
         cout << sum;

         Matrix ras = matrix1 - matrix2;
         cout << "�������� ������: " << endl;
         cout << ras;

         Matrix product = matrix1 * matrix2;
         cout << "������������ ������:" << endl;
         cout << product;
     }
     catch (const invalid_argument& e) {
         cerr << e.what() << endl;
     }
     try {
         Matrix matrix3 = matrix1;
         matrix3 += matrix2;
         cout << "������ �������: " << endl;
         cout << matrix3;
     }
     catch (const invalid_argument& e) {
         cerr << e.what() << endl;
     }

     double chislo1, chislo2;
     try {
         cout << "������� �����, ������� ����� ���������� �� �������! " << endl;
         cin >> chislo1;
         Matrix scaledMatrix1 = chislo1 * matrix1;
         cout << "������ ���������������� ������� (���������� ����� �� �������): " << endl;
         cout << scaledMatrix1;
         Matrix scaledMatrix2 = matrix1 * chislo1;
         cout << "������ ���������������� ������� (���������� ������� �� �����): " << endl;
         cout << scaledMatrix2;
         cout << "������� �����, �� ������� ����� �������� �������! " << endl;
         cin >> chislo2;
         Matrix dividedMatrix = matrix1 / chislo2;
         cout << "����������� ������� (����������� �� �����): " << endl;
         cout << dividedMatrix;
     }
     catch (const invalid_argument& e) {
         cerr << e.what() << endl;
     }
     cout << endl;
     if (matrix1 == matrix2) {
         cout << "������ ������� ����� ������ �������! " << endl;
     }
     else {
         cout << "������ ������� �� ����� ������ �������!" << endl;
     }
     cout << endl;
     if (matrix1 != matrix2) {
         cout << "������ ������� �� ����� ������ �������!" << endl;
     }
     else {
         cout << "������ ������� ����� ������ �������!" << endl;
     }

     cout << endl;*/
     return 0;
}