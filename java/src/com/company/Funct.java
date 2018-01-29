package com.company;

import java.util.ArrayList;
import java.util.Random;

/**
 * Created by Anna-PC on 18.09.2017.
 */
public class Funct {

    public  void Input_Vector (int[] v,int n ){
        final Random rand = new Random();
        for(int i=0;i<n;i++){
            v[i]=rand.nextInt(10)+1;
        }
    }
    public void Output_Vector(int[] v, int n){
        for(int i=0;i<n;i++){
            System.out.print(v[i]+" ");
        }
        System.out.println("");
    }
    public void Input_Matrix(int[][] m, int n){
        final Random rand = new Random();
        for(int i=0; i<n;i++){
            for(int j=0;j<n;j++){
              m[i][j]=rand.nextInt(10)+1;
            }
        }
    }
    public void Output_Matrix(int[][] m, int n){
        for(int i=0; i<n;i++){
            for(int j=0;j<n;j++){
                System.out.print(m[i][j]+" ");
            }
            System.out.println("");
        }
    }
    public int[][] Mult_Matrixes(int[][] m1, int[][] m2, int n){
        int[][] m3 = new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    m3[i][j]=m3[i][j]+m1[i][k]*m2[k][j];
                }
            }
        }
        return m3;
    }
    public int[] Mult_Vector_Matrix(int[] v, int[][] m1, int n){
        int[] v1=new int[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                v1[i]=v1[i]+m1[i][j]*v[j];
            }
        }
        return v1;
    }
    public int[] Sum_Vectors(int[] v1, int[] v2, int n){
        int[] v3=new int[n];
        for(int i=0;i<n;i++){
            v3[i]=v1[i]+v2[i];
        }
        return v3;
    }
    public int[][] Sum_Matrixes(int[][] m1,int[][] m2, int n){
        int[][] m3=new  int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m3[i][j]=m1[i][j]+m2[i][j];
            }
        }
        return m3;
    }
    public int Min_Vector(int[] v, int n){
        int min=v[0];
        for(int i=1;i<n;i++){
            if(min>v[i]){
                min=v[i];
            }
        }
        return min;
    }
    public int[] Sort_Vector(int[] v, int n){
        int buf;
        int[] v1=new int[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i]<v[j]){
                   buf=v[i];
                    v[i]=v[j];
                    v[j]=buf;
                }
            }
        }
        return v;
    }
    public int[] Mult_Scalar_Vector(int[] v,int a, int n){
        int v1[]=new int[n];
        for(int i=0;i<n;i++){
            v1[i]=v[i]*a;
        }
        return v1;
    }
    public int[][] Trans_Matrix(int[][] m, int n){
        int[][] trans=new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                trans[i][j]=m[j][i];
                trans[j][i]=m[i][j];
            }
        }
        return trans;
    }
}
