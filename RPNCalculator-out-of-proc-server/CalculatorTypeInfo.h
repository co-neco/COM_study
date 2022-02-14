

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for CalculatorTypeInfo.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __CalculatorTypeInfo_h__
#define __CalculatorTypeInfo_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IRPNCalculator_FWD_DEFINED__
#define __IRPNCalculator_FWD_DEFINED__
typedef interface IRPNCalculator IRPNCalculator;

#endif 	/* __IRPNCalculator_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IRPNCalculator_INTERFACE_DEFINED__
#define __IRPNCalculator_INTERFACE_DEFINED__

/* interface IRPNCalculator */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRPNCalculator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F24C4FC4-3667-421D-A144-0AC0DF90D0AF")
    IRPNCalculator : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE push( 
            /* [in] */ double value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE pop( 
            /* [out] */ double *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE add( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE subtract( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRPNCalculatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRPNCalculator * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRPNCalculator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRPNCalculator * This);
        
        HRESULT ( STDMETHODCALLTYPE *push )( 
            IRPNCalculator * This,
            /* [in] */ double value);
        
        HRESULT ( STDMETHODCALLTYPE *pop )( 
            IRPNCalculator * This,
            /* [out] */ double *value);
        
        HRESULT ( STDMETHODCALLTYPE *add )( 
            IRPNCalculator * This);
        
        HRESULT ( STDMETHODCALLTYPE *subtract )( 
            IRPNCalculator * This);
        
        END_INTERFACE
    } IRPNCalculatorVtbl;

    interface IRPNCalculator
    {
        CONST_VTBL struct IRPNCalculatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRPNCalculator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRPNCalculator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRPNCalculator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRPNCalculator_push(This,value)	\
    ( (This)->lpVtbl -> push(This,value) ) 

#define IRPNCalculator_pop(This,value)	\
    ( (This)->lpVtbl -> pop(This,value) ) 

#define IRPNCalculator_add(This)	\
    ( (This)->lpVtbl -> add(This) ) 

#define IRPNCalculator_subtract(This)	\
    ( (This)->lpVtbl -> subtract(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRPNCalculator_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


