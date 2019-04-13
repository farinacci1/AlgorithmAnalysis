//MaxSubArray.cpp: used to find the 'k' largest elements of a vector
#include "pch.h"
#include<iostream>
#include<vector>

std::vector<int> KthLargestUnsorted(std::vector<int> vect, int k) {//use if unsorted array
	int outerIter, innerIter, max , maxIndex, vectorSize;
	if (k > vect.size()) return {};// invalid input
	std::vector<int> kthLargest;
	max = vect[0];
	maxIndex = 0;
	vectorSize = vect.size();
	for (outerIter = 0; outerIter < vectorSize; ++outerIter) {
		if (k == 0) break;
		for (innerIter = 0; innerIter < vectorSize; ++innerIter)
		{
			if (vect[innerIter] > max) {
				max = vect[innerIter];
				maxIndex = innerIter;
			}
		}
		kthLargest.push_back(max);
		vect.erase(vect.begin() + maxIndex);
		vectorSize--;
		k--;
		max = vect[0];
	}
	return kthLargest;
}
std::vector<int> KthLargestSorted(std::vector<int> vect, int k) {
	int iter;
	if (k > vect.size()) return {};// invalid input
	std::vector<int> kthLargest;
	for (iter = 0; iter < k; iter++) {
		kthLargest.push_back(vect[vect.size() - 1 - iter]);
	}
	return kthLargest;
	
}
void printVec(std::vector<int> vector)
{
	std::cout << "kth largest implmented with vector: ";
	int iter;
	for (iter = 0; iter < vector.size(); ++iter)
	{
		std::cout << vector[iter];
	}
	std::cout << "\n";
}
void kthLargestTest(void) {

	std::vector<int> vectUnsorted{ 2,8,7,5,3,1,4 };
	std::vector<int> vectSorted{ 1,2,3,4,5,7,8 };
	printVec(KthLargestUnsorted(vectUnsorted, 3));
	printVec(KthLargestSorted(vectSorted, 3));
}
int main() {
	kthLargestTest();
	return 0;
}