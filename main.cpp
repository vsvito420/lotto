#include <iostream>
#include <vector>
#include <map>
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

    vector<s_element> getVector() { return vector; }
    void setVector(vector<s_element> v) { vector = v; }

    virtual void m_Tippschein() = 0; // Pure virtual function

    void m_zahlEingeben(int i, int temp){
        s_element newZahl = {i, temp};
        vector.push_back(newZahl);
    }

    bool pruefen(int zahl, int zahlenSize) {
        if (zahl >= 1 && zahl <= zahlenSize) {
            return true; 
        } 
        else{
            return false; 
        }       
    }

    void m_scheinPrint() {
        cout << color2 << "+--------------------o_lottoschein------------------------+" << color0 << endl;
        map<int, int> countMap;
        for (auto& el : vector) {
            countMap[el.i_zahl] = el.i_anzahl;
        }
        for (int i = 1; i <= 50; ++i) {
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

protected:
    vector<s_element> vector;
};

class NormalLotto : public C_LoteryTicket {
public:
    void m_Tippschein() override {
        int zahlenSize = 6;
        int scheinRange = 49;
        bool IstEinzigartig=0;
        int zahl = 0;
        cout << "Geben Sie " << zahlenSize << " Werte ein (1-" << scheinRange << "):" << endl;
        for (int i = 0; i < zahlenSize; i++) {
            do {
                cin >> zahl;
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
};

class EuroLotto : public C_LoteryTicket {
public:
    void m_Tippschein() override {
        int zahlenSize = 5;
        int scheinRange = 50;
        bool IstEinzigartig=0;
        int zahl = 0;
        cout << "Geben Sie " << zahlenSize << " Werte ein (1-" << scheinRange << "):" << endl;
        for (int i = 0; i < zahlenSize; i++) {
            do {
                cin >> zahl;
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
        zahlenSize = 2;
        scheinRange = 12;
        cout << "Geben Sie " << zahlenSize << " Werte ein (1-" << scheinRange << "):" << endl;
        for (int i = 0; i < zahlenSize; i++) {
            do {
                cin >> zahl;
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
};

int main() {
    cout << color0 << "Vitos Lotto rewrite 4 mit Vektoren! "<< endl;
    int numTickets;
    cout << "Wie viele Lottoscheine möchten Sie eingeben? ";
    cin >> numTickets;
    vector<C_LoteryTicket*> tickets(numTickets);
    for (int i = 0; i < numTickets; ++i) {
        int type;
        cout << "Wählen Sie den Typ des Lottoscheins (1 für NormalLotto, 2 für EuroLotto): ";
        cin >> type;
        if (type == 1) {
            tickets[i] = new NormalLotto();
        } else if (type == 2) {
            tickets[i] = new EuroLotto();
        } else {
            cout << "Ungültige Eingabe! Bitte geben Sie 1 oder 2 ein." << endl;
            --i;
            continue;
        }
        tickets[i]->m_Tippschein();
        tickets[i]->m_scheinPrint();
        cout << endl;
    }

    // Überlagern Sie alle Lottoscheine
    C_LoteryTicket* o_combined = new NormalLotto(); // Erstellen Sie ein NormalLotto-Objekt für die kombinierten Lottoscheine
    for (auto& ticket : tickets) {
        o_combined->m_scheinOverlay(*ticket);
    }
    o_combined->m_scheinPrint();

    // Löschen Sie die dynamisch zugewiesenen Lottoscheine
    for (auto& ticket : tickets) {
        delete ticket;
    }
    delete o_combined;

    return 0;
}
