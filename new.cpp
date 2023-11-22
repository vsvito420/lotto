#include <iostream>
#include <vector>
using namespace std;

class LotteryTicket {
public:
    struct Element {
        int number;
        int count;
    };

private:
    vector<Element> elements;

public:
    bool isValidNumber(int number, int maxNumber) {
        if (number >= 1 && number <= maxNumber) {
            return true;
        } else {
            return false;
        }
    }

    void enterNumber(int number, int maxNumber) {
        bool isUnique = true;
        for (size_t i = 0; i < elements.size(); i++) {
            if (!isValidNumber(number, maxNumber)) {
                isUnique = false;
                cout << "Invalid input! Please enter a number between 1 and " << maxNumber << "." << endl;
            }
            if (elements[i].number == number) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            Element newNumber = {number, 1};
            elements.push_back(newNumber);
        }
    }

    void printTicket(int ticketWidth) {
        cout << "+--------------------o_lottoschein------------------------+" << endl;
        int counter = 0;
        for (size_t i = 0; i < elements.size(); ++i) {
            counter++;
            cout << "|" << elements[i].count << "x " << elements[i].number << "\t";
            if (counter % ticketWidth == 0) {
                cout << "|" << endl;
            } else {
                continue;
            }
        }
        cout << "+-------------------------------------------------------+" << endl;
    }
};

int main() {
    LotteryTicket lotto;
    lotto.enterNumber(2, 6);
    lotto.printTicket(7);
    cout << endl;

    return 0;
}
