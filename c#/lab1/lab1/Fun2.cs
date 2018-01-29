using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab1
{
    class Fun2
    {
       // static object locker = new object();
            int[,] ma, mb, mz, mk;
            int n;
            Func f2 = new Func();

            public Fun2(int n)
        {
            this.n = n;
            ma = new int[n, n];
            mb = new int[n, n];
            mz = new int[n, n];
            mk = new int[n, n];
        }    

            public void run()
              {
                Console.WriteLine("Task 2 started!");
                
                f2.inputMatrix(ma, n);
                f2.inputMatrix(mb, n);
                f2.inputMatrix(mz, n);
                //  f2.outputMatrix(f2.multMatrixes(ma, f2.multMatrixes(ma, mz, n), n),n);
                mk = f2.sumMatrixes(f2.multMatrixes(ma, f2.multMatrixes(ma, mz, n), n), f2.Trans_Matrix(mb, n), n);
                if (n <= 10)
                {
                lock (Program.locker)
                {
                    Console.WriteLine("(F2)Matrix MA:");
                    f2.outputMatrix(ma, n);
                    Console.WriteLine("(F2)Matrix MB:");
                    f2.outputMatrix(mb, n);
                    Console.WriteLine("(F2)Matrix MZ:");
                    f2.outputMatrix(mz, n);
                    Console.WriteLine("(F2)Matrix MK:");
                    f2.outputMatrix(mk, n);
                }
                }
                Console.WriteLine("Task 2 finished!");
        }
    }
}
