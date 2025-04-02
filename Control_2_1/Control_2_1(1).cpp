#include <iostream>
#include<string>
#include "Metodi_dochki.h"
#include "Metodi_maina.h"

using namespace std;

int Actor::next_id = 0;
int Actor::amount_actors = 0;

int main()
{
    setlocale(LC_ALL, "Russian");
    try {
        Actor actor1("Smith", Amplua::komik);
        Actor actor2("Johnson", Amplua::tragic);
        cout << "Сравнение двух объектов Актера:" << endl;
        if (actor1 == actor2.get_amplua()) {
            cout << "актер 1 и актер 2 имеют одинаковую АМПЛУА" << endl;
        }
        else {
            cout << "актер 1 и актер 2 имеют разную АМПЛУА" << endl;
        }
        Filming filming1(5);
        Filming filming2(5);

        cout << "Сравнение двух объектов съемки:" << endl;
        filming1.set_current_years_filming(3);
        filming2.set_current_years_filming(3);
        Actor actor3("Brown", Amplua::travesti);
        Filming filming3(4);
        cout << "Сравнение объекта 'Актер' и объекта 'Съемкa' :" << endl;
        if (actor3 == filming3.get_amplua()) {
            cout << "актер 3 и съемка 3 имеют одинаковую АМПЛУА" << endl;
        }
        else {
            cout << "актер 3 и съемка 3 имеют разные АМПЛУА" << endl;
        }
        Actor a("Felix", travesti);
        a.set_amplua(travesti);
        cout << a;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
  
    return 0;
}


