#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <map>
#include <limits>
#include <algorithm>

class Lotto {
public:
    Lotto(int numbersToDraw, int maxNumber);
    virtual ~Lotto();
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
    std::vector<int> numbers;
    std::map<int, int> frequency;
    std::string filename;
};

Lotto::Lotto(int numbersToDraw, int maxNumber) {
    this->numbersToDraw = numbersToDraw;
    this->maxNumber = maxNumber;
    filename = "lotto_" + std::to_string(numbersToDraw) + "_" + std::to_string(maxNumber) + ".txt";
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
        while (!(std::cin >> number)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << std::endl;
        }

        if (number < 1 || number > maxNumber) {
            std::cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl zwischen 1 und " << maxNumber << " ein." << std::endl;
            i--;
        } else if (find(numbers.begin(), numbers.end(), number) != numbers.end()) {
            std::cout << "Diese Zahl wurde bereits eingegeben. Bitte geben Sie eine andere Zahl ein." << std::endl;
            i--;
        } else {
            numbers.push_back(number);
            frequency[number]++;
        }
    }
}

void Lotto::printNumbers() {
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }

    std::cout << std::endl;
}

void Lotto::printFrequency() {
    std::cout << "Häufigkeit der Zahlen: " << std::endl;

    for (auto const& pair : frequency) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

void Lotto::setNumbersToDraw(int numbersToDraw) {
    this->numbersToDraw = numbersToDraw;
}

void Lotto::setMaxNumber(int maxNumber) {
    this->maxNumber = maxNumber;
}

void Lotto::saveNumbers() {
    std::ofstream outfile(filename);

    if (outfile.is_open()) {
        for (int i = 0; i < numbers.size(); i++) {
            outfile << numbers[i] << " ";
        }

        outfile.close();
    } else {
        std::cout << "Fehler beim Speichern der Zahlen." << std::endl;
    }
}

void Lotto::loadNumbers() {
    numbers.clear();
    frequency.clear();
    std::ifstream infile(filename);
    int number;

    if (infile.is_open()) {
        while (infile >> number) {
            numbers.push_back(number);
            frequency[number]++;
        }

        infile.close();
    } else {
        std::cout << "Fehler beim Laden der Zahlen." << std::endl;
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

    while (true) {
        std::cout << "Willkommen beim Lotto-Programm!" << std::endl;
        std::cout << "Was mochten Sie tun?" << std::endl;
        std::cout << "1. Lotto 6 aus 49" << std::endl;
        std::cout << "2. Eurolotto" << std::endl;
        std::cout << "3. Zahlen speichern" << std::endl;
        std::cout << "4. Zahlen laden" << std::endl;
        std::cout << "5. Ende des Programmes" << std::endl;

        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << std::endl;
        }

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
                std::cout << "Fuer welches Spiel moechten Sie Zahlen speichern?" << std::endl;
                std::cout << "1. Lotto 6 aus 49" << std::endl;
                std::cout << "2. Eurolotto" << std::endl;

                while (!(std::cin >> choice)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << std::endl;
                }

                if (choice == 1) {
                    lotto = new Lotto6aus49();
                    lotto->enterNumbers();
                    lotto->saveNumbers();
                } else if (choice == 2) {
                    lotto = new Eurolotto();
                    lotto->enterNumbers();
                    lotto->saveNumbers();
                } else {
                    std::cout << "Ungueltige Eingabe. Bitte versuchen Sie es erneut." << std::endl;
                }
                break;
            case 4:
                std::cout << "Fuer welches Spiel moechten Sie Zahlen laden?" << std::endl;
                std::cout << "1. Lotto 6 aus 49" << std::endl;
                std::cout << "2. Eurolotto" << std::endl;

                while (!(std::cin >> choice)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein." << std::endl;
                }

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
                    std::cout << "Ungueltige Eingabe. Bitte versuchen Sie es erneut." << std::endl;
                }
                break;
            case 5:
                std::cout << "Auf Wiedersehen!" << std::endl;
                delete lotto;
                return 0;
            default:
                std::cout << "Ungueltige Eingabe. Bitte versuchen Sie es erneut." << std::endl;
                break;
        }

        delete lotto;
    }

    return 0;
}
