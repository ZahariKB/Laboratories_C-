#include<string>
#include<vector>
#include<iostream>
using namespace std;

struct SMark
{
    string Subject;                 //�������
    int mark;                       //������
    //������������
    SMark() {
        mark = 0;
        Subject = "����������� �������";
    }
    SMark(int mark, string subject) {
        this->mark = mark;
        this->Subject = subject;
    }
    friend ostream& operator <<(ostream& OUT, const SMark sm) {
        OUT << " ������� - " << sm.Subject << endl;
        OUT << " ������ - " << sm.mark << endl;
        return OUT;
    }
};

class SStudData {
private:
    string name;                     // �������
    int ID;                          // ����� �������
    vector <SMark> marks;            // ���-�� ������ � ������ �� ������ ��������
public:
    //������������,
    SStudData() {
        name = "����������� �������";
        ID = 1;
    }

    SStudData(string name, int ID, vector<SMark> marks) {
        this->name = name;
        this->ID = ID;
        this->marks = marks;
    }

    SStudData(const SStudData& other) {
        this->name = other.name;
        this->ID = other.ID;
        this->marks = other.marks;
    }
    //���������� =
    SStudData& operator =(const SStudData& other) {
        if (this != &other) {
            this->name = other.name;
            this->ID = other.ID;
            this->marks = other.marks;
        }
        return *this;
    }
    //���������� <<
    friend ostream& operator <<(ostream& out, const SStudData& other) {
        out << "��� ��������: " << other.name << endl;
        out << "����� �������: " << other.ID << endl;
        for (int i = 0; i < other.marks.size(); ++i) {
            out << other.marks[i];
        }
        return out;
    }
    //get - ������,
    string get_name() {
        return name;
    }

    int get_id() {
        return ID;
    }

    vector<SMark> get_marks() {
        return marks;
    }
    //����� ��� ���������� ������
    void push_mark(const SMark& mark) {
        marks.push_back(mark);
    }
};
