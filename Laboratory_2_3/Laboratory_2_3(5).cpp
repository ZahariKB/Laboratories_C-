#include <iostream>
#include <fstream>
#include "Lesnoe&plodovoe.h"
#include "vector_trees.cpp"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/
	
	int listovoe_2, hvoi;
	int les, plod;
	int amount_of_elements, age_of_tree_2, type, other_parametr;
	string type_of_class, name_of_tree_2;
	container_of_vector v1;
	
	ifstream input("help_2.txt");
	input >> amount_of_elements;         //количество элементов в векторе
	
	for (int i = 0; i < amount_of_elements; i++) {
		input >> type_of_class >> name_of_tree_2 >> age_of_tree_2 >> type >> other_parametr;
		if (type_of_class == "Plodovoe_tree")
		{
			if (type == 0) {
				v1.push_tree(new Plodovoe_tree(age_of_tree_2, name_of_tree_2, listovoe, other_parametr));      
			} 
			else if (type == 1) {
				v1.push_tree(new Plodovoe_tree(age_of_tree_2, name_of_tree_2, hvoinoe, other_parametr));
			}
		}
		else if (type_of_class == "Lesnoe_tree") {
			if (type == 0) {
				v1.push_tree(new Lesnoe_tree(age_of_tree_2, name_of_tree_2, listovoe, other_parametr));
			}
			else if (type == 1) {
				v1.push_tree(new Lesnoe_tree(age_of_tree_2, name_of_tree_2, hvoinoe, other_parametr));
			}
		}
	}


	/*Lesnoe_tree tree_1(234, "Ель", hvoinoe), tree_4(190, "Пихта", hvoinoe), tree_3(191, "Сосна", hvoinoe);
	Plodovoe_tree tree_2(23, "Дубик", listovoe);*/
	/*v1.push_tree(&tree_1);
	v1.push_tree(&tree_2);
	v1.push_tree(&tree_3);
	v1.push_tree(&tree_4);*/


	cout << "Вектор деревьев:" << endl << endl;
	v1.print_trees();
	//
	cout << "Количество хвойных деревьев в векторе: " << endl;
	hvoi = v1.get_of_index_of_hvoinoe();
	cout << hvoi << endl;
	//
	cout << "Количество листовых деревьев в векторе: " << endl;
	listovoe_2 = v1.get_of_index_of_listvennoe();
	cout << listovoe_2 << endl;
	//
	cout << "Количество лесных деревьев: " << endl;
	les = v1.get_of_index_of_les();
	cout << les << endl;
	//
	cout << "Количество плодовых деревьев: " << endl;
	plod = v1.get_of_index_of_plod();
	cout << plod << endl;

	cout << endl << endl;
	
	cout << "Вектор деревьев после сортировки по имени (если равны,то по размеру): " << endl << endl;
	v1.sortTrees();
	v1.print_trees();
	
	input.close();
	return 0;
}


