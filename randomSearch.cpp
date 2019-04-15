//randomSearch.cpp: search to see if key is present in vector by random access
#include "pch.h"
#include<iostream>
#include <stdlib.h>   
#include <time.h>    
#include <algorithm>
#include<vector>
template<typename type>
bool randomSearch(std::vector<type> vect, type const& key) {
	srand(time(NULL));
	int index;
	std::vector<int> posChecked;
	int size = std::distance(vect.begin(), vect.end());
	bool allPosChechecked = false;
	while (!allPosChechecked) {
		index = rand() % size;
		if (key == vect[index]) return true;
		if (!(std::find(posChecked.begin(), posChecked.end(), index) != posChecked.end())) {
			posChecked.push_back(index);
		}
		if (posChecked.size() == std::distance(vect.begin(), vect.end())) allPosChechecked = true;
	}
	return false;
}
void randomSearhTest(void) 
{
	std::vector<int> vect = { 1,3,10,2,5,6,11,8 };
	int key = 4;
	std::cout << "value " << key << " found: " << (randomSearch<int>(vect, key) ? "True": "False");
}
int main() 
{
	randomSearhTest();
	return 0;
}