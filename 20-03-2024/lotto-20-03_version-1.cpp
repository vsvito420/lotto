#include <iostream>         // cout, cin
#include <ctime>            // time
#include <cstdlib>          // srand und rand
#include <iomanip>          // setw
using namespace std;        // std:: fällt weg

class LottoGame             // Klasse für das Lotto Spiel
{
private:
    int *numbers;           // Array für die Zahlen des Spielers
    int *winningNumbers;    // Array für die Gewinnzahlen
    int numCount;           // Anzahl der Zahlen des Spielers

public:
    LottoGame(int count = 6) : numCount(count) // Lotto Game with 6 numbers drawn
    {
        numbers = new int[numCount];        // Array für die Zahlen des Spielers
        winningNumbers = new int[numCount]; // Array für die Gewinnzahlen
    }
    ~LottoGame()    // Destructor
    {
        delete[] numbers;           // Löscht das Array der Zahlen des Spielers
        delete[] winningNumbers;    // Löscht das Array der Gewinnzahlen
    }
    void getNumbers() // Eingabe der Zahlen des Spielers
    {
        cout << "Enter " << numCount << " numbers between 1 and 49:" << "\n";   // Aufforderung zur Eingabe der Zahlen
        for (int i = 0; i < numCount; i++)  // Durchläuft die Zahlen des Spielers
        {
            while (true)
            {
                cin >> numbers[i];  // Eingabe der Zahlen
                if (numbers[i] >= 1 && numbers[i] <= 49)    // Prüft, ob die Zahl zwischen 1 und 49 liegt
                {
                    break;
                }
                cout << "Invalid number. Please enter a number between 1 and 49:" << "\n";
            }
        }
    }
    void generateNumbers() // Generiert die Gewinnzahlen
    {
        srand(time(0)); // Initialisiert den Zufallsgenerator
        for (int i = 0; i < numCount; i++)  // Generiert die Gewinnzahlen
        {
            winningNumbers[i] = rand() % 49 + 1;    // Zufällige Zahl zwischen 1 und 49
            for (int j = 0; j < i; j++) // Prüft, ob die Zahl bereits generiert wurde
            {
                if (winningNumbers[i] == winningNumbers[j])  // Falls ja, wird die Zahl erneut generiert
                {
                    i--;    // Dekrementiert i, um die Zahl erneut zu generieren
                    break;  
                }
            }
        }
    }

    void printWinningNumbers() // Druckt die Gewinnzahlen
    {
        cout << "Winning numbers:" << "\n";
        for (int i = 0; i < numCount; i++)
        {
            cout << winningNumbers[i] << " ";
        }
        cout << "\n";
    }

    void printTicket()  // Druckt den Lottoschein des Spielers
    {
        cout << "Your ticket:" << "\n";
        for (int i = 1; i <= 49; i++)   // Durchläuft die Zahlen von 1 bis 49
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
            
            if (i % 7 == 0) {   // Eine neue Zeile nach 7 Zahlen
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

int main()
{
    LottoGame game; // Erzeugt ein Lotto Spiel
    
    while (true)   // "\n"osschleife für das Spiel
    {
        game.getNumbers();          // Eingabe der Zahlen des Spielers
        game.generateNumbers();     // Generiert die Gewinnzahlen
        game.printTicket();         // Druckt den Lottoschein des Spielers
        game.checkTicket();         // Prüft, ob die Zahlen des Spielers mit den Gewinnzahlen übereinstimmen
        game.printWinningNumbers(); // Druckt die Gewinnzahlen
        
        cout << "Do you want to play again? (y/n): ";
        char answer;    // Variable für die Antwort des Spielers
        cin >> answer;  // Fragt den Spieler, ob er noch einmal spielen möchte
        if (answer != 'y')  // Beendet das Spiel, falls der Spieler nicht noch einmal spielen möchte
        {
            break;
        }
    }
    return 0;
}
