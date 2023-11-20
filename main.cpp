#include <iostream>
using namespace std:
#define cRST  "\033[0m"       // Reset
#define cBLK  "\033[30m"      // Schwarz
#define cRED  "\033[31m"      // Rot
#define cGRN  "\033[32m"      // Grün
#define cYLW  "\033[33m"      // Gelb
#define cBLU  "\033[34m"      // Blau
#define cMGT  "\033[35m"      // Magenta
#define cCYN  "\033[36m"      // Cyan
#define cWHT  "\033[37m"      // Weiß

class Spiel { 
/* Die Spiel-Klasse hat Methoden zum Setzen und Abrufen 
der gezogenen Zahlen sowie eine Methode, um zu prüfen, ob ein Spieler gewonnen hat.*/
public:
    void setZahlen(vector<int> zahlen);
    vector<int> getZahlen();
    bool gewonnen();
private:
    vector<int> gezogeneZahlen;
};

class Spieler {
/*Die Spieler-Klasse hat Methoden zum Setzen und Abrufen des Gewinnstatus eines Spielers.*/
public:
    void setGewonnen(bool gewonnen);
    bool getGewonnen();
private:
    bool gewonnen;
};

class Lotto {
/*Die Lotto-Klasse hat Methoden zum Erstellen neuer Spiele, zum Sammeln von Spieler-Eingaben, 
zur Ziehung der Lottozahlen und zum Anzeigen des Ergebnisses.*/
public:
    void neuesSpiel();
    void spielerEingabe(Spieler spieler);
    void ziehung();
    void ergebnis();
private:
    vector<Spiel> spiele;
    vector<Spieler> spieler;
};



int main(){
  cout << "hello";
}
