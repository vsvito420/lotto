#include <iostream>
#include <map>
#include <set>
#include <random>
using namespace std;

class Ticket
{
public:
    int t_numCount = 0;     //Amount of numbers
    int t_numRange = 0;     //Number range
    int t_width = 0;        //Width of the ticket
};

//Constructors
class Ticket649 : public Ticket
{
public:
    int t_numCount = 6;     //Amount of numbers
    int t_numRange = 49;    //Number range
    int t_width = 7;        //Width of the ticket
};
class Ticket550 : public Ticket
{
public:
    int t_numCount = 5;     //Amount of numbers
    int t_numRange = 50;    //Number range
    int t_width = 5;        //Width of the ticket
};
class Ticket212 : public Ticket
{
public:
    int t_numCount = 2;     //Amount of numbers
    int t_numRange = 12;    //Number range
    int t_width = 6;        //Width of the ticket
};
//End of constructors



class Program
{

};

int main()
{
    //Init
    Program program; // Create the program
    Ticket ticket;   // Create a ticket   
    cout << "Program: End!" << endl;
}