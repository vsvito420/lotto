#include <iostream>
#include <map>
#include <vector>
#include <random>
#include <algorithm>
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
private:
    int ticketAmountOfNumbers;
    int ticketRange;
    int ticketWidth;

    //map<ticketNumber, ticketNumberCount>
    map<int, int> mapTicketNumbers; 

public:    
    //Standard Constructor
    Ticket(){ cout << color1 << "Ticket   constructed" << color0 << endl; }
    
    //Constructor with parameters
    Ticket(int ticketAmountOfNumbers, int ticketRange, int ticketWidth)
    {
        cout << color1 << "Ticket   constructed for Lotto " << ticketAmountOfNumbers << " of " << ticketRange << " Width :" << ticketWidth << color0 <<endl;
    }
    
    //Destructor
    ~Ticket(){ cout << color1 << "Ticket   destructed" << color0 << endl; }

    //Methods
    /* Generates a map with random numbers
        @param ticketAmountOfNumbers: amount of random numbers in the ticket
        @param ticketRange: range of random numbers in the ticket
        @param ticketWidth: width of the ticket
        @return map with random numbers
    */
    map<int, int> generateMapTicketNumbers(int ticketAmountOfNumbers, int ticketRange, int ticketWidth)
    {
        map<int, int> mapTicketNumbers;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, ticketRange);
        for (int i = 0; i < ticketAmountOfNumbers; ++i)
        {
            int randomNumber = dis(gen);
            mapTicketNumbers.insert(pair<int, int>(randomNumber, 1));
        }
        return mapTicketNumbers;
    }
    //getters
    int getTicketAmountOfNumbers() { return ticketAmountOfNumbers; }
    int getTicketRange() { return ticketRange; }
    int getTicketWidth() { return ticketWidth; }
    map<int, int> getMapTicketNumbers() { return mapTicketNumbers; }
    
    friend class Program;   
};

class Table //prints map numbers and values 
{
    Ticket ticket;
    protected:
    
    //Standard Constructor
    Table(){ cout << color1 << "Table    constructed" << color0 << endl; }
    //Constructor with parameters
    Table(Ticket &ticket, int tableWidth) { cout << color1 << "Table constructed with tableWidth " << tableWidth << color0 << endl;}
        
    //Destructor
    ~Table(){ cout << color1 << "Table    destructed" << color0 << endl; }

    //print all numbers from map
    void printTable(int tableWidth)
    {
        for (int i = 0; i < ticket.getTicketRange(); i++)
        {
            /* code */
        }
        
    }

    friend class Program;
};

class Program
{
    protected:
    Ticket ticket;
    Table table;

    void createTicket(int ticketAmountOfNumbers, int ticketRange, int ticketWidth)
    {
        ticket = Ticket(ticketAmountOfNumbers, ticketRange, ticketWidth);
    }

    public:
    Program()   //Constructor
    {
        cout << color1 << "Program  constructed" << color0 << endl;
        createTicket(6, 49, 7);
    }
    ~Program()  //Destructor
    {
        cout << color1 << "Program  destructed" << color0 << endl;
    }
};

int main()
{
    Program program; 
    return 0;
}