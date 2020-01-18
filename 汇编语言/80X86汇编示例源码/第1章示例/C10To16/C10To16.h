// C10To16.h : main header file for the C10TO16 application
//

#if !defined(AFX_C10TO16_H__C64A5152_FCFE_4239_9FA7_186B8F1ED82E__INCLUDED_)
#define AFX_C10TO16_H__C64A5152_FCFE_4239_9FA7_186B8F1ED82E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CC10To16App:
// See C10To16.cpp for the implementation of this class
//

class CC10To16App : public CWinApp
{
public:
	CC10To16App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC10To16App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CC10To16App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C10TO16_H__C64A5152_FCFE_4239_9FA7_186B8F1ED82E__INCLUDED_)
