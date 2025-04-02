#include<iostream>
#include"header.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "russian");
	try {
		Money cash(4, 5, 5.75);
		cout << cash;
		Money money1, money2(7,14,11);
		cout << money1;
		Money cash1(1, 4, 8);
		cout << (cash1 + cash) << endl;
		cout << cash1 - cash << endl;
		cout << money2;
		money2 += cash1;
		cout << money2;
		money2 -= cash1;
		cout << money2;
		cout << (money2 < cash) << endl;
		cout << (money2 == cash) << endl;
		money2 = cash;
		cout << (money2 == cash) << endl;
		Money cash3(23, 21, 5.75);
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
		return -1;
	}



}