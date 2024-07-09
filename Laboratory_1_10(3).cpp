#pragma once
#include <iostream>

using namespace std;

class List {
protected:
	struct Ocean {
		string name;
		int ploshad, temp;
		Ocean* Next;
		Ocean() {
			ploshad = 10;
			name = "Тихий";
			temp = 1;
			Next = nullptr;
		}
		Ocean(const Ocean& s) {
			name = s.name;
			ploshad = s.ploshad;
			temp = s.temp;
			Next = s.Next;
		}
	};
	Ocean* First;
	Ocean* Last;
	int index;
public:
	List();
	List(const List&);
	const List& operator = (const List&);
	virtual~List();
	int Find(string);
	bool remove_front();
	bool remove_back();
	void insert_front(const string, const int, const int);
	void insert_back(const string, const int, const int);
	void insert(int, const string, const int, const int);
	void Erase(string);
	void ForEach(void Fun(Ocean&));
	void ForEach(void Fun(const string, const int))const;
	void ListPrint() const;
	void Print(Ocean) const;
	friend void PrintPlus(List::Ocean&);
};