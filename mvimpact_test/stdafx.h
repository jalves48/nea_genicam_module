
// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

// turns off MFC's hiding of some common and often safely ignored warning messages
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC support for ribbons and control bars
#include <atlstr.h>

#include "DeclareUserMsg\DeclareUserMsg.h"





#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif




//////////////////////////////////////////////////////////////////////////
// User Windows Messages


/***************************************************************
*                           UWM_SET_INTERFACE_FUNCTION
* Inputs:
*       WPARAM: (WPARAM)(int)
Index do item
*       LPARAM: (LPARAM)(int)
Index do subitem

* Result: LRESULT
*	Endereço da estrutura com os dados pedidos
* Effect:
*	Enviada pela dialog principal para executar comandos e libertar a Aplicação
***************************************************************/
 #define WM_SET_INTERFACE_FUNCTION_MSG _T("UWM_GET_TOOL_INFO-{2CDA807A-44EF-4627-81DA-E6B9FF1D1C0D}")
 //static const UINT name = ::RegisterWindowMessage(WM_SET_INTERFACE_FUNCTION_MSG)
DECLARE_USER_MESSAGE(WM_SET_INTERFACE_FUNCTION)



/***************************************************************
*                           WM_MAIN_THREAD_CALLBACK
* Inputs:
*       WPARAM: (WPARAM)(int)
Index do item
*       LPARAM: (LPARAM)(int)
Index do subitem

* Result: LRESULT
*	Endereço da estrutura com os dados pedidos
* Effect:
*	Enviada pela Thread principal para executar comandos na classe CCamera e afins
***************************************************************/
#define WM_MAIN_THREAD_CALLBACK_MSG _T("UWM_GET_TOOL_INFO-{90512D5D-3CF3-4899-BD0D-846C696FEA85}")
//static const UINT name = ::RegisterWindowMessage(WM_MAIN_THREAD_CALLBACK_MSG)
DECLARE_USER_MESSAGE(WM_MAIN_THREAD_CALLBACK)
