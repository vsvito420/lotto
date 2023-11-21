#include <iostream>
#include <vector>
using namespace std;
int lottoSize=6;
int lottoRange=49;

struct Zahl {
    int number;
    int count;
};



int main() {
    vector<Zahl> vector;

    for (int i = 1; i <= 49; ++i) {
        Zahl newZahl = {i, 0};
        vector.push_back(newZahl);
    }

    for (auto& v : vector) {
        cout << "Zahl: " << v.number << ", \tAnzahl: " << v.count << endl;
    }
    
    return 0;
}
