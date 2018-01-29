// lab3.cpp: определяет точку входа для консольного приложения.
//
#include <Windows.h>
#include "stdafx.h"
#include <stdio.h>
#include <ctime>
using namespace std;
const int N = 3;

int main()
{
	DWORD TidA, TidB, TidC;
	HANDLE thread1, thread2, thread3;
	thread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)TF1, NULL, 0, &TidA);
	thread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)TF2, NULL, 0, &TidB);
	thread3 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)TF3, NULL, 0, &TidC);
	SetThreadPriority(thread1, THREAD_PRIORITY_HIGHEST);
	SetThreadPriority(thread2, THREAD_PRIORITY_NORMAL);
	SetThreadPriority(thread3, THREAD_PRIORITY_LOWEST);
	CloseHandle(thread1);
	CloseHandle(thread2);
	CloseHandle(thread3);
	system("pause");
	//getChar();
    return 0;
}
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
int* Sort_Vect(int* A){
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
//
int* Mult_Numb_Vect(int a, int* B) {
	for (int i = 0; i < N; i++) {
			B[i] = B[i] * a;
		}
	return B;
}


//**********************************************
int** readMatr(int n, char* message) {
	int** matr = new int*[n];
	for (int i = 0; i < n; i++) {
		matr[i] = new int[n];
	}
	printf(message);
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			matr[i][j] = 1;
		}
	}
	return matr;
}
//
void showMatr(int** matr, char* message) {
	//	printf(message);
	//	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", matr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
//
int* readVect(int n, char* message) {
	int* vect = new int[n];

	printf(message);
	printf("\n");
	for (int i = 0; i < n; i++) {
		vect[i] = 1;
	}
	return vect;
}
//
void showVect(int* vect, char* message) {
	printf(message);
	for (int i = 0; i < N; i++) {
		printf("%d ", vect[i]);
	}
	printf("\n");
}
//***********************************************
/*
* F1: A=B*MIN(C)*(MA*MD+MD)
*/
void TF1() {
	int* A;
	int* B;
	int* C;
	int** MA;
	int** MD;
	int n = N;
	int* vectRes;
	printf("TF1 started");
	A = readVect(n, "Enter vector A for F1");
	B = readVect(n, "Enter vector B for F1");
	C = readVect(n, "Enter vector C for F1");
	MA = readMatr(n, "Enter matrix MA for F1");
	MD = readMatr(n, "Enter matrix MB for F1");

	Sleep(500);

	vectRes = Mult_Vect_Matr(Mult_Numb_Vect(Min_Vect(C),B),Sum_Matr(Mult_Matr(MA,MD),MD));
	showVect(vectRes, "Result of F1");
	printf("TF1 finished\n");
}


/**
* F2: MK=MA*(MA*MZ)+TRANS(MB)
*/

void TF2() {
	int** MA;
	int** MB;
	int** MZ;
	int n = N;
	int** matrRes;
	printf("TF2 started\n");
	MA = readMatr(n, "Enter matrix MA for F2");
	MB = readMatr(n, "Enter matrix MB for F2");
	MZ = readMatr(n, "Enter matrix MZ for F2");

	Sleep(300);

	matrRes = Sum_Matr(Mult_Matr(Mult_Matr(MA,MZ),MA),Trans(MB));
	showMatr(matrRes, "Result of F2");
	printf("TF2 finished\n");
}


/**
* F3: O=SORT(R+S)*(MT*MP)
*/
void TF3() {
	int* R;
	int* S;
	int** MT;
	int** MP;
	int n = N;
	int* vectRes;
	printf("TF3 started\n");
	R = readVect(n, "Enter vector R for F3");
	S = readVect(n, "Enter vector S for F3");
	MT= readMatr(n, "Enter matrix MT for F3");
	MP = readMatr(n, "Enter matrix MP for F3");

	Sleep(100);

	vectRes = Mult_Vect_Matr(Sort_Vect(Sum_Vect(R,S)),Mult_Matr(MT,MP));
	printf("Result of F3: ");
	showVect(vectRes, "Result of F1");
	printf("TF3 finished\n");
}


