#include <iostream>
#include <vector>
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

    void m_scheinPrint() {
        cout << color2 << "+--------------------o_lottoschein------------------------+" << color0 << endl;
        map<int, int> countMap;
        for (auto& el : vector) {
            countMap[el.i_zahl] = el.i_anzahl;
        }
        for (int i = 1; i <= 49; ++i) {
            cout << color2<< "|" << color0 ;
            if (countMap[i] == 0) {
                cout << color6 << countMap[i] << "x " << color0 << i << "\t";
            } else {
                cout << color1 << countMap[i] << "x " << color0 << i << "\t";
            }
            if (i % 7 == 0) {
                cout << color2<< "|" << color0 ;
                cout << endl;
            }
        }
        cout << color2 << "+-------------------------------------------------------+" << color0 << endl;
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

void createAndPrintTicket(C_LoteryTicket& ticket) {
    int choice;
    cout << "Möchten Sie die Zahlen selbst eingeben oder generieren lassen? (1 - Selbst eingeben, 2 - Generieren lassen): ";
    cin >> choice;
    if (choice == 1) {
        ticket.m_Tippschein(6,49);
    } else {
        ticket.m_Tippschein(6,49, true);
    }
    ticket.m_scheinPrint();
    cout << endl;
}

int main() {
    int numTickets;
    cout << "Wie viele Lottoscheine möchten Sie erstellen? ";
    cin >> numTickets;

    vector<C_LoteryTicket> tickets(numTickets);

    for (int i = 0; i < numTickets; i++) {
        createAndPrintTicket(tickets[i]);
    }

    cout << endl << "Alle Lottoscheine Anzahl+Zahlen: " << endl;
    for (int i = 1; i < numTickets; i++) {
        tickets[0].m_scheinOverlay(tickets[i]);
    }
    tickets[0].m_scheinPrint();

    return 0;
}