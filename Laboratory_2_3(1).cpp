#pragma once
#include <iostream>
#include "Lesnoe&plodovoe.h"
using namespace std;

Lesnoe_tree::Lesnoe_tree()  {
	amount_of_drevesina = 200;
	age_of_tree = 20;
	name_of_tree = "Пихта";
	type_of_tree = hvoinoe;
}

Lesnoe_tree::Lesnoe_tree(const Lesnoe_tree& other) {
	this->age_of_tree = other.age_of_tree;
	this->amount_of_drevesina = other.amount_of_drevesina;
	this->name_of_tree = other.name_of_tree;
	this->type_of_tree = other.type_of_tree;
}

Lesnoe_tree& Lesnoe_tree::operator =(const Lesnoe_tree& other) {
	if (this != &other) {
		this->age_of_tree = other.age_of_tree;
		this->amount_of_drevesina = other.amount_of_drevesina;
		this->name_of_tree = other.name_of_tree;
		this->type_of_tree = other.type_of_tree;
	}
	return *this;
}

Lesnoe_tree::Lesnoe_tree(int age_of_tree, string name_of_tree, Type type_of_tree, int amount_of_drevesina) {
	this->age_of_tree = age_of_tree;
	this->name_of_tree = name_of_tree;
	this->type_of_tree = type_of_tree;
	this->amount_of_drevesina = amount_of_drevesina;
}

Plodovoe_tree::Plodovoe_tree()  {
	name_of_tree = "Груша";
	age_of_tree = 5;
	type_of_tree = listovoe;
	average_days_hranenia = 60;
}

Plodovoe_tree::Plodovoe_tree(const Plodovoe_tree& other) {
	this->age_of_tree = other.age_of_tree;
	this->average_days_hranenia = other.average_days_hranenia;
	this->name_of_tree = other.name_of_tree;
	this->type_of_tree = other.type_of_tree;
}

Plodovoe_tree& Plodovoe_tree::operator =(const Plodovoe_tree& other) {
	if (this != &other) {
		this->age_of_tree = other.age_of_tree;
		this->average_days_hranenia = other.average_days_hranenia;
		this->name_of_tree = other.name_of_tree;
		this->type_of_tree = other.type_of_tree;
	}
	return *this;
}

Plodovoe_tree::Plodovoe_tree(int age_of_tree, string name_of_tree, Type type_of_tree, int average_days_hranenia) {
	this->age_of_tree = age_of_tree;
	this->name_of_tree = name_of_tree;
	this->type_of_tree = type_of_tree;
	this->average_days_hranenia = average_days_hranenia;
}

void Lesnoe_tree::print() {
	string help_2 = "";
	switch (type_of_tree) {
	case listovoe:
		help_2 = "Листовое";
		break;
	case hvoinoe:
		help_2 = "Хвойное";
		break;
	default:
		break;
	}
	cout << "Лесное дерево: " << "\n";
	cout << "Название дерева: " << name_of_tree << endl;
	cout << "Возраст дерева: " << age_of_tree << " года(лет)" << endl;
	cout << "Тип дерева: " << help_2 << endl;
	cout << "Количество древесины: " << amount_of_drevesina << " кубов" << endl << endl;
}

void Plodovoe_tree::print()  {
	string help_3 = "";
	switch (type_of_tree) {
	case listovoe:
		help_3 = "Листовое";
		break;
	case hvoinoe:
		help_3 = "Хвойное";
		break;
	default:
		break;
	}
	cout << "Плодовое дерево: " << "\n";
	cout << "Название дерева: " << name_of_tree << endl;
	cout << "Возраст дерева: " << age_of_tree << " года(лет)" << endl;
	cout << "Тип дерева: " << help_3 << endl;
	cout << "Средняя продолжительность хранения: " << average_days_hranenia << " дней(дня)" << endl << endl;
}

Type Lesnoe_tree::get_type() {
	return type_of_tree;
}

Type Plodovoe_tree::get_type() {
	return type_of_tree;
}

string Lesnoe_tree::get_of_name() {
	return name_of_tree;
}

string Plodovoe_tree::get_of_name() {
	return name_of_tree;
}

int Lesnoe_tree::get_of_age() {
	return age_of_tree;
}

int Plodovoe_tree::get_of_age() {
	return age_of_tree;
}

//void Lesnoe_tree::set_of_type(int help) {
//	switch (help)
//	{
//	case 0:
//		type_of_tree = listovoe;
//		break;
//	case 1:
//		type_of_tree = hvoinoe;
//		break;
//	default:
//		break;
//	}
//}

//void Plodovoe_tree::set_of_type(int help) {
//	switch (help)
//	{
//	case 0:
//		type_of_tree = listovoe;
//		break;
//	case 1:
//		type_of_tree = hvoinoe;
//		break;
//	default:
//		break;
//	}
//}

