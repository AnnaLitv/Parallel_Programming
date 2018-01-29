// LabWin32.cpp: определяет точку входа для консольного приложения.
//Anna Litvinenko
//IP-53 5311

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
const int N = 3;
using namespace std;

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
DWORD WINAPI F1(LPVOID lpParam) {
	int* A;
	int* B;
	int* C;
	int** MA;
	int** MD;
	int n = N;
	int* vectRes;
	WaitForSingleObject((CONST HANDLE)lpParam, INFINITE);
	printf("TF1 started\n");
	ReleaseMutex((CONST HANDLE)lpParam);
	A = readVect(n);
	B = readVect(n);
	C = readVect(n);
	MA = readMatr(n);
	MD = readMatr(n);


	vectRes = Mult_Vect_Matr(Mult_Numb_Vect(Min_Vect(C), B), Sum_Matr(Mult_Matr(MA, MD), MD));
	WaitForSingleObject((CONST HANDLE)lpParam, INFINITE);
	if (n <= 10) {
		
		showVect(A, "(F1) Vector A");
		showVect(B, "(F1) Vector B");
		showVect(C, "(F1) Vector C");
		showMatr(MA, "(F1) Matrix MA");
		showMatr(MD, "(F1) Matrix MD");
		showVect(vectRes, "Result of F1");
	}
	printf("TF1 finished\n");
	ReleaseMutex((CONST HANDLE)lpParam);
	return 0;
}


/**
* F2: MK=MA*(MA*MZ)+TRANS(MB)
*/

DWORD WINAPI F2(LPVOID lpParam) {
	int** MA;
	int** MB;
	int** MZ;
	int n = N;
	int** matrRes;
	WaitForSingleObject((CONST HANDLE)lpParam, INFINITE);
	printf("TF2 started\n");
	ReleaseMutex((CONST HANDLE)lpParam);
	MA = readMatr(n);
	MB = readMatr(n);
	MZ = readMatr(n);


	matrRes = Sum_Matr(Mult_Matr(Mult_Matr(MA, MZ), MA), Trans(MB));
	WaitForSingleObject((CONST HANDLE)lpParam, INFINITE);
	if (n <= 10) {
		showMatr(MA,"(F2) Matrix MA");
		showMatr(MB,"(F2) Matrix MB");
		showMatr(MZ,"(F2) Matrix MZ");
		showMatr(matrRes, "Result of F2");
	}
	printf("TF2 finished\n");
	ReleaseMutex((CONST HANDLE)lpParam);
	return 0;
}


/**
* F3: O=SORT(R+S)*(MT*MP)
*/
DWORD WINAPI F3(LPVOID lpParam) {
	int* R;
	int* S;
	int** MT;
	int** MP;
	int n = N;
	int* vectRes;
	WaitForSingleObject((CONST HANDLE)lpParam, INFINITE);
	printf("TF3 started\n");
	ReleaseMutex((CONST HANDLE)lpParam);
	R = readVect(n);
	S = readVect(n);
	MT = readMatr(n);
	MP = readMatr(n);


	vectRes = Mult_Vect_Matr(Sort_Vect(Sum_Vect(R, S)), Mult_Matr(MT, MP));
	WaitForSingleObject((CONST HANDLE)lpParam, INFINITE);
	if (n <= 10) {
		showVect(R,"(F3) Vector R");
		showVect(S,"(F3) Vector S");
		showMatr(MT,"(F3) Matrix MT");
		showMatr(MP,"(F3) Matrix MP");
		showVect(vectRes, "Result of F3");
		
	}
	printf("TF3 finished\n");
	ReleaseMutex((CONST HANDLE)lpParam);
	return 0;
}

int main()
{
	HANDLE  hThreadArray[3];
	CONST HANDLE hMutex = CreateMutex(NULL,
	FALSE,//unlocked mutex
	NULL);//name of the mutex

	hThreadArray[0] = CreateThread(
		NULL,                   // default security attributes
		0,                      // use default stack size  
		F1,						// thread function name
		hMutex,				// argument to thread function 
		0,                      // use default creation flags 
		NULL);   // returns the thread identifier

	hThreadArray[1] = CreateThread(
		NULL,
		0,
		F2,
		hMutex,
		0,
		NULL);

	hThreadArray[2] = CreateThread(
		NULL,
		0,
		F3,
		hMutex,
		0,
		NULL);

	WaitForMultipleObjects(3, hThreadArray, TRUE, INFINITE);
	system("pause");
	return 0;
}

