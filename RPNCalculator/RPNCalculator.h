#pragma once

#include <stack>
#include "RPNCalcInterfaces.h"

class __declspec(uuid("D4B830A5-7DFC-4C81-9268-8BB0BEA7CACE")) 
RPNCalculator : public IRPNCalculator {
public:
	HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject) override;
	ULONG __stdcall AddRef(void) override;
	ULONG __stdcall Release(void) override;

	HRESULT __stdcall push(double value) override;
	HRESULT __stdcall pop(double* value) override;
	HRESULT __stdcall add() override;
	HRESULT __stdcall subtract() override;

private:
	ULONG m_refCount = 1;
	const static ULONG sm_ulMaxStackSize = 256;
	std::stack<double> m_data;
};