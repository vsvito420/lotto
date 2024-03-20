#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

class Lotto {
public:
    Lotto(int numbersToDraw, int maxNumber);
    virtual ~Lotto(); // virtual weil es eine abgeleitete Klasse gibt
    void generateNumbers();
    void enterNumbers();
    void printNumbers();
    void printFrequency();
    void setNumbersToDraw(int numbersToDraw);
    void setMaxNumber(int maxNumber);
    void saveNumbers();
    void loadNumbers();

protected:
    int numbersToDraw;
    int maxNumber;
    vector<int> numbers;
    map<int, int> frequency;
    string filename;
};

Lotto::Lotto(int numbersToDraw, int maxNumber) {
    this->numbersToDraw = numbersToDraw;
    this->maxNumber = maxNumber;
    filename = "lotto_" + to_string(numbersToDraw) + "_" + to_string(maxNumber) + ".txt";
}

Lotto::~Lotto() {
    // Nothing to do
}

void Lotto::generateNumbers() {
    srand(time(0));
    frequency.clear();

    for (int i = 0; i < numbersToDraw; i++) {
        int number = rand() % maxNumber + 1;
        numbers.push_back(number);
        frequency[number]++;
    }
}

void Lotto::enterNumbers() {
    int number;
    numbers.clear();
    frequency.clear();



    for (int i = 0; i < numbersToDraw; i++) {
        cin >> number;

        if (number < 1 || number > maxNumber) {
            cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl zwischen 1 und " << maxNumber << " ein." << endl;
            i--;
        } else if (find(numbers.begin(), numbers.end(), number) != numbers.end()) {
            cout << "Diese Zahl wurde bereits eingegeben. Bitte geben Sie eine andere Zahl ein." << endl;
            i--;
        } else {
            numbers.push_back(number);
            frequency[number]++;
        }
    }
}

void Lotto::printNumbers() {
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }

    cout << endl;
}

void Lotto::printFrequency() {
    cout << "Häufigkeit der Zahlen: " << endl;

    for (auto const& pair : frequency) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

void Lotto::setNumbersToDraw(int numbersToDraw) {
    this->numbersToDraw = numbersToDraw;
}

void Lotto::setMaxNumber(int maxNumber) {
    this->maxNumber = maxNumber;
}

void Lotto::saveNumbers() {
    ofstream outfile(filename);

    if (outfile.is_open()) {
        for (int i = 0; i < numbers.size(); i++) {
            outfile << numbers[i] << " ";
        }

        outfile.close();
    } else {
        cout << "Fehler beim Speichern der Zahlen." << endl;
    }
}

void Lotto::loadNumbers() {
    numbers.clear();
    frequency.clear();
    ifstream infile(filename);
    int number;

    if (infile.is_open()) {
        while (infile >> number) {
            numbers.push_back(number);
            frequency[number]++;
        }

        infile.close();
    } else {
        cout << "Fehler beim Laden der Zahlen." << endl;
    }
}

class Lotto6aus49 : public Lotto {
public:
    Lotto6aus49();
};

Lotto6aus49::Lotto6aus49() : Lotto(6, 49) {
    // Nothing to do
}

class Eurolotto : public Lotto {
public:
    Eurolotto();
};

Eurolotto::Eurolotto() : Lotto(5, 50) {
    // Nothing to do
}

int main() {
    int choice;

    cout << "Willkommen beim Lotto-Programm!" << endl;
    cout << "Was mochten Sie tun?" << endl;
    cout << "1. Lotto 6 aus 49" << endl;
    cout << "2. Eurolotto" << endl;
    cout << "3. Zahlen speichern" << endl;
    cout << "4. Zahlen laden" << endl;
    cout << "5. Ende des Programmes" << endl;
    cin >> choice;

    Lotto* lotto;

    switch (choice) {
        case 1:
            lotto = new Lotto6aus49();
            lotto->generateNumbers();
            lotto->printNumbers();
            lotto->printFrequency();
            break;
        case 2:
            lotto = new Eurolotto();
            lotto->generateNumbers();
            lotto->printNumbers();
            lotto->printFrequency();
            break;
        case 3:
            cout << "Fuer welches Spiel moechten Sie Zahlen speichern?" << endl;
            cout << "1. Lotto 6 aus 49" << endl;
            cout << "2. Eurolotto" << endl;
            cin >> choice;

            if (choice == 1) {
                lotto = new Lotto6aus49();
                lotto->enterNumbers();
                lotto->saveNumbers();
            } else if (choice == 2) {
                lotto = new Eurolotto();
                lotto->enterNumbers();
                lotto->saveNumbers();
            } else {
                cout << "Ungueltige Eingabe. Bitte versuchen Sie es erneut." << endl;
            }
            break;
        case 4:
            cout << "Fuer welches Spiel moechten Sie Zahlen laden?" << endl;
            cout << "1. Lotto 6 aus 49" << endl;
            cout << "2. Eurolotto" << endl;
            cin >> choice;

            if (choice == 1) {
                lotto = new Lotto6aus49();
                lotto->loadNumbers();
                lotto->printNumbers();
                lotto->printFrequency();
            } else if (choice == 2) {
                lotto = new Eurolotto();
                lotto->loadNumbers();
                lotto->printNumbers();
                lotto->printFrequency();
            } else {
                cout << "Ungueltige Eingabe. Bitte versuchen Sie es erneut." << endl;
            }
            break;
        case 5:
            cout << "Auf Wiedersehen!" << endl;
            break;
        default:
            cout << "Ungueltige Eingabe. Bitte versuchen Sie es erneut." << endl;
            // restart menu
            main();
            break;
    }

    delete lotto;

    return 0;
}
