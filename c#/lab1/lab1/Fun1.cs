using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab1
{
    class Fun1
    {
        //static object locker = new object(); 
        int[] a, b, c;
        int[,] ma, md;
        int n;
        Func f1 = new Func();
        public Fun1(int n)
        {
            this.n = n;
            ma = new int[n, n];
            md = new int[n, n];
            a = new int[n];
            b = new int[n];
            c = new int[n];
        }
        public void run()
        {
            //Thread.Sleep();
            Console.WriteLine("Task 1 started!");
            f1.inputMatrix(ma, n);
            f1.inputMatrix(md, n);
            f1.inputVector(b, n);
            f1.inputVector(c, n);
            a = f1.multVectorMatrix(f1.multScalarVector(b, f1.minVector(c, n), n), f1.sumMatrixes(f1.multMatrixes(ma, md, n), md, n), n);
            if (n <= 10)
            {   lock (Program.locker)
                {
                    Console.WriteLine("(F1)Matrix MA:");
                    f1.outputMatrix(ma, n);
                    Console.WriteLine("(F1)Matrix MD:");
                    f1.outputMatrix(md, n);
                    Console.WriteLine("(F1)Vector B:");
                    f1.outputVector(b, n);
                    Console.WriteLine("(F1)Vector C:");
                    f1.outputVector(c, n);
                    Console.WriteLine("(F1)A:");
                    f1.outputVector(a, n);
                }
            }
            Console.WriteLine("Task 1 finished!");
        }
    }

}
