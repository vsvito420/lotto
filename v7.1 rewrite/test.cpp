#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Lotto {
private:
    map<int, int> paar;

public:
    // Konstruktor
    Lotto() {
        // Elemente hinzufügen
        paar[1] = 1;
        paar[2] = 2;
        paar[3] = 3;
    }

    // Funktion zum Ausgeben der Paare
    void printPaar() {
        for (const auto& pair : paar) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
};

int main() {
    // Erstellen Sie ein Lotto-Objekt
    Lotto lotto;

    // Paare ausgeben
    lotto.printPaar();

    return 0;
}