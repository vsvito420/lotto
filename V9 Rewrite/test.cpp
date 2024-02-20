#include <iostream>
using namespace std;

class Lotto {
public:
    int anzeigebreite; // für die zahlen in reihe
    int anzahl; // 6 für Kolon 
    int maxzahl; // 49 für alles
    int ziehung[6]; // 6 zahlen
    // Konstruktor
    Lotto() {
        cout << "Lotto constructor" << endl;
    }
    //parameterized constructor
    Lotto(int anzahl, int maxzahl, int anzeigebreite) {
        cout << "Lotto parameterized constructor" << endl;
        this->anzahl = anzahl;
        this->maxzahl = maxzahl;
        this->anzeigebreite = anzeigebreite;
    }
    // Destruktor
    ~Lotto() {
        cout << "Lotto destructor" << endl;
    }
};
