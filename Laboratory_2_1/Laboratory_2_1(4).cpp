#include <iostream>
#include "Class.h"
#include "release.h"
using namespace std;
class Fabric {
public:
    virtual Alcohol* CreateAlcohol() const = 0;
    virtual ~Fabric() {}
};

class VodkaFabric : public Fabric {
public:
    Alcohol* CreateAlcohol() const override {
        return new Vodka();
    }
};

class BeerFabric : public Fabric {
public:
    Alcohol* CreateAlcohol() const override {
        return new Beer;
    }
};

class VinoFabric : public Fabric {
public:
    Alcohol* CreateAlcohol() const override {
        return new Vino;
    }
};

class CognacFabric : public Fabric {
public:
    Alcohol* CreateAlcohol()const override {
        return new Cognac;
    }
};
CompositeAlcohol* createAlcohol() {

    CompositeAlcohol* yachik = new CompositeAlcohol;
    for (int i = 0; i < 20; ++i)
        yachik->addAlcohol(new Vodka);
    for (int i = 0; i < 15; ++i)
        yachik->addAlcohol(new Vino);
    for (int i = 0; i < 5; ++i)
        yachik->addAlcohol(new Cognac);
    for (int i = 0; i < 30; ++i)
        yachik->addAlcohol(new Beer);
    return yachik;
}
int main()
{
    setlocale(LC_ALL, "Russian");


    CompositeAlcohol* ach = new CompositeAlcohol;
    for (int i = 0; i < 1; ++i)
        ach->addAlcohol(createAlcohol());
    cout << "len: "
        << ach->getStrength() << endl;
    delete ach;

  /*  VodkaFabric* vf = new VodkaFabric;
    BeerFabric* bf = new BeerFabric;
    VinoFabric* vvf = new VinoFabric;
    CognacFabric* cf = new CognacFabric;
    vector<Alcohol*> v, v1;
    
    
    v1.push_back(Alcohol::CreateAlcohol(Vodka_ID));
    v1.push_back(Alcohol::CreateAlcohol(Beer_ID));
    v1.push_back(Alcohol::CreateAlcohol(Vino_ID));
    v1.push_back(Alcohol::CreateAlcohol(Cognac_ID));



    v.push_back(vf->CreateAlcohol());
    v.push_back(bf->CreateAlcohol());
    v.push_back(vvf->CreateAlcohol());
    v.push_back(cf->CreateAlcohol());


    cout << "Классическая реализация: " << endl << endl;
    for (int i = 0; i < v.size(); ++i) {
        v[i]->print();
    }
    cout << endl;
    cout << "Обобщенный конструктор: " << endl << endl;
    for (int i = 0; i < v.size(); ++i) {
        v1[i]->print();
    }*/
    /*Vodka vodka1, vodka2;
    cout << "Количество созданных объектов класса Водка: " << vodka2.Get_Count() << endl;
    Vino vino;
    Beer beer;
    Cognac cognac;*/
    //const int size = 10;
    //Alcohol* arr[size];
    //for (int i = 0; i < size; i++) {
    //    arr[i] = new Vodka();
    //}    
    //arr[6]->print();
    //vodka2.Get_Count();
    //vodka1.print();
    //vodka1.shot();
    //vino.tostik();
    //vodka1.shot(); //1
    //vino.tostik();
    //vodka1.shot(); 
    //vino.tostik();
    //vodka1.shot();
    //vino.tostik();
    //vodka1.shot();
    //vino.tostik();
    //vodka1.shot();  //5
    //vino.tostik();
    //vodka1.shot();
    //vino.tostik();
    //vodka1.shot();
    //vino.tostik();
    //vodka1.shot();
    //vino.tostik();
    //vodka1.shot();
    //vino.tostik();
    //vodka1.shot();  //10
    //vino.tostik();
    //vodka1.shot();
    //vino.tostik();
    //vodka1.shot();
    //vino.tostik();
    //vodka1.shot();
    //vino.tostik();
    //vodka1.shot();  //14
    //vino.tostik();
    //vodka1.shot();
    //vino.print();
    //beer.print();
    //cognac.print();
    //if (vodka1 == vodka2) {
    //    cout << "Перегрузка оператора равенства работает!" << endl << endl;
    //}
    //vino.tostik();
    //vodka1.shot();
    //vodka1.print();
    //vodka1 = vodka2;
    //vodka1.print();
    //cout << "Конструктор присваивания работает!" << endl << endl;
    //vodka1.shot();
    //vodka1.print();
    //
    //cout << endl;
    /*Vodka vodka1, vodka2, vodka4;
    vodka1.print();
    Vodka vodka3(move(vodka1));
    vodka3.print();
    vodka2 = vodka1;
    vodka2.print();
    Vodka vodka5(vodka4);
    vodka5.print();
    vodka4 = move(vodka2);
    vodka4.print();*/
    return 0;
}


