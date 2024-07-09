#include <iostream>
#include<ctime>
using namespace std;

void Min_Array(double array[], int n, int index)
{
    double min1 = 1.79769e+308;
    double max1 = -1.79769e+308;
    for (int i = n - 1; i >= 0; i--)
    {
        if (array[i] < min1)
        {
            min1 = array[i];
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (array[i] == min1)
        {
            index++;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (array[i] > max1)
        {
            max1 = array[i];
            break;
        }
    }
    if (index == 1)
    {
        cout << "Минимальное значение массива = " << min1;
    }
    if (index != 1)
    {
        cout << "Максимальное значение массива = " << max1;

    }
}

double Sum_Elements(double array[], int n)
{
    double sum = 0;
    int l1 = -1;
    int l2 = -1;
    for (int i = 0; i < n; i++)
    {
        if (array[i] > 0)
        {
            l1 = i;
            break;
        }
    }
    for (int i = n - 1; i > -1; i--)
    {
        if (array[i] > 0)
        {
            l2 = i;
            break;
        }
    }
    if (l1 < 0 || l2 < 0)
    {
        cout << endl << "Нет положительных чисел!" << endl;
        return 0;
    }
    if (l1 == l2)
    {
        return 0;
    }
    for (int i = l1; i < l2; i++)
    {
        sum += array[i];
    }
    return sum - array[l1];
}
int Converted_Array(double array[], int n, double x)
{

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] > x || array[i] < -x)
        {
            for (int j = i; j > k; j--)
            {
                swap(array[j], array[j - 1]);
            }
            k++;
        }

    }
    return 0;
}
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    const int SIZE = 1000;
    double array[SIZE];
    int n, a, b, p;
    int index = 0;
    double x;
    cout << " Введите кол-во элементов в массиве, не превышающий 1000" << endl;
    cin >> n;
    if (n < 1 or n > SIZE)
    {
        cerr << "Ошибка!" << endl;
        return 0;
    }
    cout << "Выберите способ заполнения массива: 1 - вручную. 2 - рандомно." << endl;
    cin >> p;
    if (p == 1)
    {
        cout << "Введите элементы массива!" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }
    }
    else if (p == 2)
    {
        cout << "Введите границы массива!" << endl;
        cin >> a >> b;
        if (a >= b)
        {
            cerr << "Ошибка!" << endl;
        }
        double left_num, right_num;
        for (int i = 0; i < n; i++)
        {
            left_num = rand() % (b - a) + a;
            right_num = rand();
            while (right_num > 1)
            {
                right_num *= 0.1;
            }
            array[i] = right_num + left_num;
        }
        for (int i = 0; i < n; i++)
        {
            cout << array[i] << endl;
        }
    }
    else
    {
        cerr << "Ошибка!" << endl;
        return 0;
    }

    Min_Array(array, n, index);

    cout << endl << "Сумма элементов, находящихся между первым и последним положительными элементами = " << Sum_Elements(array, n) << endl;
    cout << " Введите х!" << endl;
    cin >> x;
    Converted_Array(array, n, x);
    cout << " Вывод преобразованного массива, в котором элементы, превосходящие по модулю х, стоят в начале массива: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << endl;
    }
}
