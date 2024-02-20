/* Dieses Programm ist eine Schulaufgabe. (alle namen sollen auf englisch sein)
Aufgabe: Schreiben Sie ein Lottoprogramm, das folgende Funktionen hat:
- Einlesen eines Lottoscheins (nutzereingabe oder zufällig)
- Zufälliges Erzeugen eines Lottoscheins
- Ausgabe eines Lottoscheins (beispiel 6 aus 49)
Ausgabe:
Lottoschein (lottoscheinnr)
Lottoscheinzahlen|Anzahl:
1|0 2|1 3|0 4|0 5|0 6|0 *zeilen umbruch nach ticket.getWidth() zahlen*
...bis 49 da 6 aus 49

Erweiterung:
- Ausgabe der Lottoscheine in einer Datenbank
- Einlesen der Lottoscheine aus einer Datenbank
- übereinanderlegen von Lottoscheinen (zahlen die auf mehreren Scheinen vorkommen werden zusammengezählt)
- Ausgabe der übereinandergelegten Lottoscheine
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

class Ticket
{ // Bauplan Lottoschein
public:
    static int currentID; // aktuelle TicketID
    // standardkonstruktor
    Ticket()
    {
        cout << "standardkonstruktor" << endl;
        t_numCount = 0;
        t_numRange = 0;
        t_numWidth = 0;
    }
    // Konstruktor mit Parametern
    Ticket(int numCount, int numRange, int numWidth)
    {
        static int currentID;
        cout << "Lottoschein: " << numCount << " aus " << numRange << "\tBreite :"<< numWidth << "\n";
        t_numCount = numCount;
        t_numRange = numRange;
        t_numWidth = numWidth;
        inputTicket();
        printTicket();
    }
    // Destruktor
    ~Ticket()
    {
        cout << "Lottoschein wurde gelöscht" << endl;
    }
    // rekursive Funktion zum Ausgeben des Tickets
    void printTicketRecursive(int i = 1)
    {
        // wenn die Zahl kleiner oder gleich dem Zahlenbereich ist, wird die Zahl ausgegeben
        if (i <= t_numRange)
        {
            cout << "-";
            if (i < 10)
            { // wenn die Zahl kleiner als 10 ist, wird eine 0 vor die Zahl gesetzt
                cout << "0";
            }
            cout << i << "|" << m_map_numberAmount[i] << " "
                 << "-\t"; // Zahl und Anzahl werden ausgegeben
            if (i % t_numWidth == 0)
            { // wenn die Zahl durch die Breite teilbar ist, wird ein Zeilenumbruch gemacht
                cout << endl;
            }
            printTicketRecursive(i + 1);
        }
    }

    void printTicket()
    { // Ausgabe des Tickets
        cout << "Lottoschein: " << endl;
        cout << "Lottoscheinzahlen|Anzahl: " << endl;
        printTicketRecursive();
    }
    void generateTicketRecursive(vector<int> &v_numRange, int i = 0)
    { // rekursive Funktion zum Erzeugen des Tickets
        if (i < t_numCount)
        {
            m_map_numberAmount[v_numRange[i]]++;
            generateTicketRecursive(v_numRange, i + 1);
        }
    }

    void generateTicket()
    {
        vector<int> v_numRange;
        for (int i = 1; i <= t_numRange; i++)
        {
            v_numRange.push_back(i);
        }
        random_shuffle(v_numRange.begin(), v_numRange.end());
        generateTicketRecursive(v_numRange);
    }

    void inputTicketRecursive(int i = 1)
    {
        if (i <= t_numCount)
        {
            int input;
            cout << "Zahl " << i << ": ";
            cin >> input;
            m_map_numberAmount[input]++;
            inputTicketRecursive(i + 1);
        }
    }

    void inputTicket()
    {
        inputTicketRecursive();
    }
    int t_numCount;                   // Anzahl der Zahlen
    int t_numRange;                   // Zahlenbereich
    int t_numWidth;                   // Breite der Ausgabe
    map<int, int> m_map_numberAmount; // Zahlen und Anzahl
};

int main()
{
    Ticket ticket;
    // random generator
    srand(time(NULL));
    ticket = Ticket(6, 49, 7);
}