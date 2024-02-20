#include <iostream>
#include <vector>
#include <map>  // ich benutze map anstatt map da ich die gezogenen zahlen später zählen will
#include <iomanip>  // für setw() und setfill()
#include <random>
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
            cout << "[" << setfill(' ') << setw(2) << pair.first << "*" << setw(2) << pair.second << "]  ";
            zeilenumbruch++;
            if (zeilenumbruch == darstellungsBreite) {
                cout << "\t";
                zeilenumbruch = 0;
            }
        }
    }
    //6 Einzigartige zufallszahlen(zwischen 1-49) sollen pair second um 1 erhöhen wenn es gezogen wurde
    void generate(int anzahl, int rangeStart, int rangeEnd) {
        // Zufallsgenerator initialisieren
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(rangeStart, rangeEnd);
        // Zufallszahlen generieren
        for (int i = 0; i < anzahl; i++) {
            paar[dis(gen)]++;
        }
    }
};

int main() {
    // Erstellen Sie ein Lotto-Objekt
    Lotto lotto(1, 49);

    // Paare ausgeben
    lotto.generate(6, 1, 49);
    lotto.print();
    return 0;
}