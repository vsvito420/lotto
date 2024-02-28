#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm> // Für std::find

using namespace std;

class C_Tippschein {
public:
    vector<int> v_tippschein;
    bool gewinn;

    C_Tippschein(vector<int> t) : v_tippschein(t), gewinn(false) {}

    vector<int> getTipps() {
        return v_tippschein;
    }

    void setGewinn(bool g) {
        gewinn = g;
    }

    bool isGewinn() {
        return gewinn;
    }
};

class C_Lotto {
private:
    vector<C_Tippschein> tippscheine;

public:

    void m_addTippschein(C_Tippschein t) {
        tippscheine.push_back(t);
    }

    void m_zieheGewinnzahlen(int a_zahlen_N, int zahlenRange) {
        for (int i = 0; i < a_zahlen_N; i++) {
            vector<int> v_tippschein;
            int zahl;
            bool istEinzigartig;
            do {
                zahl = (rand() % zahlenRange) + 1;
                istEinzigartig = true;
                for (int j = 0; j < i; j++) {
                    if (v_tippschein[j] == zahl) {
                        istEinzigartig = false;
                        break;
                    }
                }
                if (istEinzigartig) {
                    v_tippschein.push_back(zahl);
                }
            } while (!istEinzigartig);
            C_Tippschein schein(v_tippschein);
            this->m_addTippschein(schein);
        }
    }

    void pruefeGewinne() {
        vector<int> gewinnzahlen;
        for (auto &schein : tippscheine) {
            for (int zahl : schein.getTipps()) {
                gewinnzahlen.push_back(zahl);
            }
        }
        for (auto &schein : tippscheine) {
            for (int zahl : schein.getTipps()) {
                if (find(gewinnzahlen.begin(), gewinnzahlen.end(), zahl) == gewinnzahlen.end()) {
                    schein.setGewinn(false);
                    break;
                } else {
                    schein.setGewinn(true);
                }
            }
        }
    }
};

int main() {
    C_Lotto obj_Lotto;
    obj_Lotto.m_zieheGewinnzahlen(6,49);
    
    return 0;
}
