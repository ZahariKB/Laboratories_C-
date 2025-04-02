#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	const int SIZE1 = 100000;
	long long int arr[SIZE1];
	long long int N, k, sum = 0, sum2 = 0;
	cin >> N;
	long long int j = N - 1;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	cin >> k;
	sort(arr, arr + N);
	for (int i = 0; i < N - 2; i++)
	{
		int l = i + 1;
		j = N - 1;
		sum = arr[i];
		sum += arr[l];
		sum += arr[j];
		
		while (j-1 != l)
		{
			    if (sum >= sum2 && sum <= k)
			    {
					sum2 = sum;
			    }
				if (sum < k)
				{
					sum -= arr[l];
					l++;
					sum += arr[l];
				}

				else if (sum > k)
				{
					sum -= arr[j];
					j--;
					sum += arr[j];
				}

				else if (sum == k)
				{
					cout << k;
					return 0;
				}
		}
		if (sum2 <= sum && sum <= k)
		{
			sum2 = sum;
		}
	}
	if (sum2 <= sum && sum <= k)
	{
		sum2 = sum;
	}
		cout << sum2;
		return 0;
}
