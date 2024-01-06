#ifndef BST_
#define BST_
#include <vector>
#include <string>
#include <iostream>
#include "BSTNode.h"
using namespace std;
class BST {
private:
	BSTNode* root;
public:
	vector<string> orderedStrings;
	vector<string> orderedStrings2;
	BST();
	BST(BSTNode* root);
void searchTreeInsert(string key);
void searchTreeDelete(string key);
vector<string> inorderTraversal(BSTNode* root);
vector<string> inorderTraversalCharBased(BSTNode* root, char x);
void processLeftmost(BSTNode*& nodePtr, BSTNode*& prevPtr,string &item);
void addKmer(string kmer);
BSTNode* getRoot();
void generateTree(string fileName, int k);
int getUniqueKmerCount();
int getNumberOfKmerThatStartWith(char ch);
void inorderTraversalPrint(BSTNode* root);
int getHeight(BSTNode* root);
void printAll();
int getHeight();
};
#endif