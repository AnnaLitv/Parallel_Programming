from multiprocessing import Process, Lock
#Anna Litvinenko
#IP-53
#1.10 A=B*MIN(C)*(MA*MD+MD)
#2.10 MK=MA*(MA*MZ)+TRANS(MB)
#3.10 O=SORT(R+S)*(MT*MP)
import threading
N = 3

#введение вектора
def readVect():
    vector = []
    for i in range(N):
        vector.append(1)
    return vector
#введение матрицы
def readMatrix():
    matrix = []
    for i in range(N):
        matrix.append([])
        for j in range(N):
            matrix[i].append(1)
    return matrix
#вывод вектора
def printVect(vector):
    print(vector)
    pass
#вывод матрицы
def printMatrix(matrix):
    for i in range(N):
        print(matrix[i])
    pass
#сумирование векторов
def sumVect(A, B):
    res = readVect()
    for i in range(N):
        res[i] = A[i] + B[i]
    return res
#сумирование матриц
def sumMatrix(MA, MB):
    res = readMatrix()
    for i in range(N):
        for j in range(N):
            res[i][j] = MA[i][j]+MB[i][j]
    return res
#перемножение векторов
def multVect(A, B):
    res = 0
    for i in range(N):
        res = res + A[i] + B[i]
    return res
#умножение вектора на матрицу
def multVectMatrix(A, MA):
    res = readVect()
    for i in range(N):
        res[i] = 0
        for j in range(N):
            res[i] = res[i] + A[i] * MA[j][i]
    return res
#перемножение матриц
def multMatrix(MA, MB):
    res = readMatrix()
    for i in range(N):
        for j in range(N):
            tmp = 0
            for k in range(N):
                tmp = tmp + MA[i][k] * MB[k][j]
            res[i][j] = tmp
    return res
#поиск минимального в векторе
def searchMin(A):
    res = A[0]
    for i in range(N):
        if res > A[i]:
            res = A[i]
    return res
#сортировка матрицы
def sortVect(A):
    tmp = 0
    for i in range(N):
        for k in range(N - 1):
            if A[k] > A[k + 1]:
                tmp = A[k]
                A[k] = A[k + 1]
                A[k + 1] = tmp
    return A
#умножение вектора на число
def multNumbVect(A, n):
    res = readVect()
    for i in range(N):
        res[i] = A[i] * n
    return res
#транспнирование матрицы
def transMatr(MA):
    res = readMatrix()
    for i in range(N):
        for j in range(N):
            res[i][j] = MA[j][i]
    return res

#1.10 A=B*MIN(C)*(MA*MD+MD)
def f1(l):
    l.acquire()
    print('Thread 1 started!')
    l.release()
    B = readVect()
    C = readVect()
    MA = readMatrix()
    MD = readMatrix()
    A = multVectMatrix(multNumbVect(B,searchMin(C)),sumMatrix(multMatrix(MA,MD),MD))
    l.acquire()
    if N<=10:
        print('(F1) Vector B')
        printVect(B)
        print('(F1) Vector C')
        printVect(C)
        print('(F1) Matrix MA')
        printMatrix(MA)
        print('(F1) Matrix MD')
        printMatrix(MD)
        print('(F1) Result Vector A')
        printVect(A)
    print('Thread 1 finished!')
    l.release()
    pass
#2.10 MK=MA*(MA*MZ)+TRANS(MB)
def f2(l):
    l.acquire()
    print('Thread 2 started!')
    l.release()
    MA = readMatrix()
    MZ = readMatrix()
    MB = readMatrix()
    MK = sumMatrix(multMatrix(multMatrix(MA,MZ),MA),transMatr(MB));
    l.acquire()
    if N<=10:
        print('(F2) Matrix MA')
        printMatrix(MA)
        print('(F2) Matrix MB')
        printMatrix(MB)
        print('(F2) Matrix MZ')
        printMatrix(MZ)
        print('(F2) Result Matrix MK')
        printMatrix(MK)
    print('Thread 2 finished!')
    l.release()
    pass
#3.10 O=SORT(R+S)*(MT*MP)
def f3(l):
    l.acquire()
    print('Thread 3 started!')
    l.release()
    R = readVect()
    S = readVect()
    MT = readMatrix()
    MP = readMatrix()
    O = multVectMatrix(sortVect(sumVect(R, S)),multMatrix(MT,MP))
    l.acquire
    if N <= 10:
        print('(F3) Vector R')
        printVect(R)
        print('(F3) Vector S')
        printVect(S)
        print('(F3) Matrix MT')
        printMatrix(MT)
        print('(F3) Matrix MP')
        printMatrix(MP)
        print('(F3) Result Vector O')
        printVect(O)
    print('Thread 3 finished!')
    l.release
    pass

if __name__ == "__main__":
    print('Main started\n')
    lock = Lock()
    p1 = Process(target=f1,args=(lock,))
    p2 = Process(target=f2,args=(lock,))
    p3 = Process(target=f3,args=(lock,))

    p1.start()
    p2.start()
    p3.start()

    p1.join()
    p2.join()
    p3.join()

    print('Main finished\n')