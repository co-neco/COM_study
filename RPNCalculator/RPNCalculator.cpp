#include "pch.h"

#include "RPNCalculator.h"


HRESULT __stdcall
RPNCalculator::QueryInterface(REFIID riid, void** ppvObject) {
	
	if (ppvObject == nullptr)
		return E_POINTER;

	if (riid == __uuidof(IUnknown)
		||
		riid == __uuidof(IRPNCalculator)) {
		AddRef();
		*ppvObject = static_cast<IRPNCalculator*>(this);
		return S_OK;
	}

	return E_NOINTERFACE;
}

ULONG __stdcall RPNCalculator::AddRef(void) {
	return ++m_refCount;
}

ULONG __stdcall RPNCalculator::Release(void) {
	auto count = --m_refCount;
	if (count == 0)
		delete this;

	return count;
}

HRESULT __stdcall RPNCalculator::push(double value) {

	if (m_data.size() > sm_ulMaxStackSize)
		return E_UNEXPECTED;

	m_data.push(value);
	return S_OK;
}

HRESULT __stdcall RPNCalculator::pop(double* value) {

	if (m_data.empty())
		return E_UNEXPECTED;

	*value = m_data.top();
	m_data.pop();

	return S_OK;
}

HRESULT __stdcall RPNCalculator::add() {

	double x, y;
	auto hr = pop(&x);
	if (FAILED(hr))
		return hr;

	hr = pop(&y);
	if (FAILED(hr))
		return hr;

	push(x + y);

	return S_OK;
}

HRESULT __stdcall RPNCalculator::subtract() {

	double x, y;
	auto hr = pop(&x);
	if (FAILED(hr))
		return hr;

	hr = pop(&y);
	if (FAILED(hr))
		return hr;

	push(x - y);

	return S_OK;
}