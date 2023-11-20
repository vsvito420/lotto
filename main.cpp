#include <iostream>
#include <vector>
using namespace std;

class Spiel {
public:
    void setZahlen(vector<int> zahlen) {
        // Methodencode
    }
    vector<int> getZahlen() {
        return gezogeneZahlen;
        // Methodencode
    }
    bool gewonnen() {
        // Methodencode
        return 0;
    }
private:
    vector<int> gezogeneZahlen;
};

class Spieler {
public:
    void setGewonnen(bool gewonnen) {
        // Methodencode
    }
    bool getGewonnen() {
        // Methodencode
        return gewonnen;
    }
private:
    bool gewonnen;
};

class Lotto {
public:
    void neuesSpiel() {
        // Methodencode
    }
    void spielerEingabe(Spieler spieler) {
        // Methodencode
    }

    bool pruefen(int zahl, int zahlenSize) {
        if (zahl >= 1 && zahl <= zahlenSize) {
            return true; // Die Zahl ist gültig
        } else {
            return false; // Die Zahl ist ungültig
        }
    }

    void eingabeM(int zahlenSize, int zahlenRange, int ausgabeBreite) {
        cout << "Geben Sie " << zahlenSize << " Werte ein (1-" << zahlenRange << "):" << endl;
        bool istEinzigartig;
        int zahl = 0;
        vector<int> zahlen(zahlenSize);
        for (int i = 0; i < zahlenSize; i++) {
            do {
                cin >> zahl;
                istEinzigartig = true;
                for (int j = 0; j < i; j++) {
                    if (!pruefen(zahl, zahlenRange)) {
                        istEinzigartig = false;
                        cout << "Ungültige Eingabe! Bitte geben Sie eine Zahl zwischen 1 und " << zahlenRange << " ein." << endl;
                    }
                    if (zahlen[j] == zahl) {
                        istEinzigartig = false;
                        break;
                    }
                }
            } while (!istEinzigartig);
            zahlen[i] = zahl;
        }
        
    }

    void ziehung() {
        // Methodencode
    }
    void ergebnis() {
        // Methodencode
    }
private:
    vector<Spiel> spiele;
    vector<Spieler> spieler;
};

int main(){
  Lotto lotto;
  lotto.eingabeM(6,49,7);
}