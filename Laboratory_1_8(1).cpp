#include "ClassFraction.cpp"

int main()
{
    setlocale(LC_ALL, "russian");
    Fraction arr[8];
    int a, b, count = 0;
    Fraction sum (0,1);
    srand(time(NULL));
    for (int i = 0; i < 4; i++)
    {
         a = rand() % 4 - 2;
         b = rand() % 4 - 2;
         if (b == 0) {
             cerr << "Ошибка, деление на нуль!";
             return 0;
         }
        /*arr[i] = Fraction(a, b);*/
         arr[i].setA(a);
         arr[i].setB(b);
         cout <<"Дробь: " << arr[i] << endl;
    }
    Fraction product = arr[0];
    for (int i = 1; i < 4; i++)
    {
        product *= arr[i];
    }
    arr[4] = product;

    for (int i = 5; i < 7; i++)
    {
        arr[i] = Fraction(arr[i - 1].getId() + arr[i - 1].getA(), 1);
    }

    for (int i = 0; i < 8; i++)
    {
        cout << "Дробь" << i + 1 << ": " << arr[i].getA() << "/" << arr[i].getB() << " " << "Идентификатор: " << arr[i].getId() << endl;
    }
    for (int i = 0; i < 8; i++)
    {
        if (arr[i].getId() % 2 != 0)
        {
            sum += arr[i];
            count++;
        }
    }
    if (count > 0) {

        sum /= count;
        cout << "Среднее арифметическое дробей с нечётными идентификаторами: " << sum << endl;
    }
    else
    {
        cout << "Нет дробей с нечётными идентификаторами!" << endl;
    }
    return 0;
}
//#include "ClassFraction.cpp"

//int main()
//{
//    Fraction arr[8];
//    int a, b, ii;
//    double maxVal = 0;
//    srand(time(NULL));
//    for (int i = 0; i < 2; i++) {
//        b = rand() % 10;
//
//        if (b == 0) {
//            cout << "Error. Division by zero!";
//            return 0;
//            break;
//        }
//        a = rand() % (b * 6) - (b * 3);
//        arr[i].setA(a);
//        arr[i].setB(b);
//        cout << arr[i] << endl;
//    }
//
//    for (int i = 2; i < 5; i++) {
//        arr[i] = (arr[i - 1] + arr[i - 2]);
//        cout << arr[i] << endl;
//    }
//
//    for (int i = 5; i < 8; i++) {
//        arr[i] = (arr[i - 3] - (2 * arr[i - 2]));
//        cout << arr[i] << endl;
//    }
//
//    for (int i = 0; i < 8; i++) {
//        if (arr[i].getId() % 2 == 0) {
//            if (maxVal < arr[i].getValue()) {
//                maxVal = arr[i].getValue();
//                ii = i;
//            }
//        }
//    }
//
//    cout << arr[ii];
//}