#include <iostream>
#include <string>
#include<cstring>
#include <cctype>
using namespace std;
int main() 
{
    string formula;
    int sum = 0, index = 1, znach;
    cin >> formula;
    for (int i = formula.length() - 1; i >= 0; i--) {

        if (formula[i] >= '1' && formula[i] <= '9')
        {
            index = formula[i] - '0';
        }

        else {
            switch (formula[i])
            {
            case 'H':
                znach = 1;
                break;
            case 'C':
                znach = 12;
                break;
            case 'N':
                znach = 14;
                break;
            case 'O':
                znach = 16;
                break;
                
            }
                sum += znach * index;
                index = 1;
        }
    }
    cout << sum << endl;
    return 0;
}


//
//    for (int i = formula.length() - 1; i >= 0; i--) {
//        if (isdigit(formula[i])) {
//            multiplier = formula[i] - '0';
//        }
//        else {
//            switch (formula[i]) {
//            case 'H':
//                mass += 1.008 * multiplier;
//                break;
//            case 'C':
//                mass += 12.01 * multiplier;
//                break;
//            case 'N':
//                mass += 14.01 * multiplier;
//                break;
//            case 'O':
//                mass += 16.00 * multiplier;
//                break;
//                // Add cases for other elements as needed
//            }
//            multiplier = 1;
//        }
//    }
//
//    std::cout << "The molar mass of the substance is: " << mass << std::endl;
//
//    return 0;
//}
