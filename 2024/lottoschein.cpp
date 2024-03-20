#include <fstream>
#include <iomanip> // Include the <iomanip> header for setw
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Lotto {
public:
  Lotto(int anzahlN, int range, int ausgabebreite)
      : anzahlN_(anzahlN), range_(range), ausgabebreite_(ausgabebreite) {
    // Initialisiere die Lottozahlen mit dem Wert 0
    for (int i = 1; i <= range_; ++i) {
      lottozahlen_[i] = 0;
    }
  }

  // Ziehe Lottozahlen und inkrementiere die Anzahl der gezogenen Lottozahlen
  void ziehe_lottozahlen() {
    for (int i = 0; i < anzahlN_; ++i) {
      int zahl = 1 + rand() % range_;
      lottozahlen_[zahl]++;
    }
  }

  // Schreibe die Lottozahlen in eine Datei
  void schreibe_in_datei(const string &dateiname) {
    ofstream datei(dateiname);
    if (datei.is_open()) {
      for (int i = 1; i <= range_; ++i) {
        datei << "0x" << setw(2) << setfill('0') << i << ": "
              << lottozahlen_[i] << "\n";
      }
      datei.close();
    }
  }

  // Lade die Lottozahlen aus einer Datei
  void lade_aus_datei(const string &dateiname) {
    ifstream datei(dateiname);
    if (datei.is_open()) {
      string zeile;
      while (getline(datei, zeile)) {
        size_t pos = zeile.find(": ");
        if (pos != string::npos) {
          string schluessel = zeile.substr(0, pos);
          string wert = zeile.substr(pos + 2);
          int zahl = stoi(schluessel, nullptr, 16);
          lottozahlen_[zahl] = stoi(wert);
        }
      }
      datei.close();
    }
  }

  // Gib die Lottozahlen in der gewünschten Darstellung aus
  void gib_aus() {
    for (int i = 1; i <= range_; ++i) {
      if (i % ausgabebreite_ == 1) {
        cout << "\n";
      }
      cout << "0x" << setw(2) << setfill('0') << i << " ";
    }
    cout << "\n\n";

    for (int i = 1; i <= range_; ++i) {
      if (i % ausgabebreite_ == 1) {
        cout << "\n";
      }
      cout << setw(3) << lottozahlen_[i] << " ";
    }
    cout << "\n\n";
  }

private:
  int anzahlN_;
  int range_;
  int ausgabebreite_;
  unordered_map<int, int> lottozahlen_;
};

int main() {
  Lotto lotto(6, 49, 7);
  lotto.ziehe_lottozahlen();
  lotto.schreibe_in_datei("lottozahlen.txt");
  lotto.lade_aus_datei("lottozahlen.txt");
  lotto.gib_aus();

  return 0;
}
