#include <iostream>
#include <fstream>      // für Datei-Ein-/Ausgabe
#include <random>       // Zufallsbibliothek für die Generierung von Zufallszahlen
#include <vector>       // Vektorbibliothek, um Vektoren zu verwenden
using namespace std;
/* erstelle kommentare auf deutsch
ich möchte mehrere tippscheine generieren können.
lotto vererbt 2 klassen: normal-lotto und euro-lotto
erstelle eine eingabefunktion, parameter= anzahl der zahlen, rückgabewert= vector<int>
Bei der Eingabe werden die Zahlen überprüft, ob diese schon eingegeben wurden.
Im Fall eines Duplikats kommt die Aufforderung, eine andere Zahl einzugeben.

es soll folgende menüpunkte geben:
1. tippschein generieren (6 aus 49)
2. tippschein generieren (5 aus 50)
3. tippschein generieren (2 aus 12)
4. "Pool-eingabemodus"
5. normal-lotto
6. euro-lotto
7. beenden

6 aus 49:
Es werden 6 Zufallszahlen zwischen 1 und 49 (einschließlich) generiert.

Euro-Lotto:
Es werden 5 Zufallszahlen zwischen 1 und 50 (einschließlich) und 2 Zufallszahlen zwischen 1 und 12 (einschließlich) generiert.

pool-eingabemodus:
Es können manuell bis zu 30 Zahlen eingegeben werden.
Aus diesen Zahlen werden dann die Zufallszahlen für entweder 6 aus 49 oder Eurolotto ausgewählt.
Die Eingabe erfolgt so lange, bis -1 eingegeben wird.
benutze die eingabefunktion, um die zahlen einzulesen.

*/
class Lotto {
    protected:
        int anzahlZahlen;
        int maxZahlen;
        int ausgabeBreite;
        // vordekleration
        vector<int> eingabe(int anzahlZahlen);
        void ausgabe(vector<int> zahlen);
    private:
        vector<int> zahlen;
};

int main() {
    random_device rd;   // Erstelle ein Objekt der Klasse random_device, um einen Zufallssamen zu erhalten
    mt19937 gen(rd());  // Erstelle einen Mersenne Twister Pseudo-Zufallsgenerator mit dem erhaltenen Samen
    uniform_int_distribution<int> dis(1, 49); // Erstelle ein Objekt der Klasse uniform_int_distribution, um Zufallszahlen zwischen 1 und 49 (einschließlich) zu generieren
    Lotto lotto;
    

    return 0;
}