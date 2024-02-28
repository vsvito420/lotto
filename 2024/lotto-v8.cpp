#include <iostream>     // std::cout, std::cin
#include <vector>       // std::vector
#include <random>       // std::random_device, std::mt19937, std::uniform_int_distribution
#include <algorithm>    // std::find
#include <stdexcept>    // std::invalid_argument
#include <string>       // std::string
#include <iomanip>      // std::setw
#include <sstream>      // std::stringstream
#include <fstream>      // std::ofstream    
using namespace std;

class Lotto
{
private:
    int size;         // amount of numbers to be picked
    int rangeMin = 1; // start range from 1
    int rangeMax;     // range
    int tableWidth;   // table width
    vector<int> numbers;

public:
    // Parameter constructor
    Lotto(int size = 6, int rangeMax = 49, int tableWidth = 10) : size(size), rangeMax(rangeMax), tableWidth(tableWidth)
    {
        // validate size
        if (size > rangeMax)
        {
            throw invalid_argument("size cannot be greater than rangeMax");
        }
    }

    // Destructor
    ~Lotto()
    {
        numbers.clear();
    }

    // Input Method
    void userInputNumbers(int limit)
    {
        for (size_t i = 0; i < limit || numbers.size(); ++i)
        {
            int num;
            cout << "Enter a number between " << rangeMin << " and " << rangeMax << ": ";
            cin >> num;
            numbers.push_back(num);
        }
    }
    
protected:
    // Input Method
    void generateNumbers()
    {
        random_device rd;                                   // create random device
        mt19937 gen(rd());                                  // seed the engine with current time
        uniform_int_distribution<> dis(rangeMin, rangeMax); // create distribution
        for (int i = 0; i < size; ++i)
        {
            numbers.push_back(dis(gen));
        }
    }



    // display numbers in a Table
    void displayNumbers() const
    {
        for (int num = rangeMin; num <= rangeMax; ++num)
        {
            if (find(numbers.begin(), numbers.end(), num) != numbers.end())
            {
                cout << "[" << setw(2) << setfill('0') << num << "] ";
            }
            else
            {
                cout << " " << setw(2) << setfill('0') << num << "  ";
            }

            if ((num - rangeMin + 1) % tableWidth == 0)
            {
                cout << "\n";
            }
        }
    }

public:
    // set and get methods
    void setSize(int size)
    {
        this->size = size;
    }
    int getSize() const
    {
        return size;
    }
    void setRangeMax(int rangeMax)
    {
        this->rangeMax = rangeMax;
    }
    int getRangeMax() const
    {
        return rangeMax;
    }
    void setTableWidth(int tableWidth)
    {
        this->tableWidth = tableWidth;
    }
    int getTableWidth() const
    {
        return tableWidth;
    }
    void setNumbers(vector<int> numbers)
    {
        this->numbers = numbers;
    }
    vector<int> getNumbers() const
    {
        return numbers;
    }
    void callGenerateNumbers()
    {
        generateNumbers();
    }
    void callDisplayNumbers()
    {
        displayNumbers();
    }

    int getNumbersFromVector(int index)
    {
        return numbers.at(index);
    }
};

class Controller : public Lotto
{
    Lotto lotto;

public:
    Controller() : lotto(6, 49, 7)
    {
        lotto.callGenerateNumbers();
        lotto.callDisplayNumbers();
    }
    /*
    0: Exit
    1: Generate numbers
    2: lotto(6,49,7)
    3: lotto(5,50,10)
    4: lotto(2,12,6)
    5: Custom input
    */
    void menu()
    {  
        int choice;
        do
        {
            cout << "0: Exit\n1: Generate numbers\n2: lotto(6,49,7)\n3: lotto(5,50,10)\n4: lotto(2,12,6)\n5: Custom input\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 0:
                cout << "Goodbye!" << endl;
                break;
            case 1:
                lotto.callGenerateNumbers();
                lotto.callDisplayNumbers();
                break;
            case 2:
                lotto.setSize(6);
                lotto.setRangeMax(49);
                lotto.setTableWidth(7);
                lotto.callGenerateNumbers();
                lotto.callDisplayNumbers();
                break;
            case 3:
                lotto.setSize(5);
                lotto.setRangeMax(50);
                lotto.setTableWidth(10);
                lotto.callGenerateNumbers();
                lotto.callDisplayNumbers();
                break;
            case 4:
                lotto.setSize(2);
                lotto.setRangeMax(12);
                lotto.setTableWidth(6);
                lotto.callGenerateNumbers();
                lotto.callDisplayNumbers();
                break;
            case 5:
                int limit;
                cout << "Enter the amount of numbers to be picked: ";
                cin >> limit;
                lotto.setSize(limit);
                lotto.userInputNumbers(limit);
                lotto.callDisplayNumbers();
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }
        } while (choice != 0);  
    }
};

int main()
{
    Controller controller;
    
    return 0;
}