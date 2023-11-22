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

    void m_Tippschein(int zahlenSize, int scheinRange){
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

    void m_scheinPrint() {
        cout << color2 << "+--------------------o_lottoschein------------------------+" << color0 << endl;
        map<int, int> countMap;
        for (auto& el : vector) {
            countMap[el.i_zahl] = el.i_anzahl;
        }
        for (int i = 1; i <= 49; ++i) {
            cout << color2<< "|" << color0 ;
            cout << color1 << countMap[i] << "x " << color0 << i << "\t";
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

int main() {
    cout << color0 << "Vitos Lotto rewrite 4 mit Vektoren! "<< endl;
    C_LoteryTicket o_lotto;
    o_lotto.m_Tippschein(6,49);
    o_lotto.m_scheinPrint();
    cout << endl;

    // Erstellen Sie einen weiteren Lottoschein
    C_LoteryTicket o_anotherLotto;
    o_anotherLotto.m_Tippschein(6,49);
    o_anotherLotto.m_scheinPrint();
    cout << endl;

    // Überlagern Sie die beiden Lottoscheine
    o_lotto.m_scheinOverlay(o_anotherLotto);
    o_lotto.m_scheinPrint();

    return 0;
}
