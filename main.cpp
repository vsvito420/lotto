#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Zahlen {
public:
    int zahl;
    int anzahl;

    Zahlen(int zahl, int anzahl) : zahl(zahl), anzahl(anzahl) {}
};

class Tippschein {
private:
    vector<Zahlen> zahlen;

public:
    void addZahl(int zahl, int anzahl) {
        zahlen.push_back(Zahlen(zahl, anzahl));
    }

    void vergleiche(Tippschein &andererTippschein) {
        // Implementieren Sie hier die Logik zum Vergleichen der Tippscheine
    }
};

class LottoSpiel {
private:
    vector<Tippschein> tippscheine;
    int lottoRange = 49;
    int lottoSize = 6;
    int ausgabeBreite = 7;

public:
    void addTippschein(Tippschein tippschein) {
        tippscheine.push_back(tippschein);
    }

    void vergleicheTippscheine() {
        // Implementieren Sie hier die Logik zum Vergleichen der Tippscheine
    }

    void eingabe(int lottoSize, int lottoRange) {
        set<int> eingabeZahlen;
        while (eingabeZahlen.size() < lottoSize) {
            int zufallszahl = rand() % lottoRange + 1;
            eingabeZahlen.insert(zufallszahl);
        }

        for (int zahl : eingabeZahlen) {
            cout << zahl << " ";
        }
        cout << endl;
    }

    void generieren(int lottoSize, int lottoRange) {
        set<int> generierteZahlen;
        while (generierteZahlen.size() < lottoSize) {
            int zufallszahl = rand() % lottoRange + 1;
            generierteZahlen.insert(zufallszahl);
        }

        for (int zahl : generierteZahlen) {
            cout << zahl << " ";
        }
        cout << endl;
    }

    void ausgabe(Tippschein tippschein, bool anzahlAusgeben) {
        vector<int> auswahl;
        for (Zahlen z : tippschein.zahlen) {
            auswahl.push_back(z.zahl);
        }
        ausgabeM(lottoRange, auswahl.size(), auswahl, ausgabeBreite);
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
};

int main() {
    LottoSpiel lottoSpiel;
    lottoSpiel.eingabe(6, 49);
    lottoSpiel.generieren(6, 49);
    // Vergleichen Sie die Tippscheine und geben Sie die Ergebnisse aus
}
