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
        vector<s_element> vector;

        for (int i = 1; i <= scheinRange; ++i) {
            s_element newZahl = {i, 0};
            vector.push_back(newZahl);
        }

        int j=0; // bugfix: use of j intead of i did the job
        for (size_t i = 0; i < vector.size(); ++i) {
            j++;
            cout << colorRED << vector[i].i_anzahl << "x " << colorRST << vector[i].i_zahl << "\t";
            if (j % scheinBreite == 0) {
                cout << endl;
            } else {
                continue;
            }
        }
        cout << endl << vector[5].i_anzahl;
    }

private:

};

int main() {
    C_LoteryTicket lotto;
    lotto.m_schein(49,7);
    cout << endl;
    

    return 0;
}
