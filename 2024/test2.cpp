#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class LottoGenerator {
private:
    vector<int> numbers;
    int numberCount;
    int maxNumber;
    int anzeigeBreite;

public:
    LottoGenerator(int numberCount = 6, int maxNumber = 49, int anzeigeBreite = 0) : numberCount(numberCount), maxNumber(maxNumber), anzeigeBreite(anzeigeBreite) {
        srand(time(0)); // Setzt den Seed für die Zufallszahlen auf die aktuelle Zeit

        for (int i = 0; i < numberCount; i++) {
            numbers.push_back(generateNumber());
        }

        sort(numbers.begin(), numbers.end()); // Sortiert die Lottozahlen
    }

    void printNumbers() {
        cout << "Deine Lottozahlen sind: ";
        for (int number : numbers) {
            cout << number << " ";
        }
        cout << endl;
    }

private:
    int generateNumber() {
        int number = rand() % maxNumber + 1; // Generiert eine Zufallszahl zwischen 1 und maxNumber

        // Überprüft, ob die generierte Zahl bereits im Vektor vorhanden ist
        for (int n : numbers) {
            if (n == number) {
                return generateNumber(); // Wenn die Zahl bereits vorhanden ist, wird eine neue generiert
            }
        }

        return number;
    }
};

int main() {
    LottoGenerator generator1(6, 49, 7);
    generator1.printNumbers();

    LottoGenerator generator2(5, 50, 10);
    generator2.printNumbers();

    LottoGenerator generator3(2, 12, 6);
    generator3.printNumbers();

    return 0;
}
