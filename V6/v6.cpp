#include <iostream>
#include <map>
#include <set>
#include <random>
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
    int t_numCount = 0;     //Amount of numbers
    int t_numRange = 0;     //Number range
    int t_width = 0;        //Width of the ticket

    map<int, int>& getNumberAmount() 
    {
        return m_number_amount;
    }

protected:
    map<int, int> m_number_amount; // Numbers and amount
};

//Constructors          ####################
class Ticket_649 : public Ticket
{
public:
    Ticket_649()
    {
        t_numCount = 6;
        t_numRange = 49;
        t_width = 7;
    }
};
class Ticket_550 : public Ticket
{
public:
    Ticket_550()
    {
        t_numCount = 5;
        t_numRange = 50;
        t_width = 10;
    }
};
class Ticket_212 : public Ticket
{
public:
    Ticket_212()
    {
        t_numCount = 2;
        t_numRange = 12;
        t_width = 6;
    }
};  
//End of constructors   ####################

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
        cout << "\tLegende: "<< "(" << color2 << "Zahl" << color0 << ") x " << color1 << "Anzahl " << color0 << endl;
        cout << endl;
        
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

class Program
{
    Table table;
public:
    Ticket_649 ticket_649;
    Ticket_550 ticket_550;
    Ticket_212 ticket_212;
};

int main()
{
    //Init
    Program program;    // Create the program
    Ticket ticket;      // Create a ticket

    cout << color0;     // Reset color   
    cout << "End of main()" << endl;
    return 0;
}