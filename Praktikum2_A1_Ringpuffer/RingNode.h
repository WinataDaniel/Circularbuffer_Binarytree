/*************************************************
* ADS Praktikum 2.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>

const int maxRingNode = 6;

class RingNode{
	
private:
	int oldAge;
	std::string description;
	std::string symbolicData;
	RingNode* next;

public:
	RingNode();
	RingNode(int, std::string, std::string);
	int getAge() const;
	void setAge(int);
	std::string getDescription() const;
	void setDescription(std::string);
	std::string getData() const;
	void setData(std::string);
	
	RingNode* getNext();
	void setNext(RingNode*);

	friend std::ostream& operator<<(std::ostream& stream, RingNode const& RingNode); // Ausgabeoperator überladen
};
