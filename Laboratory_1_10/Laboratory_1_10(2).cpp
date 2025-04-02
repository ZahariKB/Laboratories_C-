#include "Class.cpp"

List::List() {
	First = nullptr;
	Last = nullptr;
}

//List::List(const List& L)
//{
//	First = L.First;
//	Ocean* O = First;
//	Ocean* OO = L.First;
//	while (O != nullptr) {
//		Ocean* oc1 = OO;
//		Ocean* oc2 = oc1;
//		O = oc2;
//		OO = OO->Next;
//		O = O->Next;
//	}
//	Last = nullptr;
//}
List::List(const List& L)
{
	Ocean* origCurrent = L.First;
	Ocean* prevNew = nullptr;
	Ocean* currentNew = nullptr;

	while (origCurrent != nullptr) {
		Ocean* newOcean = new Ocean();
		newOcean->name = origCurrent->name;
		newOcean->ploshad = origCurrent->ploshad;
		newOcean->temp = origCurrent->temp;

		if (prevNew == nullptr) {
			First = newOcean;
			currentNew = newOcean;
		}
		else {
			prevNew->Next = newOcean;
			currentNew = newOcean;
		}

		origCurrent = origCurrent->Next;
		prevNew = currentNew;
	}

	Last = currentNew;
}

List::~List()
{
	if (First != nullptr) {
		while (First != nullptr) {
			Ocean* O = First;
			First = O->Next;
			delete O;
		}
	}
}
//List::~List()
//{
//	while (First != nullptr) {
//		Ocean* O = First;
//		First = First->Next;
//		delete O;
//	}
//	Last = nullptr;
//}
const List& List::operator = (const List& L)
{
	if (&L == this)
		return *this;
	if (First != nullptr) {
		while (Last != nullptr) {
			Ocean* O = First;
			First = O->Next;
			delete O;
		}
	}
	First = L.First;
	Last = L.Last;
	Ocean* O = First;
	Ocean* OO = L.First;
	while (O != nullptr) {
		OO = OO->Next;
		O = OO->Next;
	}
	return *this;
}
//const List& List::operator=(const List& L)
//{
//	if (&L == this)
//		return *this;
//
//	// Очистка текущего списка
//	while (First != nullptr) {
//		Ocean* O = First;
//		First = First->Next;
//		delete O;
//	}
//	Last = nullptr;
//
//	// Копирование элементов из списка L
//	Ocean* O = L.First;
//	while (O != nullptr) {
//		insert_back(O->name, O->ploshad, O->temp);
//		O = O->Next;
//	}
//
//	return *this;
//}

void List::insert_front(const string n, const int c, const int tempr) {
	Ocean* O = new Ocean;
	O->name = n;
	O->ploshad = c;
	O->temp = tempr;
	O->Next = First;
	First = O;
	if (Last == nullptr) Last = First;
	index++;
}

bool List::remove_front() {
	if (First == nullptr)
		return false;
	Ocean* O = First;
	First = First->Next;
	index--;
	return true;
}

void List::insert_back(const string n, const int c, const int tempr) {
	Ocean* O = new Ocean;
	O->name = n;
	O->ploshad = c;
	O->temp = tempr;
	O->Next = nullptr;
	Last->Next = O;
	Last = O;
	index++;
}

bool List::remove_back() {
	if (First == nullptr)
		return false;
	if (First == Last) {
		remove_front();
		return true;
	}
	Ocean* O = First;
	while (O->Next != Last) O = O->Next;
	O->Next = nullptr;
	Last = O;
	return true;
}
void List::insert(int i, const string n, const int c, const int tempr) {
	if (i == 0) {
		insert_front(n, c, tempr);
	}
	Ocean* O = First; Ocean* NO = new Ocean;
	/*if (i < 0 || i > index) {
		cout << "Ошибка: индекс вставки находится вне границ списка." << endl;
		return;
	}*/
	for (int j = 0; j < i; j++) {
		O = O->Next;
	} NO->name = n;
	NO->ploshad = c;
	NO->temp = tempr;
	NO->Next = O->Next; O->Next = NO;
}

void List::Erase(string name) {
	List L = *this;
	int index = L.Find(name);
	if (index == 0) {
		remove_front();
	}
	else {
		Ocean* O = First;
		Ocean* OO = First->Next;
		//int index = Find(name);
		///*if (index == -1) {
		//	cout << "Ошибка: элемент с указанным именем не найден." << endl;
		//	return;
		//}*/
		for (int i = 0; i < index - 1; i++) {
			O = O->Next;
			OO = OO->Next;
		}
		O->Next = OO->Next;
		if (OO->Next == nullptr) Last = O->Next;
	}
}

void List::ListPrint()const
{
	Ocean* O = First;
	if (O == nullptr)
		cout << "Cписок пуст! " << endl;
	if (O != nullptr)
	{
		cout << "Cодержимое списка: " << endl;
		while (O != nullptr)
		{
			cout << O->name << " - Площадь(в млн.км квадратных): " << O->ploshad << endl;
			cout << O->name << " - Температура(в градусах): " << O->temp << endl;
			O = O->Next;
		}
	};
}

int List::Find(string n) {
	int c = 0;
	Ocean* O = First;
	while (O != nullptr) {
		if (O->name == n) {
			return c;
		}
		else {
			O = O->Next;
			c++;
		}
	}
	return -1;
}

void List::ForEach(void(*Fun)(Ocean&)) {
	Ocean* O = First;
	if (O == nullptr)
		cout << "Cписок пуст! " << endl;
	if (O != nullptr)
	{
		cout << "Cодержимое списка: " << endl;
		while (O != nullptr)
		{
			Fun(*O);
			O = O->Next;
		}
	};
}

void List::ForEach(void Fun(const string name, const int ploshad)) const {
	Ocean* O = First;
	if (O == nullptr)
		cout << "Cписок пуст! " << endl;
	if (O != nullptr)
	{
		cout << "Cодержимое списка:" << endl;
		while (O != nullptr)
		{
			Fun(O->name, O->ploshad);
			O = O->Next;
		}
	};
}