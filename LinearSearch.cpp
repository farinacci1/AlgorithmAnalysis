#include "pch.h"
#include <iostream>
#include <vector>
template<typename type>
bool linearSearch(std::vector<type> vect, type const& key) {
	typename std::vector<type>::iterator j;
	for (j = vect.begin(); j < vect.end(); j++) {
		if (key == vect[std::distance(vect.begin(), j)]) return true;
	}
	return false;
}
void linearSearchTest(void) {

	std::vector<int> vect{ 2,8,7,5,3,1,4 };
	int key = 5;	
	std::cout << "key " << key << " found: "<< (linearSearch<int>(vect, key) ? "True" : "False"); 
}


int main() {
	linearSearchTest();
	return 0;
}