#include "pch.h"
#include <iostream>
#include <vector>

std::vector<int> countingSort(std::vector<int> vect,int k)
{// vect is list of values, k is largest element in list
	int i;
	std::vector<int> occurences, sortedList;
	std::cout << "occurences init: ";
	for (i = 0; i <= k; i++) 
	{
		occurences.push_back(0);
		std::cout << occurences[i] << " ";
	}
	for (i = 0; i < vect.size(); i++)//occurence of each number in vect
	{
		occurences[vect[i]]++;
	}
	for (i = 1; i <= k; i++) //number of elements less than or equal to i
	{
		occurences[i] += occurences[i -1];
	}
	std::cout << std::endl << "occurences counted: ";
	for (i = 0; i <= k; i++) //number of elements less than or equal to i
	{
		std::cout << occurences[i] << " ";
	}
	std::cout << std::endl << "sorted list init: ";
	//new empty vector to store sorted vect
	for (i = 0; i < vect.size(); i++)
	{
		sortedList.push_back(0);
		std::cout << sortedList[i] << " ";
	}
	std::cout << std::endl;
	
	for(i = vect.size() -1 ; i >= 0; i--)
	{
		sortedList[occurences[vect[i]] - 1] = vect[i];
		occurences[vect[i]] -=  1;
		
	}
	std::cout << std::endl;
	return sortedList; 
}
void print(std::vector<int> vect)
{
	int i; 
	for(i = 0; i <vect.size(); i++)
	{
		std::cout << vect.at(i) << " ";
	}
	std::cout << std::endl;
}
void countingSortTest()
{
	std::vector<int> vect = { 8,5,4,2,0,9,10,10,1,1,3,5,5 };
	print(vect);
	int k = 10;
	print(countingSort(vect, k));
}
int main() {
	countingSortTest();
	return 0;
}