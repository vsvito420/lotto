#include <iostream>
#include <set> // unordered_set
#include <random>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

/*
write a lotto programm in c++:
use using namespace std
output the code in one piece
Use Classes and Objects
u should keep the code simple by using appropiate librarys that can help
i want a menu with 3 options: 1. "normal lotto", 2. load numbers, 3. exit
normal lotto is 6 of 49 linebreak 7
eurolotto is 5 of 50 linebreak 10 AND 2 of 12 linebreak 6

i want 2 options: A: the user typing in numbers OR B:generating numbers with <random>
lotto has variables: nNumbers of nRange nlinebreak
i want to save the numbers in a file and then load them in a unordered set

after this sort the set

print function should display all numbers that are there but only increment the number of the set if the number was picked 
print out the set like this (nx is the how many times the number was picked in the unordered set) 0n is the number with a leading 0 using setw?
(0x)01, (1x)02, (0x)03, (0x)04, (1x)05, (0x)06, (0x)07,
(0x)08, (0x)09, (0x)10, ... 49
*/

class Lotto {
private:
    int drawCount;
    int range;
    int drawWidth;
    vector<int> drawnNumbers;
    vector<vector<int>> drawHistory;
    mt19937 rng;
    

};