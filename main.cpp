#include <iostream>
#include <vector>
using namespace std;

struct Zahl {
    int number;
    int count;
};

int main() {
    vector<Zahl> vector;

    for (int i = 1; i <= 5; ++i) {
        Zahl newZahl = {i, 0};
        vector.push_back(newZahl);
    }

    for (auto& v : vector) {
        cout << "Zahl: " << v.number << ", Anzahl: " << v.count << endl;
    }
    
    return 0;
}
