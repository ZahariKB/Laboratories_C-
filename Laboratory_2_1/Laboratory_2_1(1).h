#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <assert.h>
using namespace std;

static bool toste = 0;

enum Alcohol_ID { Vodka_ID = 0, Beer_ID, Vino_ID, Cognac_ID };
class Alcohol {
protected:
	const int ID;
	int degree;
	bool taste;
	double volume;
	string name;
	
	Alcohol() : ID(next_id++) {}

	string Taste() const {
		if (!(this->taste)) {
			return "Невкусный!";
		}
		else {
			return  "Вкусный!";
		}
	}

	vector<string> vec{ "За любовь!", "До свидания! Трезвыми мы с вами сегодня не увидимся!", "Друзья мои, нельзя пить индивидуально, давайте будем напиваться коллективно.За великую силу коллектива!", "Пьянству – бой! Так выпьем перед боем!", "Прощай здоровье!" };

	bool tost() {
		toste = 1;
		random_shuffle(vec.begin(), vec.end());
		if (vec.size() == 0) {
			cout << "Хватит пить, остaновитесь!" << endl << endl;
			return false;
		}
		cout << "Тост: " << vec[0] << endl;
		vec.erase(vec.begin());
		return true;
	}

	friend ostream& operator<<(ostream& out, const Alcohol& x) {
		out << "Напиток: " << x.name << endl;
		out << "Градус напитка: " << x.degree << " градусов" << endl;
		out << "Вкусный или невкусный напиток: " << x.Taste() << endl;
		out << "Объём напитка: " << x.volume << " литра(ов) " << endl;
		out << "ID: " << x.ID << endl << endl;
		return out;
	}

private:
	static int next_id;

public:
	virtual int getStrength() = 0;
	virtual void addAlcohol(Alcohol* p) {
		assert(false);
	}
	virtual ~Alcohol() {}

	static Alcohol* CreateAlcohol(Alcohol_ID ide);
	
};

class CompositeAlcohol : public Alcohol
{
public:
	int getStrength() {
		int total = 0;
		for (int i = 0; i < c.size(); ++i)
			total += c[i]->getStrength();
		return total;
	}
	void addAlcohol(Alcohol* p) {
		c.push_back(p);
	}
	~CompositeAlcohol() {
		for (int i = 0; i < c.size(); ++i)
			delete c[i];
	}
private:
	vector<Alcohol*> c;
};



int Alcohol::next_id = 0;
