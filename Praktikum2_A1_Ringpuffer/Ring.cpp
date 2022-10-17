/*************************************************
* ADS Praktikum 2.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>
#include <vector>

// Zu Beginn ist Ihr Ring noch leer und der Anker zeigt auf ”null”.
Ring::Ring() {
	countNodes = 0;
	//anker = nullptr;
	anker = new RingNode;
	anker->setNext(nullptr);
}

void Ring::addNewNode(std::string description, std::string symbolicData) {
	RingNode* newRNode = new RingNode(0, description, symbolicData);
	
	if (countNodes == 0) {
		newRNode->setNext(newRNode);
		countNodes++;
	}
	else {
		 /* Knoten ist hier weniger als 6, daher addiert man den Knoten ganz normal und entsprechend den Zeiger umbauen.*/
		if (countNodes < maxRingNode) {
			addAge(anker);
			newRNode->setNext(anker->getNext());
			anker->setNext(newRNode);
			countNodes++;
		}
		else {
			addAge(anker);
			/* Knoten ist hier mehr als 6, daher ...*/
			// erstes Knoten merken.
			RingNode* hilfsPtr = anker->getNext();
			newRNode->setNext(hilfsPtr->getNext());
			anker->setNext(newRNode);
			// kein countNodes++ mehr hier.
			delete hilfsPtr;
		}
	}
	anker = newRNode;
}

// Iterieren vor vorne bis hinten
bool Ring::search(std::string symbolicData) {
	if (anker == nullptr) return false;

	RingNode* hilfsPtr = anker->getNext();

	while (hilfsPtr->getData() != symbolicData && hilfsPtr->getAge() != 0) {
		hilfsPtr = hilfsPtr->getNext();
	}

	if (hilfsPtr->getData() == symbolicData) return true;

	return false;
	/*if (anker->getData() == symbolicData) {
		return true;
	}
	else {
		return false;
	}*/
}

void Ring::printData(std::string symbolicData) {
	std::string output = "";

	// do i need this?
	//if (anker == nullptr);

	RingNode* hilfsPtr = anker->getNext();

	while (hilfsPtr->getData() != symbolicData && hilfsPtr->getAge() != 0) {
		hilfsPtr = hilfsPtr->getNext();
	}

	if (hilfsPtr->getData() == symbolicData) {
		std::cout << *hilfsPtr << std::endl;
		return;
	}

	/*if (anker->getData() == symbolicData) {
		std::cout << *anker << std::endl;
	}*/
}

void Ring::print() {
	if (anker == nullptr) {
		std::cout << "Keine Backups!!!" << std::endl;
	}
	else {
		print2(anker->getNext());
	}
}

void Ring::print2(RingNode* rNode) {
	if (rNode->getAge() == 0) {
		std::cout << "Alter: " << rNode->getAge() << ", "
					<< "Beschreibung: " << rNode->getDescription() << ", "
					<< "Daten: " << rNode->getData() << std::endl;
	}
	else {
		print2(rNode->getNext());
		std::cout << "--------------------------" << std::endl;
		std::cout << "Alter: " << rNode->getAge() << ", "
			<< "Beschreibung: " << rNode->getDescription() << ", "
			<< "Daten: " << rNode->getData() << std::endl;
	}
}

//void Ring::print() {
//
//	std::vector<RingNode> nodes;
//
//	RingNode* hilfsPtr = anker->getNext();
//
//	for (int i = 0; i < countNodes; i++) {
//
//		/*Appends the given element value to the end of the container.
//		1) The new element is initialized as a copy of value.
//		2) value is moved into the new element.*/
//
//		nodes.push_back(*hilfsPtr);
//		hilfsPtr = hilfsPtr->getNext();
//	}
//
//	std::string lineSeparator = "--------------------------";
//
//	for (int i = countNodes - 1; i >= 0 ; --i) {
//		std::cout << "Alter: " << nodes[i].getAge() << ", "
//			<< "Beschreibung: " << nodes[i].getDescription() << ", "
//			<< "Daten: " << nodes[i].getData() << std::endl;
//		std::cout << lineSeparator << std::endl;
//		nodes.pop_back();
//	}
//}



void addAge(RingNode* anker) {
	RingNode* hilfsPtr = anker->getNext();

	// Iterieren von vorne bis Knoten mit oldAge 0
	while (hilfsPtr->getAge() != 0) {
		hilfsPtr->setAge(hilfsPtr->getAge() + 1);
		hilfsPtr = hilfsPtr->getNext();
	}
	// Pointer als Referenz?
	anker->setAge(anker->getAge() + 1);
}

