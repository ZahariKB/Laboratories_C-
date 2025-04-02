#pragma once
#include "MAIN_CLASS.cpp"

enum Artefacts{palochka = 0, mantia, kamen};

class MagicPerson : public Person {

private:
	int max_mana;
	int present_mana;
	int amount_artefacts;
	Artefacts artefacts;
	Artefacts* arr_artefacts;
public:
	MagicPerson();
	MagicPerson(const MagicPerson&);
	MagicPerson(string, bool, Sost, Artefacts, int, int, int, Artefacts*);
	MagicPerson& operator =(const MagicPerson&);
	friend ostream& operator <<(ostream&, const MagicPerson&);
	void set_Max_mana(int);
	void set_present_mana(int);
	void set_amount_artefact(int);
	void set_artefacts(Artefacts);
	void set_arr_artefacts(Artefacts*);
	int get_Max_mana();
	int get_present_mana();
	int get_amount_artefact();
	Artefacts get_artefacts();
	Artefacts* get_arr_artefacts();
	~MagicPerson();
};