#include <iostream>     // for cout, cin, etc.
#include <string>       // for string
#include <vector>       // for vector
#include <algorithm>    // for sort
#include <fstream>      // for file I/O
#include <map>          // for map
#include <random>       // default_random_engine
using namespace std;

class Ticket
{
    private:
    int numbersRange;
    int amountOfNumbersPicked; 
    int ticketPrintWidth;
    map<int, int> ticketNumbers;

    public:
    //Default Constructor
    Ticket()
    {
        this->numbersRange = 0;
        this->amountOfNumbersPicked = 0;
        this->ticketPrintWidth = 0;
        reset_ticketNumbers(amountOfNumbersPicked,numbersRange);
    }
    //Constructor
    Ticket(int amountOfNumbersPicked,int numbersRange,int ticketPrintWidth)
    {
        this->numbersRange = numbersRange;
        this->amountOfNumbersPicked = amountOfNumbersPicked;
        this->ticketPrintWidth = ticketPrintWidth;
          
    }
    
    
    //reset everything to 0. so there are 1 - range numbers and all are 0
    map<int, int> reset_ticketNumbers(int numCount, int numRange)
    {
        map<int, int> ticketNumbers; // Map(Zahl): Anzahl
        vector<int> numbers;            // Zahlen
        for (int i = 1; i <= numRange; i++)
        {
            numbers.push_back(i); // Zahlen in den vector einfügen
        }

        for (int i = 0; i < numCount; i++)
        {
            ticketNumbers[numbers[i]] = 0; // Zahlen in die map einfügen
        }
        return ticketNumbers;
    }

/*
    example: Map(range 49 width 7) should look like this(from 1 to range):
    (x) = ticketNumbers[x](value)
    01(x) 02(x) 03(x) 04(x) 05(x) 06(x) 07(x)
    08(x) 09(x) 10(x) 11(x) 12(x) 13(x) 14(x)
    15(x) 16(x) 17(x) 18(x) 19(x) 20(x) 21(x)
    22(x) 23(x) 24(x) 25(x) 26(x) 27(x) 28(x)
    29(x) 30(x) 31(x) 32(x) 33(x) 34(x) 35(x)
    36(x) 37(x) 38(x) 39(x) 40(x) 41(x) 42(x)
    43(x) 44(x) 45(x) 46(x) 47(x) 48(x) 49(x)
    */
    map<int, int> generateNumbers(int numCount, int numRange, int ticketPrintWidth) // generate random numbers
    {
        map<int, int> ticketNumbers = reset_ticketNumbers(numCount, numRange);
        vector<int> numbers; // Zahlen
        for (int i = 1; i <= numRange; i++)
        {
            numbers.push_back(i); // Zahlen in den vector einfügen
        }

        random_device rd; // obtain a random number from hardware
        mt19937 eng(rd()); // seed the generator
        shuffle(numbers.begin(), numbers.end(), eng); // shuffle the vector

        for (int i = 0; i < numCount; i++)
        {
            ticketNumbers[numbers[i]]++; // Zahlen in die map einfügen
        }
        return ticketNumbers;
    }
    /*
    print numbers like this: ticketNumbers(KEY)|ticketNumbers(VALUE)
    01|0 02|0 03|0 04|0 05|0 06|0 07|0
    08|0 09|0 10|0 11|0 12|0 13|0 14|0
    15|0 16|0 17|0 18|0 19|0 20|0 21|0
    22|0 23|0 24|0 25|0 26|0 27|0 28|0
    29|0 30|0 31|0 32|0 33|0 34|0 35|0
    36|0 37|0 38|0 39|0 40|0 41|0 42|0
    43|0 44|0 45|0 46|0 47|0 48|0 49|0 (from 1 to range)
    */
    void print_ticketNumbers(map<int, int> ticketNumbers)
    {
        int counter = 0;
        for (auto const &int_int : ticketNumbers)
        {
            if (counter == ticketPrintWidth)
            {
                cout << endl;
                counter = 0;
            }
            cout << int_int.first << "|" << int_int.second << " ";
            counter++;
        }
    }
};

int main()
{
    Ticket ticket;
    ticket.print_ticketNumbers(ticket.generateNumbers(6, 49, 7));
    
    return 0;
}
