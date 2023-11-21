#include <iostream>
#include <vector>
using namespace std;

struct Zahl {
    int zahl;
    int count;
};

int main() {
    vector<Zahl> vector;
    Zahl p1 = {1, 0};
    Zahl p2 = {2, 0};
    vector.push_back(p1);
    vector.push_back(p2);
    for (auto& v : vector) {
        cout << "Zahl: " << v.zahl << ", Anzahl: " << v.count << endl;
    }
    return 0;
}
