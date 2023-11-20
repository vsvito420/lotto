#include <iostream>
#include <vector>
using namespace std;

class Spiel {
public:
    void setZahlen(vector<int> zahlen) {
        // Methodencode
    }
    vector<int> getZahlen() {
        return gezogeneZahlen;
        // Methodencode
    }
    bool gewonnen() {
        // Methodencode
        return 0;
    }
private:
    vector<int> gezogeneZahlen;
};

class Spieler {
public:
    void setGewonnen(bool gewonnen) {
        // Methodencode
    }
    bool getGewonnen() {
        // Methodencode
        return gewonnen;
    }
private:
    bool gewonnen;
};

class Lotto {
public:
    void neuesSpiel() {
        // Methodencode
    }
    void spielerEingabe(Spieler spieler) {
        // Methodencode
    }
    void ziehung() {
        // Methodencode
    }
    void ergebnis() {
        // Methodencode
    }
private:
    vector<Spiel> spiele;
    vector<Spieler> spieler;
};

int main(){
  cout << "hello";
}
