#include <iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
int main()
{
    vector<char> str = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','_','!','?','$','+','-',')','(','*','%','^','/','&','=','~','`',';',':','@','<','>','"','#'};
    bool index1 = 0, index2 = 0, index3 = 0;
    string pass, pass1 = "";
    int index = 0;
    getline(cin, pass);
    for (int i = 0; i < str.size(); ++i) {                   //
        if (index3) {
            pass1.pop_back();
            pass1.pop_back();
            pass1.pop_back();
        }
        index2 = 0;
        pass1 += str[i];
        for (int j = 0; j < str.size(); ++j) {                 //
            if (index2) {
                pass1.pop_back();
                pass1.pop_back();
            }
            pass1 += str[j];
            index3 = 1;
            index1 = 0;
            for (int k = 0; k < str.size(); ++k) {             //
                if (index1) {
                    pass1.pop_back();
                }
                pass1 += str[k];
                index2 = 1;
                for (int l = 0; l < str.size(); ++l) {           //
                    pass1 += str[l];
                    if (pass1 == pass) {
                        cout << "Your password: " << pass1 << endl;
                        cout << "Amount of attempts: "<< index << endl;
                        return 0;
                    }
                    else {
                        pass1.pop_back();
                    }
                    index1 = 1;
                    index++;
                }
            }
        }
    }
    return 0;
}


