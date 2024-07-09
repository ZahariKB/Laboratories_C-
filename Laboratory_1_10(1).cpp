#include "Class.cpp"
#include <iostream>

using namespace std;

void Print(const string name, const int ploshad, const int temp) {
	cout << " Имя: " << name << " - Площадь: " << ploshad << endl;
	cout << " Имя: " << name << " - Температура: " << temp << endl;
}

void PrintPlus(List::Ocean& O) {
	O.temp += 3;
	cout << " Имя: " << O.name << " - Площадь: " << O.ploshad << endl;
	cout << " Имя: " << O.name << " - Температура: " << O.temp << endl;
}

int main()
{
	setlocale(LC_ALL, "russian");
	try
	{
		setlocale(LC_ALL, ".1251");


		List L;
		L.ListPrint();
		cout << endl;
		cout << "Добавление Тихого океана в начало списка: " << endl;
		L.insert_front("Тихий океан", 179, 19);
		L.ListPrint();
		cout << endl;
		cout << "Добавление Атлантического океана в конец списка: " << endl;
		L.insert_back("Атлантический океан", 92, 17);
		L.ListPrint();
		cout << endl;
		cout << "Добавление Северно-ледовитого океана в начало списка: " << endl;
		L.insert_front("Северно-Ледовитый океан", 14, 1);
		L.ListPrint();
		cout << endl;
		cout << "Добавление Индийского океана в конец списка: " << endl;
		L.insert_back("Индийский океан", 76, 17);
		L.ListPrint();
		cout << endl;
		cout << "Увеличение температуры на три градуса:" << endl;
		L.ForEach(PrintPlus);
		cout << endl;
		cout << "Увеличение температуры на три градуса:" << endl;
		L.ListPrint();
		cout << endl;
		cout << "Список L, после добавления Южного океана после Северно-Ледовитого океана:" << endl;
		L.insert(L.Find("Cеверно-ледовитый океан"), "Южный океан", 20, 10);
		cout << "Номер Тихого океана: " << L.Find("Тихий океан") << endl;
		cout << "Номер Атлантического океана: " << L.Find("Атлантический океан") << endl;
		cout << "Номер Северно-Ледовитого океана: " << L.Find("Северно-Ледовитый океан") << endl;
		cout << "Номер Индийского океана: " << L.Find("Индийский океан") << endl;
		cout << "Номер Южного океана: " << L.Find("Южный океан") << endl;
		cout << "Номер Лужи(которой нет в списке): " << L.Find("Лужа") << endl;
		cout << endl;
		L.ListPrint();
		cout << endl;

		cout << "Конструктор копирования M = L:" << endl;
		List M = L;

		cout << "Cписок M: " << endl;
		M.ListPrint();
		cout << endl;

		L.Erase("Индийский океан");
		cout << endl;
		cout << "L после удаления по значению: " << endl;
		L.ListPrint();
		cout << endl;
		if (L.remove_front())
		{
			cout << "L после удаления элемента из начала: " << endl;
			L.ListPrint();
		}
		else
		{
			cout << "L пуст! " << endl;
		}
		cout << endl;
		if (L.remove_front())
		{
			cout << "L после удаления элемента из начала: " << endl;
			L.ListPrint();
		}
		else
		{
			cout << "L пуст! " << endl;
		}
		cout << endl;
		/*L.insert_front("Тихий", 179, 19);
		L.ListPrint();*/

		if (L.remove_front())
		{
			cout << "L после удаления из начала: " << endl;
			L.ListPrint();
		}
		else
		{
			cout << "L пуст! " << endl;
		}
		cout << endl;
		if (L.remove_front())
		{
			cout << "L после удаления из начала: " << endl;
			L.ListPrint();
		}
		else
		{
			cout << "L пуст! " << endl;
		}

		
		cout << endl;
		cout << "Cписок M: " << endl;
		if (M.remove_front())
		{
			cout << "M после удаления из начала: " << endl;
			M.ListPrint();
		}
		else
		{
			cout << "M пуст! " << endl;
		}
		cout << endl;
		if (M.remove_front())
		{
			cout << "M после удаления из начала: " << endl;
			M.ListPrint();
		}
		else
		{
			cout << "M пуст! " << endl;
		}
		cout << endl;
		if (M.remove_front())
		{
			cout << "M после удаления из начала: " << endl;
			M.ListPrint();
		}
		else
		{
			cout << "M пуст! " << endl;
		}
		cout << endl;
		if (M.remove_front())
		{
			cout << "M после удаления из начала: " << endl;
			M.ListPrint();
		}
		else
		{
			cout << "M пуст! " << endl;
		}
		cout << endl;
		if (M.remove_front())
		{
			cout << "M после удаления из начала: " << endl;
			M.ListPrint();
		}
		else
		{
			cout << "M пуст! " << endl;
		}

	}
	catch (char*)
	{
		cout << "Теперь пусто!" << endl;
	}
}

