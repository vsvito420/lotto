#include <iostream>
#include <random>
#include <algorithm>
#include <map>
using namespace std;
#define color0 "\033[0m"  // Reset
#define color1 "\033[31m" // Rot
#define color2 "\033[32m" // Grün
#define color3 "\033[33m" // Gelb
#define color4 "\033[34m" // Blau
#define color5 "\033[35m" // Magenta
#define color6 "\033[36m" // Cyan

class Ticket // Store the ticket
{
    Table table; // Table class to print the table of Ticket
private:
    int t_numCount;                   // Anzahl der Zahlen
    int t_numRange;                   // Zahlenbereich
    int t_numWidth;                   // Anzahl der Zahlen pro Zeile
    map<int, int> m_map_numberAmount; // MAP(Zahl): Anzahl
protected:
    map<int, int> generateNumbers(int numCount, int numRange) // generate random numbers
    {
        map<int, int> map_numberAmount; // Map(Zahl): Anzahl
        vector<int> numbers;            // Zahlen
        for (int i = 1; i <= numRange; i++)
        {
            numbers.push_back(i); // Zahlen in den vector einfügen
        }

        random_device whatIsRandomAnyways;
        default_random_engine generator(whatIsRandomAnyways());
        shuffle(numbers.begin(), numbers.end(), generator); // Zahlen im vector mischen
        for (int i = 0; i < numCount; i++)
        {
            map_numberAmount[numbers[i]] = 1; // Zahlen in die map einfügen
        }
        return map_numberAmount;
    }

public:
    // Constructor
    Ticket() : t_numCount(0), t_numRange(0), t_numWidth(0)
    {
        cout << color4 << "class " << color3 << "Ticket:\t " << color0 << "\tconstructed" << color0 << "\n";
    };
    // Parameterized Constructor
    Ticket(int numCount, int numRange, int width) : t_numCount(numCount), t_numRange(numRange), t_numWidth(width)
    {
        m_map_numberAmount = generateNumbers(t_numCount, t_numRange);
        cout << color4 << "class " << color3 << "Ticket:\t. " << color0 << "\t constructed with " << t_numCount << " " << t_numRange << " " << t_numWidth << color0 << "\n";
    }
    // Destructor
    ~Ticket()
    {
        cout << color4 << "class " << color3 << "Ticket:\t  " << color0 << "\t deconstructed" << color0 << "\n";
    }
    // Map(Zahl): Anzahl
    map<int, int> inputLottoTicketManual()
    {
        cout << "manual"
             << "\n";
        map<int, int> map_numberAmount; // Zahlen und Anzahl
        vector<int> numbers;            // Zahlen
        int number = 0;
        for (int i = 1; i <= t_numCount; i++)
        {
            cout << "Bitte geben Sie die " << i << ". Zahl ein:"
                 << "\n";
            cin >> number;
            numbers.push_back(number); // Add number to vector
        }
        for (int i = 0; i < t_numCount; i++)
        {
            map_numberAmount[numbers[i]] = 1; // Insert number into map
        }
        return map_numberAmount;
    }

    map<int, int> &getNumberAmount()
    { // Zahlen und Anzahl
        return m_map_numberAmount;
    }

    int getNumCount()
    { // Anzahl der Zahlen
        return t_numCount;
    }

    int getNumRange()
    { // Zahlenbereich
        return t_numRange;
    }

    int getWidth()
    { // Breite der Ausgabe
        return t_numWidth;
    }
};

class Table // this class should be used to print the table of Ticket
{
public:
    // constructor
    Table()
    {
        cout << color4 << "class " << color3 << "Table:\t " << color0 << "\tconstructed" << color0 << "\n";
    }
    // Destructor code here
    ~Table()
    {
        cout << color4 << "class " << color3 << "Table:\t\t " << color0 << "deconstructed" << color0 << "\n";
    }

    void printTable(Ticket &ticket) // print the table of Ticket
    {
        cout << "Ihr Lottoschein:"
             << "\n";
        int width = ticket.getWidth();
        int numRange = ticket.getNumRange();
        map<int, int> &numberAmount = ticket.getNumberAmount();

        cout << "\nLegende: "
             << "" << color4 << "Zahl" << color0 << "^ " << color3 << "Anzahl " << color0 << "\n";
        cout << "\n";

        for (int k = 1; k < width + 1; k++) // print top line
        {
            cout << color0 << "------\t";
        }
        cout << "\n";

        for (int i = 1; i <= numRange; i++) // print the table
        {
            cout << color0 << "|" << color4 << " ";
            if (i < 10) // add a Zero before the number if it is smaller than 10 to make it look nice
            {
                cout << "0";
            }
            cout << i << "" << color0 << "";

            int count = getNumberAmount(numberAmount, i);
            if (count != 0)
            {
                cout << color3 << toSuperscript(count);
            }
            else
            {
                cout << color0 << "⁰";
            }
            cout << "\t";

            // every ticketWidth-th number a new line
            if (i % width == 0)
            {
                cout << "\n";
            }
        }

        for (int k = 1; k < width + 1; k++) // print bottom line
        {
            cout << color0 << "------\t";
        }
        cout << "\n";
        cout << "\n";
    }

    string toSuperscript(int number)
    {
        string superscript;
        string digits = to_string(number);
        string superscripts[] = {"⁰", "¹", "²", "³", "⁴", "⁵", "⁶", "⁷", "⁸", "⁹"};
        for (char digit : digits)
        {
            int index = digit - '0';
            superscript += superscripts[index];
        }
        return superscript;
    }

private:
    int getNumberAmount(const map<int, int> &numberAmount, int number) // get the amount of a number
    {
        auto it = numberAmount.find(number);
        if (it != numberAmount.end()) // if the number is in the map
        {
            return it->second; // return the amount of the number
        }
        return 0; // else return 0
    }
};

int main() {
    cout << "Normales Lotto" << "\n";
    cout << "6 aus 49" << "\n";
    ticket = Ticket(6, 49, 7); // Constructor
    table.printTable(ticket);
    
    return 0;
}