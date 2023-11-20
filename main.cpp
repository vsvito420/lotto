#include <iostream>
#include <vector>
using namespace std;

const string colorRED = "\033[31m";
const string colorRST = "\033[0m";

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

    void ausgabeM(int zahlenRange, int zahlenSize, vector<int> zahlen, int ausgabeBreite) {
        cout << endl << "Ihre ausgewählten Zahlen sind:\n";
        for (int i = 1; i <= zahlenRange; i++) {
            bool isHighlighted = false;
            for (int j = 0; j < zahlenSize; j++) {
                if (i == zahlen[j]) {
                    isHighlighted = true;
                    break;
                }
            }
            if (isHighlighted) {
                cout << colorRED;
            }
            if (i < 10) {
                cout << "0" << i << " ";
            }
            if (i > 9) {
                cout << i << " ";
            }
            cout << colorRST;
            if (i % ausgabeBreite == 0) {
                cout << endl;
            }
        }
    }

    void ziehung() {
        bool istEinzigartig;
        int zahl = 0;
        vector<int> zahlen(6);
        srand(static_cast<unsigned int>(time(NULL)));
        for (int i = 0; i < 6; i++) {
            do {
                zahl = (rand() % 49) + 1;
                istEinzigartig = true;
                for (int j = 0; j < i; j++) {
                    if (zahlen[j] == zahl) {
                        istEinzigartig = false;
                        break;
                    }
                }
            } while (!istEinzigartig);
            zahlen[i] = zahl;
        }
        ausgabeM(49, 6, zahlen, 7);
    }

    void ergebnis() {
        // Methodencode
    }
public:
    vector<Spiel> spiele;
    vector<Spieler> spieler;
};

int main(){
  Lotto lotto;
  lotto.neuesSpiel();
  lotto.spielerEingabe(Spieler());
  lotto.ausgabeM(49, 6, lotto.spiele.back().getZahlen(), 7);
  lotto.ziehung();
}
