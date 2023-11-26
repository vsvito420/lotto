#include <iostream> // cout, cin, endl
#include <vector>   // vector
#include <map>      // map
using namespace std;

class Table
{
public:
    void anzeigenLottoZahlen() {
        for(const auto& zelle : lottoTableVector) {
            cout << "Lottozahl: " << zelle.lottoTableCellNumber << ", Anzahl: " << zelle.lottoTableCellAmount << endl;
        }
    }

protected: // protected, weil die Klasse Table von der Klasse Program erweitert wird    
    map<int, int> lottoTableMap;
    struct lottoTableCell
    {
        int lottoTableCellNumber;
        int lottoTableCellAmount;
    };

    vector<lottoTableCell> lottoTableVector;
};

class Program : public Table
{
public:
    void run() {
        // Hier können Sie Methoden der Table-Klasse aufrufen, z.B.
        anzeigenLottoZahlen();
    }
};

int main()
{
    Program programm;
    programm.run();
    cout << "Programm beendet." << endl;
    return 0;
}
