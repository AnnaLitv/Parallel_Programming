#include<omp.h>
#include "stdafx.h"
#include<Windows.h>
#include<stdio.h>
#include<time.h>


/*
Parallel and distributed computing
Krut Vladyslad
IO-43
27.09.2016
1.18 F1: d = (A * B) + (C * (B * (MA * MD)))
2.18 F2: h = MIN(MG * ML)
3.18 F3: s = MAX(SORT(MS) + (MC * MB))
*/
using namespace std;

const int dimension = 3;
const int maxRandom = 20;

void printVector(int *A) {
	printf("\n");
	for (int i = 0; i < dimension; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}
void printMatrix(int **MA) {
	printf("\n");
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			printf("%d ", MA[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int multipleVectors(int *A, int *B) {
	int result = 0;
	for (int i = 0; i < dimension; i++)
	{
		result = result + A[i] * B[i];
	}
	return result;
}

int *multipleVectorMatrix(int *A, int **MA) {
	int* result = new int[dimension];
	for (int i = 0; i < dimension; i++)
	{
		result[i] = 0;
		for (int j = 0; j < dimension; j++)
		{
			result[i] = result[i] + MA[i][j] * A[j];
		}
	}
	return result;
}

int **multipleMatrix(int **MA, int **MB) {
	int **result = new int*[dimension];
	for (int i = 0; i < dimension; i++)
	{
		result[i] = new int[dimension];
	}

	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < dimension; k++)
			{
				result[i][j] = result[i][j] + MA[i][k] * MB[k][j];
			}
		}
	}
	return result;
}

int minElement(int **MA) {
	int result = MA[0][0];
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			if (result > MA[i][j]) {
				result = MA[i][j];
			}
		}
	}
	return result;
}

int maxElement(int **MA) {
	int result = MA[0][0];
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			if (result < MA[i][j]) {
				result = MA[i][j];
			}
		}
	}
	return result;
}

int **sortMatrix(int **MA) {
	int buffer = 0;
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			for (int k = 0; k < j - 1; k++) {
				if (MA[i][k] < MA[i][k + 1]) {
					buffer = MA[i][k];
					MA[i][k] = MA[i][k + 1];
					MA[i][k + 1] = buffer;
				}
			}
		}
	}
	return MA;
}

int **addMatrix(int **MA, int **MB) {
	int **result = new int*[dimension];
	for (int i = 0; i < dimension; i++)
	{
		result[i] = new int[dimension];
	}

	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			result[i][j] = MA[i][j] + MB[i][j];
		}
	}
	return result;
}

int **randomMatrix() {
	int **result = new int*[dimension];
	for (int i = 0; i < dimension; i++)
	{
		result[i] = new int[dimension];
	}
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			srand((unsigned)time(NULL) / rand());
			result[i][j] = rand() % maxRandom;
		}
	}
	return result;
}

int *randomVector() {
	int *result = new int[dimension];
	for (int i = 0; i < dimension; i++)
	{
		srand((unsigned)time(NULL) / rand());
		result[i] = rand() % maxRandom;
	}
	return result;
}

void function1() {
	printf("Thread1 started \n");
	int* A = randomVector();
	int* B = randomVector();
	int* C = randomVector();
	int** MA = randomMatrix();
	int** MD = randomMatrix();

	int d = multipleVectors(A, B) + multipleVectors(C, multipleVectorMatrix(B, multipleMatrix(MA, MD)));
	printf("Thread1 finished: d = %d \n", d);
}

void function2() {
	printf("Thread2 started \n");
	int** MG = randomMatrix();
	int** ML = randomMatrix();
	int h = minElement(multipleMatrix(MG, ML));
	printf("Thread2 finished: h = %d \n", h);
}

void function3() {
	printf("Thread3 started \n");
	int** MS = randomMatrix();
	int** MC = randomMatrix();
	int** MB = randomMatrix();

	int s = maxElement(addMatrix(sortMatrix(MS), multipleMatrix(MC, MB)));
	printf("Thread3 finished: s = %d \n", s);
}

int main() {
	printf("Lab5 started \n");


	for (int i = 5; i > 0; i--)
	{
		printf("Boom after %d...\n", i);
		Sleep(1000);
	}
	omp_set_num_threads(3);
#pragma omp parallel
	{
#pragma omp sections
		{
#pragma omp section
			{
				function1();
			}
#pragma omp section
			{
				function2();

			}
#pragma omp section
			{
				function3();

			}
		}
	}

	printf("Lab5 finished \n");

	getchar();
	return 0;
}



