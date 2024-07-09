#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<windows.h>
using namespace std;
// Функция для проверки, состоит ли слово только из букв латиницы
bool isLatin(const string& word)
{
    for (const char c : word)
    {
        if (!isalpha(c))
        {
            return false;
        }
    }
    return true;
}


// функция для перестановки слов, состоящих только из букв латиницы, по алфавиту
string changeLatinWords(const string& str, const string& delimiter)
{
    string result;
    vector<string> words;
    size_t pos1 = 0, pos2 = str.find(delimiter);
    while (pos2 != string::npos)
    {
        words.push_back(str.substr(pos1, pos2 - pos1)); // добавляем отдельное слово в вектор 
        pos1 = pos2 + delimiter.size();                 // начальная позиция pos1 смещается на размер разделителя вправо(до следующего слова)
        pos2 = str.find(delimiter, pos1);               // ищет следующий разделитель
    }
    /*words.push_back(str.substr(pos1, pos2));*/


    vector<string> latinWords;
    for (const string& word : words)
    {
        if (isLatin(word))
        {
            latinWords.push_back(word);
        }
    }
    sort(latinWords.begin(), latinWords.end());

    // заменяем в исходной строке слова, состоящие только из букв латиницы, на отсортированные
    size_t Index = 0;
    for (const string word : words)
    {
        if (isLatin(word))
        {
            result += latinWords[Index];
            Index++;
        }
        else
        {
            result += word;
        }
        result += delimiter;
    }

    // Удаляем последний лишний разделитель
    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}

int main() {
    SetConsoleCP(1251);
    /*SetConsoleOutputCP(1251);*/
    setlocale(LC_ALL, "russian");
    string str, delimiter;
    cout << "Введите разделитель: ";
    getline(cin, delimiter);
    while (delimiter.size() == 0) {
        cout << "Ошибка! Нет разделителя! Введите еще раз!" << endl;
        getline(cin, delimiter);
    }
    cout << "Введите строку: ";
    getline(cin, str);
    // удаляем первый разделитель
    size_t firstDelimiterPos = str.find(delimiter);
    if (firstDelimiterPos != string::npos) {
        str.erase(firstDelimiterPos, delimiter.size());
    }
    string newStr = changeLatinWords(str, delimiter);
    if (newStr.empty()) {
        cerr << "Ошибка где-то не хватает разделителя или пустая строка!" << endl;
        return 0;
    }
    cout << "Переставленная строка: " << newStr << endl;
    return 0;
}

// ,12,sad,das,a,1s3,
// ,s,as,dsa,aqw,
// ,aq,lo,d,3d,a,aad,1a,