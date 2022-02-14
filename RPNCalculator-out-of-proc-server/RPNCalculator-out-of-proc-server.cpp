// RPNCalculator-out-of-proc-server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "RPNCalculatorFactory.h"
#include "RPNCalculator.h"
#include <iostream>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    HRESULT hr = CoInitialize(NULL);

    static RPNCalculatorFactory calcFactory;
    DWORD dwRegID;
    hr = CoRegisterClassObject(__uuidof(RPNCalculator), (IClassFactory*)&calcFactory, 
        CLSCTX_LOCAL_SERVER, REGCLS_MULTIPLEUSE, &dwRegID);
    if (hr != S_OK) {
        std::cout << "CoRegisterClassObject failed" << "\n";
        CoUninitialize();
        return 0;
    }
    
    MSG ms;
    while (GetMessage(&ms, 0, 0, 0))
    {
        TranslateMessage(&ms);
        DispatchMessage(&ms);
    }

    CoRevokeClassObject(dwRegID);


    CoUninitialize();
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
