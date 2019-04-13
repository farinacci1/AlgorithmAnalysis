// InsertionSort.cpp : implemnting insertion sort using both array and vector options
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <cstdarg>
template <typename type> 
std::vector<type> insertionSortVector(std::vector<type> vector) {// sort vector of keys
	typename std::vector<type>::iterator j;	
	for (j = vector.begin() + 1; j < vector.end(); j++)
	{
		type key = vector[std::distance(vector.begin(), j)];
		int i = std::distance(vector.begin(), j) - 1;
		while (i >= 0 && vector[i] > key)
		{
			vector[i + 1] = vector[i];
			i -= 1;
		}
		vector[i + 1] = key;
	}
	return vector;
}
template <typename type> 
type *insertionSortArray(type *array, size_t arraySize) {// sort array of keys
	int j;
	for (j = 1; j < arraySize; j++)
	{
		type key = array[j];
		int i = j - 1;
		while (i >= 0 && array[i] > key)
		{
			array[i + 1] = array[i];
			i -= 1;
		}
		array[i + 1] = key;
	}
	return array;
}
template <typename type>
void printVec(std::vector<type> vector)
{
	std::cout << "insertionSort implmented with vector: ";
	typename std::vector<type>::iterator index;
	for (index = vector.begin(); index < vector.end(); index++)
	{
		std::cout << vector[std::distance(vector.begin(), index)];
	}
	std::cout << "\n";
}
template <typename type>
void printArr(type *array, size_t arraySize)
{
	std::cout << "insertionSort implmented with array: ";
	int index;	
	for (index = 0; index < arraySize; index++)
	{
		std::cout << array[index];
	}
	std::cout << "\n";
}
 void insertionSortTest(void) {

	 //as stands the insertion sort methods work well for integers, however note == >= <= < > are not ideal methods for string comparison and sorting
	 // as such should build a helper function that check strings character comparing each one to sort alphabetically
	 // then send array[i],key to helper function to compute comparsion
	 std::vector<int> vect{ 2,8,7,5,3,1,4 };
	 int array[] = { 2,8,7,5,3,1,4 };	 
	 printArr<int>(insertionSortArray<int>(array, sizeof(array) / sizeof(array[0])), sizeof(array) / sizeof(array[0]));
	 printVec<int>(insertionSortVector<int>(vect));	 

}

 /**int main() {
	 insertionSortTest();
	 return 0;
 }
 **/