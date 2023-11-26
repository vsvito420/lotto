#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class LottoTableCell
{
public:
    int lottoTableCellNumber;
    int lottoTableCellAmount;
};

class Table
{
public:
    int tableSize;
    int tableRange;

    void generateTable(int num, int range)
    {
        tableRange = range;
        tableSize = num;
        // Implement the logic to generate tickets here
    }

    void showTable(int tableWidth)
    {
        int columns = tableWidth; // Number of columns
        for (int i = 1; i <= tableRange; i++)
        {
            auto it = find_if(lottoTableVector.begin(), lottoTableVector.end(), [i](const LottoTableCell &cell)
                              { return cell.lottoTableCellNumber == i; });

            int count = 0;
            if (it != lottoTableVector.end())
            {
                count = it->lottoTableCellAmount;
            }

            // Display numbers less than 10 with leading 0
            if (i < 10)
            {
                cout << "0";
            }

            cout << i << "(";

            // Display individual digits of count with leading 0
            if (count < 10)
            {
                cout << "0";
            }

            cout << count << ") ";

            // New line after every 'columns'-th number
            if (i % columns == 0)
            {
                cout << endl;
            }
        }
    }

    void showList()
    {
        for (int i = 1; i <= tableRange; i++)
        {
            auto it = find_if(lottoTableVector.begin(), lottoTableVector.end(), [i](const LottoTableCell &cell)
                              { return cell.lottoTableCellNumber == i; });

            if (it != lottoTableVector.end())
            {
                cout << "Number: " << it->lottoTableCellNumber << ", Amount: " << it->lottoTableCellAmount << endl;
            }
            else
            {
                cout << "Number: " << i << ", Amount: 0" << endl;
            }
        }
    }

protected:
    vector<LottoTableCell> lottoTableVector;
};

class Program
{
public:
    void run()
    {
        Table table;
        table.generateTable(6, 49);
        table.showTable(7);
    }
};

int main()
{
    Program program;
    program.run();
    return 0;
}