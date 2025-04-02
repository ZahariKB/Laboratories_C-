#include<iostream>

using namespace std;

//bool isPrime(int i&)
//{
//	if (n <= 1) {
//		return false;
//	}
//	for (int i = 2; i * i <= n; i++) {
//		if (n % i == 0) {
//			return false;
//		}
//	}
//	return true;
//}

bool isPrime(int n)
{
	int key = 0;
	key = 0;
	for (int k = 1; k < n; k++)
	{
		if (n % k == 0)
		{
			key++;
		}
	}
	if (key >= 2)
	{
		return false;
	}
	return true;
}
int main()
{
	long long int x, chislo1 = 1, chislo2 = 1;
	cin >> x;
	for (int i = 1; i < 54; i++)
	{
		if (isPrime(i))
		{
			chislo1 *= i;
			
		}
		for (int j = 1; j < 54; j++)
		{
			if (isPrime(j))
			{
				chislo2 *= j;
			}
			if (x == chislo2 - chislo1)
			{
				cout << j << " " << i;
				return 0;
			}
		}
		
		chislo2 = 1;
		
	}
}