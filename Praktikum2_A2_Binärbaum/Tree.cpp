/*************************************************
 * ADS Praktikum 2.2
 * Tree.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iomanip>
#include <iostream>
//#include <queue>

using namespace std;

Tree::Tree() {
	anker = nullptr;
	currentNodeChronologicalID = 0;
}

// Post-Order-Traversierung
 void Tree::deleteTeilBaum(TreeNode* b) {
	 if (b->getLeft()) {
		 deleteTeilBaum(b->getLeft());
		 b->setLeft(nullptr);
	 }
	 if (b->getRight()) {
		 deleteTeilBaum(b->getRight());
		 b->setRight(nullptr);
	 }
	 if (b->getLeft() == nullptr && b->getRight() == nullptr)
	 {
		 delete b;
		 return;
	 }
	 return;
}

Tree::~Tree() {
	if (anker != nullptr) deleteTeilBaum(anker);
}

void Tree::addNode(string name, int age, double income, int postCode) {
	// einen neuen Knoten erzeugen und initialisieren
	double newNodeOrderId = age + income + postCode;
	TreeNode* newTreeNode = new TreeNode(newNodeOrderId , currentNodeChronologicalID++, name, age, income, postCode);
	newTreeNode->setLeft(nullptr);
	newTreeNode->setRight(nullptr);

	// Wenn Baum leer ist
	if (anker == nullptr) {
		anker = newTreeNode;
		//newTreeNode->print();
		//cout << "success Baum jetzt hat einen Knoten" << endl;
		return;
	}

	// Sonst ist Baum nicht leer
	// Mit der While-Schleife iteriere ich, bis ich ein Blatt erreiche
	TreeNode* tmp = anker;
	TreeNode* prev = anker;
	
	while (tmp != nullptr) {
		prev = tmp;
		if (tmp->getNodeOrderID() > newNodeOrderId) {
			tmp = tmp->getLeft();
		}
		else if (tmp->getNodeOrderID() <= newNodeOrderId) {
			tmp = tmp->getRight();
		}
	}

	// hinzufuegen den Knoten in den Baum entsprechend der OrderID
	if (newTreeNode->getNodeOrderID() < prev->getNodeOrderID()) {
		prev->setLeft(newTreeNode);
		//prev->print();
		//newTreeNode->print();
		//cout << "successlinks" << endl;
	}
	else if (newTreeNode->getNodeOrderID() > prev->getNodeOrderID()) {
		prev->setRight(newTreeNode);
		//prev->print();
		//newTreeNode->print();
		//cout << "successrechts" << endl;
	}
	else {
		delete newTreeNode;
		currentNodeChronologicalID--;
	}
	return;
}

bool Tree::deleteNode(int nodeOrderID) {
	// Wenn Baum leer ist
	if (anker == nullptr) return false;

	// Wenn Baum nur einen Knoten hat
	if (anker->getLeft() == nullptr && anker->getRight() == nullptr) {
		if (anker->getNodeOrderID() != nodeOrderID) return false;
		delete anker;
		anker = nullptr;
		return true;
	}

	TreeNode* prev = anker;
	TreeNode* tmp = anker;

	// Suche den zu löschenden Knoten entsprechend der ID
	while (tmp != nullptr && tmp->getNodeOrderID() != nodeOrderID) {
		prev = tmp;
		if (tmp->getNodeOrderID() > nodeOrderID) {
			tmp = tmp->getLeft();
		}
		else {
			tmp = tmp->getRight();
		}
	}

	// Knoten mit dieser Id nicht gefunden
	if (tmp == nullptr) return false;

	// eine Variable, um mir zu helfen, ob tmp links or rechts von prev ist.
	bool left = false;
	if (prev->getLeft() == nullptr) {
		left = false;
	}
	else if (prev->getRight() == nullptr) {
		left = true;
	} 
	else if (prev->getLeft()->getNodeOrderID() == nodeOrderID) {
		left = true;
	}

	// Knoten gefunden!
	// Fall 1 : Der zu löschende Knoten ist ein Blatt
	if (tmp->getLeft() == nullptr && tmp->getRight() == nullptr) {
		if (left) prev->setLeft(nullptr);
		else prev->setRight(nullptr);
		delete tmp;
		return true;
	}

	// Fall 2 : Der zu löschende Knoten hat einen Nachfolger
	else if (tmp->getLeft() == nullptr) {
		// Wurzel
		if (prev == tmp) {
			anker = tmp->getRight();
			delete tmp;
			return true;
		}

		if (left) prev->setLeft(tmp->getRight());
		else prev->setRight(tmp->getRight());
		delete tmp;
		return true;
	}
	else if (tmp->getRight() == nullptr) {
		// Wurzel
		if (prev == tmp) {
			anker = tmp->getLeft();
			delete tmp;
			return true;
		}

		if (left) prev->setLeft(tmp->getLeft());
		else prev->setRight(tmp->getLeft());
		delete tmp;
		return true;
	}

	// Fall 3 : Der zu löschende Knoten hat 2 Nachfolger
	else {
		TreeNode* prevMin = tmp->getRight();
		TreeNode* min = prevMin->getLeft();
		
		// Jetzt suchen wir Minimum von dem rechten Teilbaum
		// hier if rechts Knoten direkt min Knoten ist 
		if (min == nullptr) {
			prevMin->setLeft(tmp->getLeft());

			// Wenn der zu löschende Knoten eine Wurzel ist
			if (prev == tmp) {
				anker = prevMin;
				delete tmp;
				return true;
			}

			if (left) prev->setLeft(prevMin);
			else prev->setRight(prevMin);
			delete tmp;
			return true;
		}
		// Iterieren weiter bis zum Minimum
		else {
			while (min->getLeft() != nullptr) {
				prevMin = min;
				min = min->getLeft();
			}

			// Min gefunden!
			// Zeiger von PrevMin umbauen
			if (min->getRight() == nullptr) {
				prevMin->setLeft(nullptr);
			}
			else {
				prevMin->setLeft(min->getRight());
			}
		
			min->setLeft(tmp->getLeft());
			min->setRight(tmp->getRight());

			// Wenn der zu löschende Knoten eine Wurzel ist
			if (prev == tmp) {
				anker = min;
				delete tmp;
				return true;
			}

			if (left) prev->setLeft(min);
			else prev->setRight(min);
			delete tmp;
			return true;
		}
	}
}

// Post-Order
bool Tree::searchRekursiv(TreeNode* b, string name, bool& findLeft, bool& findRight, bool& find) {
	if (b->getLeft() != nullptr) {
		findLeft = searchRekursiv(b->getLeft(), name, findLeft, findRight, find);
	}
	if (b->getRight() != nullptr) {
		findRight = searchRekursiv(b->getRight(), name, findLeft, findRight, find);
	}
	if (b->getName() == name) {
		gefundenStellen.push(b);
		find = true;;
	}
	return findLeft || findRight || find;
}

bool Tree::searchNode(string name) {
	if (anker == nullptr) return false;
	else {
		TreeNode* hilfsPtr = anker;
		bool findLeft = false;
		bool findRight = false;
		bool find = false;
		searchRekursiv(hilfsPtr, name, findLeft, findRight, find);

		return findLeft || findRight || find;
	}
}

// Pre Order
void Tree::printAll() {
	TreeNode* hilfsPtr = anker;
	cout << "ID  | Name             | Age   | Income    | PostCode | OrderID" << endl;
	cout << "----+------------------+-------+-----------+----------+-------" << endl;
	printPreOrder(hilfsPtr);
}

void Tree::printPreOrder(TreeNode* b) {
	if (b != nullptr) {
		cout << setfill(' ');
		cout << setw(4) << b->getNodeChronologicalID() << "|" <<
			setw(18) << b->getName() << "|" <<
			setw(7) << b->getAge() << "|" <<
			setw(11) << b->getIncome() << "|" <<
			setw(11) << b->getPostCode() << "|" <<
			setw(11) << b->getNodeOrderID() << "|" << endl;
		
		printPreOrder(b->getLeft());
		printPreOrder(b->getRight());
	}
}

void Tree::levelOrder() {
	int maxLevel = 10;
	cout << "ID  | Name             | Age   | Income    | PostCode | OrderID" << endl;
	cout << "----+------------------+-------+-----------+----------+-------" << endl;
	
	TreeNode* hilfsPtr = anker;

	// 2 Queue instanzieren
	std::queue<TreeNode*> q;
	std::queue<int> nq;
	if (/*hilfsPtr == nullptr*/!hilfsPtr) {
		//cout << "BST IST LEEEEEEEEEEEEEEER" << endl;
		return;
	}

	// Wurzelknoten und Startniveau in die Queues pushen
	q.push(hilfsPtr);
	nq.push(1);

	int level;

	while (!q.empty()) {
		// Entnahme aus den Queues und löschen 
		TreeNode* curr = q.front();
		q.pop();
		level = nq.front(); 
		nq.pop();

		// max Niveau 10
		if (level > maxLevel) return;

		cout << setfill(' ');
		cout << setw(4) << curr->getNodeChronologicalID() << "|" <<
			setw(18) << curr->getName() << "|" <<
			setw(7) << curr->getAge() << "|" <<
			setw(11) << curr->getIncome() << "|" <<
			setw(11) << curr->getPostCode() << "|" <<
			setw(11) << curr->getNodeOrderID() << "|" <<
			setw(6) << level << "|" << endl;

		// Linker Nachfolgeknoten in die Queues
		if (curr->getLeft() != nullptr)
		{
			q.push(curr->getLeft());
			nq.push(level + 1);
		}
		// Rechter Nachfolgeknoten in die Queues
		if (curr->getRight() != nullptr)
		{
			q.push(curr->getRight());
			nq.push(level + 1);
		}
	}
	return;
}

void Tree::printGefundenStellen() {
	TreeNode* hilfsPtr;
	if (gefundenStellen.empty()) {
		cout << "Daten nicht gefunden!!!!!!!" << endl;
	}

	while (!gefundenStellen.empty()) {
		cout << "+ Fundstellen: " << endl;
		hilfsPtr = gefundenStellen.front();
		hilfsPtr->print();
		gefundenStellen.pop();
	}
}























//// Pointer zurück geben, da Wurzel gelöscht werden könnte
//TreeNode* Tree::deleteTreeNode(TreeNode* b, int nodeOrderId) {
//	if (b == nullptr) return b;
//	else if (nodeOrderId < b->getNodeOrderID()) {
//		b->setLeft(deleteTreeNode(b->getLeft(), nodeOrderId));
//	}
//	else if (nodeOrderId > b->getNodeOrderID()) {
//		b->setRight(deleteTreeNode(b->getRight(), nodeOrderId));
//	}
//	else {
//		// Knoten gefunden!
//			// Fall 1 : Der zu löschende Knoten ist ein Blatt
//		if (b->getLeft() == nullptr && b->getRight() == nullptr) {
//			delete b;
//			b = nullptr;
//			return b;
//		}
//		// Fall 2 : Der zu löschende Knoten hat einen Nachfolger
//		else if (b->getLeft() == nullptr) {
//			TreeNode* tmp = b;
//			b = b->getRight();
//			delete tmp;
//			return b;
//		}
//		else if (b->getRight() == nullptr) {
//			TreeNode* tmp = b;
//			b = b->getLeft();
//			delete tmp;
//			return b;
//		}
//		// Fall 3 : der zu löschende Knoten hat 2 Nachfolger
//		// finde min von dem rechten Teilbaum
//		else {
//			TreeNode* tmp = findMin(b->getRight());
//
//			// Erstelle neuen Knoten
//			TreeNode* newNode = new TreeNode(tmp->getNodeOrderID(), tmp->getNodeChronologicalID(), tmp->getName(), tmp->getAge(), tmp->getIncome(), tmp->getPostCode());
//			newNode->setLeft(b->getLeft());
//			newNode->setRight(deleteTreeNode(b->getRight(), tmp->getNodeOrderID()));
//
//			// habe ich zurückgesetzt?
//			delete b; // b nullptr
//			return newNode;
//			// delete tmp?
//		}
//	}
//}