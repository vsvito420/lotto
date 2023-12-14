#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm> 
#include <random>
using namespace std;

class Ticket
{
private:
    int t_numCount;         // Anzahl der Zahlen
    int t_numRange;         // Zahlenbereich
    int t_numWidth;         // Anzahl der Zahlen pro Zeile
    map<int, int> m_map_numberAmount; // MAP(Zahl): Anzahl

    //setmap
    void setMap(map<int, int> map_numberAmount)
    {
        m_map_numberAmount = map_numberAmount;
    }

public:
    map<int, int> generateNumbers(int numCount, int numRange)   // generate random numbers
    {
        map<int, int> map_numberAmount;                         // Map(Zahl): Anzahl
        vector<int> numbers;                                    // Zahlen
        for (int i = 1; i <= numRange; i++)
        {
            numbers.push_back(i);                               //Zahlen in den vector einfügen
        }

        random_device whatIsRandomAnyways;
        default_random_engine generator(whatIsRandomAnyways());
        shuffle(numbers.begin(), numbers.end(), generator);     //Zahlen im vector mischen
        for (int i = 0; i < numCount; i++)
        {
            map_numberAmount[numbers[i]] = 1;                   //Zahlen in die map einfügen
        }
        return map_numberAmount;  
    }

    // Default constructor
    Ticket() : t_numCount(0), t_numRange(0), t_numWidth(0)
    {
        cout << "Ticket  created with default constructor 0/0/0" << "\n";
    } 

    // Parameter constructor
    Ticket(int numCount, int numRange, int numWidth) 
    {
        cout << "Ticket  created" << " ["<< numCount << "/" << numRange << "/" << numWidth << "]"<< "\n";
    }

    // Destructor
    ~Ticket()
    {
        cout << "Ticket  destroyed" << "\n";
    } 

public:
    // Getter
    map <int, int> getMap(){    return m_map_numberAmount; }
    int getNumCount() {         return t_numCount; }
    int getNumRange(){          return t_numRange;}
    int getNumWidth(){          return t_numWidth;}
};


/*
Render a Table to Display the numbers of Ticket
1. show all elements from map
2. show all elements from map in a table
*/
class Table 
{
public:
    Table()
    {
        cout << "Table   created" << "\n";
    }
    ~Table()
    {
        cout << "Table   destroyed" << "\n";
    }
    /* Print the Table like this with the numbers of the map:
    amount should be map_numberAmount
     01(amount) 02(amount) 03(amount) 04(amount) 05(amount) 06(amount) 07(amount)
     08(amount) 09(amount) 10(amount) 11(amount) 12(amount) 13(amount) 14(amount)..
    */
    void printNumber(Ticket& ticket)
    {
        int numCount = ticket.getNumCount();
        int numRange = ticket.getNumRange();
        int numWidth = ticket.getNumWidth();
        map<int, int> map_numberAmount = ticket.getMap();
        int counter = 0;
        for (int i = 1; i <= numRange; i++)
        {
            if (map_numberAmount[i] == 1)
            {
                cout << i << " ";
                counter++;
                if (counter == numWidth)
                {
                    cout << "\n";
                    counter = 0;
                }
            }
        }
    }
};


class Program
{
private:
    Ticket ticket;  // Ticket
    Table table;    // Render Table
    
    void runTicketSelectionMenu()
    {
        cout << "Menu - Select what ticket should be created" << "\n";
        cout << "1. Normal  Lotto   6/49" << "\n";
        cout << "2. Euro    Lotto   5/50 + 2/10" << "\n";
        cout << "3. Custom          X/Y/Z" << "\n";
        cout << "0. Exit" << "\n";
        int input = 0;
        cin >> input;
        switch (input)
        {
        case 1:
            cout << "Normal Lotto" << "\n";
            ticket = Ticket(6, 49, 7);

            table.printNumber(ticket);
            break;
        case 2:
            cout << "Euro Lotto" << "\n";
            
            cout << "5/50" << "\n";
            ticket = Ticket(5, 50, 5);
            table.printNumber(ticket);
            cout << "\n";

            cout << "2/10" << "\n";
            ticket = Ticket(2, 12, 6);
            table.printNumber(ticket);
            break;
        }
    }
    void selectInputMethod()  
    {
        cout << "Menu" << "\n";
        cout << "1. Automatic" << "\n";
        cout << "2. Manual" << "\n";
        cout << "0. Exit          " << "\n";
        int input = 0;
        cin >> input;
        switch (input)
        {
        case 1:
            cout << "Automatic" << "\n";
            ticket.generateNumbers(6, 49);
            break;
        case 2:
            cout << "Manual" << "\n";

            break;
        }
    }
public:
    Program()   // Constructor
    {
        cout << "Program created" << "\n";
    }

    ~Program()  // Destructor
    {
        cout << "Program destroyed" << "\n";
    }

    void start() // Start the program
    {
        cout << "Program started" << "\n";
        runTicketSelectionMenu();
    }
};

int main()
{
    Program program;
    program.start();
    cout << "Program finished" << "\n";
    return 0;
}