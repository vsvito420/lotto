#include <iostream>
#include <map>
#include <random>
using namespace std;

/*
Aufgabenblatt 30
1. 
Schreiben Sie eine Routine, die 6 aus 49 oder Eurolotto ermöglicht. 
Nutzen Sie dazu die eine Bibliothek für Zufallszahlen.
Erstellen Sie ein grundlegendes Menü:
- Lotto 6 aus 49
- Eurolotto
- Manuelle Eingabe
- Ende des Programmes

Aufgabenblatt 31
2. 
der nutzer soll von 1 bis zu 30 zahlen eingeben, diese werden dann der zahlenpool.(Die Eingabe erfolgt so lange, bis -1 eingegeben wird.)
Aus diesen Zahlenpool werden dann die Zufallszahlen für 6 aus 49 oder Eurolotto gezogen.

Bei der Eingabe werden die Zahlen überprüft, ob diese schon eingegeben wurden.
Im Fall eines Duplikats kommt die Aufforderung, eine andere Zahl einzugeben.

3. 
Eigene Zahlen
Erweitern Sie das Menü um folgenden Menüpunkt:
Eigene Zahlen eingeben
Überlegen Sie, an welcher Stelle Sie implementieren, ob Sie eigene Zahlen nehmen und diese zufällig generieren oder nur zufällig generierte Zahlen nehmen.
Überlegen Sie sich einen sinnvollen Prozess.

Aufgabenblatt 32
Geben Sie bei der Generierung des Tippscheines die Häufigkeit der Zahlen (Eurolotto / 6 aus 49) an.

Aufgabenblatt 33
Klassen
Transformieren Sie die Aufgaben 30 – 32 in eine Klassenstruktur.
Bilden Sie entsprechende
Konstruktoren,
Destruktoren,
Set und Header-Datei.
Bilden Sie dazu jeweils eine Header- und eine Implementierungsdatei für jedes System.
Sie möchten Ihre manuell eingegebenen Zahlen speichern bzw. auch wieder laden können.
Definieren Sie dazu einen Speicher- und Ladeprozess. Erweitern Sie das Menü entsprechend.
Bilden Sie eine einfache Vererbung für das bereits bestehende System:
Lotto vererbt 2 Klassen:
- 6 aus 49
- Eurolotto (5 aus 50 und 2 aus 12)
*/

class Lotto {
    public:
    friend class Menu;
private:
    int Amount;
    int Range;
    int displayWidth;
    //Standardkonstruktor
    Lotto(){
        Amount = 0;
        Range = 0;
        displayWidth = 0;
    }

    //Parameterkonstruktor
    Lotto(int Amount, int Range, int displayWidth){
        this->Amount = Amount;
        this->Range = Range;
        this->displayWidth = displayWidth;
    }

    // Map function to generate numbers from 1 to Range
    void drawNumbers(int Amount, int Range, int displayWidth){
        map <int, int> keyValuePair; //key = Lotto Number, value = selected numbers
        int randomNumber;
        int i = 0;
        while (i < Amount){
            randomNumber = rand() % Range + 1;
            if (keyValuePair.find(randomNumber) == keyValuePair.end()){ //check if randomNumber is already in map
                keyValuePair.insert(pair<int, int>(randomNumber, 0)); //insert key value pair
                i++;
            }
        }
        displayNumbers(keyValuePair, displayWidth);
    }

    void displayNumbers(map <int, int> keyValuePair, int displayWidth){
        int i = 0;
        for (auto itr = keyValuePair.begin(); itr != keyValuePair.end(); itr++){
            cout.width(displayWidth);
            cout << itr->first;
            i++;
        }
        cout << endl;
    }
    
    map <int, int> keyValuePair; //key = Lotto Number, value = selected numbers
};

class Menu:Lotto {
public:
        //recursive manual input until -1 is entered or the amount of 30 numbers is reached
    void manualInput(){
        int input;
        cout << "Enter a number between 1 and " << Range << endl;
        cin >> input;
        if (input == -1){                                   //check if input is -1
            return;
        }
        else if (input > 0 && input <= Range){              //check if input is in range
            keyValuePair.insert(pair<int, int>(input, 0)); //insert key value pair
            manualInput();
        }
        else{
            cout << "Wrong input" << endl;
            manualInput();
        }
    }
    void drawNumbers(int Amount, int Range, int displayWidth) {
        vector<int> numberPool;
        for (auto itr = keyValuePair.begin(); itr != keyValuePair.end(); itr++) {
            numberPool.push_back(itr->first);
        }

        map<int, int> selectedNumbers;
        int i = 0;
        while (i < Amount && !numberPool.empty()) {
            int randomIndex = rand() % numberPool.size();
            int randomNumber = numberPool[randomIndex];
            selectedNumbers.insert(pair<int, int>(randomNumber, 0));
            numberPool.erase(numberPool.begin() + randomIndex);
            i++;
        }

        displayNumbers(selectedNumbers, displayWidth);
    }

    Menu(){
        Lotto lotto;
        int choice=0;
        cout << "Welcome to the Lotto-Programm" << endl;
        cout << "1. Lotto 6 aus 49" << endl;
        cout << "2. Eurolotto" << endl;
        cout << "3. manual input" << endl;
        cout << "4. custom" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Lotto 6 aus 49" << endl;
                Amount = 6;
                Range = 49;
                displayWidth = 7;
                lotto.drawNumbers(Amount, Range, displayWidth);
                break;
            case 2:
                cout << "Lotto 6 aus 49" << endl;
                Amount = 6;
                Range = 49;
                displayWidth = 7;
                lotto.drawNumbers(Amount, Range, displayWidth);
                break;
            case 3:	
                cout << "Manual input" << endl;
                Amount = 6;
                Range = 49;
                displayWidth = 7;
                manualInput();
                break;
            case 4:
                cout << "Custom" << endl;
                cout << "How many numbers do you want to play?" << endl;
                cin >> Amount;
                cout << "How many numbers are in the pool?" << endl;
                cin >> Range;
                cout << "How many numbers do you want to display?" << endl;
                cin >> displayWidth;
                break;
            case 5:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Wrong input" << endl;
                break;
        }
    }
};

int main (){
    Menu start;
    start.manualInput();

    return 0;
}
