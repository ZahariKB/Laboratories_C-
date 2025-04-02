/* ||==or, && == and; */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	
    cout << "input 4 numbers";
		double x, y, a, b;
    cin >> x;
	cin >> y;
	cin >> a;
	cin >> b;

	if ((x <= a and x >= -a) and (y <= a))

	{
		cout << "na nozke";
	}
	else if ((x <= a + b) and (y >= a and y <= a + b))

	{
		cout << "na shliapke";
	}
	else if ((x > a or x < -a) or (y > a))

	{
		cout << "ne v nozke";
	}
	else if ((x > a + b) or (y > a + b))

	{
		cout << "ne na gribe";
	}
	return 0;
}

