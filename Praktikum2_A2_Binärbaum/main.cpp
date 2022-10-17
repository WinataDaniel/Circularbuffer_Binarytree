/*************************************************
 * ADS Praktikum 2.2
 * main.cpp
 *
 *************************************************/
#define CATCH_CONFIG_RUNNER
#include "Tree.h"
#include "catch.h"
#include <iostream>
#include <string>

using namespace std;

///////////////////////////////////////
// Hilfsmethoden fürs Menü hier:



/***************************
 ** Vorgegebene  Funktion **
 ***************************
   "mainscreen_addTreeCSV"

Importiert CSV Datei in bestehenden Baum.
Bei Aufruf in der main() Methode, muss der Pointer auf den Anker des Baums, als Parameter übergeben werden.
Es wird die im gleichen Verzeichnis liegende Datei "ExportZielanalyse.csv" geladen.
****************************/
void mainscreen_addTreeCSV(Tree*& ref)
{
    char j;
    cout << "+ Moechten Sie die Daten aus der Datei ExportZielanalyse.csv "
        "importieren(j / n) ? >";
    cin >> j;
    cin.ignore();
    if (j == 'j')
    {
        ifstream csvread;
        csvread.open("ExportZielanalyse.csv", ios::in);
        if (!csvread.is_open())
            cout << "Fehler beim Lesen!" << endl;
        else
        {
            string name, age, postcode, income;

            while (!csvread.eof())
            {
                cout << !csvread.eof() << endl;

                getline(csvread, name, ';');
                getline(csvread, age, ';');
                getline(csvread, income, ';');
                getline(csvread, postcode, '\n');
                ref->addNode(name, stoi(age), stod(income), stoi(postcode));
            }
            csvread.close();
        }
        cout << "+ Daten wurden dem Baum hinzugefuegt." << endl;
    }
}
//
///////////////////////////////////////
int main()
{
    int result = Catch::Session().run();


    string name;
    int age;
    double income;
    int postCode;
    int orderId;

    int i;

    Tree* myData = new Tree();

    cout << "=========================================" << endl;
    cout << "   ADS - ELK - Stack v1.9, by 25th Bam   " << endl;
    cout << "=========================================" << endl << endl;
    cout << "1) Datensatz einfuegen, manuell" << endl;
    cout << "2) Datensatz einfuegen, CSV Datei" << endl;
    cout << "3) Datensatz loeschen" << endl;
    cout << "4) Suchen" << endl;
    cout << "5) Datenstruktur anzeigen" << endl;
    cout << "6) Level-Order Ausgabe" << endl;
    cout << "7) Beenden" << endl;

    do {
        cout << "?> ";
        while (!(cin >> i)) {
            cout << "Falsche Eingabe." << endl;
            cout << "?> ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (i) {
        case 1 :
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "+ Bitte geben Sie die den Datensatz ein: " << endl;
            cout << "Name ?> "; getline(cin, name);
            cout << "Alter ?> "; cin >> age;
            cout << "Einkommen ?> "; cin >> income;
            cout << "PLZ ?> "; cin >> postCode;
            cout << "+ Ihr Datensatz wurde eingefuegt" << endl;
            myData->addNode(name, age, income, postCode);
            break;
        case 2:
            mainscreen_addTreeCSV(myData);
            break;
        case 3:
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "+ Bitte geben Sie den zu loeschenden Datensatz an" << endl << " OrderID ?> ";
            cin >> orderId;
            cout << "+ Eintrag wurde geloescht." << endl;
            myData->deleteNode(orderId);
            break;
        case 4:
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "+ Bitte geben Sie den zu suchenden Datensatz an" << endl << " Name ?> ";
            getline(cin, name);
            myData->searchNode(name);
            myData->printGefundenStellen();
            break;
        case 5:
            myData->printAll();
            break;
        case 6:
            myData->levelOrder();
            break;
        case 7 :
            system("PAUSE");
            return 0;
        }
        if (!(i >= 1 && i <= 7)) {
            cout << "Nur von 1 bis 7 !!" << endl;
        }
    } while (true);
    
    delete myData;

    system("PAUSE");

    return 0;
}
