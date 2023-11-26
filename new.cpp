#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class LottoTableCell {
public:
    int lottoTableCellNumber;
    int lottoTableCellAmount;
};

class Table {
public:
    int tableSize;
    int tableRange;
    
    void generateTable(int num, int range) {
        tableRange = range;
        tableSize = num;
        // Implementieren Sie hier die Logik zur Generierung von Tickets
    }

    void anzeigenLottoZahlen() {
        for(int i = 1; i <= tableRange; i++) {
            auto it = find_if(lottoTableVector.begin(), lottoTableVector.end(), [i](const LottoTableCell& zelle) {
                return zelle.lottoTableCellNumber == i;
            });

            if(it != lottoTableVector.end()) {
                cout << "Zahl: " << it->lottoTableCellNumber << ", Anzahl: " << it->lottoTableCellAmount << endl;
            } else {
                cout << "Zahl: " << i << ", Anzahl: 0" << endl;
            }
        }
    }

protected:
    vector<LottoTableCell> lottoTableVector;
};

class Program {
public:
    void run() {
        Table table;
        table.generateTable(6, 49);
        table.anzeigenLottoZahlen();
    }
};

int main() {
    Program program;
    program.run();
    return 0;
}