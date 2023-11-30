#include <iostream>     // cout, cin
#include <vector>       // vector
#include <algorithm>    // find_if and find and sort and unique 
#include <map>          // map
#include <ctime>        // time()
#include <random>       // default_random_engine, uniform_int_distribution
#include <unordered_set>// unordered_set
#include <chrono>       // system_clock
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
    int t_numCount = 0; //Anzahl der Zahlen
    int t_numRange = 0; //Zahlenbereich
    int t_width = 0;    //Breite der Ausgabe

    map<int, int> generateLottonumbers(int t_numCount, int t_numRange)
    {
        map<int, int> generatedNumbers;
        unordered_set<int> uniqueNumbers;

        // Initialize random engine
        std::default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> distribution(1, t_numRange);

        // Generate unique numbers
        while (uniqueNumbers.size() < t_numCount) {
            int number = distribution(engine);
            uniqueNumbers.insert(number);
        }

        // Initialize the number amount map
        for (int i = 1; i <= t_numRange; i++) {
            generatedNumbers[i] = 0;
        }

        // Count the generated numbers
        for (int number : uniqueNumbers) {
            generatedNumbers[number]++;
        }

        return generatedNumbers;
    }

    map<int, int>& getNumberAmount() {
        return m_number_amount;
    }

protected:
    map<int, int> m_number_amount; //Zahlen und Anzahl
};

class Ticket_649 : public Ticket
{
public:
    Ticket_649() // Constructor
    {
        t_numCount = 6;
        t_numRange = 49;
        t_width = 7;
        m_number_amount = generateLottonumbers(t_numCount, t_numRange);
    }
};

class Ticket_550 : public Ticket
{
public:
    Ticket_550() // Constructor
    {
        t_numCount = 5;
        t_numRange = 50;
        t_width = 5;
        m_number_amount = generateLottonumbers(t_numCount, t_numRange);
    }
};

class Ticket_212 : public Ticket
{
public:
    Ticket_212() // Constructor
    {
        t_numCount = 2;
        t_numRange = 12;
        t_width = 6;
        m_number_amount = generateLottonumbers(t_numCount, t_numRange);
    }
};


class Table // this class should be used to print the table of Ticket
{

public:
    void printTable(Ticket &ticket) // print the table of Ticket
    {
        cout << "Ihr Lottoschein:" << endl;
        for (int k = 1; k < ticket.t_width; k++)
        {
            cout << "=========";
        }
        cout << endl;
        cout << "(" << color2 << "Zahl" << color0 << ") x " << color1 << "Anzahl " << color0 << endl;
        for (int i = 1; i <= ticket.t_numRange; i++)
        {
            if (i < 10)
            {
                cout << color2 << "(0" << i << ")" << color0 << "x";
            }
            else
            {
                cout << color2 << "(" << i << ")" << color0 << "x";
            }
            if (ticket.getNumberAmount()[i] != 0)
            {
                cout << color1;
            }
            else
            {
                cout << color0;
            }
            cout << ticket.getNumberAmount()[i] << color0 << "\t";
            // every ticketWidth-th number a new line
            if (i % ticket.t_width == 0)
            {
                cout << endl;
            }
        }
        for (int k = 1; k < ticket.t_width; k++)
        {
            cout << "=========";
        }
        cout << endl;
        cout << endl;
    }

private:
};

class Program // Manage the program
{
    Table table;

public:
    Ticket_649 ticket_649;
    Ticket_550 ticket_550;
    Ticket_212 ticket_212;

    Program() // Constructor
    {
        int choice = 0;
        do
        {
            cout << "Bitte waehlen Sie ein Spiel aus:" << endl;
            cout << "1: 6 aus 49" << endl;
            cout << "2: 5 aus 50" << endl;
            cout << "3: 2 aus 12" << endl;
            cout << "0: Beenden" << endl;
            cin >> choice;
            switch (choice)
            {
            case 0:
                cout << "Beenden" << endl;
                break;
            case 1:
                cout << "6 aus 49" << endl;
                table.printTable(ticket_649);
                break;
            case 2:
                cout << "5 aus 50" << endl;
                table.printTable(ticket_550);
                break;
            case 3:
                cout << "2 aus 12" << endl;
                table.printTable(ticket_212);
                break;
            default:
                cout << "Falsche Eingabe" << endl;
                break;
            }
        } while (choice != 0);
    }

private:
};



int main()
{
    Ticket ticket;

    cout << "Programm zur Verwaltung von Lottoscheinen" << endl;
    Program program;

    return 0;
}