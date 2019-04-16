#include "pch.h"
#include<iostream>
#include <algorithm>
void swap(int *x, int *y) 
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
class MaxHeap {
	int *heaparray;
	int heapCapacity;
	int heapSZ;
	public:
		int getParentIndex(int currIndex) {
			int parent = currIndex / 2;
			return parent;
		}
		int getLeftChildIndex(int currIndex) {
			int lChild = 2* currIndex;
			return lChild;
		}
		int getRightChildIndex(int currIndex) {
			int rChild = 2* currIndex + 1;
			return rChild;
		}
		MaxHeap(int capacity);
		void maxHeapify(int index);
		void insertKey(int key);
		void changeKey(int index, int newKey);
		int extractMax();
		void heapPrintByLevel();
};
MaxHeap::MaxHeap(int cap)
{
	int heapSZ = 0;
	heapCapacity = cap;
	heaparray = new int[cap];
}
void MaxHeap::maxHeapify(int index) 
{
	int lchildIndex = getLeftChildIndex(index);
	int rchildIndex = getRightChildIndex(index);
	int largest;
	if (lchildIndex <= heapSZ && heaparray[lchildIndex] > heaparray[index])
		largest = lchildIndex;
	else largest = index;
	if (rchildIndex <= heapSZ && heaparray[rchildIndex] > heaparray[index])
		largest = rchildIndex;
	if (largest != index) {
		swap(&heaparray[index], &heaparray[largest]);
		maxHeapify(largest);
	}
}
void MaxHeap::insertKey(int key) 
{
	if (heapSZ == heapCapacity)
	{
		//double size of heap allocate more memory
		int *temp = new int[heapCapacity * 2];
		std::copy(heaparray, heaparray + heapSZ, temp);
		heaparray = temp;
		heapCapacity *= 2;
	}
	heapSZ++;
	int i = heapSZ;
	heaparray[i] = key;

	while (i != 0 && heaparray[getParentIndex(i)] < heaparray[i])
	{
		swap(&heaparray[i], &heaparray[getParentIndex(i)]);
		i = getParentIndex(i);
	}
}
void MaxHeap::changeKey(int index, int newKey)
{
	// if key is larger
	int i = index;
	int currentValue = heaparray[index];
	heaparray[index] = newKey;

	if (newKey > currentValue) {
		while (i != 0 && heaparray[getParentIndex(i)] < heaparray[i])
		{
			swap(&heaparray[i], &heaparray[getParentIndex(i)]);
			i = getParentIndex(i);
		}
	}

	else if (newKey < currentValue) {		
		maxHeapify(index);
	}
}
int MaxHeap::extractMax() {
	if (heapSZ <= 0)
		return INT_MAX;
	else if (heapSZ == 1)
	{
		heapSZ--;
		return heaparray[0];
	}
	else {
		int max = heaparray[0];
		swap(&heaparray[0], &heaparray[heapSZ]);
		heapSZ--;
		maxHeapify(0);
		return max;
	}
}
void MaxHeap::heapPrintByLevel() {
	int index, locale = 0, level = 1;
	for (index = 0; index < heapSZ; index++)
	{
		std::cout << heaparray[index] << " ";
		locale++;
		if (locale == level)
		{
			level *= 2;
			locale = 0;
			std::cout << std::endl;
		}

	}
	std::cout << std::endl;
}
void maxHeapTest(void) {
	MaxHeap heap(10);
	heap.insertKey(3);
	heap.insertKey(2);
	heap.insertKey(7);
	heap.insertKey(4);
	heap.insertKey(5);
	heap.insertKey(9);
	heap.insertKey(8);
	heap.insertKey(6);
	heap.heapPrintByLevel();
	std::cout << "remove max: " << heap.extractMax() << std::endl;
	heap.heapPrintByLevel();
	heap.changeKey(4, 21);
	heap.heapPrintByLevel();
	heap.changeKey(2, 1);
	heap.heapPrintByLevel();
}
int main() {
	maxHeapTest();
	return 0;
}