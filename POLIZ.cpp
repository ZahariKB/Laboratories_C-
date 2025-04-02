#include <iostream>
#include <string>
#include <cstring>
#include <windows.h>
#include <exception>
struct mystack {
	int n;
	char* items;
	int top;
};
mystack st1;
void createStack(mystack& st1, int count) {
	st1.items = new char[count];
	st1.top = 0;
	st1.n = count;
}
void deleteStack(mystack& st1) {
	delete[] st1.items;
	st1.items = nullptr;
}
void push(mystack& st1, const char& k) {
	if (st1.top > st1.n - 1) {
		throw 0/*exception("Stack is full!")*/;
	}
	st1.items[st1.top++] = k;
}
char pop(mystack& st1) {
	if (st1.top == 0) {
		throw 0;/*exception ("Stack is empty!");*/
	}
	char k = st1.items[--st1.top];
	return k;
}
char top(mystack& st1) {
	if (st1.top == 0) {
		throw 0;/*exception("Stack is empty!");*/
	}
	char k = st1.items[--st1.top];
	st1.top++;
	return k;
}
bool isEmpty(mystack st1) {
	return (st1.top == 0);
}
bool isFull(mystack st1) {
	return (st1.top == st1.n - 1);
}
struct mystack1 {
	int n;
	double* items;
	int top;
};
mystack1 st;
void createStack1(mystack1& st, int count) {
	st.items = new double[count];
	st.top = 0;
	st.n = count;
}
void deleteStack1(mystack1& stack) {
	delete[] st.items;
	st.items = nullptr;
}
void push1(mystack1& st, const double& k) {
	if (st.top > st.n - 1) {
		throw  "Stack is full!";
	}
	st.items[st.top++] = k;
}
double pop1(mystack1& st) {
	if (st.top == 0) {
		throw "Stack is empty!";
	}
	double k = st.items[--st.top];
	return k;
}
bool isEmpty1(mystack1 st) {
	return (st.top == 0);
}
bool op(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}
int priority(char c)
{
	if (c == '+' || c == '-') return 1;
	else if (c == '*' || c == '/') return 2;
	else
		return 0;
}
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char buf;
	double temp = 0, res = 0;
	int len, count1 = 0, count2 = 0;
	bool v = 0, t = 0;
	double  a = 10, b = 34, c = -10, d = 32, e = 5, f = 0, j = -3, g = -12, h = 4, k = 43, l = -22;
	string s;
	string polis;
	string check = { "abcdefghkl+-/*()" };
	string let = { "abcdefghkl" };
	cout << "Введите выражение без пробелов, используя символы 'abcdefghkl+-/*()' " << endl;
	getline(cin, s);
	len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] == '(')
			count1++;
		if (s[i] == ')')
			count2++;
		if (count2 > count1) {
			v = 1;
			break;
		}
		if (let.find_first_of(s[i]) != -1 && let.find_first_of(s[i + 1]) != -1) {
			t = 1;
			break;
		}
	}
	if (count1 != count2)
		v = 1;
	while ((s.find_first_not_of(check) != -1) || v || t || s.length() == 0) {
		cout << "Ошибка ввода данных, повторите попытку" << endl;
		getline(cin, s);
		len = s.length();
		v = 0;
		t = 0;
		count1 = 0;
		count2 = 0;
		for (int i = 0; i < len; i++) {
			if (s[i] == '(')
				count1++;
			if (s[i] == ')')
				count2++;
			if (count2 > count1) {
				v = 1;
				break;
			}
			if (let.find_first_of(s[i]) != -1 && let.find_first_of(s[i + 1]) != -1) {
				t = 1;
				break;
			}
		}
		if (count1 != count2)
			v = 1;
	}
	len = s.length();
	mystack stack1;
	createStack(stack1, len);
	/*cout << "Нажмите 1, если хотите ввести значения переменных сами, или 0, если хотите получить выражения для предустановленных значений переменных (a = 10, b = 34, c = -10, d = 32, e = 5, f = 34, j = -3, g = -12, h = 4, k = 43, l = -22)" << endl;
	cin >> fl;
	if (fl) {
		cin >> a >> b >> c >> d >> e >> f >> j >> g >> h >> k >> l;
	}*/
	cout << "Выражение в виде польской инверсной записи:" << endl;
	try {
		for (int i = 0; i < len; i++) {
			switch (s[i]) {
			case '(': push(stack1, s[i]); break;
			case ')': {
				while (!isEmpty(stack1) && top(stack1) != '(') {

					buf = top(stack1);
					cout << buf;
					polis += buf;
					pop(stack1);


				}

				pop(stack1);


				break;
			}
			case '+':
			case '-':
			case '*':
			case '/': {
				while (!isEmpty(stack1) && (priority(top(stack1)) >= priority(s[i]))/*priority(st.top()) >= priority(s[i])*/)
				{
					cout << top(stack1);
					polis += top(stack1);
					pop(stack1);

				}
				push(stack1, s[i]);

				break;
			}
			default: {
				cout << s[i];
				polis += s[i];
			}
			}
		}
		while (!isEmpty(stack1)) {
			buf = top(stack1);
			cout << buf;
			polis += buf;
			pop(stack1);
		}
	}
	catch (/*const exception& e*/...) {
		cerr << "Неправильный формат выражения" << endl;
		return -1;
	}
	cout << endl;
	len = polis.length();
	mystack1 stack2;
	createStack1(stack2, len);
	cout << "Результат выражения:" << endl;
	try {
		for (int i = 0; i < len; i++) {
			switch (polis[i]) {
			case '+': {
				temp = pop1(stack2);
				res = pop1(stack2) + temp;
				push1(stack2, res);
				break;
			}
			case '-': {  temp = pop1(stack2);
				res = pop1(stack2) - temp;
				push1(stack2, res);
				break;
			}
			case '*': {  temp = pop1(stack2);
				res = pop1(stack2) * temp;
				push1(stack2, res);
				break;
			}
			case '/': {
				temp = pop1(stack2);
				if (static_cast<int> (temp) == 0) {
					cout << "Ошибка: деление на ноль";
					return -1;
				}
				res = pop1(stack2) / temp;
				push1(stack2, res);
				break;
			}
			case 'a': {push1(stack2, a); break; }
			case 'b': {push1(stack2, b); break; }
			case 'c': {push1(stack2, c); break; }
			case 'd': {push1(stack2, d); break; }
			case 'e': {push1(stack2, e); break; }
			case 'f': {push1(stack2, f); break; }
			case 'g': {push1(stack2, g); break; }
			case 'h': {push1(stack2, h); break; }
			case 'j': {push1(stack2, j); break; }
			case 'k': {push1(stack2, k); break; }
			case 'l': {push1(stack2, l); break; }


			}
		}
	}
	catch (...) {
		cerr << "Ошибка, неверный формат выражения";
		return -1;
	}
	cout << pop1(stack2);
	deleteStack(stack1);
	deleteStack1(stack2);
	return 0;
}