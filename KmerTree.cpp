/**
* Title: Binary Search Trees
* Author: Emre Furkan Akyol
* ID: 22103352
* Section: 1
* Homework: 2
* Description: KmerTree.cpp For Kmer Methods
*/
#include <string>
#include <iostream>
#include <fstream>
#include "BST.h"
#include "BSTNode.h"
#include "KmerTree.h"
using namespace std;
KmerTree::KmerTree()
{
	bst = new BST();
}

void KmerTree::searchTreeDelete(string key)
{
	this->bst->searchTreeDelete(key);
}

void KmerTree::inorderTraverse(vector<string>& sortingVec)
{
	//sortingVec is empty vec
	this->bst->orderedStrings.clear();
	sortingVec= this->bst->inorderTraversal(this->bst->getRoot());
}

void KmerTree::addKmer(string kmer)
{
	this->bst->addKmer(kmer);
}

void KmerTree::generateTree(string fileName, int k)
{
	this->bst->generateTree(fileName, k);
}

int KmerTree::getUniqueKmerCount()
{
	return this->bst->getUniqueKmerCount();
}

int KmerTree::getNumberOfKmerThatStartWith(char ch)
{
	return this->bst->getNumberOfKmerThatStartWith(ch);
}


void KmerTree::printAll()
{
	this->bst->printAll();
}

int KmerTree::getHeight()
{
	return this->bst->getHeight();
}
