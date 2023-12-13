// Creator:  VitoIKA922
// Date:     10-12-2023
#include <iostream>     // cout, cin, "\n"
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
    int t_numCount; // Anzahl der Zahlen
    int t_numRange; // Zahlenbereich
    int t_width;    // Breite der Ausgabe
    map<int, int> m_map_numberAmount; // Count how othen numbers were selected
    

public:
    
    Ticket() : t_numCount(0), t_numRange(0), t_width(0) {   // Constructor
        cout << color4 << "class "<< color3 << "Ticket:\t "<< color0 <<"\tconstructed" << color0 << "\n"; 
    };

    Ticket(int numCount, int numRange, int width) : t_numCount(numCount), t_numRange(numRange), t_width(width) // Parameterized Constructor
    {
        m_map_numberAmount = generateLottonumbers(t_numCount, t_numRange);
        cout << color4 << "class "<< color3 << "Ticket:\t. " << color0 <<"\t constructed" << color0 << "\n";
    }

    ~Ticket() // Destructor
    {
        // Destructor code here
        cout << color4 << "class "<< color3 << "Ticket:\t  "<< color0 <<"\t deconstructed" << color0 << "\n";
    }

    map<int, int> inputLottoTicketManual()      //Eingabe der Zahlen
    {
        map<int, int> map_numberAmount;         //Zahlen und Anzahl
        vector<int> numbers;                    //Zahlen
        int number = 0;
        for (int i = 1; i <= t_numCount; i++)
        {
            cout << "Bitte geben Sie die " << i << ". Zahl ein:" << "\n";
            cin >> number;
            numbers.push_back(number);          // Zahlen hinzufügen
        }
        for (int i = 0; i < t_numCount; i++)
        {
            map_numberAmount[numbers[i]] = 1;   // Zahlen in die map einfügen
        }
        return map_numberAmount;
    }

    map<int, int> generateLottonumbers(int numCount, int numRange) 
    {
        map<int, int> map_numberAmount;         // Map(Zahl): Anzahl
        vector<int> numbers;                    // Zahlen
        for (int i = 1; i <= numRange; i++)
        {
            numbers.push_back(i);               //Zahlen in den vector einfügen
        }
        random_device rd;
        default_random_engine generator(rd());
        shuffle(numbers.begin(), numbers.end(), generator); //Zahlen im vector mischen
        for (int i = 0; i < numCount; i++)
        {
            map_numberAmount[numbers[i]] = 1;   //Zahlen in die map einfügen
        }
        return map_numberAmount;  
    }

    map<int, int>& getNumberAmount() {          //Zahlen und Anzahl
        return m_map_numberAmount;
    }

    int getNumCount()  {                        //Anzahl der Zahlen
        return t_numCount;
    }

    int getNumRange()  {                        //Zahlenbereich
        return t_numRange;
    }

    int getWidth()  {                           //Breite der Ausgabe
        return t_width;
    }
};

class Table                                     // this class should be used to print the table of Ticket
{
public:
    //constructor
    Table()
    {
        cout << color4 << "class "<< color3 << "Table:\t "<< color0 <<"\tconstructed" << color0 << "\n";
    }
    //destructor
    ~Table()
    {
        // Destructor code here
        cout << color4 << "class "<< color3 << "Table:\t\t "<< color0 <<"deconstructed" << color0 << "\n";
    }


    void printTable(Ticket& ticket) // print the table of Ticket
    {
        cout << "Ihr Lottoschein:" << "\n";
        for (int k = 1; k < ticket.getWidth(); k++)
        {
            cout << "=========";
        }
        cout << "\nLegende: " << "" << color4 << "Zahl" << color0 << "^ " << color3 << "Anzahl " << color0 << "\n";
        cout << "\n";

        for (int i = 1; i <= ticket.getNumRange(); i++)
        {
            if (i < 10)
            {
                cout << color4 << " 0" << i << "" << color0 << "";
            }
            else
            {
                cout << color4 << " " << i << "" << color0 << "";
            }
            if (getNumberAmount(ticket, i) != 0)
            {
                cout << color3;
            }
            else
            {
                cout << color0;
            }
            int count = getNumberAmount(ticket, i);
            if (count == 0)     
            {
                cout << "⁰";
            }
            else
            {
                cout << toSuperscript(count);
            }
            cout << "\t";
            // every ticketWidth-th number a new line
            if (i % ticket.getWidth() == 0)
            {
                cout << "\n";
            }
        }
        for (int k = 1; k < ticket.getWidth(); k++)
        {
            cout << color0 << "=========";
        }
        cout << "\n";
        cout << "\n";
    }

    string toSuperscript(int number)
    {
        string superscript;
        string digits = to_string(number);
        for (char digit : digits)
        {
            switch (digit)
            {
            case '0':   superscript += "⁰";
                break;
            case '1':   superscript += "¹";
                break;
            case '2':   superscript += "²";
                break;
            case '3':   superscript += "³";
                break;
            case '4':   superscript += "⁴";
                break;
            case '5':   superscript += "⁵";
                break;
            case '6':   superscript += "⁶";
                break;
            case '7':   superscript += "⁷";
                break;
            case '8':   superscript += "⁸";
                break;
            case '9':   superscript += "⁹";
                break;
            }
        }
        return superscript;
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
    Table table;    // Table object
    Ticket ticket;  // Ticket object
public:
    Program() // Constructor
    {
        cout << color4 << "class "<< color3 <<"Program:\t "<< color0 <<"\tconstructed" << color0 << "\n";
    }

    ~Program()
    {
        // Destructor code here
        cout << color4 << "class "<< color3 <<"Program:\t "<< color0 <<"\t deconstructed" << color0 << "\n";
    }

    void start()
    {
        cout << color2 << ":Program Started:" << color0 << "\n";
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
            cout << "Bitte wählen Sie ein Spiel aus:" << "\n";
            cout << color4 << "\t\t1: preset 6 | 49" << color0 << "\n";
            cout << color4 << "\t\t2: preset 5 | 50" << color0 << "\n";
            cout << color4 << "\t\t3: preset 2 | 12" << color0 << "\n";
            cout << color5 << "\t\t4: customRunXofY" << color0 << "\n";
            cout << color5 << "\t\t5: customRunLoop" << color0 << "\n";
            cout << color6 << "\t\t6: inputNumbersIntoPool" << color0 << "\n";
            cout << color6 << "\t\t0: Beenden" << color0 << "\n";
            
            cin >> choice;
            switch (choice)
            {
            case 0:
                cout << color3 << "Beenden" << color0 << "\n";
                break;
            case 1:
                cout << "6 aus 49" << "\n";
                ticket = Ticket(6, 49, 7); // Constructor 
                table.printTable(ticket);
                break;
            case 2:
                cout << "5 aus 50" << "\n";
                ticket = Ticket(5, 50, 5);
                table.printTable(ticket);
                break;
            case 3:
                cout << "2 aus 12" << "\n";
                ticket = Ticket(2, 12, 6);
                table.printTable(ticket);
                break;
            case 4:
                cout << color4 << "customRun" << color0 << "\n";
                customRun();
                break;
            case 5:
                cout << color4 << "customRunLoop" << color0 << "\n";
                customRunLoop();
                break;
            case 6:
                cout << color4 << "inputNumbersIntoPool" << color0 << "\n";
                inputNumbersIntoPool();
                break;
            default:
                cout << color1 << "Falsche Eingabe" << color0 << "\n";
                break;
                
            }
        } while (choice != 0);
    }

    void customRunXofY(int x, int y, int z)
    {
        if (x > y) {
            cout << "Die Anzahl der zu ziehenden Zahlen kann nicht größer sein als der Zahlenbereich." << "\n";
            return;
        }
        if (z <= 0) {
            cout << "Die Anzahl der Zahlen pro Zeile muss größer als 0 sein." << "\n";
            return;
        }
        cout << x << " aus " << y << "\n";
        ticket = Ticket(x, y, z); //
        table.printTable(ticket);
    }
/*
Pool:
Es können manuell bis zu 30 Zahlen eingegeben werden.
Aus diesen Zahlen werden dann die Zufallszahlen für 6aus49 und 5aus50+2aus12 gezogen.
Die Eingabe erfolgt solange bis -1 eingegeben wird.
Bei der Eingabe werden die Zahlen auf überpfüft ob diese schon eingegeben wurden.
Im Fall einer doppelten Eingabe wird eine Fehlermeldung ausgegeben es ernuet zu versuchen.
*/
    void inputNumbersIntoPool()
    {
        vector<int> pool;
        int number = 0;
        do
        {
            cout << "Bitte geben Sie eine Zahl ein:" << "\n";
            cin >> number;
            if (number == -1)
            {
                break;
            }
            if (find(pool.begin(), pool.end(), number) != pool.end())
            {
                cout << "Diese Zahl wurde bereits eingegeben. Bitte versuchen Sie es erneut." << "\n";
            }
            else
            {
                pool.push_back(number);
            }
        } while (true);
        cout << "Die Zahlen im Pool sind:" << "\n";
        for (int i = 0; i < pool.size(); i++)
        {
            cout << pool[i] << "\t";
        }
        cout << "\n";
    }

    void customRun()
    {
        int custom_n = 0; //Anzahl der Zahlen
        int custom_r = 0; //Zahlenbereich
        int custom_w = 0; //Breite der Ausgabe
        
        cout << "Lotto" << "\n";

        cout << "Wie viele Zahlen sollen gezogen werden?" << "\n";
        cin >> custom_n;        cout << "Wie viele Zahlen sollen zur Auswahl stehen?" << "\n";
        
        cin >> custom_r;
        
        cout << "Wie viele Zahlen sollen pro Reihe angezeigt werden?" << "\n";
        cin >> custom_w;
        
        customRunXofY(custom_n, custom_r, custom_w);
    }

    void loop()
    {
        int custom_n = 0; //Anzahl der Zahlen
        int custom_r = 0; //Zahlenbereich
        int custom_w = 0; //Breite der Ausgabe
        
        cout << "Lotto" << "\n";

        cout << "Wie viele Zahlen sollen gezogen werden?" << "\n";
        cin >> custom_n;        cout << "Wie viele Zahlen sollen zur Auswahl stehen?" << "\n";
        
        cin >> custom_r;
        
        cout << "Wie viele Zahlen sollen pro Reihe angezeigt werden?" << "\n";
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
    program.start();
    cout << "Program exited successfully" << "\n";
    return 0;
}