# Lotto Aufgaben Litera:
**Aufgabenblatt 30**
1. Routine
Schreiben Sie eine Routine, die 6 aus 49 oder Eurolotto ermöglicht. Nutzen Sie dazu die folgende Bibliothek für Zufallszahlen.
    ```c
    #include <stdlib.h>
    int zufall = rand();
    ```
2. Ermöglichen Sie die Auswahl, wie viele Tippscheine erstellt werden sollen.

3. Erstellen Sie ein grundlegendes Menü:
    - Lotto 6 aus 49
    - Eurolotto
    - Ende des Programmes

**Aufgabenblatt 31**
1. Bis zu 30 zahlen eingeben (Pool)
- Es können manuell bis zu 30 Zahlen eingegeben werden. 
    - Aus diesen Zahlen werden dann die Zufallszahlen für 6 aus 49 oder Eurolotto ausgewählt. 
    - Die Eingabe erfolgt so lange, bis -1 eingegeben wird. 
    - Bei der Eingabe werden die Zahlen überprüft, ob diese schon eingegeben wurden. 
    - Im Fall eines Duplikats kommt die Aufforderung, eine andere Zahl einzugeben.

2. Eigene Zahlen
    - Erweitern Sie das Menü um folgenden Menüpunkt:
        - Eigene Zahlen eingeben
        - Überlegen Sie, an welcher Stelle Sie implementieren, ob Sie eigene Zahlen nehmen und diese zufällig generieren oder nur zufällig generierte Zahlen nehmen. 
        - Überlegen Sie sich einen sinnvollen Prozess.

**Aufgabenblatt 32**
1. Häufigkeit:
    -  Geben Sie bei der Generierung des Tippscheines die Häufigkeit der Zahlen (Eurolotto / 6 aus 49) an.

**Aufgabenblatt 33**
1. Klassen

- Transformieren Sie die Aufgaben 30 – 32 in eine Klassenstruktur. 
    - Bilden Sie entsprechende 
        - Konstruktoren, 
        - Destruktoren, 
        - Set
        - und Header-Datei.
2. Bilden Sie dazu jeweils eine Header- und eine Implementierungsdatei für jedes System.
3. 
    - Sie möchten Ihre manuell eingegebenen Zahlen speichern bzw. auch wieder laden können. 
    - Definieren Sie dazu einen Speicher- und Ladeprozess. Erweitern Sie das Menü entsprechend.
4. Bilden Sie eine einfache Vererbung für das bereits bestehende System: 
    - Lotto vererbt 2 Klassen: 
        - 6 aus 49
        - Eurolotto
