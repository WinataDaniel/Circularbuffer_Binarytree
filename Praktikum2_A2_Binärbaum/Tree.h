/*************************************************
 * ADS Praktikum 2.2
 * Tree.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include "TreeNode.h"
#include "catch.h"
#include <string>
#include <queue>

class Tree
{
private:
    TreeNode* anker;
    int currentNodeChronologicalID;

    // Weitere Attribute
    std::queue<TreeNode*> gefundenStellen;

    // Hilfsmethoden
    void deleteTeilBaum(TreeNode*);
    bool searchRekursiv(TreeNode*, string, bool&, bool&, bool&);
    void printPreOrder(TreeNode*);

public:
    Tree();
    ~Tree();
    void addNode(string, int, double, int);
    bool deleteNode(int);
    bool searchNode(string);
    void printAll();
    void levelOrder();

    // Hilfsmethoden
    void printGefundenStellen();

    ////////////////////////////////////
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode* get_anker(Tree& TN);
};
