// Creator:  VitoIKA922
// Date:     07-12-2023
#include <iostream>     // cout, cin
#include <vector>       // vector
#include <algorithm>    // find_if and find and sort and unique 
#include <map>          // map
#include <random>       // default_random_engine

using namespace std;
// Farben für die Ausgabe
#define color0 "\033[0m"  // Reset
#define color1 "\033[31m" // Rot
#define color2 "\033[32m" // Grün
#define color3 "\033[33m" // Gelb
#define color4 "\033[34m" // Blau
#define color5 "\033[35m" // Magenta
#define color6 "\033[36m" // Cyan


class Ticket    
{
private:
    int t_numCount; //Anzahl der Zahlen
    int t_numRange; //Zahlenbereich
    int t_width;    //Breite der Ausgabe
    map<int, int>  m_number_amount; //Zahlen und Anzahl

public:
    
    Ticket() : t_numCount(0), t_numRange(0), t_width(0) {
        cout << color4 << "class "<< color3 << "Ticket:\t "<< color0 <<"constructed" << color0 << endl;
    };

    Ticket(int numCount, int numRange, int width) : t_numCount(numCount), t_numRange(numRange), t_width(width)
    {
        m_number_amount = generateLottonumbers(t_numCount, t_numRange);
        cout << color4 << "class "<< color3 << "Ticket:\t. " << color0 <<"\t constructed" << color0 << endl;
    }

    ~Ticket()
    {
        // Destructor code here
        cout << color4 << "class "<< color3 << "Ticket:\t  "<< color0 <<"\t deconstructed" << color0 << endl;
    }

    map<int, int> inputLottoTicketManual()    //Eingabe der Zahlen
    {
        map<int, int> number_amount; //Zahlen und Anzahl
        vector<int> numbers;         //Zahlen
        int number = 0;
        for (int i = 1; i <= t_numCount; i++)
        {
            cout << "Bitte geben Sie die " << i << ". Zahl ein:" << endl;
            cin >> number;
            numbers.push_back(number); //Zahlen in den vector einfügen
        }
        for (int i = 0; i < t_numCount; i++)
        {
            number_amount[numbers[i]] = 1; //Zahlen in die map einfügen
        }
        return number_amount;
    }

    map<int, int> generateLottonumbers(int numCount, int numRange) 
    {
        map<int, int> number_amount; //Zahlen und Anzahl
        vector<int> numbers;         //Zahlen
        for (int i = 1; i <= numRange; i++)
        {
            numbers.push_back(i); //Zahlen in den vector einfügen
        } 
        random_device rd;
        default_random_engine generator(rd());
        shuffle(numbers.begin(), numbers.end(), generator); //Zahlen im vector mischen
        for (int i = 0; i < numCount; i++)
        {
            number_amount[numbers[i]] = 1; //Zahlen in die map einfügen
        }
        return number_amount;  
    }

    map<int, int>& getNumberAmount() {
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
    //constructor
    Table()
    {
        cout << color4 << "class "<< color3 << "Table:\t "<< color0 <<"\tconstructed" << color0 << endl;
    }
    //destructor
    ~Table()
    {
        // Destructor code here
        cout << color4 << "class "<< color3 << "Table:\t "<< color0 <<"deconstructed" << color0 << endl;
    }


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
        if (ticket.getNumberAmount().count(number) > 0)
        {
            return ticket.getNumberAmount().at(number);
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
        cout << color4 << "class "<< color3 <<"Program:\t "<< color0 <<"\t constructed" << color0 << endl;
    }

    ~Program()
    {
        // Destructor code here
        cout << color4 << "class "<< color3 <<"Program:\t "<< color0 <<"\t deconstructed" << color0 << endl;
    }

    void menu()
    {
        cout << color4 << "Game Start:" << color0 << endl;
        cout << "_____________________________"<< endl;
        run();
    }

    void customRunLoop()
    {
        loop();
    }
private:
    
    void run()
    {
        int choice = 0;
        do
        {
            cout << "Bitte wählen Sie ein Spiel aus:" << endl;
            cout << color4 << "\t\t1: preset 6 | 49" << color0 << endl;
            cout << color4 << "\t\t2: preset 5 | 50" << color0 << endl;
            cout << color4 << "\t\t3: preset 2 | 12" << color0 << endl;
            cout << color5 << "\t\t4: customRunXofY" << color0 << endl;
            cout << color5 << "\t\t5: customRunLoop" << color0 << endl;
            cout << color6 << "\t\t0: Beenden" << color0 << endl;
            cin >> choice;
            switch (choice)
            {
            case 0:
                cout << color3 << "Beenden" << color0 << endl;
                break;
            case 1:
                cout << "6 aus 49" << endl;
                ticket = Ticket(6, 49, 7); // Constructor 
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
            case 4:
                cout << color4 << "customRun" << color0 << endl;
                customRun();
                break;
            case 5:
                cout << color4 << "customRunLoop" << color0 << endl;
                customRunLoop();
                break;
            
            default:
                cout << color1 << "Falsche Eingabe" << color0 << endl;
                break;
                
            }
        } while (choice != 0);
    }

    void customRunXofY(int x, int y, int z)
    {
        cout << x << " aus " << y << endl;
        ticket = Ticket(x, y, z); //
        table.printTable(ticket);
    }

    void customRun()
    {
        int custom_n = 0; //Anzahl der Zahlen
        int custom_r = 0; //Zahlenbereich
        int custom_w = 0; //Breite der Ausgabe
        
        cout << "Lotto" << endl;

        cout << "Wie viele Zahlen sollen gezogen werden?" << endl;
        cin >> custom_n;        cout << "Wie viele Zahlen sollen zur Auswahl stehen?" << endl;
        
        cin >> custom_r;
        
        cout << "Wie viele Zahlen sollen pro Reihe angezeigt werden?" << endl;
        cin >> custom_w;
        
        customRunXofY(custom_n, custom_r, custom_w);
    }

    void loop()
    {
        int custom_n = 0; //Anzahl der Zahlen
        int custom_r = 0; //Zahlenbereich
        int custom_w = 0; //Breite der Ausgabe
        
        cout << "Lotto" << endl;

        cout << "Wie viele Zahlen sollen gezogen werden?" << endl;
        cin >> custom_n;        cout << "Wie viele Zahlen sollen zur Auswahl stehen?" << endl;
        
        cin >> custom_r;
        
        cout << "Wie viele Zahlen sollen pro Reihe angezeigt werden?" << endl;
        cin >> custom_w;
        
        do
        {
            customRunXofY(custom_n, custom_r, custom_w);
            cin.ignore();
        } while (true);
        
    }
   
};

int main()
{
    Program program;
    
    program.menu();
    
    cout << "Program exited successfully" << endl;
    return 0;
}