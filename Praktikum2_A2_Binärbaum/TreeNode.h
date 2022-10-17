/*************************************************
 * ADS Praktikum 2.2
 * TreeNode.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include <string>

using namespace std;

class TreeNode
{
private:
    int nodeOrderID;
    int nodeChronologicalID;
    string name;
    int age;
    double income;
    int postCode;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(int, int, string, int, double, int);
    void print();
    int getNodeOrderID();
    void setNodeOrderID(int);
    int getNodeChronologicalID();
    void setNodeChronologicalID(int);
    string getName();
    void setName(string);
    int getAge();
    void setAge(int);
    double getIncome();
    void setIncome(double);
    int getPostCode();
    void setPostCode(int);
    TreeNode* getLeft();
    void setLeft(TreeNode*);
    TreeNode* getRight();
    void setRight(TreeNode*);

    // stream << operator?
};
