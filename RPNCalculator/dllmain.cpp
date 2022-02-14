// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <ktmw32.h>

#pragma comment(lib, "KtmW32.lib")

#include "RPNCalculatorFactory.h"
#include "RPNCalcInterfaces.h"
#include "RPNCalculator.h"

// {D4B830A5-7DFC-4C81-9268-8BB0BEA7CACE}
DEFINE_GUID(CLSID_RPNCalculator,
    0xd4b830a5, 0x7dfc, 0x4c81, 0x92, 0x68, 0x8b, 0xb0, 0xbe, 0xa7, 0xca, 0xce);

HMODULE g_hInstance = NULL;

static const WCHAR clsidPath[] = L"CLSID\\{D4B830A5-7DFC-4C81-9268-8BB0BEA7CACE}";

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        g_hInstance = hModule;
        
        // bi thread_attach and thread_detach
        ::DisableThreadLibraryCalls(hModule);
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


_Check_return_ STDAPI DllGetClassObject(_In_ REFCLSID rclsid, _In_ REFIID riid, _Outptr_ LPVOID FAR* ppv) {
    if (rclsid == __uuidof(RPNCalculator)) {
        static RPNCalculatorFactory factory;
        return factory.QueryInterface(riid, ppv);
    }
    return CLASS_E_CLASSNOTAVAILABLE;
}

STDAPI DllRegisterServer() {

    HANDLE hTransaction = CreateTransaction(NULL, NULL, TRANSACTION_DO_NOT_PROMOTE, 0, 0, INFINITE, NULL);
    if (hTransaction == INVALID_HANDLE_VALUE)
        return HRESULT_FROM_WIN32(GetLastError());

    HKEY hKey;
    auto error = RegCreateKeyTransactedW(HKEY_CLASSES_ROOT, clsidPath, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE,
        NULL, &hKey, NULL, hTransaction, NULL);
    if (error != ERROR_SUCCESS)
        return HRESULT_FROM_WIN32(error);

    WCHAR value[] = L"RPNCalculator";
    error = RegSetValueExW(hKey, NULL, 0, REG_SZ, (const BYTE*)value, sizeof(value));
    if (error != ERROR_SUCCESS)
        return HRESULT_FROM_WIN32(error);

    HKEY hInProcKey;
    error = RegCreateKeyTransactedW(hKey, L"InProcServer32", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, 
        NULL, &hInProcKey, NULL, hTransaction, NULL);
    if (error != ERROR_SUCCESS)
        return HRESULT_FROM_WIN32(error);

    WCHAR path[MAX_PATH];
    GetModuleFileNameW(g_hInstance, path, _countof(path));
    error = RegSetValueEx(hInProcKey, NULL, 0, REG_SZ, (const BYTE*)path, DWORD(wcslen(path) + 1) * sizeof(WCHAR));
    if (error != ERROR_SUCCESS)
        return HRESULT_FROM_WIN32(error);

    auto ok = CommitTransaction(hTransaction);
    auto hr = ok ? S_OK : HRESULT_FROM_WIN32(GetLastError());

    RegCloseKey(hInProcKey);
    RegCloseKey(hKey);
    CloseHandle(hTransaction);

    return hr;
}

STDAPI DllUnregisterServer() {

    HANDLE hTransaction = CreateTransaction(NULL, NULL, TRANSACTION_DO_NOT_PROMOTE, 0, 0, INFINITE, NULL);
    if (hTransaction == INVALID_HANDLE_VALUE)
        return HRESULT_FROM_WIN32(GetLastError());

    HKEY hKey;
    auto error = RegOpenKeyTransactedW(HKEY_CLASSES_ROOT, clsidPath, 0,
        DELETE | KEY_ENUMERATE_SUB_KEYS | KEY_QUERY_VALUE | KEY_SET_VALUE,
        &hKey, hTransaction, NULL);
    if (error != ERROR_SUCCESS)
        return HRESULT_FROM_WIN32(error);

    error = RegDeleteTreeW(hKey, NULL);
    if (error != ERROR_SUCCESS)
        return HRESULT_FROM_WIN32(error);

    error = RegDeleteKeyTransactedW(HKEY_CLASSES_ROOT, clsidPath, 0, 0, hTransaction, NULL);
    if (error != ERROR_SUCCESS)
        return HRESULT_FROM_WIN32(error);

    BOOL bOk = CommitTransaction(hTransaction);
    auto hr = bOk ? S_OK : HRESULT_FROM_WIN32(GetLastError());

    RegCloseKey(hKey);
    CloseHandle(hTransaction);

    return hr;
}