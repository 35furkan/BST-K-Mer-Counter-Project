/**
* Title: Binary Search Trees
* Author: Emre Furkan Akyol
* ID: 22103352
* Section: 1
* Homework: 2
* Description: BST.cpp Binary Search Tree with required methods
*/
#include <string>
#include <iostream>
#include <fstream>
#include "BST.h"
#include "BSTNode.h"
using namespace std;
BST::BST() {
	this->root = nullptr;
}
BST::BST(BSTNode* root) {
	this->root = root;
}

void BST::searchTreeInsert(string key) {
	BSTNode* curNode = root;
	BSTNode* newItem = new BSTNode(key);
	bool inserted = false;
	while (!inserted) {
		if (root == nullptr) {
			curNode = newItem;
			root = newItem;
			inserted = true;
		}
		else if (curNode->getItem() > key) {
			if (curNode->getLeftChild() == nullptr) {
				curNode->setLeftChild(newItem);
				inserted = true;
			}
			curNode = curNode->getLeftChild();
		}
		else if (curNode->getItem() < key) {
			if (curNode->getRightChild() == nullptr) {
				curNode->setRightChild(newItem);
				inserted = true;
			}
			curNode = curNode->getRightChild();
		}
		else if (curNode->getItem() == key) {

				inserted = true;
				int countNew = curNode->getCount(); 
				countNew++;
				curNode->setCount(countNew);
			
		}
	}

}
void BST::processLeftmost(BSTNode*& nodePtr, BSTNode*& prevPtr,string &item) {

	if (nodePtr ->getLeftChild() == nullptr) {
		item = nodePtr->getItem();
		BSTNode* delPtr = nodePtr;
		nodePtr = nodePtr->getRightChild();
		delPtr->setRightChild(nullptr);
		prevPtr->setRightChild(nullptr);
		//delPtr->setItem(nullptr);
		delete delPtr;
	}
	else
	{
		prevPtr = nodePtr;
		BSTNode* countPtr = nodePtr->getLeftChild();
		processLeftmost(countPtr,prevPtr, item);
	}
		
}

void BST::searchTreeDelete(string key) {
	BSTNode* leftParentNode = nullptr;
	BSTNode* rightParentNode = nullptr;
	BSTNode* deletedNode = nullptr;
	BSTNode* curNode = root;
	string newKey = "";
	bool found = false;
	while (!found&&curNode!=nullptr) {
		if (curNode->getItem() == key) {
			deletedNode = curNode;
			found = true;
		}
		else if (curNode->getItem() > key) {
			leftParentNode = curNode;
			curNode = curNode->getLeftChild();
		}
		else if (curNode->getItem() < key) {
			rightParentNode = curNode;
			curNode = curNode->getRightChild();
		}
	}
	if (deletedNode != nullptr) {
		if (deletedNode->getLeftChild() == nullptr && deletedNode->getRightChild() == nullptr) {
			if (leftParentNode!= nullptr ) {
				if (leftParentNode->getLeftChild() == deletedNode) {
					leftParentNode->setLeftChild(nullptr);
				}
				
			}
			if (rightParentNode != nullptr ) {
				if (rightParentNode->getRightChild() == deletedNode) {
					rightParentNode->setRightChild(nullptr);
				}
				
			}
			delete deletedNode;
		}
		else if (deletedNode->getLeftChild() == nullptr) {
			BSTNode* deletingNode = deletedNode;
			if (leftParentNode != nullptr) {
				if (leftParentNode->getLeftChild() == deletingNode) {
					leftParentNode->setLeftChild(deletingNode->getLeftChild());
				}
			}
			if (rightParentNode != nullptr) {
				if (rightParentNode->getRightChild() == deletingNode) {
					rightParentNode->setRightChild(deletingNode->getRightChild());
				}
			}

			deletingNode = deletingNode->getRightChild();
			deletedNode->setRightChild(nullptr);
			delete deletedNode;

		}
		else if (deletedNode->getRightChild() == nullptr) {
			BSTNode* deletingNode = deletedNode;
			if (leftParentNode != nullptr) {
				if (leftParentNode->getLeftChild() == deletingNode) {
					leftParentNode->setLeftChild(deletingNode->getLeftChild());
				}
			}
			if (rightParentNode != nullptr) {
				if (rightParentNode->getRightChild() == deletingNode) {
					rightParentNode->setRightChild(deletingNode->getRightChild());
				}
			}
			deletingNode = deletingNode->getLeftChild();
			deletedNode->setLeftChild(nullptr);
			delete deletedNode;

		}
		else {
			BSTNode* prevPtr = deletedNode;
			BSTNode* countPtr = deletedNode->getRightChild();
			processLeftmost(countPtr,prevPtr, newKey);
			deletedNode->setItem(newKey);
		}
	}
}
vector<string> BST::inorderTraversal(BSTNode* root) {
	
	if (root != nullptr) {
		if (root->getLeftChild() != nullptr) {
			inorderTraversal(root->getLeftChild());
		}
		orderedStrings.push_back(root->getItem());
		if (root->getRightChild() != nullptr) {
			inorderTraversal(root->getRightChild());
		}
	}

	return orderedStrings;
}
void BST::inorderTraversalPrint(BSTNode* root) {

	if (root != nullptr) {
		if (root->getLeftChild() != nullptr) {
			inorderTraversalPrint(root->getLeftChild());
		}
		cout << "\t"<<root->getItem() << ", " << "frequency" << " = " << root->getCount() << endl;
		if (root->getRightChild() != nullptr) {
			inorderTraversalPrint(root->getRightChild());
		}
	}

	
}
vector<string> BST::inorderTraversalCharBased(BSTNode* root, char x) {

	if (root != nullptr) {
		if (root->getLeftChild() != nullptr) {
			inorderTraversalCharBased(root->getLeftChild(),x);
		}
		char first = root->getItem()[0];
		if (first == x) {
			orderedStrings2.push_back(root->getItem());
		}
		
		if (root->getRightChild() != nullptr) {
			inorderTraversalCharBased(root->getRightChild(),x);
		}
	}

	return orderedStrings2;
}
	void BST::addKmer(string kmer)
	{
		for (char& x : kmer) {
			x = tolower(x);
		}
		searchTreeInsert(kmer);
	}
	void BST::generateTree(string fileName, int k) {
		
		ifstream file(fileName);

		if (!file.is_open()) {
			cout << "Error opening file: " << fileName << std::endl;
			return ;
		}

		string text;
		file >> text;

		file.close();
		if (text.length() < k) {
			cout << "Text length is less than k." << std::endl;
			return ;
		}
		
		for (int i = 0; i < text.length()-k-1; i = i+k) {
			string kmer = text.substr(i, k);
			addKmer(kmer);
		}
		
	}

	BSTNode* BST::getRoot()
	{
		return root;
	}

	int BST::getUniqueKmerCount()
	{
		int size = 0;
		orderedStrings.clear();
		vector<string> sorted = inorderTraversal(root);
		for (string x : sorted)
		{
			size++;
		}
		return size;
	}
	int BST::getNumberOfKmerThatStartWith(char ch) {
		int size = 0;
		orderedStrings2.clear();
		vector<string> sorted = inorderTraversalCharBased(root, ch);
		for (string x : sorted)
		{
			size++;
		}
		return size;
	}
	void BST::printAll() {
		inorderTraversalPrint(root);
	}
	int BST::getHeight(BSTNode* root){
		if (root == nullptr) {
			return 0;
		}
		else {
			int leftHeight = getHeight(root->getLeftChild());
			int rightHeight = getHeight(root->getRightChild());

			return 1 + max(leftHeight, rightHeight);
		}
	}
	int BST::getHeight() {
		return getHeight(root);
	}