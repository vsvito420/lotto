#include <iostream>
#include <vector>
using namespace std;
#define color0  "\033[0m"       // Reset
#define color1  "\033[31m"      // Rot
#define color2  "\033[32m"      // 
#define color3  "\033[33m"      // 
#define color4  "\033[34m"      // 
#define color5  "\033[35m"      // 
#define color6  "\033[36m"      // 

class C_LoteryGen{
public:
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
        int zahlen[zahlenSize];
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
};
class C_LoteryTicket {
public:
    
    struct s_element { // schein element , eine zahl und eine anzahl
        int i_zahl;
        int i_anzahl;
    };
    
    vector<s_element> vector;
    
    void m_zahlEingeben(int scheinZahlenAnzahl, int scheinRange,int ausgabeBreite){
        for (int i = 1; i <= scheinRange; ++i) {
            int temp;
            cin >> temp;
            s_element newZahl = {i, temp};
            vector.push_back(newZahl);
        }
    }

    void m_scheinPrint(int scheinBreite) {
        cout << color2 << "+--------------------o_lottoschein------------------------+" << color0 << endl;
        int j=0; // bugfix: use of j intead of i did the job
        for (size_t i = 0; i < vector.size(); ++i) {
            j++;
            cout << color2<< "|" << color0 ;
            cout << color1 << vector[i].i_anzahl << "x " << color0 << vector[i].i_zahl << "\t";
            if (j % scheinBreite == 0) {
                cout << color2<< "|" << color0 ;
                cout << endl;
            } else {
                
                continue;
            }
        }
        cout << color2 << "+-------------------------------------------------------+" << color0 << endl;
        cout << endl << vector[5].i_anzahl;
    }

private:

};

int main() {
    C_LoteryTicket o_lotto;
    o_lotto.m_zahlEingeben(6,49,7);
    o_lotto.m_scheinPrint(7);
    cout << endl;
    

    return 0;
}
