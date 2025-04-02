#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	long long N, k, index = 0, min1 = 10000;
	cin >> N >> k;
	vector<long long> arr(N);
	vector<long long> arr2;
	for (long long i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	for (long long i = 0; i < N; i++)
	{
		long long j = i;
		while (j < N && arr[i] == arr[j])
		{
			j++;
		}
		if (j - i == k) {
			arr2.push_back(arr[i]);
			index++;
		}
		i = j - 1;
	}

	if (index != 0)
	{
		sort(arr2.begin(), arr2.end());
		cout << index << " " << arr2[0];
	}
	else
	{
		cout << 0 << " " << arr[0];
		return 0;
	}
}

