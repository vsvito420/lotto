#include <iostream>
#include <vector>
#include <map>  // ich benutze map anstatt map da ich die gezogenen zahlen später zählen will
#include <iomanip>  // für setw() und setfill()
using namespace std;

class Lotto {
private:
    map<int, int> paar;
    int darstellungsBreite = 7;

public:
    // Konstruktor
    Lotto() {
        int rangeStart = 0;
        int rangeEnd = 0;
        // Elemente hinzufügen
        for (int i = rangeStart; i <= rangeEnd; i++) {
            paar[i] = 0;
        }
    }

    // Parameter Konstruktor
    Lotto(int rangeStart, int rangeEnd) {
        // Elemente hinzufügen
        for (int i = rangeStart; i <= rangeEnd; i++) {
            paar[i] = 0;
        }
    }
    // Funktion zum Ausgeben der Paare
    void print() {
        int zeilenumbruch = 0;  // Zähler für die neue Zeile
        for (const auto& pair : paar) {
            cout << "|" << setfill('0') << setw(2) << pair.first << " = " << setw(2) << pair.second << "  ";
            zeilenumbruch++;
            if (zeilenumbruch == darstellungsBreite) {
                cout << endl;
                zeilenumbruch = 0;
            }
        }
    }
};

int main() {
    // Erstellen Sie ein Lotto-Objekt
    Lotto lotto(1, 49);

    // Paare ausgeben
    lotto.print();

    return 0;
}