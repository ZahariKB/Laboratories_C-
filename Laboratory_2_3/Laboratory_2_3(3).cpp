#pragma once
#include <string>
using namespace std;

enum Type {listovoe = 0, hvoinoe};

class Tree {
protected:
	string name_of_tree;
	int age_of_tree;
	Type type_of_tree;
	
public:
	/*virtual void set_of_type(int help) = 0;*/
	virtual void print() = 0;
	virtual Type get_type() = 0;
	/*virtual ~Tree() {};*/
	virtual string get_of_name() = 0;
	virtual int get_of_age() = 0;
};