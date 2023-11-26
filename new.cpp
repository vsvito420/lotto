#include <iostream> // cout, cin, endl
#include <vector>   // vector
using namespace std;

struct LottoTableCell
{
    int lottoTableCellNumber;
    int lottoTableCellAmount;
};

class Table
{
public:
    void hinzufuegenZahl(int nummer, int anzahl) {
        LottoTableCell zelle {nummer, anzahl};
        lottoTableVector.push_back(zelle);
    }

    void anzeigenLottoZahlen() {
        for(const auto& zelle : lottoTableVector) {
            cout << "Lottozahl: " << zelle.lottoTableCellNumber << ", Anzahl: " << zelle.lottoTableCellAmount << endl;
        }
    }

protected:   
    vector<LottoTableCell> lottoTableVector;
};

class Program : public Table
{
public:
    void run() {
        // Hier können Sie Methoden der Table-Klasse aufrufen, z.B.
        hinzufuegenZahl(7, 1);
        hinzufuegenZahl(14, 1);
        hinzufuegenZahl(21, 1);
        hinzufuegenZahl(28, 1);
        hinzufuegenZahl(35, 1);
        hinzufuegenZahl(42, 1);
        anzeigenLottoZahlen();
    }
};

int main()
{
    Program programm;
    programm.run();
    return 0;
}