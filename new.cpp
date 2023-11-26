#include <iostream> // cout, cin, endl
#include <vector>   // vector
#include <limits>   // numeric_limits
#include <map>      // map
#include <cstdlib>  // rand, srand
#include <ctime>    // time
using namespace std;

class LottoSchein
{
public:
    map<int, int> map;
private:
    struct cell
    {
        int cellNumber;
        int cellAmount;
    };
    
    vector<cell> vector;
};
