#include<stdio.h>
#include<time.h>
#include<mpi.h>
#include<Windows.h>
#include <iostream>
/*
Anna Litvinenko
IP-53
2017
1.10 F1: d = (A * B) + (C * (B * (MA * MD)))
2.10 F2: h = MIN(MG * ML)
3.10 F3: s = MAX(SORT(MS) + (MC * MB))
*/
using namespace std;

const int N = 3;
const int maxRandom = 20;
/*
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
*/
// сума векторов
int* Sum_Vect(int* A, int* B) {
	for (int i = 0; i < N; i++) {
		A[i] += B[i];
	}
	return A;

}
//умножение двух матриц
int** Mult_Matr(int** MA, int** MB) {
	int temp = 0;
	int** resultMatr = new int*[N];
	for (int i = 0; i < N; i++) {
		resultMatr[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp = 0;
			for (int k = 0; k < N; k++) {
				temp += MA[i][k] * MB[k][j];
			}
			resultMatr[i][j] = temp;
		}
	}
	return resultMatr;
}
//транспонирование матрицы
int** Trans(int** MA) {
	int** resultMatr = new int*[N];
	for (int i = 0; i < N; i++) {
		resultMatr[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			resultMatr[i][j] = MA[j][i];
		}
	}
	return resultMatr;
}
//минимальный элемент вектора
int Min_Vect(int* A) {
	int min = A[0];
	for (int i = 0; i < N; i++) {
		if (min > A[i]) {
			min = A[i];
		}
	}
	return min;
}
//сума матриц
int** Sum_Matr(int** MA, int** MB) {
	int** resultMatr = new int*[N];
	for (int i = 0; i < N; i++) {
		resultMatr[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			resultMatr[i][j] = MA[i][j] + MB[i][j];
		}
	}
	return resultMatr;
}
//умножение вектора на матрицу
int* Mult_Vect_Matr(int* A, int** B) {
	int temp = 0;
	int* resultVect = new int[N];
	for (int i = 0; i < N; i++) {
		temp = 0;
		for (int j = 0; j < N; j++) {
			temp += A[j] * B[j][i];
		}
		resultVect[i] = temp;
	}
	return resultVect;
}
//сортировка вектора по возрастанию
int* Sort_Vect(int* A) {
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (i - 1); j++) {
			if (A[j] > A[j + 1]) {
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
	return A;
}
//умножение вектора на число
int* Mult_Numb_Vect(int a, int* B) {
	for (int i = 0; i < N; i++) {
		B[i] = B[i] * a;
	}
	return B;
}

//**********************************************
int** readMatr(int n) {
	int** matr = new int*[n];
	for (int i = 0; i < n; i++) {
		matr[i] = new int[n];
	}
	//printf(message);
	//printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			matr[i][j] = 1;
		}
	}
	return matr;
}
//
void showMatr(int** matr, char* message) {
	printf(message);
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", matr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
//
int* readVect(int n) {
	int* vect = new int[n];

	//printf(message);
	//printf("\n");
	for (int i = 0; i < n; i++) {
		vect[i] = 1;
	}
	return vect;
}
//
void showVect(int* vect, char* message) {
	printf(message);
	printf("\n");
	for (int i = 0; i < N; i++) {
		printf("%d ", vect[i]);
	}
	printf("\n");
}
//***********************************************
/*
* F1: A=B*MIN(C)*(MA*MD+MD)
*/
void function1() {
	int n = N;
	printf("Thread1 started \n");
	int* A = readVect(n);
	int* B = readVect(n);
	int* C = readVect(n);
	int** MA = readMatr(n);
	int** MD = readMatr(n);

	int* vectRes = Mult_Vect_Matr(Mult_Numb_Vect(Min_Vect(C), B), Sum_Matr(Mult_Matr(MA, MD), MD));
	if (n <= 10) {

		showVect(A, "(F1) Vector A");
		showVect(B, "(F1) Vector B");
		showVect(C, "(F1) Vector C");
		showMatr(MA, "(F1) Matrix MA");
		showMatr(MD, "(F1) Matrix MD");
		showVect(vectRes, "Result of F1");
	}
	printf("Thread1 finished!");
}
/**
* F2: MK=MA*(MA*MZ)+TRANS(MB)
*/
void function2() {
	int n = N;
	printf("Thread2 started \n");
	int** MA = readMatr(n);
	int** MB = readMatr(n);
	int** MZ = readMatr(n);
	int** matrRes = Sum_Matr(Mult_Matr(Mult_Matr(MA, MZ), MA), Trans(MB));

	if (n <= 10) {
		showMatr(MA, "(F2) Matrix MA");
		showMatr(MB, "(F2) Matrix MB");
		showMatr(MZ, "(F2) Matrix MZ");
		showMatr(matrRes, "Result of F2");
	}
	printf("Thread2 finished!");
}
/**
* F3: O=SORT(R+S)*(MT*MP)
*/
void function3() {
	int n = N;
	printf("Thread3 started \n");
	int* R = readVect(n);
	int* S = readVect(n);
	int** MT = readMatr(n);
	int** MP = readMatr(n);

	int* vectRes = Mult_Vect_Matr(Sort_Vect(Sum_Vect(R, S)), Mult_Matr(MT, MP));

	if (n <= 10) {
		showVect(R, "(F3) Vector R");
		showVect(S, "(F3) Vector S");
		showMatr(MT, "(F3) Matrix MT");
		showMatr(MP, "(F3) Matrix MP");
		showVect(vectRes, "Result of F3");

	}
	printf("Thread3 finished!");
}

int main(int argc, char* argv[]) {
	//cout << "Lab 6 started!";
	int rank;
	int size;
	
	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (size < 3) {
		MPI_Finalize();
		return 0;
	}


	switch (rank) {
	case 0:
		function1();
		break;
	case 1:
		function2();
		break;
	case 2:
		function3();
		break;
	default: {
		MPI_Finalize();
		return 0;
	}
	}
	MPI_Finalize();
	//cout << "Lab 6 finished!";
	return 0;
}



