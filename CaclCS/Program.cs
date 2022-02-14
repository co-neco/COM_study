using System;

namespace CaclCS
{
    class Program
    {
        [STAThread]
        static void Main(string[] args)
        {
            ICalculator calc = (ICalculator)new RPNCalculator();
            calc.push(10);
            calc.push(20);
            calc.add();
            Console.WriteLine(calc.pop());
        }
    }
}
