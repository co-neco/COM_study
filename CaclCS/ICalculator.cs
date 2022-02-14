using System;
using System.Runtime.InteropServices;

namespace CaclCS
{
    [ComImport, Guid("F24C4FC4-3667-421D-A144-0AC0DF90D0AF")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    interface ICalculator
    {
        void push(double value);
        double pop();
        void add();
        void subtract();
    }

    [ComImport, Guid("D4B830A5-7DFC-4C81-9268-8BB0BEA7CACE")]
    class RPNCalculator { }
}
