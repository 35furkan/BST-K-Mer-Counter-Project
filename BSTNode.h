#ifndef BSTNode_
#define BSTNode_
#include <string>
#include <iostream>
using namespace std;
class BSTNode {
private:
	BSTNode* leftChild;
	BSTNode* rightChild;
	string item;
	int count;
public:
	BSTNode();
	BSTNode(string item);
	BSTNode(BSTNode* leftChild, BSTNode* rightChild,string item);
	BSTNode* getLeftChild();
	void setLeftChild(BSTNode* leftChild);
	BSTNode* getRightChild();
	void setRightChild(BSTNode* rightChild);
	string getItem();
	void setItem(string newItem);
	int getCount();
	void setCount(int newCount);
};
#endif
