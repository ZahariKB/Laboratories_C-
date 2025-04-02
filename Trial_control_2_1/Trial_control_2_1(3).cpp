#include "Metodi.h"
#include <assert.h>

MagicPerson::MagicPerson() {
	max_mana = 500;
	present_mana = 100;
	amount_artefacts = 1;
	artefacts = palochka;
}

MagicPerson::MagicPerson(string name, bool move, Sost sostoianie, Artefacts artefacts, int max_mana, int present_mana, int amount_artefacts, Artefacts* arr_artefacts) : Person(name, move, sostoianie) {
		if (max_mana > 500) {
			throw exception("ÌÀÊÑÈÌÀËÜÍÀß ÌÀÍÀ ÂÂÅÄÅÍÀ ÍÅÂÅĞÍÎ!");
		}
		else {
			this->max_mana = max_mana;
		}
		if (present_mana > max_mana || present_mana < 0 || present_mana < 1) {
			throw exception("ÌÀÍÀ ÂÂÅÄÅÍÀ ÍÅÂÅĞÍÎ");
		}
		else {
			this->present_mana = present_mana;
		}

		if (amount_artefacts > 1) {
			throw exception("ÊÎËÈ×ÅÑÒÂÎ ÀĞÒÅÔÀÊÒÎÂ ÂÂÅÄÅÍÎ ÍÅÂÅĞÍÎ");
		}
		else {
			this->amount_artefacts = amount_artefacts;
		}
		this->artefacts = artefacts;

		Artefacts* arr2_artefacts = new Artefacts[amount_artefacts];
		for (int i = 0; i < amount_artefacts; ++i) {
			arr2_artefacts[i] = arr_artefacts[i];
		}
		this->arr_artefacts = arr2_artefacts;
}

MagicPerson::MagicPerson(const MagicPerson& pers) {
	this->artefacts = pers.artefacts;
	this->max_mana = pers.max_mana;
	this->present_mana = pers.present_mana;
	this->amount_artefacts = pers.amount_artefacts;
	this->name = pers.name;
	this->move = pers.move;
	this->sostoianie = pers.sostoianie;
	this->next_id = pers.next_id;
	this->arr_artefacts = new Artefacts[this->amount_artefacts];
	for (int i = 0; i < pers.amount_artefacts; ++i) {
		this->arr_artefacts[i] = pers.arr_artefacts[i];
	}
}

MagicPerson& MagicPerson::operator =(const MagicPerson& pers) {
	{
		if (this != &pers) {
			this->artefacts = pers.artefacts;
			this->max_mana = pers.max_mana;
			this->present_mana = pers.present_mana;
			this->amount_artefacts = pers.amount_artefacts;
			this->name = pers.name;
			this->move = pers.move;
			this->sostoianie = pers.sostoianie;
			this->next_id = pers.next_id;
			delete[] this->arr_artefacts;
		    this->arr_artefacts = new Artefacts[pers.amount_artefacts];  
			for (int i = 0; i < pers.amount_artefacts; ++i) {
				this->arr_artefacts[i] = pers.arr_artefacts[i];
			}
		}
		return *this;
	}
}

ostream& operator <<(ostream& out, const MagicPerson& pers)  {
	string vano;
	string vanyalo, realn;

	switch (pers.rase) {
	case man:
		vanyalo = "×åëîâåê";
		break;
	case gnom:
		vanyalo = "Ãíîìèê";
		break;
	case elf:
		vanyalo = "İëüô";
		break;
	}

	switch (pers.sostoianie) {
	case norm:
		realn = "Íîğìàëüíîå";
		break;
	case paraliz:
		realn = "Ïàğàëèçîâàí";
		break;
	case mertv:
		realn = "Ì¸ğòâ";
		break;
	}

	switch (pers.artefacts) {
	case palochka:
		vano = "Ïàëî÷êà";
		break;
	case mantia:
		vano = "Ìàíòèÿ";
		break;
	case kamen:
		vano = "Êàìåíü";
		break;
	default:
		assert(false);
	}
	int index = 1;
	out << "Ğàñà ïåğñîíàæà: " << vanyalo << endl;
	out << "Èìÿ ïåğñîíàæà: " << pers.name << endl;
	out << "Ñîñòîÿíèå ïåğñîíàæà: " << realn << endl;
	out << "Ìîæåò äâèãàòüñÿ èëè íåò: " << pers.move << endl;
	out << "ID ïåğñîíàæà: " << pers.id << endl;
	out << "Ìàêñèìàëüíàÿ ìàíà: " << pers.max_mana << endl;
	out << "Òåêóùàÿ ìàíà: " << pers.present_mana << endl;
	out << "Êîëè÷åñòâî àğòåôàêòîâ: " << pers.amount_artefacts << endl;
	out << "Âàø àğòåôàêò: " << vano << endl;
	/*for (int i = 0; i < pers.amount_artefacts; ++i) {
		out << index << "-ûé Àğòåôàêò â ìàññèâå: " << pers.arr_artefacts << endl;
		index++;
 	}*/
	return out;
}

void MagicPerson::set_Max_mana(int max_mana) {
	this->max_mana = max_mana;
}

void MagicPerson::set_present_mana(int present_mana) {
	this->present_mana = present_mana;
}

void MagicPerson::set_amount_artefact(int amount_artefacts) {
	this->amount_artefacts = amount_artefacts;
}

void MagicPerson::set_artefacts(Artefacts artefacts) {
	this->artefacts = artefacts;
}

void MagicPerson::set_arr_artefacts(Artefacts* arr) {
	this->arr_artefacts = arr;
}

int MagicPerson::get_Max_mana() {
	return max_mana;
}

int MagicPerson::get_present_mana() {
	return present_mana;
}

int MagicPerson::get_amount_artefact() {
	return amount_artefacts;
}

Artefacts MagicPerson::get_artefacts() {
	return artefacts;
}

Artefacts* MagicPerson::get_arr_artefacts() {
	return arr_artefacts;
}

MagicPerson::~MagicPerson() {
	delete arr_artefacts;
}
