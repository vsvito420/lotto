#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm> 
#include <random>
using namespace std;
// Farben für die Ausgabe
#define color0 "\033[0m"    // Reset
#define color1 "\033[31m"   // Rot
#define color2 "\033[32m"   // Grün
#define color3 "\033[33m"   // Gelb
#define color4 "\033[34m"   // Blau
#define color5 "\033[35m"   // Magenta
#define color6 "\033[36m"   // Cyan

class Ticket
{
private:
    int t_numCount;         // Anzahl der Zahlen
    int t_numRange;         // Zahlenbereich
    int t_numWidth;         // Anzahl der Zahlen pro Zeile
    map<int, int> m_map_numberAmount; // MAP(Zahl): Anzahl

public:
    //The generated numbers should be they Key and the Value should be the amount of the number.
    map<int, int> numbersGenerate(int numCount, int numRange)   // generate random numbers
    {
        cout << color1 << "numbersGenerate" << color0 << "\n";
        map<int, int> map_numberAmount;                         // Map(Zahl): Anzahl
        vector<int> numbers;                                    // Zahlen
        for (int i = 1; i <= numRange; i++)
        {
            numbers.push_back(i);                               //Zahlen in den vector einfügen
        }
        random_shuffle(numbers.begin(), numbers.end());         //Zahlen im vector mischen
        for (int i = 0; i < numCount; i++)
        {
            map_numberAmount[numbers[i]] = 1;                   //Zahlen in die map einfügen
        }
        return map_numberAmount;
    }

    map<int, int> numbersInput(int numCount, int numRange)      // input numbers
    {
        cout << color1 << "numbersInput" << color0 << "\n";
        map<int, int> map_numberAmount;                         // Map(Zahl): Anzahl
        vector<int> numbers;                                    // Zahlen
        for (int i = 1; i <= numRange; i++)
        {
            numbers.push_back(i);                               //Zahlen in den vector einfügen
        }
        int input = 0;
        for (int i = 0; i < numCount; i++)
        {
            cout << "Enter number " << i + 1 << " of " << numCount << ": ";
            cin >> input;
            map_numberAmount[input] = 1;                        //Zahlen in die map einfügen
        }
        return map_numberAmount;
    }

    // Default constructor
    Ticket() : t_numCount(0), t_numRange(0), t_numWidth(0)
    {
        cout << color2 << "Ticket  created with default constructor 0/0/0" << color0 << "\n";
    } 

    // Parameter constructor
    Ticket(int numCount, int numRange, int numWidth) 
    {
        cout << color2 << "Ticket  created" << " ["<< numCount << "/" << numRange << "/" << numWidth << "]"<< color0 << "\n";
        m_map_numberAmount = numbersGenerate(numCount, numRange);
        
    }

    // Destructor
    ~Ticket()
    {
        cout << color2 << "Ticket  destroyed" << color0 <<"\n";
    } 

public:
    // Getter
    map <int, int>& getMap()
    {
        return m_map_numberAmount; 
    }
    int getNumCount(){return t_numCount;}
    int getNumRange(){return t_numRange;}
    int getNumWidth(){return t_numWidth;}
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
        cout << color2 << "Table   created" << color0 << "\n";
    }
    ~Table()
    {
        cout << color2 << "Table   destroyed" << color0 << "\n";
    }
    /* Print Table with numbers from Ticket
    print the map from 1 to numRange
    make a line break after numWidth numbers

    */
    void printNumber(Ticket& ticket)
    {
        cout << color1 << "printNumber" << color0 << "\n";
        int numCount = ticket.getNumCount();
        int numRange = ticket.getNumRange();
        int numWidth = ticket.getNumWidth();
        map<int, int> map_numberAmount = ticket.getMap();
        int counter = 0;
        for (int i = 1; i <= numRange; i++)
        {
            if (map_numberAmount[i] == 1)
            {
                cout << color3 << i << color0 << " ";
                counter++;
            }
            else
            {
                cout << color1 << i << color0 << " ";
            }
            if (counter == numWidth)
            {
                cout << "\n";
                counter = 0;
            }
        }
    }
};


class Program
{
private:
    Ticket ticket;  // Ticket
    Table table;    // Render Table
public:
    Program()   // Constructor
    {
        cout << color2 << "Program created" << color0 << "\n";
    }

    ~Program()  // Destructor
    {
        cout << color2 << "Program destroyed" << color0 << "\n";
    }

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
            cout << "Normal Lotto Selected" << "\n";
            int x = 6;
            int y = 49;
            int z = 7;
            ticket = Ticket(x, y, z);
            selectInputMethod(x, y);
            break;
        }
    }
    void selectInputMethod(int x, int y)  
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
            ticket.numbersGenerate(x, y);
            table.printNumber(ticket);
            break;
        case 2:
            cout << "Manual" << "\n";
            ticket.numbersInput(x, y);
            table.printNumber(ticket);
            break;
        }
    }
    void start() // Start the program
    {
        cout << color2 << "Program started" << color0 << "\n";
        runTicketSelectionMenu();
        start();
    }
};

int main()
{
    Program program;
    program.start();
    cout << color2 << "\nProgram finished" << color0 << "\n";
    return 0;
}