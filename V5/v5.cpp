#include <iostream>     // cout, cin
#include <vector>       // vector
#include <algorithm>    // find_if and find and sort and unique 
#include <cstdlib>      // rand()
#include <map>          // map
#include <ctime>        // time()
using namespace std;

class Ticket    
{
public:
    int t_numCount = 0; //Anzahl der Zahlen
    int t_numRange = 0; //Zahlenbereich
    int t_width = 0;    //Breite der Ausgabe

    map<int, int> generateLottonumbers(int t_numCount, int t_numRange)
    {
        for (int i = 1; i <= t_numRange; i++)
        {
            m_number_amount[i] = 0;
        }
        for (int i = 1; i <= t_numCount; i++)
        {
            int number = rand() % t_numRange + 1;
            m_number_amount[number]++;
        }
        return m_number_amount;
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
    Ticket_649() //Constructor
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
    Ticket_550() //Constructor
    {
        t_numCount = 5;
        t_numRange = 50;
        t_width = 10;
        m_number_amount = generateLottonumbers(t_numCount, t_numRange);
    }
};

class Ticket_212 : public Ticket
{
public:
    Ticket_212() //Constructor
    {
        t_numCount = 2;
        t_numRange = 12;
        t_width = 5;
        m_number_amount = generateLottonumbers(t_numCount, t_numRange);
    }
};

class Table //this class should be used to print the table of Ticket
{
public:
    void printTable(Ticket& ticket)
    {
        cout << "Ihr Lottoschein:" << endl;
        cout << "================" << endl;
        cout << "Ziehung: " << endl;
        for (int i = 1; i <= ticket.t_numRange; i++)
        {
            cout << i << "\t";
            //every ticketWidth-th number a new line
            if (i % ticket.t_width == 0)
            {
                cout << endl;
            }
        }
        cout << endl;
        cout << "Anzahl:" << endl;
        for (int j = 1; j <= ticket.t_numRange; j++)
        {
            cout << ticket.getNumberAmount()[j] << "\t";
            if (j % ticket.t_width == 0)
            {
                cout << endl;
            }
        }
        cout << endl;
    }
private:
};

class Program   //this class should be used to manage the program
{   
public:
    Ticket_649 ticket_649;
    Ticket_550 ticket_550;
    Ticket_212 ticket_212;

    Program()
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
            case 1:
                cout << "6 aus 49" << endl;
                
                Table table;
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
            case 0:
                cout << "Beenden" << endl;
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
    srand(time(NULL));	//Zufallsgenerator initialisieren
    cout << "Programm zur Verwaltung von Lottoscheinen" << endl;
    Program program;

    return 0;
}