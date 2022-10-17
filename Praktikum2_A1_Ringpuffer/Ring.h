/*************************************************
* ADS Praktikum 2.1
* Ring.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .h
#pragma once
#include<string>
#include "catch.h"
#include"RingNode.h"

class Ring{
	
	private:
		int countNodes;
		RingNode* anker;

		// Hilfsmethode
		void print2(RingNode*);
	public:
		Ring();
		void addNewNode(std::string, std::string);
		bool search(std::string);
		void print();

		// Hilfsmethode
		void printData(std::string);

		////////////////////////////////////
		// friend Funktionen müssen unangetastet bleiben! 
		friend RingNode * get_anker(Ring& r);
		friend int get_countNodes(Ring& r);
};

void addAge(RingNode* anker);

