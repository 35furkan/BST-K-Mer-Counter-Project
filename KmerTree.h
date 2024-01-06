#ifndef KmerTree_
#define KmerTree_
#include <vector>
#include <string>
#include <iostream>
#include "BST.h"
#include "BSTNode.h"
using namespace std;
class KmerTree {
private:
	BST* bst;
public:
	
	KmerTree();
	void searchTreeDelete(string key);
	void inorderTraverse(vector<string>& sortingVec);
	void addKmer(string kmer);
	void generateTree(string fileName, int k);
	int getUniqueKmerCount();
	int getNumberOfKmerThatStartWith(char ch);
	//int getHeight(BSTNode* root);
	void printAll();
	int getHeight();
};
#endif