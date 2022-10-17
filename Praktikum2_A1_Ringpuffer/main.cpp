/*************************************************
* ADS Praktikum 2.1
* main.cpp
* 
*************************************************/
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.h"

using namespace std;


int main()
{
	int result = Catch::Session().run();

	Ring myBackups;
	int i;
	string eingabeDescription;
	string eingabeData;
	
	cout << "========================================" << endl;
	cout << "SuperBackUp-Organizer over 9000, by. Son Goku" << endl;
	cout << "========================================" << endl << endl;
	cout << "1) Backup anlegen" << endl;
	cout << "2) Backup suchen" << endl;
	cout << "3) Alle Backups ausgeben" << endl;
	
	do {
		cout << "?> ";
		cin >> i;
		switch (i) {
		case 1:
			cout << "+Neuen Datensatz anlegen" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Beschreibung ?> "; getline(cin, eingabeDescription);
			cout << "Daten ?> "; getline(cin, eingabeData);
			cout << "+Ihr Datensatz wurde hinzugefuegt." << endl << endl;
			myBackups.addNewNode(eingabeDescription, eingabeData);

			break;
		case 2:
			cout << "+Nach welchen Daten soll gesucht werden?" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "?> "; getline(cin, eingabeData);

			if (myBackups.search(eingabeData)) {
				cout << "+ Gefunden in Backup: ";
				myBackups.printData(eingabeData);
			}
			else {
				cout << "+ Datensatz konnte nicht gefunden werden." << endl;
			}
			break;
		case 3:
			myBackups.print();
		}
	} while (i > 0 && i < 4 );

	system("Pause");
	return 0;
}
