#include "pch.h"
#include<iostream>
template <size_t colA, size_t colB>
int **matMul(int A[][colA], int B[][colB], int rowsA,int rowsB ){
	// matrix multiplication requires that number of columns in A are equal to number or rows in b
	size_t i, j, k;
	int **c;	
	c = new int*[rowsA];
	for (i = 0; i < rowsA; i++)
		c[i] = new int[colB];

	if (colA != rowsB) { std::cout << "columns of matrix A not same dimensions as rows of matrix B  "; return c; }

	for( i = 0; i < rowsA; i++)
	{
		for (j = 0; j < colB; j++) 
		{
			c[i][j] = 0;
			for (k = 0; k < colA; k++) 
			{
				c[i][j] += A[i][k] * B[k][j];
			}
			
		}
		
	}
	return c;
}

void print(int** matrix,int rows, int cols ) {
	size_t i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void matTest(void) {
	int A[4][4] = { {1,8,12,20}, {5,9,13,24}, {3,2,5,3}, {6,7,5,21} };
	int B[4][4] = { {1,8,16,2}, {3,9,5,32},{3,1,5,6},{4,5,6,2} };
	int ** matrix = matMul(A, B,4,4);	
	print(matrix, 4, 4);
}


int main() 
{
	matTest();
	return 0;
}