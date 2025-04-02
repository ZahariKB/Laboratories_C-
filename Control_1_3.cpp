#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Rhomb {

private:
    int a1, b1, a2, b2;

public:
    Rhomb(int a1, int b1, int a2, int b2) : a1(a1), b1(b1), a2(a2), b2(b2) {}

    bool isInsideFirstQuadrant() const {
        return a2 >= 0 && (2 * b2 - b1) >= 0;
    }
};
int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    int N, count = 0, a1, b1, a2, b2;
    fin >> N;

    vector<Rhomb> rhomb;
    for (int i = 0; i < N; i++)
    {
        fin >> a1 >> b1 >> a2 >> b2;
        rhomb.push_back(Rhomb(a1, b1, a2, b2));
    }

    for (const Rhomb& rhombs : rhomb)
    {
        if (rhombs.isInsideFirstQuadrant())
        {
            count++;
        }
    }

    fout << count;

    fin.close();
    fout.close();

    return 0;
}