#include "Class.cpp"
#include <iostream>

using namespace std;

void Print(const string name, const int ploshad, const int temp) {
	cout << " ���: " << name << " - �������: " << ploshad << endl;
	cout << " ���: " << name << " - �����������: " << temp << endl;
}

void PrintPlus(List::Ocean& O) {
	O.temp += 3;
	cout << " ���: " << O.name << " - �������: " << O.ploshad << endl;
	cout << " ���: " << O.name << " - �����������: " << O.temp << endl;
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
		cout << "���������� ������ ������ � ������ ������: " << endl;
		L.insert_front("����� �����", 179, 19);
		L.ListPrint();
		cout << endl;
		cout << "���������� �������������� ������ � ����� ������: " << endl;
		L.insert_back("������������� �����", 92, 17);
		L.ListPrint();
		cout << endl;
		cout << "���������� �������-���������� ������ � ������ ������: " << endl;
		L.insert_front("�������-��������� �����", 14, 1);
		L.ListPrint();
		cout << endl;
		cout << "���������� ���������� ������ � ����� ������: " << endl;
		L.insert_back("��������� �����", 76, 17);
		L.ListPrint();
		cout << endl;
		cout << "���������� ����������� �� ��� �������:" << endl;
		L.ForEach(PrintPlus);
		cout << endl;
		cout << "���������� ����������� �� ��� �������:" << endl;
		L.ListPrint();
		cout << endl;
		cout << "������ L, ����� ���������� ������ ������ ����� �������-���������� ������:" << endl;
		L.insert(L.Find("C������-��������� �����"), "����� �����", 20, 10);
		cout << "����� ������ ������: " << L.Find("����� �����") << endl;
		cout << "����� �������������� ������: " << L.Find("������������� �����") << endl;
		cout << "����� �������-���������� ������: " << L.Find("�������-��������� �����") << endl;
		cout << "����� ���������� ������: " << L.Find("��������� �����") << endl;
		cout << "����� ������ ������: " << L.Find("����� �����") << endl;
		cout << "����� ����(������� ��� � ������): " << L.Find("����") << endl;
		cout << endl;
		L.ListPrint();
		cout << endl;

		cout << "����������� ����������� M = L:" << endl;
		List M = L;

		cout << "C����� M: " << endl;
		M.ListPrint();
		cout << endl;

		L.Erase("��������� �����");
		cout << endl;
		cout << "L ����� �������� �� ��������: " << endl;
		L.ListPrint();
		cout << endl;
		if (L.remove_front())
		{
			cout << "L ����� �������� �������� �� ������: " << endl;
			L.ListPrint();
		}
		else
		{
			cout << "L ����! " << endl;
		}
		cout << endl;
		if (L.remove_front())
		{
			cout << "L ����� �������� �������� �� ������: " << endl;
			L.ListPrint();
		}
		else
		{
			cout << "L ����! " << endl;
		}
		cout << endl;
		/*L.insert_front("�����", 179, 19);
		L.ListPrint();*/

		if (L.remove_front())
		{
			cout << "L ����� �������� �� ������: " << endl;
			L.ListPrint();
		}
		else
		{
			cout << "L ����! " << endl;
		}
		cout << endl;
		if (L.remove_front())
		{
			cout << "L ����� �������� �� ������: " << endl;
			L.ListPrint();
		}
		else
		{
			cout << "L ����! " << endl;
		}

		
		cout << endl;
		cout << "C����� M: " << endl;
		if (M.remove_front())
		{
			cout << "M ����� �������� �� ������: " << endl;
			M.ListPrint();
		}
		else
		{
			cout << "M ����! " << endl;
		}
		cout << endl;
		if (M.remove_front())
		{
			cout << "M ����� �������� �� ������: " << endl;
			M.ListPrint();
		}
		else
		{
			cout << "M ����! " << endl;
		}
		cout << endl;
		if (M.remove_front())
		{
			cout << "M ����� �������� �� ������: " << endl;
			M.ListPrint();
		}
		else
		{
			cout << "M ����! " << endl;
		}
		cout << endl;
		if (M.remove_front())
		{
			cout << "M ����� �������� �� ������: " << endl;
			M.ListPrint();
		}
		else
		{
			cout << "M ����! " << endl;
		}
		cout << endl;
		if (M.remove_front())
		{
			cout << "M ����� �������� �� ������: " << endl;
			M.ListPrint();
		}
		else
		{
			cout << "M ����! " << endl;
		}

	}
	catch (char*)
	{
		cout << "������ �����!" << endl;
	}
}

