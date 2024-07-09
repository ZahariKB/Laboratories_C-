#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
#include <algorithm>                                                                                                                         
using namespace std;
int line_of_word(const string& text, vector<string>& words)
{
    string s;
    string probel = " ";
    string Textik = text + " ";
    unsigned pos1 = 0;
    unsigned pos2;
    while ((pos1 = Textik.find_first_not_of(probel, pos1)) != -1)
    {
        pos2 = Textik.find_first_of(probel, pos1);
        s = Textik.substr(pos1, pos2 - pos1);
        words.push_back(s);
        pos1 = pos2;
    }
    return words.size();
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int maxWordCount = 0;
    vector<string> words;
    string line_of_text;
    ifstream fin;
    /* ofstream fout("output.txt", ios::_Nocreate);*/
    fin.open("input.txt");
    if (!fin)
    {
        cerr << "Error opening input file!" << endl;
        return 1;
    }
        /*  if (!fout)
       {
          cerr << "Error opening output file" << endl;
          return 1;
       }*/
    fin.peek();
    if (!fin.good())
    {
        cerr << "Input file is empty!" << endl;
        return 1;
    }
    vector<string> maxWordLines;
    while (getline(fin, line_of_text))
    {
        words.clear();
        int wordCount = vector_of_word(line_of_text, words);
        if (wordCount > maxWordCount)
        {
            maxWordCount = wordCount;
            maxWordLines.clear();
            maxWordLines.push_back(line_of_text);
        }
        else if (wordCount == maxWordCount && maxWordLines.size() < 10)
        {
            maxWordLines.push_back(line_of_text);
        }
    }
    fin.close();
    cout << "Lines with the maximum number of words:" << endl;
    for (const auto& line : maxWordLines)
    {
        cout << line << endl;
        /* fout << line << endl;*/
    }
    /* fout.close();*/
    return 0;
}
