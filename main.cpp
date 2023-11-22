#include "header.h"



void createAndPrintTicket(C_LoteryTicket& ticket) {
    int choice;
    cout << "Möchten Sie die Zahlen selbst eingeben oder generieren lassen?" << endl << "(1 - Selbst eingeben, 2 - Generieren lassen): ";
    cin >> choice;
    if (choice == 1) {
        ticket.m_Tippschein(6,49);
    } else {
        ticket.m_Tippschein(6,49, true);
    }
    ticket.m_scheinPrint();
    cout << endl;
}

int main() {
    srand(time(0)); // Initialisieren Sie den Zufallsgenerator

    int auswahl;
    do {
        cout << "Bitte wählen Sie eine Option:\n";
        cout << "1. Lotto 6 aus 49\n";
        cout << "2. Eurolotto\n";
        cout << "3. Ende des Programmes\n";
        cin >> auswahl;

        switch (auswahl) {
            case 1: {
                int numTickets;
                while (true) {
                    cout << "Wie viele Lottoscheine möchten Sie erstellen? ";
                    cin >> numTickets;
                    if (cin.fail() || numTickets <= 0) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Ungültige Eingabe. Bitte geben Sie eine positive Zahl ein." << endl;
                    } else {
                        break;
                    }
                }

                vector<C_LoteryTicket> tickets(numTickets);

                int auswahl2;
                cout << "Möchten Sie die Lottoscheine generieren oder manuell eingeben?\n";
                cout << "1. Generieren\n";
                cout << "2. Manuell eingeben\n";
                cin >> auswahl2;
                
                switch (auswahl2) {
                    case 1: {
                        for (int i = 0; i < numTickets; i++) {
                            tickets[i].m_Tippschein(6, 49, true);
                        }
                        break;
                    }
                    case 2: {
                        for (int i = 0; i < numTickets; i++) {
                            tickets[i].m_Tippschein(6, 49);
                        }
                        break;
                    }
                    default:
                        cout << "Ungültige Auswahl. Bitte wählen Sie eine gültige Option.\n";
                }

                cout << endl << "Alle Lottoscheine Anzahl+Zahlen: " << endl;
                for (int i = 1; i < numTickets; i++) {
                    tickets[0].m_scheinOverlay(tickets[i]);
                }
                tickets[0].m_scheinPrint();
                break;
            }
            case 2: {
                C_LoteryTicket eurolotto;
                eurolotto.m_Tippschein(5, 50);
                // Hier können Sie weitere Operationen mit dem Eurolotto-Schein durchführen
                break;
            }
            case 3:
                cout << "Programm beendet.\n";
                break;
            default:
                cout << "Ungültige Auswahl. Bitte wählen Sie eine gültige Option.\n";
        }
    } while (auswahl != 3);

    return 0;
}