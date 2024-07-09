#pragma once
#include "tree.cpp"

class Lesnoe_tree : public Tree {
private:
	int amount_of_drevesina;

public:
	Lesnoe_tree();
	Lesnoe_tree(const Lesnoe_tree&);
	Lesnoe_tree& operator =(const Lesnoe_tree&);
	Lesnoe_tree(int, string, Type, int);
	void print() override;
	Type get_type() override;
	string get_of_name() override;
	int get_of_age() override;
	/*void set_of_type(int help) override;*/
};


class Plodovoe_tree : public Tree {
private:
	int average_days_hranenia;

public:
	Plodovoe_tree();
	Plodovoe_tree(const Plodovoe_tree&);
	Plodovoe_tree& operator =(const Plodovoe_tree&);
	Plodovoe_tree(int, string, Type, int);
	void print() override;
	Type get_type() override;
	string get_of_name() override;
	int get_of_age() override;
	/*void set_of_type(int help) override;*/
};