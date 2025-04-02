#include <iostream>
#include "Metodi.h"
using namespace std;

int Person::next_id = 0;

int main()
{
    setlocale(LC_ALL, "russian");

    try {
        Person p1, p2("Lola", 1, mertv);
        p1.set_move(1);
        p1.set_name("Lala");
        p1.set_sost(norm);
        p2.set_sost(mertv);
        cout << p1 << p2 << endl;
        Artefacts* arr = new Artefacts[1]{ palochka };
        MagicPerson a("Name", 1, mertv, mantia, 200, 100, 1, arr), b, d;
        cout << a;
        b = a;
    }

    catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}


