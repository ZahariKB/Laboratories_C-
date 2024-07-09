#pragma once
#include"Class.h"

class Vodka : public Alcohol {
private:
	int goruchest = 2;
	static int count_vodka;
public:
	Vodka();
	Vodka(const Vodka&);
	Vodka(Vodka&&) noexcept;
	~Vodka();
	Vodka& operator =(Vodka&&);
	Vodka& operator =(const Vodka&);
	bool operator ==(const Vodka&);
	double shot();
	void print();
	int Get_Count();
	virtual int getStrength() {
		return 4;
	}
	friend ostream& operator<<(ostream&, const Vodka&);
};

	//
class Beer : public Alcohol {
private:
	static int count_beer;
public:
	Beer();
	Beer(const Beer&);
	Beer(Beer&&) noexcept;
	~Beer();
	Beer& operator =(Beer&&);
	Beer& operator =(const Beer&);
	bool operator ==(const Beer&);
	void print();
	int Get_Count();
	virtual int getStrength() {
		return 1;
	}
};
	//
class Vino : public Alcohol {
private:
	static int count_vino;
	string sort = "Красное";
public:
	Vino();
	Vino(const Vino&);
	Vino(Vino&&) noexcept;
	~Vino();
	Vino& operator =(Vino&&);
	Vino& operator =(const Vino&);
	bool operator ==(const Vino&);
	void tostik();
	void print();
	int Get_Count();
	virtual int getStrength() {
		return 2;
	}
	friend ostream& operator<<(ostream&, const Vino&);
};
	//
class Cognac : public Alcohol {
private:
	static int count_cognac;
public:
	Cognac();
	Cognac(const Cognac&);
	Cognac(Cognac&&) noexcept;
	~Cognac();
	Cognac& operator =(Cognac&&);
	Cognac& operator =(const Cognac&);
	bool operator ==(const Cognac&);
	void print();
	int Get_Count();
	virtual int getStrength() {
		return 3;
	}
};



