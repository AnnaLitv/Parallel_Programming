package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Thread1 f1 = new Thread1("Function 1",1);
        Thread2 f2 = new Thread2("Function 2",10);
        Thread3 f3 = new Thread3("Function 3", 5);
        f1.start();
        try {
            f1.join(2000);
        }catch (InterruptedException ee){

        }

        f2.start();
        try {
            f1.join();
        }catch (InterruptedException ee){

        }
        f3.start();

        try{
            f1.join();
            f2.join();
            f3.join();
        }catch (InterruptedException pp){

        }
        /*System.out.println(f1.getName());
        System.out.println(f2.getName());
        System.out.println(f3.getName());*/
    }

}
