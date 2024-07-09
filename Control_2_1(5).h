#pragma once
#include<string>
#include<iostream>
using namespace std;

enum Amplua { tragic = 0, komik, travesti, injenu };

class Actor {
protected:
	const int id;
	const int year_of_birth;
	static int next_id;
	static int amount_actors;
	string surname;
	Amplua amplua;
public:
	Actor() = delete;
	Actor(const string&, Amplua);
	Actor& operator =(const Actor&);
	Actor& operator=(Actor&&) noexcept;
	Actor(Actor&&) noexcept;
	bool operator ==(const Amplua&);
	friend ostream& operator<<(ostream&, const Actor&);
	void set_surname(string);
	void set_amplua(Amplua);
	string get_surname();
	Amplua get_amplua();
	~Actor();
};
