
#include <iostream>
#include <cmath>
using namespace std;


bool isProstoe(int i)
{
	bool prostoe = 1;
	for (int j = 2; j < i / 2 + 1; j++)
	{
		if (i % j == 0)
		{
			prostoe = 0;
			break;
		}
	}
	if (prostoe)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()


{
	int a, b;
	cout << "enter naturelnie a < b and b, please!" << endl;
	cin >> a >> b;
	bool prostoe = 1;
	if (a > b)
	{
		cout << "vvedite a<b, please!" << endl;
	}
	


	for (int i = a; i <= b;  i++)
	{
		if (isProstoe(i))
		{
			int n = i;
			int summ = 0;
			int d;
			while (n > 0)
			{
				d = n % 10;
				summ += d;
				n /= 10;
			}
			if (isProstoe(summ))
			{
				cout << i << endl;
			}
		}
	}

	return 0;
}
