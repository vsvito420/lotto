#include "Lotto6aus49.h"
#include "Eurolotto.h"
#include <iostream>

using namespace std;

int main() {
    int choice;

    cout << "Willkommen beim Lotto-Programm!" << endl;
    cout << "Was mochten Sie tun?" << endl;
    cout << "1. Lotto 6 aus 49" << endl;
    cout << "2. Eurolotto" << endl;
    cout << "3. Zahlen speichern" << endl;
    cout << "4. Zahlen laden" << endl;
    cout << "5. Ende des Programmes" << endl;
    cin >> choice;

    Lotto* lotto;

    switch (choice) {
        case 1:
            lotto = new Lotto6aus49();
            lotto->generateNumbers();
            lotto->printNumbers();
            lotto->printFrequency();
            break;
        case 2:
            lotto = new Eurolotto();
            lotto->generateNumbers();
            lotto->printNumbers();
            lotto->printFrequency();
            break;
        case 3:
            cout << "Für welches Spiel möchten Sie Zahlen speichern?" << endl;
            cout << "1. Lotto 6 aus 49" << endl;
            cout << "2. Eurolotto" << endl;
            cin >> choice;

            if (choice == 1) {
                lotto = new Lotto6aus49();
                lotto->enterNumbers();
                lotto->saveNumbers();
            } else if (choice == 2) {
                lotto = new Eurolotto();
                lotto->enterNumbers();
                lotto->saveNumbers();
            } else {
                cout << "Ungültige Eingabe. Bitte versuchen Sie es erneut." << endl;
            }
            break;
        case 4:
            cout << "Für welches Spiel möchten Sie Zahlen laden?" << endl;
            cout << "1. Lotto 6 aus 49" << endl;
            cout << "2. Eurolotto" << endl;
            cin >> choice;

            if (choice == 1) {
                lotto = new Lotto6aus49();
                lotto->loadNumbers();
                lotto->printNumbers();
                lotto->printFrequency();
            } else if (choice == 2) {
                lotto = new Eurolotto();
                lotto->loadNumbers();
                lotto->printNumbers();
                lotto->printFrequency();
            } else {
                cout << "Ungültige Eingabe. Bitte versuchen Sie es erneut." << endl;
            }
            break;
        case 5:
            cout << "Auf Wiedersehen!" << endl;
            break;
        default:
            cout << "Ungültige Eingabe. Bitte versuchen Sie es erneut." << endl;
            break;
    }

    delete lotto;

    return 0;
}
