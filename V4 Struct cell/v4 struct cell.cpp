#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;

#define color0 "\033[0m"  // Reset
#define color1 "\033[31m" // Rot
#define color2 "\033[32m" // Grün
#define color3 "\033[33m" // Gelb
#define color4 "\033[34m" // Blau
#define color5 "\033[35m" // Magenta
#define color6 "\033[36m" // Cyan

class Ticket
{
public:
    int t_Size;
    int t_Range;
    

    struct cell
    {
        int cellNumber;
        int cellAmount;
    };

    const vector<cell> &getVector() const { return vector; }

    bool pruefen(int zahl, int t_Size) const
    {
        return zahl >= 1 && zahl <= t_Size;
    }

    void input(int t_Size, int t_Range, bool autoGenerate = false)
    {
        bool IstEinzigartig = 0;
        int zahl = 0;
        cout << "Geben Sie " << t_Size << " Werte ein (1-" << t_Range << "):" << endl;
        for (int i = 0; i < t_Size; i++)
        {
            do
            {
                if (autoGenerate)
                {
                    zahl = (rand() % t_Range) + 1;
                }
                else
                {
                    cin >> zahl;
                }
                IstEinzigartig = true;
                for (int j = 0; j < i; j++)
                {
                    if (!pruefen(zahl, t_Range))
                    {
                        IstEinzigartig = false;
                        cout << "Ungültige Eingabe! Bitte geben Sie eine Zahl zwischen 1 und " << t_Range << " ein." << endl;
                    }
                    if (vector[j].cellNumber == zahl)
                    {
                        cout << "ERROR: " << color3 << vector[j].cellNumber << color2 << " Wurde bereits gewählt!" << color5 << endl;
                        IstEinzigartig = false;
                        break;
                    }
                }
            } while (!IstEinzigartig);
            cell newZahl = {zahl, 1};
            vector.push_back(newZahl);
        }
    }

    void output()
    {
        
        cout << color2 << "_______" << color0 << endl;
        
        map<int, int> countMap;
        for (auto &el : vector)
        {
            countMap[el.cellNumber] = el.cellAmount;
        }
        for (int i = 1; i <= 49; ++i)
        {
            cout << color2 << "|" << color0;
            if (countMap[i] == 0)
            {
                cout << color1 << countMap[i] << "x " << color0;
            }
            else
            {
                cout << color4 << countMap[i] << "x " << color0;
            }
            if (i < 10) {
                cout << "0"; // Add leading zero for single-digit numbers
            }
            cout << i;
            if (i % 7 == 0)
            {
                cout << color2 << "|" << color0;
                cout << endl;
            }
        }
        cout << color2 << "+-------------------------------------------------------+" << color0 << endl;
    }

    void overlay(Ticket &other)
    {
        map<int, int> countMap;
        for (auto &el : vector)
        {
            countMap[el.cellNumber] += el.cellAmount;
        }
        for (auto &el : other.getVector())
        {
            countMap[el.cellNumber] += el.cellAmount;
        }
        vector.clear();
        for (auto &pair : countMap)
        {
            vector.push_back({pair.first, pair.second});
        }
    }

private:
    vector<cell> vector;
};

void inputAuto(Ticket &ticket, int t_Size, int t_Range)
{
    int choice;
    cout << "Möchten Sie die Zahlen selbst eingeben oder generieren lassen?" << endl
         << "(1 - Selbst eingeben, 2 - Generieren lassen): ";
    cin >> choice;
    if (choice == 1)
    {
        ticket.input(6, 49);
    }
    else
    {
        ticket.input(6, 49, true);
    }
    ticket.output();
    cout << endl;
}

void start(int t_Size, int t_Range, bool autoGenerate = false)
{
    int numTickets;
    while (true)
    {
        cout << "Wie viele Lottoscheine möchten Sie erstellen? ";
        cin >> numTickets;
        if (cin.fail() || numTickets <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ungültige Eingabe. Bitte geben Sie eine positive Zahl ein." << endl;
        }
        else
        {
            break;
        }
    }

    vector<Ticket> tickets(numTickets);
    cout << "Möchten Sie die Lottoscheine generieren oder manuell eingeben?\n";
    cout << "1. Generieren\n";
    cout << "2. Manuell eingeben\n";

    int auswahl2;
    cin >> auswahl2;

    switch (auswahl2)
    {
    case 1:
    {
        for (int i = 0; i < numTickets; i++)
        {
            tickets[i].input(t_Size, t_Range, true);
        }
        break;
    }

    case 2:
    {
        for (int i = 0; i < numTickets; i++)
        {
            tickets[i].input(t_Size, t_Range);
        }
        break;
    }

    default:
    {
        cout << "Ungültige Auswahl. Bitte wählen Sie eine gültige Option.\n";
    }
    }

    cout << endl
         << "Alle Lottoscheine Anzahl+Zahlen: " << endl;
    for (int i = 1; i < numTickets; i++)
    {
        tickets[0].overlay(tickets[i]);
    }
    tickets[0].output();
}

void menuStartPage()
{
    int auswahl;
    do
    {
        cout << "! wählen Sie eine Option:\n";
        cout << "1. Lotto 6 aus 49\n";
        cout << "2. Eurolotto\n";
        cout << "3. Ende des Programmes\n";
        cin >> auswahl;

        switch (auswahl)
        {
        case 1:
        {
            Ticket lotto_649;
            start(6, 49);
            break;
        }

        case 2:
        {
            Ticket lotto_550;
            start(6, 49);
            Ticket lotto_212;
            start(6, 49);
            break;
        }

        case 3:
        {
            cout << "Programm beendet.\n";
            break;
        }

        default:
        {
            cout << "Ungültige Auswahl. Bitte wählen Sie eine gültige Option.\n";
        }
        }
    } while (auswahl != 3);
}

int main()
{
    srand(time(0));  // Initialisieren Sie den Zufallsgenerator
    menuStartPage(); // Starten Sie das Hauptmenü

    return 0;
}