#include <iostream>     // cout, cin
#include <vector>       // vector
#include <algorithm>    // find_if
#include <cstdlib>      // rand()
#include <ctime>        // time()
using namespace std;

class LotteryTicket
{ // This class represents a single lottery ticket
public:
    vector<int> ticketNumbers;
    int ticketRange;
    int ticketWidth;
};

class NormalLottoTicket : public LotteryTicket
{ // This class represents a normal lotto ticket
public:
    NormalLottoTicket()
    {
        ticketRange = 49;
        ticketWidth = 7;
    }
};

class EuroLottoTicket : public LotteryTicket
{ // This class represents a Euro lotto ticket
public:
    vector<int> secondTableNumbers;
    int secondTableRange;

    EuroLottoTicket()
    {
        ticketRange = 50;
        ticketWidth = 5;
        secondTableRange = 12;
    }
};

class Table
{ // This class represents the table
public:
    void generateTable(vector<LotteryTicket>& tickets)
    { // This function generates the table
        for (const auto& ticket : tickets)
        {
            // Implement the logic to generate tickets here
            // You can access the ticket properties like ticket.ticketNumbers, ticket.ticketRange, etc.
        }
    }

    void Table::showTable(int tableWidth)
    {
        int columns = tableWidth; // Number of columns
        for (int i = 1; i <= ticketRange; i++)
        {
            auto it = find_if(tickets.begin(), tickets.end(), [i](const LotteryTicket &ticket)
                              { return find(ticket.ticketNumbers.begin(), ticket.ticketNumbers.end(), i) != ticket.ticketNumbers.end(); });

            int count = 0;
            if (it != tickets.end())
            {
                count = countOccurrences(it->ticketNumbers, i);
            }

            // Display numbers less than 10 with leading 0
            if (i < 10)
            {
                cout << "0";
            }

            cout << i << "(";

            // Display individual digits of count with leading 0
            if (count < 10)
            {
                cout << "0";
            }

            cout << count << ") ";

            // New line after every 'columns'-th number
            if (i % columns == 0)
            {
                cout << endl;
            }
        }
    }

    void Table::showList()
    {
        for (int i = 1; i <= ticketRange; i++)
        {
            auto it = find_if(tickets.begin(), tickets.end(), [i](const LotteryTicket &ticket)
                              { return find(ticket.ticketNumbers.begin(), ticket.ticketNumbers.end(), i) != ticket.ticketNumbers.end(); });

            if (it != tickets.end())
            {
                cout << "Number: " << it->ticketNumbers[0] << ", Amount: " << countOccurrences(it->ticketNumbers, it->ticketNumbers[0]) << endl;
            }
            else
            {
                cout << "Number: " << i << ", Amount: 0" << endl;
            }
        }
    }  
};

class Program
{
public:
    void runInstance()
    { // This function runs an instance of the program
        Table table;
        vector<LotteryTicket> tickets;

        // Create instances of different lottery tickets
        NormalLottoTicket normalLottoTicket;
        EuroLottoTicket euroLottoTicket;

        // Add the tickets to the vector
        tickets.push_back(normalLottoTicket);
        tickets.push_back(euroLottoTicket);

        // Generate and display the table
        table.generateTable(tickets);
        table.showTable(7);
    }
};

int main()
{   // This function creates an instance of the program and runs it
    Program program;
    program.runInstance();
    return 0;
}
