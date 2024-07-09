#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
int main()
{
	int i = 0, sum = 0, sum1 = 0, sum2 = 0, sum4 = 0;
	bool key4 = 0, key9 = 0, key11 = 0;
	string str;
	cin >> str;
	vector<int> arr(str.size());
	while (i < str.size())
	{
		arr[i] = stoi(string(1, str[i]));
		sum += arr[i];
		if (i % 2 == 0)
		{
			sum2 += arr[i];
		}
		else
		{
			sum1 += arr[i];
		}
		if (str.size() - 2 == i)
		{
			sum4 += arr[i] * 10;
		}
		else if (str.size() - 1 == i)
		{
			sum4 += arr[i];
		}
		i++;
	}
	if (sum4 % 4 == 0)
	{
		key4 = true;
	}
    if ((sum1 - sum2) % 11 == 0)
	{
		key11 = true;
	}
	if (sum % 9 == 0)
	{
		key9 = true;
	}
	if (key4 == true && key9 == true && key11 == true)
	{
		cout << 8;
	}
	if (key4 == false && key9 == true && key11 == true)
	{
		cout << 7;
	}
	if (key4 == true && key9 == false && key11 == true)
	{
		cout << 6;
	}
	if (key4 == true && key9 == true && key11 == false)
	{
		cout << 5;
	}
	if (key4 == false && key9 == false && key11 == true)
	{
		cout << 4;
	}
	if (key4 == false && key9 == true && key11 == false)
	{
		cout << 3;
	}
	if (key4 == true && key9 == false && key11 == false)
	{
		cout << 2;
	}
	if (key4 == false && key9 == false && key11 == false)
	{
		cout << 1;
	}
	return 0;
}