#include <iostream>     //6 / 49
#include <stdlib.h>     //Eurolotto 5 aus 50 +(2 aus 12)
#include <chrono>       // Tippschein 1-10
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;
#define RST     "\033[0m"
#define BLACK   "\033[30m"      /* Schwarz */
#define RED     "\033[31m"      /* Rot */
#define GREEN   "\033[32m"      /* Grün */
#define YELLOW  "\033[33m"      /* Gelb */
#define BLUE    "\033[34m"      /* Blau */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* Weiß */


void menu();
void menuA();
void menuB();
void menuC();
bool lottoModus;

string lottoModusAusgeben(bool lottoModus) {  //Giebt Den Lotto Modus als String aus
    if (lottoModus == 0) {
        return "Lotto 6 aus 49";
    }
    if (lottoModus == 1) {
        return "Eurojackpot";
    }
    return "Ungültiges Lotto-Spiel";
}

//////////////////////////////////////////////////////////////// 5 aus 50
void tippschein550(){
    int zahlRange=50;
    int arr550 = 5;
    int zahlen[arr550];
    cout << "Geben Sie " << arr550 << " Werte ein:\n";
    for (int i = 0; i < arr550; i++){
        cout << BLUE << "[" << i+1 << "] ";
        cin >> zahlen[i];
    }
    
    cout << "Ihre ausgewählten Zahlen sind:\n";
    for (int i = 1; i <= zahlRange; i++){
        bool isHighlighted = false;
        for (int j = 0; j < arr550; j++){
            if (i == zahlen[j]){
                isHighlighted = true;
                break;
            }
        }
        if (isHighlighted){
            cout << RED;
        }
        if (i<10){
            cout <<"0"<< i << " ";
        }
        if (i>9)cout << i << " ";
        cout << RST;
        if (i % 5 == 0){
            cout << endl;
        }
    }
    menu();
}

void routine550(){
    bool istEinzigartig;
    int zahl=0;
    int zahlen[5];
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < 5; i++) {
        do {
            zahl = (rand() % 50) + 1;
            istEinzigartig = true;
            for (int j = 0; j < i; j++) {
                if (zahlen[j] == zahl) {  
                    istEinzigartig = false;
                    break;
                }
            }
        } while (!istEinzigartig );
        zahlen[i] = zahl;
        cout << (i + 1) << "\t" << zahl << endl;
    }
    menu();
}
//////////////////////////////////////////////////////////////// 5 aus 50 Ende
//////////////////////////////////////////////////////////////// 6 aus 49 Anfang
void tippschein649(){
    int zahlRange=49;
    int arr649 = 6;
    int zahlen[arr649];
    cout << "Geben Sie " << arr649 << " Werte ein:\n";
    for (int i = 0; i < arr649; i++){
        cout << BLUE << "[" << i+1 << "] ";
        cin >> zahlen[i];
    }
    
    cout << "Ihre ausgewählten Zahlen sind:\n";
    for (int i = 1; i <= zahlRange; i++){
        bool isHighlighted = false;
        for (int j = 0; j < arr649; j++){
            if (i == zahlen[j]){
                isHighlighted = true;
                break;
            }
        }
        if (isHighlighted){
            cout << RED;
        }
        if (i<10){
            cout <<"0"<< i << " ";
        }
        if (i>9)cout << i << " ";
        cout << RST;
        if (i % 7 == 0){
            cout << endl;
        }
    }
    menu();
}

void routine649(){
    int zahlRange=49;
    int arr649 = 6;
    bool istEinzigartig;
    int zahl=0;
    int zahlen[6];
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < 6; i++) {
        do {
            zahl = (rand() % 49) + 1;
            istEinzigartig = true;
            for (int j = 0; j < i; j++) {
                if (zahlen[j] == zahl) {
                    istEinzigartig = false;
                    break;
                }
            }
        } while (!istEinzigartig );
        zahlen[i] = zahl;
        cout << (i + 1) << "\t" << zahl << endl;
    }
    cout << "Ihre ausgewählten Zahlen sind:\n";
    for (int i = 1; i <= zahlRange; i++){
        bool isHighlighted = false;
        for (int j = 0; j < arr649; j++){
            if (i == zahlen[j]){
                isHighlighted = true;
                break;
            }
        }
        if (isHighlighted){
            cout << RED;
        }
        if (i<10){
            cout <<"0"<< i << " ";
        }
        if (i>9)cout << i << " ";
        cout << RST;
        if (i % 7 == 0){
            cout << endl;
        }
    }
    menu();
}
//////////////////////////////////////////////////////////////// 6 aus 49 Ende

void menu(){
    cout << "/Menu/"<< endl;
    cout << "Sie haben Aktuell "<< YELLOW << lottoModusAusgeben(lottoModus) << RST << " ausgewählt"<< "\n";
    cout << "Bitte wählen sie aus:\n\n";
    cout << YELLOW;
    cout << "\t(1) Tippscheine" << endl;
    cout << "\t(2) Routine" << endl;
    cout << "\t(3) [Lotto 6 aus 49]" << endl;
    cout << "\t(4) [Eurojackpot]" << endl;
    cout << "\t(5) Exit" << endl;
    cout << RST;

    int choice = 0; // Menu
    cin >> choice;
    switch(choice){
        case 1: 
            menuA(); //Tippscheine
        break;
        case 2: 
            menuB(); //Routine
        break;
        case 3: 
            lottoModus = 0; //Setzt lotto modus auf 6 aus 49
            menu();
        break;
        case 4: 
            lottoModus = 1; //Setzt lotto modus auf 5 aus 50
            menu();
        break;
        case 5: 
            
        break;
    }
}

void menuA(){       //Tippscheine
    cout << "/Menu/A/"<< endl;
    cout << "Sie haben Aktuell "<< YELLOW << lottoModusAusgeben(lottoModus) << RST << " ausgewählt"<< "\n";
    cout << "Bitte wählen sie aus:\n\n";
    cout << YELLOW<< "Tippscheine..\n";
    cout << "\t-(1)> Eingeben" << endl;
    cout << "\t-(2)# Laden" << endl;
    cout << "\t-(3)# Speichern" << endl;
    cout << "\t-(4)# Anzahl der Spiele" << endl;
    cout << "\t-(5)# Exit" << endl;
    cout << RST;

    int choice = 0; // Menu
    cin >> choice;
    switch(choice){
        case 1: 
            if (lottoModus==0){
                tippschein649();    
            }
            if (lottoModus==1){
                tippschein550();    
            }
        break;
        case 2:
 
        break;
        case 3: 
            lottoModus = 0; // 6 aus 49
        break;
        case 4: 
            lottoModus = 1; // 5 aus 50
        break;
        case 5: 
            
        break;
    }
}
void menuB(){   //Routine
    cout << "/Menu/B/"<< endl;
    cout << "Sie haben Aktuell "<< YELLOW << lottoModusAusgeben(lottoModus) << RST << " ausgewählt"<< "\n";
    cout << "Bitte wählen sie aus:\n\n";
    cout << YELLOW;
    cout << "\t(1)> Lottozahlen Generieren (" << lottoModusAusgeben(lottoModus) << ")\n";
    cout << "\t(2)> " << endl;
    cout << "\t(3)" << endl;
    cout << "\t(4)" << endl;
    cout << "\t(5) Exit" << endl;
    cout << RST;

    int choice = 0; // Menu
    cin >> choice;
    switch(choice){
        case 1: 
            if (lottoModus==0){
                    routine649();    
                }
                if (lottoModus==1){
                    routine550();    
                }            
        break;
        case 2: 

        break;
        case 3: 

        break;
        case 4: 

        break;
        case 5: 
            
        break;
    }
}
void menuC(){   //Routine
    cout << "/Menu/C/"<< endl;
    cout << "Sie haben Aktuell "<< YELLOW << lottoModusAusgeben(lottoModus) << RST << " ausgewählt"<< "\n";
    cout << "Bitte wählen sie aus:\n\n";
    cout << YELLOW;
    cout << "\t(1)" << endl;
    cout << "\t(2)" << endl;
    cout << "\t(3)" << endl;
    cout << "\t(4)" << endl;
    cout << "\t(5) Exit" << endl;
    cout << RST;

    int choice = 0; // Menu
    cin >> choice;
    switch(choice){
        case 1: 

        break;
        case 2: 

        break;
        case 3: 

        break;
        case 4: 

        break;
        case 5: 
            
        break;
    }
}




/*
Notizen
 //anzahl tippscheine + speichern

*/
int main() { 
    menu();  
}

/*
cout << RED << "nr\tZahl\tTag\t\tDD.MM.YYYY\tZeit\t\tBerechnungszeit\n"<< RST;
void zeitMessen(){  //diese funktion wird später noch hinzugefügt
    //Start Zeitmessung
        auto start = chrono::system_clock::now();
    //ende zeitmessung
        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end-start;
        time_t end_time = chrono::system_clock::to_time_t(end);
        tm* utc_time = gmtime(&end_time);
        int timezone_offset = 2; // Set your timezone offset here
        utc_time->tm_hour += timezone_offset;
        time_t local_time = mktime(utc_time);
        cout << "\t" << put_time(localtime(&local_time), "%A\t%d.%m.%Y \t%H:%M:%S") << "\t" << elapsed_seconds.count() << "s" << endl;
}*/