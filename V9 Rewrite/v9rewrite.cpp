#include <iostream>
#include <map>
using namespace std;
#define color0 "\033[0m"  // Reset
#define color1 "\033[31m" // Rot
#define color2 "\033[32m" // Grün
#define color3 "\033[33m" // Gelb
#define color4 "\033[34m" // Blau
#define color5 "\033[35m" // Magenta
#define color6 "\033[36m" // Cyan

class Ticket // Lottery Ticket Lotto
{
    protected:
    int ticketAmountOfNumbers;
    int ticketRange;
    int ticketWidth;

    //map<ticketNumber, ticketNumberCount>
    map<int, int> mapTicketNumbers; 
    
    //Standard Constructor
    Ticket(){ cout << color1 << "Ticket constructed" << color0 << endl; }
    //Constructor with parameters
    Ticket(int ticketAmountOfNumbers, int ticketRange, int ticketWidth)
    {
        cout << color1 << "Ticket constructed for Lotto " << ticketAmountOfNumbers << " of " << ticketRange << " Width :" << ticketWidth << color0 <<endl;
    }

    friend class Program;   
};

class Table
{
    protected:
    //Standard Constructor
    Table(){ cout << color1 << "Table constructed default" << color0 << endl; }

    //Constructor with parameters
    Table(int tableWidth) { cout << color1 << "Table constructed with tableWidth" << tableWidth << color0 << endl;}

    friend class Program;
};

class Program
{
    protected:
    Ticket ticket;
    Table table;

    public:
    Program()
    {
        cout << color1 << "Program constructed" << color0 << endl;
        ticket = Ticket(6, 49, 7);

    }
};

int main()
{
    Program program; 
    return 0;
}