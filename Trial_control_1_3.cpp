#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class otrezok {

public:
    int start;
    int end;

    otrezok(const int s, const int e) : start(s), end(e) {}

    bool operator<(const otrezok& other) const 
    {

        if (end - start == other.end - other.start) 
        {
            return start < other.start;
        }

        else
        {
            return end - start > other.end - other.start;
        }

    }
};

int main() {
    int N, a, b;
    vector<otrezok> otrezki;
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    fin >> N;

    for (int i = 0; i < N; i++) {
        fin >> a >> b;
        otrezki.push_back(otrezok(a, b));
    }

    sort(otrezki.begin(), otrezki.end());

    for (int i = 0; i < N; i++) {
        fout << otrezki[i].start << " " << otrezki[i].end << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
