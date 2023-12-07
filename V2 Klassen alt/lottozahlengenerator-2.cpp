#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;
#define RST     "\033[0m"
#define BLACK   "\033[30m" //Ermögliche das die Anzahl der tippscheine auswählbar ist
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

bool lottoModus; 

string lottoModusAusgeben(bool lottoModus) {
    if (lottoModus == 0) {
        return "Lotto 6 aus 49";
    }
    if (lottoModus == 1) {
        return "Eurojackpot 5 aus 50 + 2 aus 12";
    }
    return "Ungültiges Lotto-Spiel";
}

class LottoC {
public:

    bool pruefen(int zahl, int zahlenSize) {
        if (zahl >= 1 && zahl <= zahlenSize) {
            return true; // Die Zahl ist gültig
        } else {
            return false; // Die Zahl ist ungültig
        }
    }
    
    void eingabeM30(int zahlenSize, int zahlenRange, int ausgabeBreite) {
        cout << "Geben Sie bis zu 30 zahlen ein" << "Beenden sie die eingabe mit -1"<< endl;
        bool istEinzigartig;
        int zahl = 0;
        int zahlen[zahlenSize];
        for (int i = 0; i < zahlenSize; i++) {
            do {
                cin >> zahl;
                istEinzigartig = true;
                for (int j = 0; j < i; j++) {
                    if (!pruefen(zahl, zahlenRange)) {
                        istEinzigartig = false;
                        cout << "Ungültige Eingabe! Bitte geben Sie eine Zahl zwischen 1 und " << zahlenRange << " ein." << endl;
                    }
                    if (zahlen[j] == zahl) {
                        istEinzigartig = false;
                        break;
                    }
                }
            } while (!istEinzigartig);
            zahlen[i] = zahl;
        }
        ausgabeM(zahlenRange, zahlenSize, zahlen, ausgabeBreite);
    }

    void eingabeM(int zahlenSize, int zahlenRange, int ausgabeBreite) {
        cout << "Geben Sie " << zahlenSize << " Werte ein (1-" << zahlenRange << "):" << endl;
        bool istEinzigartig;
        int zahl = 0;
        int zahlen[zahlenSize];
        for (int i = 0; i < zahlenSize; i++) {
            do {
                cin >> zahl;
                istEinzigartig = true;
                for (int j = 0; j < i; j++) {
                    if (!pruefen(zahl, zahlenRange)) {
                        istEinzigartig = false;
                        cout << "Ungültige Eingabe! Bitte geben Sie eine Zahl zwischen 1 und " << zahlenRange << " ein." << endl;
                    }
                    if (zahlen[j] == zahl) {
                        istEinzigartig = false;
                        break;
                    }
                }
            } while (!istEinzigartig);
            zahlen[i] = zahl;
        }
        ausgabeM(zahlenRange, zahlenSize, zahlen, ausgabeBreite);
    }

    void ausgabeM(int zahlenRange, int zahlenSize, int zahlen[], int ausgabeBreite) {
        cout << endl << "Ihre ausgewählten Zahlen sind:\n";
        for (int i = 1; i <= zahlenRange; i++) {
            bool isHighlighted = false;
            for (int j = 0; j < zahlenSize; j++) {
                if (i == zahlen[j]) {
                    isHighlighted = true;
                    break;
                }
            }
            if (isHighlighted) {
                cout << RED;
            }
            if (i < 10) {
                cout << "0" << i << " ";
            }
            if (i > 9) {
                cout << i << " ";
            }
            cout << RST;
            if (i % ausgabeBreite == 0) {
                cout << endl;
            }
        }
    }

    void routine(int zahlenSize, int zahlenRange, int ausgabeBreite) {
        bool istEinzigartig;
        int zahl = 0;
        int zahlen[zahlenSize];
        srand(static_cast<unsigned int>(time(NULL)));
        for (int i = 0; i < zahlenSize; i++) {
            do {
                zahl = (rand() % zahlenRange) + 1;
                istEinzigartig = true;
                for (int j = 0; j < i; j++) {
                    if (zahlen[j] == zahl) {
                        istEinzigartig = false;
                        break;
                    }
                }
            } while (!istEinzigartig);
            zahlen[i] = zahl;
        }
        ausgabeM(zahlenRange, zahlenSize, zahlen, ausgabeBreite);
    }
};

void menu() {
    cout << "/Menu/" << endl;
    cout << "Sie haben Aktuell " << YELLOW << lottoModusAusgeben(lottoModus) << RST << " ausgewählt" << "\n";
    cout << "Bitte wählen Sie aus:\n\n";
    cout << YELLOW;
    cout << "\t(1) Tippschein generieren für   \t[" << RED << lottoModusAusgeben(lottoModus) << YELLOW<< "]\n";
    cout << "\t(2) Tippschein selber eingeben für\t[" << RED << lottoModusAusgeben(lottoModus) << YELLOW<< "]\n";
    cout << "\t(3) ["<< RED <<"Lotto 6 aus 49" << YELLOW << "] auswählen" << endl;
    cout << "\t(4) ["<< RED <<"Eurojackpot 5 aus 50 + 2 aus 12" << YELLOW << "] auswählen" << endl;
    cout <<BLUE<< "\t(5) Exit" << YELLOW<< endl;
    cout << "\t(6) Tippschein speichern" << endl;
    cout << "\t(7) Tippschein laden" << endl;
    cout << RST;

    int choice = 0;
    cin >> choice;
    switch (choice) {
        case 1:
            {
                if(lottoModus==0){   
                    LottoC lottoObj649;
                    lottoObj649.routine(6, 49, 7);//(n,Range,Konsolen-Ausgabebreite) 
                    menu();        
                }
                if(lottoModus==1){
                    LottoC lottoObj550;
                    LottoC lottoObj212;
                    lottoObj550.routine(5, 50, 5);//(n,Range,Konsolen-Ausgabebreite) 
                    lottoObj212.routine(2, 12, 4);
                    menu();
                }
            }
            break;
        case 2:
            {
                LottoC lottoObj649;
                LottoC lottoObj550;
                LottoC lottoObj212;
                if(lottoModus==0){
                    
                    lottoObj649.eingabeM(6, 49, 7);//(n,Range,Konsolen-Ausgabebreite) 
                    menu();
                }
                if(lottoModus==1){
                    
                    lottoObj212.eingabeM(2, 12, 4);
                    lottoObj550.eingabeM(5, 50, 5);
                    menu();
                }
            }
            break;
        case 3:
            lottoModus = 0;
            menu();
            break;
        case 4:
            lottoModus = 1;
            menu();
            break;
        case 6:
            {
                string dateiname;
                cout << "Geben Sie den Dateinamen ein: ";
                cin >> dateiname;
                LottoC lottoObj649;     //Speichern / Laden
                menu();
            }
            break;
        case 7:
            {
                string dateiname;
                cout << "Geben Sie den Dateinamen ein: ";
                cin >> dateiname;
                LottoC lottoObj649;     //Speichern / Laden
                menu();
            }
            break;
        case 5:
            break;
        default:
            cout << "Ungültige Eingabe. Bitte wählen Sie eine gültige Option." << endl;
            menu();
            break;
    }
}

int main() {
    menu();
    return 0;
}
