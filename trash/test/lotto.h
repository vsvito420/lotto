#ifndef LOTTO_H
#define LOTTO_H

#include <vector>
#include <map>
#include <fstream>

class Lotto {
public:
    Lotto(int numbersToDraw, int maxNumber);
    virtual ~Lotto();
    void generateNumbers();
    void enterNumbers();
    void printNumbers();
    void printFrequency();
    void setNumbersToDraw(int numbersToDraw);
    void setMaxNumber(int maxNumber);
    void saveNumbers();
    void loadNumbers();

protected:
    int numbersToDraw;
    int maxNumber;
    std::vector<int> numbers;
    std::map<int, int> frequency;
    std::string filename;
};

#endif
