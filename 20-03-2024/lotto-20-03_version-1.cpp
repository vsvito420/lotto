#include <iostream> // cout, cin
#include <ctime>    // time
#include <cstdlib>  // srand und rand
#include <iomanip>  // setw
using namespace std;

class LottoGame
{
private:
    int *numbers;
    int *winningNumbers;
    int numCount;

public:
    LottoGame(int count = 6) : numCount(count) // Lotto Game with 6 numbers drawn
    {
        numbers = new int[numCount];
        winningNumbers = new int[numCount];
    }
    ~LottoGame()
    {
        delete[] numbers;
        delete[] winningNumbers;
    }
    void getNumbers()
    {
        cout << "Enter " << numCount << " numbers between 1 and 49:" << endl;
        for (int i = 0; i < numCount; i++)
        {
            while (true)
            {
                cin >> numbers[i];
                if (numbers[i] >= 1 && numbers[i] <= 49)
                {
                    break;
                }
                cout << "Invalid number. Please enter a number between 1 and 49:" << endl;
            }
        }
    }
    void generateNumbers()
    {
        srand(time(0));
        for (int i = 0; i < numCount; i++)
        {
            winningNumbers[i] = rand() % 49 + 1;
            for (int j = 0; j < i; j++)
            {
                if (winningNumbers[i] == winningNumbers[j])
                {
                    i--;
                    break;
                }
            }
        }
    }

    void printWinningNumbers()
    {
        cout << "Winning numbers:" << endl;
        for (int i = 0; i < numCount; i++)
        {
            cout << winningNumbers[i] << " ";
        }
        cout << endl;
    }

    void printTicket()
    {
        cout << "Your ticket:" << endl;
        for (int i = 1; i <= 49; i++)
        {
            int count = 0;
            for (int j = 0; j < numCount; j++)
            {
                if (i == numbers[j])
                {
                    count++;
                }
            }
            cout << setw(2) << setfill('0') << i << " (" << count << "), ";
            
            if (i % 7 == 0) {
                cout << endl;
            }
        }
        cout << endl;
    }
    void checkTicket()
    {
        int matches = 0;
        for (int i = 0; i < numCount; i++)
        {
            for (int j = 0; j < numCount; j++)
            {
                if (numbers[i] == winningNumbers[j])
                {
                    matches++;
                }
            }
        }
        if (matches == numCount)
        {
            cout << "Congratulations, you won!" << endl;
        }
        else
        {
            cout << "Sorry, you didn't win this time. You had " << matches << " matching numbers." << endl;
        }
    }
};

int main()
{
    LottoGame game;
    
    while (true)
    {
        game.getNumbers();
        game.generateNumbers();
        game.printTicket();
        game.checkTicket();
        game.printWinningNumbers();
        
        cout << "Do you want to play again? (y/n): ";
        char answer;
        cin >> answer;
        if (answer != 'y')
        {
            break;
        }
    }
    return 0;
}
