using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab1
{
    class Fun3
    {
        //static object locker = new object();
        int[,] mt, mp;
        int[] r, s, o;
        int n;
        Func f3 = new Func();

        public Fun3(int n)
        {
            this.n = n;
            mt = new int[n, n];
            mp = new int[n, n];
            r = new int[n];
            s = new int[n];
            o = new int[n];
        }
        public void run()
        {
            
            Console.WriteLine("Task 3 started!");
            f3.inputMatrix(mt, n);
            f3.inputMatrix(mp, n);
            f3.inputVector(r, n);
            f3.inputVector(s, n);
            o = f3.multVectorMatrix(f3.sortVector(f3.sumVectors(r, s, n), n), f3.multMatrixes(mt, mp, n), n);
            if (n <= 10)
            {
                lock (Program.locker)
                {
                    Console.WriteLine("(F3)Matrix MT:");
                    f3.outputMatrix(mt, n);
                    Console.WriteLine("(F3)Matrix MP:");
                    f3.outputMatrix(mp, n);
                    Console.WriteLine("(F3)Vector R:");
                    f3.outputVector(r, n);
                    Console.WriteLine("(F3)Vector S:");
                    f3.outputVector(s, n);
                    Console.WriteLine("(F3)O:");
                    f3.outputVector(o, n);
                }
            }
        }
    }
}
