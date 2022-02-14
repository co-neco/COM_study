#pragma once

#include "pch.h"

MIDL_INTERFACE("F24C4FC4-3667-421D-A144-0AC0DF90D0AF")
IRPNCalculator : IUnknown{
	virtual HRESULT __stdcall push(double value) = 0;
	virtual HRESULT __stdcall pop(double* value) = 0;
	virtual HRESULT __stdcall add() = 0;
	virtual HRESULT __stdcall subtract() = 0;
};

// {F24C4FC4-3667-421D-A144-0AC0DF90D0AF}
DEFINE_GUID(IID_IRPNCalculator,
	0xf24c4fc4, 0x3667, 0x421d, 0xa1, 0x44, 0xa, 0xc0, 0xdf, 0x90, 0xd0, 0xaf);

// {D4B830A5-7DFC-4C81-9268-8BB0BEA7CACE}
DEFINE_GUID(CLSID_RPNCalculator,
	0xd4b830a5, 0x7dfc, 0x4c81, 0x92, 0x68, 0x8b, 0xb0, 0xbe, 0xa7, 0xca, 0xce);

class __declspec(uuid("D4B830A5-7DFC-4C81-9268-8BB0BEA7CACE")) RPNCalculator;