#include <iostream>
#include <vector>
using namespace std;

class Spiel {
public:
    void setZahlen(vector<int> zahlen) {
        gezogeneZahlen = zahlen;
    }
    vector<int> getZahlen() {
        return gezogeneZahlen;
    }
    bool gewonnen() {
        // Methodencode
        return false;
    }
private:
    vector<int> gezogeneZahlen;
};

class Spieler {
public:
    void setGewonnen(bool gewonnen) {
        this->gewonnen = gewonnen;
    }
    bool getGewonnen() {
        return gewonnen;
    }
private:
    bool gewonnen;
};

class Lotto {
public:
    void neuesSpiel() {
        spiele.push_back(Spiel());
        spieler.push_back(Spieler());
    }
    void spielerEingabe(Spieler spieler) {
        spiele.back().setZahlen(eingabeM(6, 49, 7));
    }

    vector<int> eingabeM(int zahlenSize, int zahlenRange, int ausgabeBreite) {
        cout << "Geben Sie " << zahlenSize << " Werte ein (1-" << zahlenRange << "):" << endl;
        bool istEinzigartig;
        int zahl = 0;
        vector<int> zahlen(zahlenSize);
        for (int i = 0; i < zahlenSize; i++) {
            do {
                cin >> zahl;
                istEinzigartig = true;
                for (int j = 0; j < i; j++) {
                    if (zahl < 1 || zahl > zahlenRange) {
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
        return zahlen;
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
  lotto.neuesSpiel();
  lotto.spielerEingabe(Spieler());
}
