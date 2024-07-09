

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x, E, res = 0, f, n = 2;
	cout << "input x, E" << endl;
	cin >> x >> E;
	f = x;
	while (f > E)
	{
		res += f;
		f *= (x * x) / (n * (n + 1));
		n += 2;
	}
	cout << res << endl;
	cout << (exp(x) - exp(-1 * x)) / 2;
	return 0;
}