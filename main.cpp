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

    const vector<s_element>& getVector() const { return m_vector; }

    bool pruefen(int zahl, int zahlenSize) const {
        return zahl >= 1 && zahl <= zahlenSize;
    }

    void setVector(const vector<s_element>& newVector) { m_vector = newVector; }

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
                    if (m_vector[j].i_zahl == zahl) {
                        cout << "ERROR: " << color3 << m_vector[j].i_zahl << color2 << " Wurde bereits gewählt!" << color5 << endl;
                        IstEinzigartig = false;
                        break;
                    }
                }
            } while (!IstEinzigartig);
            s_element newZahl = {zahl, 1}; 
            m_vector.push_back(newZahl); 
        }
    }

    void m_scheinPrint(int scheinBreite, int scheinRange) {
        cout << color5 << "+";
        for (int j = 0; j < scheinBreite; j++) {
            cout << "________" << color0;
        }
        cout << "+" << color0 << endl;

        map<int, int> countMap;
        for (auto& el : m_vector) {
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
        for (auto& el : m_vector) {
            countMap[el.i_zahl] += el.i_anzahl;
        }
        for (auto& el : other.getVector()) {
            countMap[el.i_zahl] += el.i_anzahl;
        }
        m_vector.clear();
        for (auto& pair : countMap) {
            m_vector.push_back({pair.first, pair.second});
        }
    }

private:
    vector<s_element> m_vector;
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
        cout << "5. Tippscheine überlagern\n";
        cout << "6. Benutzerdefinierten Tippschein erstellen\n";
        cout << "7. Ende des Programmes\n";
        cin >> auswahl;

        switch (auswahl) {
            case 1: {
                int choice;
                cout << "Möchten Sie die Zahlen selbst eingeben oder generieren lassen?" << endl << "(1 - Selbst eingeben, 2 - Generieren lassen): ";
                cin >> choice;
                if (choice == 1) {
                    ticket.m_Tippschein(6,49);
                } else if (choice == 2) {
                    ticket.m_Tippschein(6,49, true);
                } else {
                    cout << "Ungültige Auswahl. Bitte wählen Sie eine gültige Option.\n";
                }
                break;
            }
            case 2: {
                int choice;
                cout << "Möchten Sie die Zahlen selbst eingeben oder generieren lassen?" << endl << "(1 - Selbst eingeben, 2 - Generieren lassen): ";
                cin >> choice;
                if (choice == 1) {
                    ticket.m_Tippschein(5, 50);
                } else if (choice == 2) {
                    ticket.m_Tippschein(5, 50, true);
                } else {
                    cout << "Ungültige Auswahl. Bitte wählen Sie eine gültige Option.\n";
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
                C_LoteryTicket otherTicket;
                int choice;
                cout << "Möchten Sie die Zahlen selbst eingeben oder generieren lassen?" << endl << "(1 - Selbst eingeben, 2 - Generieren lassen): ";
                cin >> choice;
                if (choice == 1) {
                    otherTicket.m_Tippschein(6,49);
                } else if (choice == 2) {
                    otherTicket.m_Tippschein(6,49, true);
                } else {
                    cout << "Ungültige Auswahl. Bitte wählen Sie eine gültige Option.\n";
                    break;
                }
                ticket.m_scheinOverlay(otherTicket);
                cout << "Tippscheine erfolgreich überlagert.\n";
                break;
            }
            case 6: {
                int zahlenSize, scheinRange;
                cout << "Geben Sie die Anzahl der Zahlen ein: ";
                cin >> zahlenSize;
                cout << "Geben Sie den Bereich der Zahlen ein: ";
                cin >> scheinRange;
                ticket.m_Tippschein(zahlenSize, scheinRange);
                ticket.m_scheinPrint(zahlenSize, scheinRange);
                break;
            }
            case 7: {
                cout << "Programm beendet.\n";
                break;
            }
            default: {
                cout << "Ungültige Auswahl. Bitte wählen Sie eine gültige Option.\n";
            }
        }
    } while (auswahl != 7);

    return 0;
}