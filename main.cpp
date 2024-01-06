/**
* Title: Binary Search Trees
* Author: Emre Furkan Akyol
* ID: 22103352
* Section: 1
* Homework: 2
* Description: Main.cpp For Time Analysis
*/
#include<iostream>
#include<string>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

#include "KmerTree.h"


void timeAnalysis(string inputfilename, int k) {
	int arr[10] = { 20000,40000,60000,80000,100000,120000,140000,160000,180000,200000};
	double elapTimeAddKmer[10];
	double elapTimeHeight[10];
	clock_t start_time;
	clock_t end_time;
	ifstream file(inputfilename);
	KmerTree* k1 = new KmerTree();
	if (!file.is_open()) {
		cout << "Error opening file: " << inputfilename << std::endl;
		return;
	}

	string text;
	file >> text;

	file.close();
	if (text.length() < k) {
		cout << "Text length is less than k." << std::endl;
		return;
	}
	
	int start = 0;
		for (int m = 0; m < 10; m++) {
			
			string textSub = text.substr(start, arr[0]);
			 start_time = clock();
			for (int i = 0; i < arr[0]-k-1; i=i+k) {
				
				 string kmer = textSub.substr(i, k);
				 k1->addKmer(kmer);
			}

				 end_time = clock();
				 cout<< "Added kmers :" << arr[m]/k << endl;
				 cout<< "Unique Kmers:" << k1->getUniqueKmerCount() << endl;
				 double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000;
				cout << "Elapsed Time addKmer:" << elapsed_time << endl;
				elapTimeAddKmer[m] = elapsed_time;
				
				
				cout<<"Height:"<<k1->getHeight() << endl;
				
			
			start = start + arr[0];
		}
		delete k1;
}
int main() {
	timeAnalysis("output-onlinestringtools.txt", 5);
}