#include <vector>           // Für die Verwendung von vector
#include <random>           // Für die Verwendung von random_device und mt19937
#include <iostream>         // Für die Verwendung von cout und cin
#include <iomanip>          // Für die Verwendung von setw und setfill
#include <algorithm>        // Für die Verwendung von find
using namespace std;    

class LottoGame
{
private:
    vector<int> numbers;           // Vector für die Zahlen des Spielers
    vector<int> winningNumbers;    // Vector für die Gewinnzahlen
    int numCount;                       // Anzahl der Zahlen des Spielers
    int numRange;                       // Bereich der Zahlen
    int newLine;                        // Zähler für die Zeilenumbrüche

public:
    LottoGame(int count, int range, int line) : numCount(count), numRange(range), newLine(line)    // Konstruktor für das Lotto Spiel
    {
        numbers.resize(numCount);        // Setzt die Größe des Vectors für die Zahlen des Spielers
        winningNumbers.resize(numCount); // Setzt die Größe des Vectors für die Gewinnzahlen
    }

    // Getter
    int getNumCount() { return numCount; }  // Gibt die Anzahl der Zahlen des Spielers zurück
    int getNumRange() { return numRange; }  // Gibt den Bereich der Zahlen zurück
    int getNewLine() { return newLine; }    // Gibt den Zähler für die Zeilenumbrüche zurück

    // Setter
    void setNumCount(int count) { numCount = count; }  // Setzt die Anzahl der Zahlen des Spielers
    void setNumRange(int range) { numRange = range; }  // Setzt den Bereich der Zahlen
    void setNewLine(int line) { newLine = line; }      // Setzt den Zähler für die Zeilenumbrüche

    void getNumbers() // Eingabe der Zahlen des Spielers
    {
        cout << "Enter " << numCount << " unique numbers between 1 and " << numRange << ":\n";   // Aufforderung zur Eingabe der Zahlen
        for (int i = 0; i < numCount; i++)  // Durchläuft die Zahlen des Spielers
        {
            while (true)
            {
                int num;
                cin >> num;  // Eingabe der Zahlen

                // Überprüfen, ob die Zahl bereits im Vektor vorhanden ist
                if (find(numbers.begin(), numbers.end(), num) != numbers.end())
                {
                    cout << "Duplicate number. Please enter a unique number.\n";
                    continue;
                }

                if (num >= 1 && num <= numRange)    // Prüft, ob die Zahl zwischen 1 und numRange liegt
                {
                    numbers[i] = num;
                    break;
                }
                cout << "Invalid number. Please enter a number between 1 and " << numRange << ":\n";
            }
        }
    }

    void generateNumbers() // Generiert die Gewinnzahlen
    {
        random_device rd;  // Erzeugt eine Zufallszahl
        mt19937 gen(rd()); // Initialisiert den Mersenne-Twister-Generator mit der erzeugten Zufallszahl
        uniform_int_distribution<> dis(1, numRange); // Erzeugt eine gleichmäßige Verteilung zwischen 1 und numRange

        for (int i = 0; i < numCount; i++)  // Generiert die Gewinnzahlen
        {
            winningNumbers[i] = dis(gen);    // Zufällige Zahl zwischen 1 und numRange
            for (int j = 0; j < i; j++) // Prüft, ob die Zahl bereits generiert wurde
            {
                if (winningNumbers[i] == winningNumbers[j])  // Falls ja, wird die Zahl erneut generiert
                {
                    i--; // Geht einen Schritt zurück in der Schleife, um die Zahl erneut zu generieren
                    break;
                }
            }
        }
    }

    void printMatchingNumbers() // Ausgabe der übereinstimmenden Zahlen
    {
        vector<int> matchingNumbers; // Vector für die übereinstimmenden Zahlen

        // Finden der übereinstimmenden Zahlen
        for (int i = 0; i < numCount; i++)
        {
            if (find(winningNumbers.begin(), winningNumbers.end(), numbers[i]) != winningNumbers.end())
            {
                matchingNumbers.push_back(numbers[i]);
            }
        }

        // Ausgabe der übereinstimmenden Zahlen
        cout << "You had following matching numbers: ";
        for (int i = 0; i < matchingNumbers.size(); i++)
        {
            cout << matchingNumbers[i];
            if (i != matchingNumbers.size() - 1) // Wenn es nicht das letzte Element ist, fügen Sie ein Komma hinzu
            {
                cout << ", ";
            }
        }
        cout << "\n";
    }

    vector<int> getNumbersFromPool() // Eingabe der Zahlen des Spielers aus einem Pool
    {
        vector<int> pool; // Vector für den Pool von Zahlen

        // Erstellen des Pools
        cout << "Enter unique numbers between 1 and " << numRange << " to form a pool (-1 to stop):\n";
        while (true)
        {
            int num;
            cin >> num;  // Eingabe der Zahlen

            if (num == -1) // Stoppen der Eingabe
            {
                break;
            }

            // Überprüfen, ob die Zahl bereits im Pool vorhanden ist
            if (find(pool.begin(), pool.end(), num) != pool.end())
            {
                cout << "Duplicate number. Please enter a unique number.\n";
                continue;
            }

            if (num >= 1 && num <= numRange)    // Prüft, ob die Zahl zwischen 1 und numRange liegt
            {
                pool.push_back(num);
            }
            else
            {
                cout << "Invalid number. Please enter a number between 1 and " << numRange << ":\n";
            }
        }

        // Ausgabe des Pools
        cout << "Pool: ";
        for (int i = 0; i < pool.size(); i++)
        {
            cout << pool[i];
            if (i != pool.size() - 1) // Wenn es nicht das letzte Element ist, fügen Sie ein Komma hinzu
            {
                cout << ", ";
            }
        }
        cout << "\n";

        // Zufällige Auswahl von Zahlen aus dem Pool
        random_device rd;  // Erzeugt eine Zufallszahl
        mt19937 gen(rd()); // Initialisiert den Mersenne-Twister-Generator mit der erzeugten Zufallszahl
        vector<int> selectedNumbers; // Vector für die ausgewählten Zahlen

        for (int i = 0; i < numCount; i++)
        {
            uniform_int_distribution<> dis(0, pool.size() - 1); // Erzeugt eine gleichmäßige Verteilung zwischen 0 und der Größe des Pools - 1
            int index = dis(gen); // Zufälliger Index
            selectedNumbers.push_back(pool[index]); // Hinzufügen der ausgewählten Zahl zum Vector
            pool.erase(pool.begin() + index); // Entfernen der ausgewählten Zahl aus dem Pool
        }
        
        return selectedNumbers;
    }

    void printNumbersFromPool(vector<int> selectedNumbers) // Ausgabe der ausgewählten Zahlen
    {
        cout << "Your numbers: ";
        for (int i = 0; i < selectedNumbers.size(); i++)
        {
            cout << selectedNumbers[i];
            if (i != selectedNumbers.size() - 1) // Wenn es nicht das letzte Element ist, fügen Sie ein Komma hinzu
            {
                cout << ", ";
            }
        }
        cout << "\n";
    }

    void printWinningNumbers() // Ausgabe- die Gewinnzahlen
    {
        cout << "Winning numbers:" << "\n";
        for (int i = 0; i < numCount; i++)
        {
            cout << winningNumbers[i] << " ";
        }
        cout << "\n";
    }

    void printTicket()  // Ausgabe den Lottoschein des Spielers
    {
        cout << "Your ticket:" << "\n";
        for (int i = 1; i <= numRange; i++)   // Durchläuft die Zahlen von 1 bis numRange
        {
            int count = 0;  // Zähler für die Treffer
            for (int j = 0; j < numCount; j++)  // Durchläuft die Zahlen des Spielers
            {
                if (i == numbers[j])    // Prüft, ob die Zahl des Spielers mit der aktuellen Zahl übereinstimmt
                {
                    count++;    // Zählt die Treffer
                }
            }
            cout << setw(2) << setfill('0') << i << " (" << count << "), "; // Druckt die Zahlen und die Anzahl der Treffer, setw und setfill sorgen für die korrekte Ausrichtung
            
            if (i % newLine == 0) {   // Eine neue Zeile nach newLine Zahlen
                cout << "\n";
            }
        }
        cout << "\n";
    }
    void checkTicket() // Prüft, ob die Zahlen des Spielers mit den Gewinnzahlen übereinstimmen
    {
        int matches = 0;    // Zähler für die Treffer
        for (int i = 0; i < numCount; i++)  // Durchläuft die Zahlen des Spielers
        {
            for (int j = 0; j < numCount; j++)  // Durchläuft die Gewinnzahlen
            {
                if (numbers[i] == winningNumbers[j])    // Vergleicht die Zahlen
                {
                    matches++;  // Zählt die Treffer
                }
            }
        }
        if (matches == numCount)    // Prüft, ob alle Zahlen übereinstimmen
        {
            cout << "Congratulations, you won!" << "\n";
        }
        else    // Falls nicht, gibt die Anzahl der Treffer aus
        {
            cout << "Sorry, you didn't win this time. You had " << matches << " matching numbers." << "\n";
        }
    }
};

class LottoController   // Controller-Klasse für das Lotto Spiel
{
    public:
    // Constructor
    LottoController(int count, int range, int line)
    {
        LottoGame game(count, range, line); // Erzeugt ein LottoGame-Objekt
        cout << "getNumbers" << "\n";
        game.getNumbers();              // Eingabe der Zahlen des Spielers
        
        cout << "generateNumbers" << "\n";
        game.generateNumbers();         // Generierung der Gewinnzahlen
        
        cout << "printWinningNumbers" << "\n";
        game.printWinningNumbers();     // Ausgabe der Gewinnzahlen
        
        cout << "printTicket" << "\n";
        game.printTicket();             // Ausgabe des Lottoscheins
        
        cout << "checkTicket" << "\n";
        game.checkTicket();             // Überprüfung des Tickets
        
        cout << "printMatchingNumbers" << "\n";
        game.printMatchingNumbers();    // Ausgabe der übereinstimmenden Zahlen
        
        cout << "getNumbersFromPool" << "\n";
        game.printNumbersFromPool(game.getNumbersFromPool()); // Ausgabe der ausgewählten Zahlen

    }

};

int main()
{
    cout << "Welcome to the Lotto Game!" << "\n";
    
    cout << "Lotto 6 aus 49" << "\n";
    LottoController lotto(6, 49, 7);
    
    cout << "Lotto 5 aus 50" << "\n";
    LottoController lotto2(5, 50, 10);
    
    cout << "Lotto 2 aus 12" << "\n";
    LottoController lotto3(2, 12, 6);


    return 0;
}
