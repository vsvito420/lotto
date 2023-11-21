#include <iostream>
#include <vector>
using namespace std;
#define cRST  "\033[0m"       // Reset
#define cRED  "\033[31m"      // Rot

class Lotto {
public:
    struct Zahl {
        int number;
        int count;
    };

    void schein(int scheinRange, int scheinBreite) {
        vector<Zahl> vector;

        for (int i = 1; i <= scheinRange; ++i) {
            Zahl newZahl = {i, 0};
            vector.push_back(newZahl);
        }

        int j=0;
        for (size_t i = 0; i < vector.size(); ++i) {
            j++;
            cout << cRED << vector[i].count << "x " << cRST << vector[i].number << "\t";
            if (j % scheinBreite == 0) {
                cout << endl;
            } else {
                continue;
            }
            
        }
    }

private:

};

int main() {
    Lotto lotto;
    lotto.schein(49,7);

    return 0;
}
