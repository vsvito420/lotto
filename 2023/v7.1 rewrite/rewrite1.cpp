#include <iostream> // cout
#include <vector>   // vector
using namespace std;
/*Ich möchte ein lotto programm machen.
ich möchte eine funktion für dieses lottoprogramm machen das folgendes tut:
1. zahlen eingeben in der gewählten range (standard 1-49)
2. die zahlen werden solange eingegeben bis entweder der nutzer -1 eingiebt oder 30 zahlen eingegeben wurden.(die eingegebenen zahlen müssen einzigartig sein)
gespeichert werden diese in einem vector.
anhand von dieser menge von zahlen möchte ich 6 (einzigartige)zufallszahlen ziehen.
Ich möchte damit meine gewinnchancen erhöhen indem ich zahlen nehme die statistisch gesehen mehr chancen haben.
*/
class Lotto
{
private:
    vector<int> poolA;
    vector<int> poolB; 
    int rangeStart;
    int rangeEnd;
    int amountOfNumbers;
    int displayWidth;
public:
    //Set and getter
    void setRangeStart(int rangeStart){this->rangeStart = rangeStart;}
    int  getRangeStart(){return rangeStart;}
    void setRangeEnd(int rangeEnd){this->rangeEnd = rangeEnd;}
    int  getRangeEnd(){return rangeEnd;}
    void setAmountOfNumbers(int amountOfNumbers){this->amountOfNumbers = amountOfNumbers;}
    int  getAmountOfNumbers(){return amountOfNumbers;}
    void setDisplayWidth(int displayWidth){this->displayWidth = displayWidth;}
    int  getDisplayWidth(){return displayWidth;}
    void setPoolA(vector<int> poolA){this->poolA = poolA;}
    vector<int> getPoolA(){return poolA;}
    void setpoolB(vector<int> poolB){this->poolB = poolB;}
    vector<int> getpoolB(){return poolB;}
    
    //default constructor
    Lotto(){
        cout << ">Lotto constructor" << endl;
        poolA = vector<int>(49, 0);
        setRangeStart(0);
        setRangeEnd(0);
        setAmountOfNumbers(0);
        setDisplayWidth(0);
    }
    //parameterized constructor
    Lotto(int rangeStart, int rangeEnd, int amountOfNumbers, int displayWidth){
        cout << ">Lotto constructor w/ Parameters:|\t RangeStart: " << rangeStart << " RangeEnd: " << rangeEnd << " AmountOfNumbers: " << amountOfNumbers << " DisplayWidth: " << displayWidth << endl;
        setRangeStart(rangeStart);
        setRangeEnd(rangeEnd);
        setAmountOfNumbers(amountOfNumbers);
        setDisplayWidth(displayWidth);
    }
    //destructor
    ~Lotto(){
        cout << ">Lotto destructor" << endl;
    }
    // Funktion zum Ausgeben des Vektors
    void printVector() {
        for (int i = 0; i < poolA.size(); ++i) {
            // Füge eine führende Null hinzu, wenn die Zahl kleiner als 10 ist
            if (i < 9) {
                cout << "0";
            }
            cout << i + 1 << ",";
            // Gehe zur nächsten Zeile nach jeder 7. Zahl
            if ((i + 1) % 7 == 0) {
                cout << "\n";
            }
        }
    }

};



void beispielVector(){
    vector<int> v = {1, 2, 3, 4, 5};
    cout << "v = {";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i < v.size() - 1)
        {
            cout << ", ";
        }
    }    cout << "}" << endl;
}

int main(){
    Lotto lotto(1, 49, 6, 7); //RangeStart, RangeEnd, AmountOfNumbers, DisplayWidth
    lotto.printVector();

    return 0;
}