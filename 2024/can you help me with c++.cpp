can you help me with c++. i want to create a program called "Lotto" (lottery).
i want you to help me think of a structure i can use for my program.
i thought of using array but i dont know how to use dynamic arrays.
i also dont really know how to use pointers.

i thought maybe of having something like this, correct me if you think you have a better solution.: 
i want you to not output code but rather think with me how the program could be implemented and why

#include <iostream>
#include <random>
using namespace std;

//Class
Class Lotto {
private:
//parameters to configure Lotto
int size; // amount of numbers to be picked
int rangeMin=1; //start range from 1
int rangeMax;  // range
int outputWidth; // i want to use cout in a loop to output all numbers from 1 to rangeMax, i want to print it out and make a new line each outputWidth
int generatedNumber();
int userInput();
void displayNumbers(int*); //pointer maybe? i dont know

public:
// default constructor 
Lotto...
//parameter constructor
Lotto...

//setter and getter here
};
//Methods of class Lotto