#include <iostream>
#include <cstdlib>
#include <ctime.h>

using namespace std;

int main() {
    int userNumbers[6]; // User-selected numbers
    int lottoNumbers[6]; // Lotto drawn numbers
    int matchCount = 0; // Number of matches between user and lotto numbers

    srand(time(NULL)); // Seed the random number generator with current time

    cout << "Enter your 6 lucky numbers: ";
    for (int i = 0; i < 6; i++) {
        cin >> userNumbers[i];
    }

    // Generate 6 random numbers for the lotto draw
    for (int i = 0; i < 6; i++) {
        lottoNumbers[i] = rand() % 45 + 1; // Generate random numbers between 1 and 45 (assuming a standard lotto setup)
        for (int j = 0; j < i; j++) { // Check if the number has already been generated
            if (lottoNumbers[i] == lottoNumbers[j]) {
                i--; // If so, generate a new number
                break;
            }
        }
    }

    cout << "Your lucky numbers: ";
    for (int i = 0; i < 6; i++) {
        cout << userNumbers[i] << " ";
    }
    cout << endl;

    cout << "Lotto numbers drawn: ";
    for (int i = 0; i < 6; i++) {
        cout << lottoNumbers[i] << " ";
        if (userNumbers[0] == lottoNumbers[i]) { // Check for a match between the first user number and the first drawn number
            matchCount++;
        }
    }
    cout << endl;

    if (matchCount > 0) { // If there's a match, print the number of matches
        cout << "Congratulations! You have matched " << matchCount << " numbers.";
    } else { // If there's no match, print a message of encouragement
        cout << "Better luck next time!";
    }

    return 0;
}