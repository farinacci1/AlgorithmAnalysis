#include "pch.h"
#include <iostream>
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int partition(int *array, int start, int end)
{
	int x, i, j;
	x = array[end], i = start - 1;
	for (j = start; j < end; j++)
	{
		if (array[j] <= x)
		{
			i += 1;
			swap(&array[j], &array[i]);
		}
	}
	swap(&array[i + 1], &array[end]);
	return i + 1;
}
int *quicksort(int *array,int start, int end) 
{
	if (start < end) 
	{
		int q = partition(array, start, end);
		quicksort(array, start, q - 1);
		quicksort(array, q + 1, end);
	}
	return array;
}
void printArr(int *array, int arraySize)
{
	std::cout << "insertionSort implmented with array: ";
	int index;
	for (index = 0; index < arraySize; index++)
	{
		std::cout << array[index];
	}
	std::cout << "\n";
}

void quickSortTest(void)
{
	int array[] = { 2,8,7,5,3,1,4 };
	int arraySize = sizeof(array) / sizeof(array[0]) - 1;
	printArr(quicksort(array,0, arraySize), arraySize);
}
int main() {
	quickSortTest();
	return 0;
}