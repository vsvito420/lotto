#include <iostream>
#include <vector>
using namespace std;

class Spiel {
public:
    void setZahlen(vector<int> zahlen) {
        // Methodencode
    }
    vector<int> getZahlen() {
        // Methodencode
    }
    bool gewonnen() {
        // Methodencode
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
