all: midl app
.PHONY: all

PROXYSTUBOBJS = dlldata.obj \
				CalculatorTypeInfo_p.obj \
				CalculatorTypeInfo_i.obj

PROXYSTUBLIBS = kernel32.lib \
				rpcns4.lib \
				rpcrt4.lib \
				uuid.lib
# rpcndr.lib   -> rpcndr.lib is deprecated

midl:
# generate all parts(headers and source files) that our proxy dll need
	midl CalculatorTypeInfo.idl

app: $(PROXYSTUBOBJS) proxy_stub.def 
# generate proxy.dll used for proxy and stub.
	link /dll /out:proxy.dll /def:proxy_stub.def \
		$(PROXYSTUBOBJS) $(PROXYSTUBLIBS)
# regsvr32 by default writes registry configurations to HKLM/Software/CLSID
# , and the operation need administrator privilege.
# Therefore, you should run a cmd with administrator privilege.
	regsvr32 /s proxy.dll 

dlldata.obj: dlldata.c
	cl /c /DWIN32 /DREGISTER_PROXY_DLL dlldata.c

CalculatorTypeInfo_p.obj: CalculatorTypeInfo_p.c
	cl /c /DWIN32 /DREGISTER_PROXY_DLL CalculatorTypeInfo_p.c

CalculatorTypeInfo_i.obj: CalculatorTypeInfo_i.c
	cl /c /DWIN32 /DREGISTER_PROXY_DLL CalculatorTypeInfo_i.c

clean:
	del *.obj *.exp *.lib