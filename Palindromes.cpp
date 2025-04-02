#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long int N, a, b, c, none = 0, nul = 0, ostr = 0, tup = 0, priam = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b >> c;

        if (a + b < c || a + c < b || b + c < a)
        {
            none++;
        }

        else if (a + b == c || a + c == b || b + c == a)
        {
            nul++;
        }

        else if (a * a + b * b > c * c && a * a + c * c > b * b && b * b + c * c > a * a)
        {
            ostr++;
        }

        else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
        {
            priam++;
        }

        else if(b * b + c * c < a * a || a * a + c * c < b * b || a * a + b * b < c * c)    
        {
            tup++;
        }

    }
    cout << none << " " << nul << " " << ostr << " " << priam << " " << tup;
    return 0;
}
//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//    int N, a, b, c, none = 0, nul = 0, ostr = 0, tup = 0, priam = 0;
//    cin >> N;
//    for (int i = 0; i < N; i++)
//    {
//        cin >> a >> b >> c;
//
//        if (a + b < c || a + c < b || b + c < a)
//        {
//            none++;
//        }
//
//        else if (a + b == c || a + c == b || b + c == a)
//        {
//            nul++;
//        }
//
//        else if (a * a + b * b > c * c && a * a + c * c > b * b && b * b + c * c > a * a)
//        {
//            ostr++;
//        }
//
//        else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
//        {
//            priam++;
//        }
//
//        else if ((b + c > a && b - c < a) || (a + c > b && a - c < b) || (a + b > c && a - b < c))
//        {
//            tup++;
//        }
//
//    }
//    cout << none << " " << nul << " " << ostr << " " << priam << " " << tup;
//    return 0;
//}