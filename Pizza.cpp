//#include<iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int N, T, k, index = 0, m, ingredient;
//    bool key = true;
//    cin >> N >> T >> k;
//    vector<int> chislo;
//
//    for (int i = 0; i < k; i++)
//    {
//        cin >> ingredient;
//        chislo.push_back(ingredient);
//    }
//
//    for (int i = 0; i < N; i++) 
//    {
//
//        cin >> m;
//
//        for (int j = 0; j < m; j++)
//        {
//
//            cin >> ingredient;
//
//            if (chislo.index(ingredient) > 0)
//            {
//
//                key = false;
//
//            }
//
//        }
//
//        if (key)
//        {
//
//            index++;
//
//        }
//    }
//
//    cout << index << endl;
//
//    return 0;
//}
#include <iostream>
#include <vector>

int main() {
    int N, T, k, index = 0, m, ingredient;
    bool key;

    std::cin >> N >> T >> k;

    std::vector<int> chislo(k);
    for (int i = 0; i < k; i++) {
        std::cin >> chislo[i];
    }

    for (int i = 0; i < N; i++) {
        key = true;
        std::cin >> m;
        for (int j = 0; j < m; j++) {
            std::cin >> ingredient;
            if (std::find(chislo.begin(), chislo.end(), ingredient) != chislo.end()) {
                key = false;
            }
        }
        if (key) {
            index++;
        }
    }

    std::cout << index << std::endl;

    return 0;
}