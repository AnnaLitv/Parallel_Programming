using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System;
using System.Diagnostics;
namespace lab1
{
    class Program
    {
        public static object locker = new object();
        static void Main(string[] args)
        {
            Fun1 task1 = new Fun1(10);
            Fun2 task2 = new Fun2(10);
            Fun3 task3 = new Fun3(10);
            Thread F1 = new Thread(task1.run);
            F1.Name = "Function 1";
            F1.Priority = ThreadPriority.Lowest;
            Thread F2 = new Thread(task2.run);
            F2.Name = "Function 2";
            F2.Priority = ThreadPriority.Highest;
            Thread F3 = new Thread(task3.run);
            F3.Name = "Function 3";
            F3.Priority = ThreadPriority.Normal;
            F1.Start();
            F2.Start();
            F3.Start();
            F1.Join();
            F2.Join();
            F3.Join();
            //Console.WriteLine(F1.Name);
            Console.Read();
        }
        
        static void Func3()
        {
            
        }
    }
}
