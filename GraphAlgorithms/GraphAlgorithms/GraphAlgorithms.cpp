
//My own DiCKStra Algorithm implementation for finding a shortest path to every single node in graph

#include "pch.h"
#include <iostream>

const int matrixSize = 12;
using namespace std;

int ** createAdjacencyMatrix(int rows, int columns) 
{
	int **matrix = new int*[rows];

	for (int i = 0; i < rows; i++) 
	{
		matrix[i] = new int[columns];
	}


	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < columns; j++) 
		{
			matrix[i][j] = -1;
		}
	}
	int value;
	int posRow, posCol;
	cout << "\nAdd matrix elements by typing in an X and Y position + value, \ntype in -1 to stop adding and change unfilled elements with -1 \n";
	while(true) 
	{
		cout << "\nEnter a value for current element\n";
		cin >> value;
		if (value == -1)
		{
			cout << "\nInitialization of matrix was successfully completed\n";
			break;
		}
		cout << "\nEnter an row position for element\n";
		cin >> posRow;
		cout << "\nEnter an column position for element\n";
		cin >> posCol;
		if (((value > 0) && (posRow <= rows) && (posCol <= columns)))
		{
			matrix[posRow][posCol] = value;
			cout << "Element with following position have been successfuly added at" << posRow << " " << posCol << "position with value " << value;
		}
	}
	cout << "\nInitialization of matrix was successfully completed";
	return matrix;
	
}

void printMatrix(int** matrix, int rows, int columns) 
{
	for (int i = 0; i < rows; i++) 
	{
		cout << "\n";
		for (int j = 0; j < columns; j++) 
		{
			cout << matrix[i][j];
		}
	}
}

void findShortestPathToEveryEdge(int matrix[][matrixSize])
{
	bool visitedVertices[matrixSize];
	int shortestPath[matrixSize];

	for (int i = 0; i < matrixSize; i++)
	{
		visitedVertices[i] = false;
		shortestPath[i] = 0;
	}
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			visitedVertices[i] = true;
			if (matrix[j][i] != -1)
			{
				if (shortestPath[j] == 0)
				{
					shortestPath[j] = matrix[j][i];
				}
				else
				{
					if ((matrix[j][i] + shortestPath[i]) < shortestPath[j])
					{
						shortestPath[j] = matrix[j][i] + shortestPath[i];

					}
				}
			}
		}
	}


	for (int i = 0; i < matrixSize; i++) 
	{
		cout << i << " - " << shortestPath[i] << "\n";
	}
}


int main()
{

	//creaing statically 
int matrix[matrixSize][matrixSize] = {
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{2,6,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,5,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,6,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,12,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,9,5,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,3,-1,4,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,11,3,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,8,-1,9,7,-1}
	};
//	int** matrix1 = createAdjacencyMatrix(matrixSize,matrixSize);
	//printMatrix(matrix1, matrixSize, matrixSize);
	findShortestPathToEveryEdge(matrix);
}