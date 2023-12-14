#include <iostream>
#include <random>
#include <map>
using namespace std;

class Ticket 
{
private:
    int Size;
    int Range;
    map <int, int> t_map; // Anzahl / Zahl
public:
    int getSize() { return Size; }
    int getRange() { return Range; }
    map <int, int> getMap() { return t_map; }
};

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 6);
    int wuerfel = dis(gen);
    cout << "Du hast eine " << wuerfel << " gewürfelt." << endl;
    return 0;
}