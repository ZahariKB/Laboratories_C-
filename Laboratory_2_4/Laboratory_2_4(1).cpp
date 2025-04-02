#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include "struct&class.cpp"
using namespace std;

bool SortStudData_2(SStudData a, SStudData b) {
    if (a.get_name() > b.get_name()) {
        return true;
    }
    else if (a.get_name() < b.get_name()) {
        return false;
    }
    else {
        return (a.get_id() < b.get_id());
    }
}

bool SortStudData_6(SStudData a, SStudData b) {
    if (a.get_name() < b.get_name()) {
        return true;
    }
    else if (a.get_name() > b.get_name()) {
        return false;
    }
    else {
        float avg_a = 0, avg_b = 0;
        for (int i = 0; i < 4; ++i) {
            avg_a += a.get_marks()[i].mark;
            avg_b += b.get_marks()[i].mark;
        }
        avg_a /= 4;
        avg_b /= 4;
        return avg_a > avg_b;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    //проверка файла
    ifstream file("file.txt");
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return true;
    }
    if (file.peek() == EOF) {
        cerr << "Файл пустой!" << endl;
        return true;
    }
    //
    string str, name, subject;
    int pos1, pos2, mark, number_of_zachetka;
    vector<SStudData> StudData;

    while (file.peek() != EOF) {
        getline(file, str);
        pos1 = str.find_first_of(";");
        name = str.substr(0, pos1);
        pos2 = str.find_first_of(";", pos1 + 1);
        number_of_zachetka = stoi(str.substr(pos1 + 1, pos2 - pos1 - 1));

        string subj2 = str.substr(pos2 + 1);
        vector<SMark> smarks;

        for (int i = 0; i < 4; i++) {
            pos1 = subj2.find_first_of("-");
            pos2 = subj2.find_first_of(",");
            subject = subj2.substr(0, pos1);
            mark = stoi(subj2.substr(pos1 + 1, pos2 - pos1 - 1));
            subj2 = subj2.substr(subj2.find_first_of(",") + 1);
            smarks.push_back(SMark(mark, subject));
        }
        StudData.push_back(SStudData(name, number_of_zachetka, smarks));
    }

    file.close();

    for (int i = 0; i < StudData.size(); i++) {
        cout << StudData[i] << endl;
    }

    //222222222222222222
  
    sort(StudData.begin(), StudData.end(), SortStudData_2);
    cout << "Сортировка по убыванию фамилий, затем - по возрастанию зачётки: " << endl;
    for (int i = 0; i < StudData.size(); i++) {
        cout << StudData[i] << endl;
    }
    cout << endl;
    //333333333333333333
    map<int, SStudData> myMap;
    for (int i = 0; i < StudData.size(); i++) {
        myMap[StudData[i].get_id()] = StudData[i];
    }

    //444444444444444444
    SStudData StudData_2;
    int max = -1000000;
    int res;
    for (int i = 0; i < StudData.size(); ++i) {
        res = 0;
        for (int j = 0; j < 4; ++j) {
            res += StudData[i].get_marks()[j].mark;
        }
        if (max < res) {
            max = res;
            StudData_2 = StudData[i];
        }
    }
    cout << "Студент с максимальной суммой баллов: " << endl;
    cout << StudData_2 << endl << endl;

    //555555555555555555
    vector<float> average_bals_of_students;
    for (int i = 0; i < StudData.size(); ++i) {
        float average = 0;
        for (int j = 0; j < 4; ++j) {
            average += StudData[i].get_marks()[j].mark;
        }
        average /= 4;
        average_bals_of_students.push_back(average);
    }
    cout << "Средний балл каждого студента: " << endl;
    for (int i = 0; i < average_bals_of_students.size(); ++i) {
        cout << StudData[i] << " Средний балл - " << average_bals_of_students[i] << endl << endl;
    }

    //66666666666666666
    sort(StudData.begin(), StudData.end(), SortStudData_6);
    cout << "Сортировка по возрастанию фамилий, если равны - сортировка по убыванию среднего балла: " << endl;
    for (int i = 0; i < StudData.size(); i++) {
        cout << StudData[i];
        cout << " Средний балл - " << average_bals_of_students[i] << endl << endl;
    }

    //77777777777777777
    float lower_bound = 7.25;
    float upper_bound = 8.75;

    vector<SStudData> filteredStudents;

    for (int i = 0; i < StudData.size(); ++i) {
        float average = 0;
        for (int j = 0; j < 4; ++j) {
            average += StudData[i].get_marks()[j].mark;
        }
        average /= 4;

        if (average >= lower_bound && average <= upper_bound) {
            filteredStudents.push_back(StudData[i]);
        }
    }

    sort(filteredStudents.begin(), filteredStudents.end(), SortStudData_6);
    cout << "Список студентов, средний балл которых принадлежит заданному диапазону: "<< lower_bound  << "-" << upper_bound << endl;
    cout << "Порядок – по убыванию среднего балла: " << endl;
    for (int i = 0; i < filteredStudents.size(); i++) {
        cout << filteredStudents[i] << " Средний балл - " << average_bals_of_students[i] << endl << endl;
    }

    //88888888888888888
    cout << "Введите предмет, чтобы просмотреть список студентов, которые сдавали его: " << endl;
    cin >> subject;
    bool found = false;
    cout << "Студенты, которые сдавали " << subject << ":" << endl;
    for (int i = 0; i < StudData.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            if (StudData[i].get_marks()[j].Subject == subject) {
                cout << StudData[i] << endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "Нет студентов, которые сдавали " << subject << "." << endl;
    }

    //9999999999999999
    map<string, int> subjectCount;
    for (int i = 0; i < StudData.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            subjectCount[StudData[i].get_marks()[j].Subject]++;
        }
    }

    cout << "Количество студентов, сдающих каждый предмет:" << endl;
    for (const auto& it : subjectCount) {
        cout << it.first << ": " << it.second << " студент(а)" << endl;
    }
    cout << endl;
    //1010101010101010
    bool noPass = 0;
    cout << "Студенты, не сдавшие сессию (хотя бы один балл равен 2):" << endl;
    for (int i = 0; i < StudData.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            if (StudData[i].get_marks()[j].mark < 4) {
                cout << StudData[i] << endl;
                noPass = 1;
                break;
            }
        }
    }

    if (!noPass) {
        cout << "Все студенты сдали сессию!" << endl;
    }
    return 0;
}