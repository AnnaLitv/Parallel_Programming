package com.company;

import java.util.Scanner;

/**
 * Created by Anna-PC on 12.09.2017.
 */
public class Thread2 extends Thread {
    String name;
    int p;
    int[][] MA, MB, MZ, MK, mad, mad2, trans;
    int N;

    Thread2(String name, int p){
        this.name=name;
        this.p=p;
    }

    Scanner in = new Scanner(System.in);

    public void run(){
        currentThread().setName(name);
        currentThread().setPriority(p);
        try {
            Thread.sleep(2000);
        }catch (InterruptedException pp){

        }
        Funct fun = new Funct();
        System.out.println("Task 2 started!");
        inputN();
        MA = new int[N][N];
        MB = new  int[N][N];
        MZ = new int[N][N];
        mad = new int[N][N];
        mad2 = new int[N][N];
        trans = new int[N][N];
        MK = new int[N][N];
        fun.Input_Matrix(MA,N);
        fun.Input_Matrix(MB,N);
        fun.Input_Matrix(MZ,N);
        MK=fun.Sum_Matrixes(fun.Mult_Matrixes(MA,fun.Mult_Matrixes(MA,MZ,N),N),fun.Trans_Matrix(MB,N),N);
        if(N<=10) {
            System.out.println("Matrix MA: ");
            fun.Output_Matrix(MA, N);
            System.out.println("Matrix MB: ");
            fun.Output_Matrix(MB, N);
            System.out.println("Matrix MZ: ");
            fun.Output_Matrix(MZ, N);
            System.out.println("MK: ");
            fun.Output_Matrix(MK, N);
        }
        System.out.println("Task 2 finished!");
    }


    private void inputN(){
        //System.out.println("Enter N: ");
        this.N=10;
        //this.N=in.nextInt();
    }

}
