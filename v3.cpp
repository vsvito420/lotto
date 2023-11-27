#include <iostream>     // cout, cin
#include <vector>       // vector
#include <algorithm>    // find_if and find and sort and unique 
#include <cstdlib>      // rand()
#include <map>          // map
using namespace std;

class Ticket    
{
public:
    int t_numCount = 0; //Anzahl der Zahlen
    int t_numRange = 0; //Zahlenbereich
    int t_width = 0;    //Breite der Ausgabe

    void userInputMap()
    {
        int input = 0;  //Eingabe
        int count = 0;  //Zähler
        while (count < t_numCount)
        {
            cout << "Bitte geben Sie eine Zahl zwischen 1 und " << t_numRange << " ein: ";
            cin >> input;
            if (input > 0 && input <= t_numRange)
            {
                m_number_amount[input]++;
                count++;
            }
            else
            {
                cout << "Die Zahl muss zwischen 1 und " << t_numRange << " liegen!" << endl;
            }
        }
    }
    void printMap()
    {
        for (auto it = m_number_amount.begin(); it != m_number_amount.end(); it++)
        {
            cout << it->first << " : " << it->second << endl;
        }
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
    }
};

class Program
{
public:
    void menu()
    {
        cout << "Bitte wählen Sie ein Spiel aus:" << endl;
        cout << "1: \t6 aus 49" << endl;
        cout << "2: \t5 aus 50" << endl;
        cout << "3: \t2 aus 12" << endl;
        cout << "4: \tBeenden" << endl;
    }
    void menuInput()
    {
        int input = 0;
        cout << "<(Bitte geben Sie eine Zahl zwischen 1 und 4 ein): ";
        cin >> input;
        switch (input)
        {
        case 1:
            cout << "|DEBUG: 6 aus 49 gewählt" << endl;
            
            break;
        case 2:
            cout << "|DEBUG: 5 aus 50 gewählt" << endl;
            
            break;
        case 3:
            cout << "|DEBUG: 2 aus 12 gewählt" << endl;
            
            break;
        case 4:
            cout << "|DEBUG: Beenden gewählt" << endl;
            break;
        default:
            cout << "Bitte geben Sie eine Zahl zwischen 1 und 4 ein!" << endl;
            break;
        }
    }
    void init()
    {
        
        Ticket_649 ticket_649;
        cout << "|DEBUG: ticket649 initialized" << endl;
        Ticket_550 ticket_550;
        cout << "|DEBUG: ticket550 initialized" << endl;
        Ticket_212 ticket_212;
        cout << "|DEBUG: ticket212 initialized" << endl;
        cout << "=========================================" << endl;  
    }

    void run()
    {
        cout << "\n|DEBUG: Program has started run()" << endl;
        init();
        menu();
        menuInput();
    }

private:

};

int main()
{
    cout << "Programm zur Verwaltung von Lottoscheinen" << endl;
    Program program;
    program.run();
    return 0;
}