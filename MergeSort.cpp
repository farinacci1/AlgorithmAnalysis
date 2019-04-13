// MergeSort.cpp : implemnting mergeSort on array
//

#include "pch.h"
#include <iostream>
#include <vector>
#include<stdlib.h> 
#include<stdio.h>
/*
* merge algorthim is used to merge the two SORTED halfs of an array into 1 fully sorted array 
* EX: 1,3,4,7,2,5,6,8
* first half = 1,3,4,7 second half = 2,5,6,8
* merged together becomes 1,2,3,4,5,6,7,8
*/
void merge(int *arr, int start, int mid, int end) {
	int i, j, k;
	int *temp = new int[ end - start + 1];
	i = start;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= end)
	{
		if (arr[i] < arr[j])
		{
			temp[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		temp[k] = arr[i];
		k++;
		i++;
	}	
	while (j <= end)
	{
		temp[k] = arr[j];
		k++;
		j++;
	}	
	for (i = start; i <= end; i++)
	{
		arr[i] = temp[i - start];
	}
	
	

}
void mergeSort(int *arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}
void printArray(int *array, int arraySize)
{
	std::cout << "mergeSort implmented with array: ";
	int index;
	for (index = 0; index < arraySize; index++)
	{
		std::cout << array[index];
	}
	std::cout << "\n";
}
void mergeSortTest(void) {
	int array[] = { 2,8,7,5,3,1,4 };
	int size = sizeof(array) / sizeof(array[0]);
	mergeSort(array, 0, size - 1);
	printArray(array, size);
}
int main() {
	mergeSortTest();
	return 0;
}