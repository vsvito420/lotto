#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;

#define color0  "\033[0m"       // Reset
#define color1  "\033[31m"      // Rot
#define color2  "\033[32m"      // Grün
#define color3  "\033[33m"      // Gelb
#define color4  "\033[34m"      // Blau
#define color5  "\033[35m"      // Magenta
#define color6  "\033[36m"      // Cyan

class C_LoteryTicket {
public:
    struct s_element {
        int i_zahl;
        int i_anzahl;
    };

    const vector<s_element>& getVector() const { return vector; }

    bool pruefen(int zahl, int zahlenSize) const {
        return zahl >= 1 && zahl <= zahlenSize;
    }

    void m_Tippschein(int zahlenSize, int scheinRange, bool autoGenerate = false){
        bool IstEinzigartig=0;
        int zahl = 0;
        cout << "Geben Sie " << zahlenSize << " Werte ein (1-" << scheinRange << "):" << endl;
        for (int i = 0; i < zahlenSize; i++) {
            do {
                if (autoGenerate) {
                    zahl = (rand() % scheinRange) + 1;
                } else {
                    cin >> zahl;
                }
                IstEinzigartig = true;
                for (int j = 0; j < i; j++) {
                    if (!pruefen(zahl, scheinRange)) {
                        IstEinzigartig = false;
                        cout << "Ungültige Eingabe! Bitte geben Sie eine Zahl zwischen 1 und " << scheinRange << " ein." << endl;
                    }
                    if (vector[j].i_zahl == zahl) {
                        cout << "ERROR: " << color3 << vector[j].i_zahl << color2 << " Wurde bereits gewählt!" << color5 << endl;
                        IstEinzigartig = false;
                        break;
                    }
                }
            } while (!IstEinzigartig);
            s_element newZahl = {zahl, 1}; 
            vector.push_back(newZahl); 
        }
    }

    void m_scheinPrint(int scheinBreite, int scheinRange) {
        cout << color5 << "+";
        for (int j = 0; j < scheinBreite; j++) {
            cout << "________" << color0;
        }
        cout << "+" << color0 << endl;

        map<int, int> countMap;
        for (auto& el : vector) {
            countMap[el.i_zahl] = el.i_anzahl;
        }
        for (int i = 1; i <= scheinRange; ++i) {
            cout << color2 << "| " << color0;
            if (countMap[i] == 0) {
                cout << color6 << countMap[i] << "x " << color0 << i << "\t";
            } else {
                cout << color1 << countMap[i] << "x " << color0 << i << "\t";
            }
            if (i % scheinBreite == 0) {
                cout << color2 << "|" << color0;
                cout << endl;
            }
        }
        cout << color5 << "+";
        for (int j = 0; j < scheinBreite; j++) {
            cout << "________" << color0;
        }
        cout << "+" << color0 << endl;


    }

    void m_scheinOverlay(C_LoteryTicket& other) {
        map<int, int> countMap;
        for (auto& el : vector) {
            countMap[el.i_zahl] += el.i_anzahl;
        }
        for (auto& el : other.getVector()) {
            countMap[el.i_zahl] += el.i_anzahl;
        }
        vector.clear();
        for (auto& pair : countMap) {
            vector.push_back({pair.first, pair.second});
        }
    }

private:
    vector<s_element> vector;
};


int main() {
    srand(time(0)); // Initialisieren Sie den Zufallsgenerator

    C_LoteryTicket ticket; // Erstellen Sie ein Ticket-Objekt

    int auswahl;
    do {
        cout << "Bitte wählen Sie eine Option:\n";
        cout << "1. Lotto 6 aus 49\n";
        cout << "2. Eurolotto\n";
        cout << "3. Lotto 6 aus 49 Tippschein anzeigen\n";
        cout << "4. Eurolotto Tippschein anzeigen\n";
        cout << "5. Ende des Programmes\n";
        cin >> auswahl;

        switch (auswahl) {
            case 1: {
                int choice;
                cout << "Möchten Sie die Zahlen selbst eingeben oder generieren lassen?" << endl << "(1 - Selbst eingeben, 2 - Generieren lassen): ";
                cin >> choice;
                if (choice == 1) {
                    ticket.m_Tippschein(6,49);
                } else {
                    ticket.m_Tippschein(6,49, true);
                }
                break;
            }
            case 2: {
                // Implementieren Sie die Logik für "Eurolotto" hier
                int choice;
                cout << "Möchten Sie die Zahlen selbst eingeben oder generieren lassen?" << endl << "(1 - Selbst eingeben, 2 - Generieren lassen): ";
                cin >> choice;
                if (choice == 1) {
                    ticket.m_Tippschein(5, 50);
                } else {
                    ticket.m_Tippschein(5, 50, true);
                }
                break;
            }
            case 3: {
                ticket.m_scheinPrint(7,49);
                cout << endl;
                break;
            }
            case 4: {
                ticket.m_scheinPrint(5,50);;
                cout << endl;
                break;
            }
            case 5: {
                cout << "Programm beendet.\n";
                break;
            }
            default: {
                cout << "Ungültige Auswahl. Bitte wählen Sie eine gültige Option.\n";
            }
        }
    } while (auswahl != 5);

    return 0;
}