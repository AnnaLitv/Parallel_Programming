package com.company;
import java.util.Scanner;
/**
 * Created by Anna-PC on 12.09.2017.
 */
public class Thread1 extends Thread {

    String name;
    int p;
    int[][] MA, MD;
    int[] A,B,C;
    int N;
    Thread1(String name, int p){
        this.name=name;
        this.p=p;
    }
    Scanner in = new Scanner(System.in);
    public void run(){
        currentThread().setName(name);
        currentThread().setPriority(p);
        try {
            Thread.sleep(1000);
        }catch (InterruptedException pp){

        }
        Funct fun = new Funct();
        System.out.println("Task 1 started!");
        inputN();
        MA = new int[N][N];
        MD = new  int[N][N];
        A = new int[N];
        B = new int[N];
        C = new int[N];
        fun.Input_Matrix(MA,N);
        fun.Input_Matrix(MD, N);
        fun.Input_Vector(B,N);
        fun.Input_Vector(C,N);
        A=fun.Mult_Vector_Matrix(fun.Mult_Scalar_Vector(B,fun.Min_Vector(C,N),N),fun.Sum_Matrixes(fun.Mult_Matrixes(MA,MD,N),MD,N),N);
        if(N<=10){
            System.out.println("Matrix MA: ");
            fun.Output_Matrix(MA, N);
            System.out.println("Matrix MD: ");
            fun.Output_Matrix(MD,N);
            System.out.println("Vector B: ");
            fun.Output_Vector(B, N);
            System.out.println("Vector C: ");
            fun.Output_Vector(C, N);
            System.out.println("A: ");
            fun.Output_Vector(A,N);
        }
        System.out.println("Task 1 finished!");
    }


    private void inputN(){
        //System.out.println("Enter N: ");
        this.N=10;
        //this.N=in.nextInt();
    }

}
