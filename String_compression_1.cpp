#include <iostream>
#include <string>
#include<cmath>
using namespace std;

string newstr(string str)
{
    string newstring = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            int index = 0;
            i++;
            while (str[i] != ')')
            {
                index = index * 10 + (str[i] - '0');
                i++;
            }
            i++; 
            char c = str[i];
            abs(index);
            for (int j = 0; j < index; j++)
            {
                newstring += c;
            }
        }
        else {
            newstring += str[i];
        }
    }
    return newstring;
}

int main() {
    string str;
    cin >> str;
    cout << newstr(str) << endl;

    return 0;
} 
//123412(12)194(11)2444