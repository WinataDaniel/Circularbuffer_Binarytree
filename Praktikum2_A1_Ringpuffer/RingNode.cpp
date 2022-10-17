/*************************************************
* ADS Praktikum 2.1
* RingNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "RingNode.h"
#include <iostream>

RingNode::RingNode() {
	oldAge = 0;
	description = "null";
	symbolicData = "null";
	next = nullptr;
}

RingNode::RingNode(int oldAge, std::string description, std::string symbolicData) {
	this->oldAge = oldAge;
	this->description = description;
	this->symbolicData = symbolicData;
	next = nullptr;
}

int RingNode::getAge() const {
	return oldAge;
}

void RingNode::setAge(int oldAge) {
	this->oldAge = oldAge;
}

std::string RingNode::getDescription() const {
	return description;
}

void RingNode::setDescription(std::string description) {
	this->description = description;
}

std::string RingNode::getData() const {
	return symbolicData;
}

void RingNode::setData(std::string symbolicData) {
	this->symbolicData = symbolicData;
}

//const?
RingNode* RingNode::getNext() {
	return next;
}

void RingNode::setNext(RingNode* next) {
	this->next = next;
}

//added iostream
std::ostream& operator<<(std::ostream& stream, RingNode const& RingNode) {
	stream << "Alter : " << RingNode.oldAge << ", Beschreibung: " << RingNode.description << ", Daten: " << RingNode.symbolicData;
	return stream;
}