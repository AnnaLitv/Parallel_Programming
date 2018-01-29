#include "stdafx.h"
#include<Windows.h>
#include<stdio.h>
#include<time.h>
 #ifdef _OPENMP
 # include <omp.h>
 #endif
 #include <set>

/*
Litvinenko Anna
IP-53
*/
using namespace std;

const int dimension = 3;
const int maxRandom = 20;
const int N = 10;
omp_lock_t lock;

//сума векторов
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
void F1() {
	int* A;
	int* B;
	int* C;
	int** MA;
	int** MD;
	int n = N;
	int* vectRes;
	omp_set_lock(&lock);
	printf("TF1 started\n");
	omp_unset_lock(&lock);
	A = readVect(n);
	B = readVect(n);
	C = readVect(n);
	MA = readMatr(n);
	MD = readMatr(n);


	vectRes = Mult_Vect_Matr(Mult_Numb_Vect(Min_Vect(C), B), Sum_Matr(Mult_Matr(MA, MD), MD));
	omp_set_lock(&lock);
	if (n <= 10) {

		showVect(A, "(F1) Vector A");
		showVect(B, "(F1) Vector B");
		showVect(C, "(F1) Vector C");
		showMatr(MA, "(F1) Matrix MA");
		showMatr(MD, "(F1) Matrix MD");
		showVect(vectRes, "Result of F1");
	}
	printf("TF1 finished\n");
	omp_unset_lock(&lock);
}


/**
* F2: MK=MA*(MA*MZ)+TRANS(MB)
*/

void F2() {
	int** MA;
	int** MB;
	int** MZ;
	int n = N;
	int** matrRes;
	omp_set_lock(&lock);
	printf("TF2 started\n");
	omp_unset_lock(&lock);
	MA = readMatr(n);
	MB = readMatr(n);
	MZ = readMatr(n);


	matrRes = Sum_Matr(Mult_Matr(Mult_Matr(MA, MZ), MA), Trans(MB));
	omp_set_lock(&lock);
	if (n <= 10) {
		showMatr(MA, "(F2) Matrix MA");
		showMatr(MB, "(F2) Matrix MB");
		showMatr(MZ, "(F2) Matrix MZ");
		showMatr(matrRes, "Result of F2");
	}
	printf("TF2 finished\n");
	omp_unset_lock(&lock);
}


/**
* F3: O=SORT(R+S)*(MT*MP)
*/
void F3() {
	int* R;
	int* S;
	int** MT;
	int** MP;
	int n = N;
	int* vectRes;
	omp_set_lock(&lock);
	printf("TF3 started\n");
	omp_unset_lock(&lock);
	R = readVect(n);
	S = readVect(n);
	MT = readMatr(n);
	MP = readMatr(n);


	vectRes = Mult_Vect_Matr(Sort_Vect(Sum_Vect(R, S)), Mult_Matr(MT, MP));
	omp_set_lock(&lock);
	if (n <= 10) {
		showVect(R, "(F3) Vector R");
		showVect(S, "(F3) Vector S");
		showMatr(MT, "(F3) Matrix MT");
		showMatr(MP, "(F3) Matrix MP");
		showVect(vectRes, "Result of F3");

	}
	printf("TF3 finished\n");
	omp_unset_lock(&lock);
}

int main() {
	printf("Lab5 started \n");
	omp_init_lock(&lock);
	omp_set_num_threads(3);
#pragma omp parallel
	{
#pragma omp sections
		{
#pragma omp section 
			{
				F1();
			}
#pragma omp section
			{
				F2();

			}
#pragma omp section
			{
				F3();

			}
		}
	}

	printf("Lab5 finished \n");
	system("pause");
	return 0;
}



