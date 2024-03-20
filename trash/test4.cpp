#include <iostream> 
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Function to save data to a file
void saveData(const string& filename, const vector<string>& data) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& line : data) {
            outFile << line << endl;
        }
        outFile.close();
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

// Function to load data from a file
vector<string> loadData(const string& filename) {
    vector<string> data;
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            data.push_back(line);
        }
        inFile.close();
    } else {
        cout << "Unable to open file for reading." << endl;
    }
    return data;
}
