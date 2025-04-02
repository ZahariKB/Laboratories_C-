#pragma once
#include"Header.h"
using namespace std;

Vodka::Vodka() {
	name = "�����";
	degree = 45;
	taste = 0;
	volume = 0.7;
	count_vodka++;
}

Vodka::Vodka(const Vodka& v) {
	this->name = v.name;
	this->degree = v.degree;
	this->taste = v.taste;
	this->volume = v.volume;
	cout << " ������� ����������� �����������" << endl;
}

Vodka::Vodka(Vodka&& other) noexcept {
	this->name = other.name;
	this->degree = other.degree;
	this->taste = other.taste;
	this->volume = other.volume;
	cout << "��������� ����������� �����������" << endl;
}

Vodka::~Vodka() {

	count_vodka--;
}

bool Vodka::operator ==(const Vodka& other) {
	if (degree != other.degree || taste != other.taste || volume != other.volume || name != other.name) {
		return false;
	}
	return true;
}

Vodka& Vodka::operator =(Vodka&& other) {
	if (this != &other) {
		name = other.name;
		degree = other.degree;
		taste = other.taste;
		volume = other.volume;
		cout << "��������� ����������� ������������" << endl;
	}
	return *this;
}

Vodka& Vodka::operator =(const Vodka& other) {
	if (this != &other) {
		name = other.name;
		degree = other.degree;
		taste = other.taste;
		volume = other.volume;
		cout << "������ ������������" << endl;
	}
	return *this;
}

double Vodka::shot() {
	static int index;
	if (toste == 1) {
		if (this->volume <= 0) {
			cout << "����� ������ ���!" << endl;
			return 0;
		}
		else {
			index++;
			this->volume -= 0.05;
			if (this->volume < 0.00001) {
				this->volume = 0;
			}
			cout << "����� ����� " << index << " ����: " << volume << endl << endl;
		}
	}
	else {
		cout << "������� ���� - ����� ���!" << endl;
	}
	toste = 0;
	return volume;
}

ostream& operator<<(ostream& out, const Vodka& x) {
	out << "�������: " << x.name << endl;
	out << "��������� �����: " << x.goruchest << endl;
	out << "������ �������: " << x.degree << endl;
	out << "������� ��� ��������� �������: " << x.Taste() << endl;
	out << "����� �������: " << x.volume << " �����(��) " << endl;
	out << "ID: " << x.ID << endl << endl;
	return out;
}

void Vodka::print() {

	cout << "�������: " << name << endl;
	cout << "��������� �����: " << goruchest << endl;
	cout << "������ �������: " << degree << " ��������" << endl;
	cout << "������� ��� ��������� �������: " << Taste() << endl;
	cout << "����� �������: " << volume << " �����(��) " << endl;
	cout << "ID: " << ID << endl;
	cout << "���������� ��������� �������� ������ '�����': " << count_vodka << endl << endl;
}

int Vodka::Get_Count() {
	return count_vodka;
}
//
Beer::Beer() {
	name = "����";
	degree = 6;
	taste = 1;
	volume = 0.33;
	count_beer++;
}

Beer::Beer(const Beer& b) {
	this->name = b.name;
	this->degree = b.degree;
	this->taste = b.taste;
	this->volume = b.volume;
	cout << " ������� ����������� �����������" << endl;
}

Beer::Beer(Beer&& b) noexcept {
	this->name = b.name;
	this->degree = b.degree;
	this->taste = b.taste;
	this->volume = b.volume;
	cout << "��������� ����������� �����������" << endl;
}

Beer::~Beer() {

	count_beer--;
}

bool Beer::operator ==(const Beer& other) {
	if (degree != other.degree || taste != other.taste || volume != other.volume || name != other.name) {
		return false;
	}
	return true;
}

Beer& Beer::operator =(Beer&& other) {
	if (this != &other) {
		name = other.name;
		degree = other.degree;
		taste = other.taste;
		volume = other.volume;
		cout << "��������� ����������� ������������" << endl;
	}
	return *this;
}

Beer& Beer::operator =(const Beer& other) {
	if (this != &other) {
		name = other.name;
		degree = other.degree;
		taste = other.taste;
		volume = other.volume;
		cout << "������ ������������" << endl;
	}
	return *this;
}

void Beer::print() {
	cout << "�������: " << name << endl;
	cout << "������ �������: " << degree << " ��������" << endl;
	cout << "������� ��� ��������� �������: " << Taste() << endl;
	cout << "����� �������: " << volume << " �����(��) " << endl;
	cout << "ID: " << ID << endl;
	cout << "���������� ��������� �������� ������ '����': " << count_beer << endl << endl;
}

int Beer::Get_Count() {
	return count_beer;
}
//
Vino::Vino() {
	name = "����";
	degree = 15;
	taste = 1;
	volume = 0.5;
	count_vino++;
}

Vino::Vino(const Vino& vi) {
	this->name = vi.name;
	this->degree = vi.degree;
	this->taste = vi.taste;
	this->volume = vi.volume;
	cout << "������� ����������� �����������" << endl;
}

Vino::Vino(Vino&& vi) noexcept {
	this->name = vi.name;
	this->degree = vi.degree;
	this->taste = vi.taste;
	this->volume = vi.volume;
	cout << "��������� ����������� �����������" << endl;
}

Vino::~Vino() {

	count_vino--;
}

bool Vino::operator ==(const Vino& other) {
	if (degree != other.degree || taste != other.taste || volume != other.volume || name != other.name) {
		return false;
	}
	return true;
}

Vino& Vino::operator =(Vino&& other) {
	if (this != &other) {
		name = other.name;
		degree = other.degree;
		taste = other.taste;
		volume = other.volume;
		cout << "��������� ����������� ������������" << endl;
	}
	return *this;
}

Vino& Vino::operator =(const Vino& other) {
	if (this != &other) {
		name = other.name;
		degree = other.degree;
		taste = other.taste;
		volume = other.volume;
		cout << "������ ������������" << endl;
	}
	return *this;
}
void Vino::tostik() {
	tost();
}

ostream& operator<<(ostream& out, const Vino& x) {
	out << "�������: " << x.name << endl;
	out << "���� ����: " << x.sort << endl;
	out << "������ �������: " << x.degree << endl;
	out << "������� ��� ��������� �������: " << x.Taste() << endl;
	out << "����� �������: " << x.volume << " �����(��) " << endl;
	out << "ID: " << x.ID << endl << endl;
	return out;
}

void Vino::print() {
	cout << "�������: " << name << endl;
	cout << "C��� ����: " << sort << endl;
	cout << "������ �������: " << degree << " ��������" << endl;
	cout << "������� ��� ��������� �������: " << Taste() << endl;
	cout << "����� �������: " << volume << " �����(��) " << endl;
	cout << "ID: " << ID << endl;
	cout << "���������� ��������� �������� ������ '����': " << count_vino << endl << endl;
}

int Vino::Get_Count() {
	return count_vino;
}
//
Cognac::Cognac() {
	name = "������";
	degree = 40;
	taste = 0;
	volume = 0.5;
	count_cognac++;
}

Cognac::Cognac(const Cognac& c) {
	this->name = c.name;
	this->degree = c.degree;
	this->taste = c.taste;
	this->volume = c.volume;
}

Cognac::Cognac(Cognac&& c) noexcept {
	this->name = c.name;
	this->degree = c.degree;
	this->taste = c.taste;
	this->volume = c.volume;
	cout << "��������� ����������� �����������" << endl;
}

Cognac::~Cognac() {

	count_cognac--;
}

bool Cognac::operator ==(const Cognac& other) {
	if (degree != other.degree || taste != other.taste || volume != other.volume || name != other.name) {
		return false;
	}
	return true;
}

Cognac& Cognac::operator =(Cognac&& other) {
	if (this != &other) {
		name = other.name;
		degree = other.degree;
		taste = other.taste;
		volume = other.volume;
		cout << "��������� ����������� ������������" << endl;
	}
	return *this;
}

Cognac& Cognac::operator =(const Cognac& other) {
	if (this != &other) {
		name = other.name;
		degree = other.degree;
		taste = other.taste;
		volume = other.volume;
		cout << "������ ������������" << endl;
	}
	return *this;
}

void Cognac::print() {
	cout << "�������: " << name << endl;
	cout << "������ �������: " << degree << " ��������" << endl;
	cout << "������� ��� ��������� �������: " << Taste() << endl;
	cout << "����� �������: " << volume << " �����(��) " << endl;
	cout << "ID: " << ID << endl;
	cout << "���������� ��������� �������� ������ '������': " << count_cognac << endl << endl;
}
//
/*Alcohol* Alcohol::CreateAlcohol(Alcohol_ID id)
{
	Alcohol* p = nullptr;
	switch (id)
	{
	case Vodka_ID:
		p = new Vodka();
		break;
	case Beer_ID:
		p = new Beer();
		break;
	case Vino_ID:
		p = new Vino();
		break;
	case Cognac_ID:
		p = new Cognac();
		break;
	default:
		assert(false);
	}
	return p;
}*/
//
int Cognac::Get_Count() {
	return count_cognac;
}
//

//
int Vodka::count_vodka = 0;
int Beer::count_beer = 0;
int Vino::count_vino = 0;
int Cognac::count_cognac = 0;




