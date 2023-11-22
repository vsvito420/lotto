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

class C_LoteryTicket {
public:
    struct s_element { // schein element , eine zahl und eine anzahl
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
            return true; // Die Zahl ist gültig
        } 
        else{
            return false; // Die Zahl ist ungültig
        }       
    }

    void m_Tippschein(int zahlenSize, int scheinRange, int ausgabeBreite){
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
                        cout << "ERROR:"<< color3 << vector[j].i_zahl << color2 << " Wurde bereits gewählt!"<< color5 << endl;
                        IstEinzigartig = false;
                        break;
                    }
                }
            } while (!IstEinzigartig);
            s_element newZahl = {zahl, 1}; // Add this line to create a new element with the entered number and an count of 1
            vector.push_back(newZahl); // Add this line to add the new element to the vector
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
    }

private:
    vector<s_element> vector;
};

int main() {
    cout << color0 << "Vitos Lotto rewrite 4 mit Vektoren! "<< endl;
    C_LoteryTicket o_lotto;
    o_lotto.m_Tippschein(6,49,7);
    o_lotto.m_scheinPrint(7);
    cout << endl;
    return 0;
}
