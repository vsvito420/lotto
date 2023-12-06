#include <iostream>     // cout, cin
#include <vector>       // vector
#include <algorithm>    // find_if and find and sort and unique 
#include <map>          // map
#include <ctime>        // time()
#include <cstdlib>      // Für rand() und srand()
#include <unordered_set>          // unordered_set
#include <chrono>       // system_clock
using namespace std;

#define color0 "\033[0m"  // Reset
#define color1 "\033[31m" // Rot
#define color2 "\033[32m" // Grün
#define color3 "\033[33m" // Gelb
#define color4 "\033[34m" // Blau
#define color5 "\033[35m" // Magenta
#define color6 "\033[36m" // Cyan

struct numberAndAmount
{
    int number;
    int amount;
};

class Ticket    
{
private:
    int t_numCount; //Anzahl der Zahlen
    int t_numRange; //Zahlenbereich
    int t_width;    //Breite der Ausgabe
    vector<numberAndAmount> m_number_amount; //Zahlen und Anzahl

public:
    Ticket() : t_numCount(0), t_numRange(0), t_width(0) {};
    Ticket(int numCount, int numRange, int width) : t_numCount(numCount), t_numRange(numRange), t_width(width)
    {
        m_number_amount = generateLottonumbers(t_numCount, t_numRange);
    }

    ~Ticket()
    {
        // Destructor code here
        cout << color1 << "Ticket:\t destructor" << color0 << endl;
    }

    vector<numberAndAmount> generateLottonumbers(int numCount, int numRange) 
    {
        vector<numberAndAmount> number_amount; //Zahlen und Anzahl
        vector<int> numbers;         //Zahlen
        srand(time(NULL));           //Zufallszahlengenerator initialisieren
        for (int i = 1; i <= numRange; i++)
        {
            numbers.push_back(i); //Zahlen in den vector einfügen
        }
        random_shuffle(numbers.begin(), numbers.end()); //Zahlen im vector mischen
        for (int i = 0; i < numCount; i++)
        {
            numberAndAmount numAmount;
            numAmount.number = numbers[i];
            numAmount.amount = 1;
            number_amount.push_back(numAmount); //Zahlen in den vector einfügen
        }
        return number_amount;  
    }

    vector<numberAndAmount>& getNumberAmount() {
        return m_number_amount;
    }

    int getNumCount()  {
        return t_numCount;
    }

    int getNumRange()  {
        return t_numRange;
    }

    int getWidth()  {
        return t_width;
    }
};

class Table // this class should be used to print the table of Ticket
{

public:
    void printTable( Ticket &ticket) // print the table of Ticket
    {
        cout << "Ihr Lottoschein:" << endl;
        for (int k = 1; k < ticket.getWidth(); k++)
        {
            cout << "=========";
        }
        cout << "\tLegende: "<< "(" << color2 << "Zahl" << color0 << ") x " << color1 << "Anzahl " << color0 << endl;
        cout << endl;
        
        for (int i = 1; i <= ticket.getNumRange(); i++)
        {
            if (i < 10)
            {
                cout << color2 << "(0" << i << ")" << color0 << "x";
            }
            else
            {
                cout << color2 << "(" << i << ")" << color0 << "x";
            }
            if (getNumberAmount(ticket, i) != 0)
            {
                cout << color1;
            }
            else
            {
                cout << color0;
            }
            cout << getNumberAmount(ticket, i) << color0 << "\t";
            // every ticketWidth-th number a new line
            if (i % ticket.getWidth() == 0)
            {
                cout << endl;
            }
        }
        for (int k = 1; k < ticket.getWidth(); k++)
        {
            cout << "=========";
        }
        cout << endl;
        cout << endl;
    }

private:
    int getNumberAmount( Ticket &ticket, int number)
    {
        for ( auto& numAmount : ticket.getNumberAmount())
        {
            if (numAmount.number == number)
            {
                return numAmount.amount;
            }
        }
        return 0;
    }
};

class Program // Manage the program
{
    Table table;
    Ticket ticket;

public:
    Program() // Constructor
    {
        cout << "Programm zur Verwaltung von Lottoscheinen" << endl;
    }

    ~Program()
    {
        // Destructor code here
        cout << color1 << "Program:\tdestructed" << color0 << endl;
    }

    void run()
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
                ticket = Ticket(6, 49, 7);
                table.printTable(ticket);
                break;
            case 2:
                cout << "5 aus 50" << endl;
                ticket = Ticket(5, 50, 5);
                table.printTable(ticket);
                break;
            case 3:
                cout << "2 aus 12" << endl;
                ticket = Ticket(2, 12, 6);
                table.printTable(ticket);
                break;
            default:
                cout << "Falsche Eingabe" << endl;
                break;
            }
        } while (choice != 0);
    }

    void customRunXofY(int x, int y, int z)
    {
        cout << x << " aus " << y << endl;
        ticket = Ticket(x, y, z);
        table.printTable(ticket);
    }
};

int main()
{
    Program program;
    program.customRunXofY(6, 49, 7);

    return 0;
}
