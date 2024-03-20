#include <iostream>
#include <vector>
#include <random>
#include <sstream>
#include <iomanip>
using namespace std;


class Lotto {
private:
    int drawCount;
    int range;
    int drawWidth;
    vector<int> drawnNumbers;
    vector<vector<int>> drawHistory;
    mt19937 rng;

public:
    Lotto(int drawCount, int range, int drawWidth) : drawCount(drawCount), range(range), drawWidth(drawWidth), rng(random_device()()) {}

    void generateNumbers() {
        drawnNumbers.clear();
        uniform_int_distribution<int> dist(1, range);
        for (int i = 0; i < drawCount; ++i) {
            int num = dist(rng);
            drawnNumbers.push_back(num);
        }
        drawHistory.push_back(drawnNumbers);
    }

    void printNumbers() {
        vector<int> count(range + 1, 0);
        for (const auto& num : drawnNumbers) {
            ++count[num];
        }

        for (int i = 1; i <= range; ++i) {
            stringstream ss;
            ss << setw(drawWidth) << setfill('0') << count[i] << " " << setw(drawWidth) << setfill('0') << i;
            cout << ss.str() << " | ";
            if (i % (drawCount / 2) == 0) {
                cout << endl;
            }
        }
    }

    string vectorToString(const vector<int>& v) {
        stringstream ss;
        for (const auto& num : v) {
            ss << num << " ";
        }
        return ss.str();
    }
};

int main() {
    Lotto lotto(6, 49, 7);
    lotto.generateNumbers();
    lotto.printNumbers();

    return 0;
}
