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
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>
using namespace std;

class Ticket
{   // Bauplan Lottoschein
public:
    static int currentID; // aktuelle TicketID
    //standardkonstruktor
    Ticket()
    {
        t_numCount = 0;
        t_numRange = 0;
        t_numWidth = 0;

    }
    //konstruktor mit parametern
    Ticket(int numCount, int numRange, int numWidth)
    {
        static int currentID;
        t_numCount = numCount;
        t_numRange = numRange;
        t_numWidth = numWidth;
        generateTicket();
        printTicket();

    }

    void printTicketRecursive(int i = 1) // rekursive Funktion zum Ausgeben des Tickets
    {
        if (i <= t_numRange)
        {
            if (i < 10)
            {
                cout << "0";
            }
            cout << i << "|" << m_map_numberAmount[i] << " ";
            if (i % t_numWidth == 0)
            {
                cout << endl;
            }
            printTicketRecursive(i + 1);
        }
    }

    void printTicket()
    {
        cout << "Lottoschein: " << endl;
        cout << "Lottoscheinzahlen|Anzahl: " << endl;
        printTicketRecursive();
    }
    void generateTicket()
    {
        // Zufallszahlen generieren
        vector<int> v_numRange;
        for (int i = 1; i <= t_numRange; i++)
        {
            v_numRange.push_back(i);
        }
        random_shuffle(v_numRange.begin(), v_numRange.end());
        // Zahlen in Map speichern
        for (int i = 0; i < t_numCount; i++)
        {
            m_map_numberAmount[v_numRange[i]]++;
        }
    }
    void inputTicket()
    {
        int input;
        for (int i = 0; i < t_numCount; i++)
        {
            cout << "Zahl " << i + 1 << ": ";
            cin >> input;
            m_map_numberAmount[input]++;
        }
    }
private:
    int t_numCount; // Anzahl der Zahlen
    int t_numRange; // Zahlenbereich
    int t_numWidth; // Breite der Ausgabe
    map<int, int> m_map_numberAmount; // Zahlen und Anzahl
};


int main()
{
    Ticket ticket;   
    //random generator 
    srand(time(NULL));


    ticket = Ticket(6, 49, 7);
}