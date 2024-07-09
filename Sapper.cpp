#include<iostream>
using namespace std;
int main()
{
	long long int m, n, k, x, y, q, z, v;
	int index = 0;
	cin >> m >> n >> k >> q;
	int** matr = new int* [m+2];
	for (int i = 0; i < m + 2; i++) {
		matr[i] = new int[n + 2];
	}
	for (int i = 0; i < m + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			matr[i][j] = 0;
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		matr[x][y] = 1;
	}
	for (int i = 0; i < m + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < q; i++)
	{
		cin >> z >> v;
		if (matr[z][v] == 1)              
		{
			cout << "*";
			return 0;
		}
		if (matr[z][v] != 1)
		{
			for (int j = z - 1; j <= z + 1; j++)
			{
				for (int k = v - 1; k <= v + 1; k++)
				{
					if (matr[j][k] == 1)
					{
						index++;
					}
				}
			}
			cout << index << endl;
		}
		index = 0;
	}
}
