#include <iostream>
#include <vector>
using namespace std;
#define colorRST  "\033[0m"       // Reset
#define colorRED  "\033[31m"      // Rot

class C_LoteryTicket {
public:
    struct s_element { // schein element , eine zahl und eine anzahl
        int i_zahl;
        int i_anzahl;
    };

    void m_schein(int scheinRange, int scheinBreite) {
        vector<s_element> vec;

        for (int i = 1; i <= scheinRange; ++i) {
            s_element newZahl = {i, 0};
            vec.push_back(newZahl);
        }

        int j=0; // bugfix: use of j intead of i did the job
        for (size_t i = 0; i < vec.size(); ++i) {
            j++;
            cout << colorRED << vec[i].i_anzahl << "x " << colorRST << vec[i].i_zahl << "\t";
            if (j % scheinBreite == 0) {
                cout << endl;
            } else {
                continue;
            }
        }
        cout << endl << vec[5].i_anzahl;
    }

    void updateZahlen(vector<s_element>& vec, int slot, int wert) {
        for (size_t i = 0; i < vec.size(); ++i) {
            if (vec[i].i_zahl == slot) {
                vec[i].i_anzahl = wert;
                break;
            }
        }
    }

private:

};

int main() {
    C_LoteryTicket lotto;
    lotto.m_schein(49,7);

    // Beispiel: Aktualisiere die Zahl 5 mit dem Wert 3
    int slot = 5;
    int wert = 3;
    lotto.updateZahlen(slot, wert);
    
    return 0;
}
