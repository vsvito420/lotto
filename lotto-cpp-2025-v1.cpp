#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>
#include <map>
#include <fstream>
#include <string>

using namespace std;

class NumberGenerator {
public:
    static vector<int> generate(int cnt, int max) {
        vector<int> pool(max);
        iota(pool.begin(), pool.end(), 1);
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(pool.begin(), pool.end(), default_random_engine(seed));
        pool.resize(cnt);
        sort(pool.begin(), pool.end());
        return pool;
    }
};

class FrequencyTracker {
    map<int, int> freqMap;
public:
    void update(const vector<int>& nums) {
        for (int n : nums) freqMap[n]++;
    }
    void print() const {
        cout << "Häufigkeit aller gezogenen Zahlen:\n";
        for (auto& p : freqMap) cout << p.first << ": " << p.second << "\n";
    }
};

class NumberStorage {
    string filename;
public:
    NumberStorage(const string& fn) : filename(fn) {}
    void save(const vector<int>& nums) const {
        ofstream out(filename);
        for (int n : nums) out << n << "\n";
    }
    vector<int> load() const {
        vector<int> nums;
        ifstream in(filename);
        int n;
        while (in >> n) nums.push_back(n);
        return nums;
    }
};

class LotteryGame {
protected:
    int maxNumber;
    int drawCount;
    vector<int> manualNums;
public:
    LotteryGame(int maxNum, int drawCnt) : maxNumber(maxNum), drawCount(drawCnt) {}
    virtual ~LotteryGame() {}
    void setManual(const vector<int>& nums) { manualNums = nums; }
    int getDrawCount() const { return drawCount; }
    virtual vector<int> draw() = 0;
    virtual string getName() const = 0;
};

class Lotto649 : public LotteryGame {
public:
    Lotto649() : LotteryGame(49, 6) {}
    vector<int> draw() override {
        if (manualNums.size() >= drawCount) {
            auto v = manualNums;
            unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            shuffle(v.begin(), v.end(), default_random_engine(seed));
            v.resize(drawCount);
            sort(v.begin(), v.end());
            return v;
        }
        return NumberGenerator::generate(drawCount, maxNumber);
    }
    string getName() const override { return "Lotto 6 aus 49"; }
};

class EuroLotto : public LotteryGame {
    int starCount;
    int maxStar;
public:
    EuroLotto() : LotteryGame(50, 5), starCount(2), maxStar(12) {}
    vector<int> draw() override {
        vector<int> mainNums;
        if (manualNums.size() >= drawCount) {
            mainNums = manualNums;
            unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            shuffle(mainNums.begin(), mainNums.end(), default_random_engine(seed));
            mainNums.resize(drawCount);
            sort(mainNums.begin(), mainNums.end());
        } else {
            mainNums = NumberGenerator::generate(drawCount, maxNumber);
        }
        vector<int> stars = NumberGenerator::generate(starCount, maxStar);
        vector<int> result = mainNums;
        result.insert(result.end(), stars.begin(), stars.end());
        return result;
    }
    string getName() const override { return "Eurolotto"; }
};

class Application {
    vector<LotteryGame*> games;
    NumberStorage storage;
    FrequencyTracker tracker;
public:
    Application() : storage("manual_numbers.txt") {
        games.push_back(new Lotto649());
        games.push_back(new EuroLotto());
    }
    ~Application() {
        for (auto g : games) delete g;
    }
    void run() {
        while (true) {
            cout << "\n--- Menu ---\n";
            for (size_t i = 0; i < games.size(); ++i)
                cout << i+1 << " - " << games[i]->getName() << "\n";
            cout << games.size()+1 << " - Eigene Zahlen eingeben\n";
            cout << games.size()+2 << " - Häufigkeitsverteilung anzeigen\n";
            cout << games.size()+3 << " - Ende\n";
            cout << "Auswahl: ";
            int choice;
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (choice == (int)games.size()+3) break;
            else if (choice >= 1 && choice <= (int)games.size()) {
                LotteryGame* game = games[choice-1];
                vector<int> manual = storage.load();
                if (!manual.empty()) {
                    cout << "Es wurden gespeicherte Zahlen gefunden. Verwenden? (j/n): ";
                    char c;
                    cin >> c;
                    if (c=='j' || c=='J') game->setManual(manual);
                    else game->setManual({});
                } else {
                    game->setManual({});
                }
                auto nums = game->draw();
                cout << "\nTipp für " << game->getName() << ":\n";
                int dcnt = game->getDrawCount();
                for (int i = 0; i < dcnt; ++i)
                    cout << nums[i] << (i+1<dcnt ? ' ' : '\n');
                if (auto* el = dynamic_cast<EuroLotto*>(game)) {
                    cout << "Sterne: ";
                    for (int i = dcnt; i < nums.size(); ++i)
                        cout << nums[i] << (i+1<nums.size()? ' ' : '\n');
                }
                tracker.update(nums);
            } else if (choice == (int)games.size()+1) {
                vector<int> input;
                cout << "Gib bis zu 30 Zahlen ein (-1 beendet):\n";
                while (input.size() < 30) {
                    int n;
                    cin >> n;
                    if (n == -1) break;
                    if (n < 1 || n > 49) {
                        cout << "Ungültig, 1-49 erlaubt\n";
                        continue;
                    }
                    if (find(input.begin(), input.end(), n) != input.end()) {
                        cout << "Duplikat, nochmal\n";
                        continue;
                    }
                    input.push_back(n);
                }
                storage.save(input);
                cout << "Zahlen gespeichert.\n";
            } else if (choice == (int)games.size()+2) {
                tracker.print();
            } else {
                cout << "Ungültige Auswahl\n";
            }
        }
    }
};

int main() {
    Application app;
    app.run();
    return 0;
}