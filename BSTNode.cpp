/**
* Title: Binary Search Trees
* Author: Emre Furkan Akyol
* ID: 22103352
* Section: 1
* Homework: 2
* Description: BSTNode.cpp For the structure of the BST
*/
#include <string>
#include <iostream>
#include "BSTNode.h"
using namespace std; 

BSTNode::BSTNode() {
	this->item = nullptr;
	this->leftChild = nullptr;
	this->rightChild = nullptr;
		
}
BSTNode::BSTNode(string item) {
	this->item = item;
	this->leftChild = nullptr;
	this->rightChild = nullptr;
	this->count = 1;
}
BSTNode::BSTNode(BSTNode* leftChild, BSTNode* rightChild, string item) {
	this->item = item;
	this->leftChild = leftChild;
	this->rightChild = rightChild;
	this->count = 1;
}
BSTNode* BSTNode::getLeftChild() {
	return leftChild;
}
void BSTNode::setLeftChild(BSTNode* leftChild) {
	this->leftChild = leftChild;
}
BSTNode* BSTNode::getRightChild() {
	return rightChild;
}
void BSTNode::setRightChild(BSTNode* rightChild) {
	this->rightChild = rightChild;
}
string BSTNode::getItem() {
	return item;
}
void BSTNode::setItem(string newItem) {
	this->item = newItem;
}
int BSTNode::getCount() {
	return count;
}
void BSTNode::setCount(int newCount) {
	this->count = newCount;
}