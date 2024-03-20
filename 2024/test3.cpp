#include <iostream>
#include <fstream>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <random>
#include <vector>

using namespace std;

class Lotto {
protected:
    unordered_set<int> numbers;
    int nNumbers;
    int nRange;
    int nLinebreak;
    Lotto(int numbers, int range, int linebreak) : nNumbers(numbers), nRange(range), nLinebreak(linebreak) {}

    void generateNumbers() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, nRange);

        while (numbers.size() < nNumbers) {
            numbers.insert(dis(gen));
        }
    }

    void saveNumbersToFile(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            for (int number : numbers) {
                file << number << endl;
            }
            file.close();
            cout << "Numbers saved to file: " << filename << endl;
        } else {
            cout << "Unable to open file: " << filename << endl;
        }
    }

    void loadNumbersFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            int number;
            while (file >> number) {
                numbers.insert(number);
            }
            file.close();
            cout << "Numbers loaded from file: " << filename << endl;
        } else {
            cout << "Unable to open file: " << filename << endl;
        }
    }

    void sortNumbers() {
        vector<int> sortedNumbers(numbers.begin(), numbers.end());
        sort(sortedNumbers.begin(), sortedNumbers.end());
        unordered_set<int> tempSet(sortedNumbers.begin(), sortedNumbers.end());
        numbers = tempSet;
    }

    void printNumbers() {
        int count = 0;
        for (int number = 1; number <= nRange; number++) {
            if (numbers.count(number) > 0) {
                cout << "(" << count << "x)" << setw(2) << setfill('0') << number << ", ";
                count++;
            } else {
                cout << "(0x)" << setw(2) << setfill('0') << number << ", ";
            }

            if ((number % nLinebreak) == 0) {
                cout << endl;
            }
        }
    }
};

class LottoController {
private:
    Lotto normalLotto;
    Lotto euroLotto;
public:
    LottoController() : normalLotto(6, 49, 7), euroLotto(7, 50, 10) {}

    void run() {
        int choice;
        string filename = "";

        do {
            cout << "Menu:" << endl;
            cout << "1. Normal Lotto" << endl;
            cout << "2. Euro Lotto" << endl;
            cout << "3. Load Numbers" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    cout << "Enter numbers manually (M) or generate random numbers (R)? ";
                    char inputType;
                    cin >> inputType;
                    if (inputType == 'M' || inputType == 'm') {
                        int number;
                        cout << "Enter " << normalLotto.nNumbers << " numbers between 1 and " << normalLotto.nRange << ": ";
                        for (int i = 0; i < normalLotto.nNumbers; i++) {
                            cin >> number;
                            normalLotto.numbers.insert(number);
                        }
                    } else if (inputType == 'R' || inputType == 'r') {
                        normalLotto.generateNumbers();
                    } else {
                        cout << "Invalid input." << endl;
                        break;
                    }
                    normalLotto.saveNumbersToFile("normal_lotto.txt");
                    normalLotto.loadNumbersFromFile("normal_lotto.txt");
                    normalLotto.sortNumbers();
                    normalLotto.printNumbers();
                    break;
                }
                case 2: {
                    cout << "Enter numbers manually (M) or generate random numbers (R)? ";
                    char inputType;
                    cin >> inputType;
                    if (inputType == 'M' || inputType == 'm') {
                        int number;
                        cout << "Enter 5 numbers between 1 and 50: ";
                        for (int i = 0; i < euroLotto.nNumbers - 2; i++) {
                            cin >> number;
                            euroLotto.numbers.insert(number);
                        }
                        cout << "Enter 2 numbers between 1 and 12: ";
                        for (int i = 0; i < 2; i++) {
                            cin >> number;
                            euroLotto.numbers.insert(number + 50);
                        }
                    } else if (inputType == 'R' || inputType == 'r') {
                        euroLotto.generateNumbers();
                    } else {
                        cout << "Invalid input." << endl;
                        break;
                    }
                    euroLotto.saveNumbersToFile("euro_lotto.txt");
                    euroLotto.loadNumbersFromFile("euro_lotto.txt");
                    euroLotto.sortNumbers();
                    euroLotto.printNumbers();
                    break;
                }
                case 3: {
                    cout << "Enter the filename: ";
                    cin >> filename;
                    normalLotto.loadNumbersFromFile(filename);
                    normalLotto.sortNumbers();
                    normalLotto.printNumbers();
                    break;
                }
                case 4:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }

            cout << endl;
        } while (choice != 4);
    }
};

int main() {
    LottoController controller;
    controller.run();

    return 0;
}
