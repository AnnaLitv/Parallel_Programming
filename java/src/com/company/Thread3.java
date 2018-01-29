package com.company;

import java.util.Scanner;

/**
 * Created by Anna-PC on 12.09.2017.
 */
public class Thread3 extends Thread {
    String  name;
    int p;
    int[][] MT, MP, mad;
    int[] R,S,O;
    int N;

    Thread3(String name, int p){
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
        System.out.println("Task 3 started!");
        inputN();
        MT = new int[N][N];
        MP = new  int[N][N];
        mad = new int[N][N];
        R = new int[N];
        S = new int[N];
        O = new int[N];
        fun.Input_Matrix(MT,N);
        fun.Input_Matrix(MP, N);
        fun.Input_Vector(R,N);
        fun.Input_Vector(S,N);
        O=fun.Mult_Vector_Matrix(fun.Sort_Vector(fun.Sum_Vectors(R,S,N),N),fun.Mult_Matrixes(MT,MP,N),N);
        if(N<=10) {
            System.out.println("Matrix MT: ");
            fun.Output_Matrix(MT, N);
            System.out.println("Matrix MP: ");
            fun.Output_Matrix(MP, N);
            System.out.println("Vector R: ");
            fun.Output_Vector(R, N);
            System.out.println("Vector S: ");
            fun.Output_Vector(S, N);
            System.out.print("O: ");
            fun.Output_Vector(O, N);
        }
        System.out.println("Task 3 finished!");
    }



    private void inputN(){
       // System.out.println("Enter N: ");
        this.N=10;
        //this.N=in.nextInt();
    }


}
