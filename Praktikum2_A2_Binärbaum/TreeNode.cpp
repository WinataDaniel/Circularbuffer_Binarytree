/*************************************************
 * ADS Praktikum 2.2
 * TreeNode.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "TreeNode.h"
#include <iostream>
#include <string>

TreeNode::TreeNode(int nodeOrderID, int nodeChronologicalID, string name, int age, double income, int postCode) {
	this->nodeOrderID = nodeOrderID;
	this->nodeChronologicalID = nodeChronologicalID;
	this->name = name;
	this->age = age;
	this->income = income;
	this->postCode = postCode;
	left = nullptr;
	right = nullptr;
}

void TreeNode::print() {
	cout << "NodeID: " << nodeChronologicalID << ", Name: " << name << ", Alter: " << age << ", Einkommen: " << income << ", PLZ: " << postCode << ", PostID: " << nodeOrderID << endl;
}

int TreeNode::getNodeOrderID() {
	return nodeOrderID;
}

void TreeNode::setNodeOrderID(int nodeOrderID) {
	this->nodeOrderID = nodeOrderID;
}

int TreeNode::getNodeChronologicalID() {
	return nodeChronologicalID;
}

void TreeNode::setNodeChronologicalID(int nodeChronologicalID) {
	this->nodeChronologicalID = nodeChronologicalID;
}

string TreeNode::getName() {
	return name;
}

void TreeNode::setName(string name) {
	this->name = name;
}

int TreeNode::getAge() {
	return age;
}

void TreeNode::setAge(int age) {
	this->age = age;
}

double TreeNode::getIncome() {
	return income;
}

void TreeNode::setIncome(double income) {
	this->income = income;
}

int TreeNode::getPostCode() {
	return postCode;
}

void TreeNode::setPostCode(int postCode) {
	this->postCode = postCode;
}

TreeNode* TreeNode::getLeft() {
	return left;
}

void TreeNode::setLeft(TreeNode* left) {
	this->left = left;
}

TreeNode* TreeNode::getRight() {
	return right;
}

void TreeNode::setRight(TreeNode* right) {
	this->right = right;
}
