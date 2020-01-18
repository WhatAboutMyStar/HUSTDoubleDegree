// CvTo01.h : main header file for the CVTO01 application
//

#if !defined(AFX_CVTO01_H__AEBC1F9C_FAE2_406C_9A03_E5F1C219BB2E__INCLUDED_)
#define AFX_CVTO01_H__AEBC1F9C_FAE2_406C_9A03_E5F1C219BB2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCvTo01App:
// See CvTo01.cpp for the implementation of this class
//

class CCvTo01App : public CWinApp
{
public:
	CCvTo01App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCvTo01App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCvTo01App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CVTO01_H__AEBC1F9C_FAE2_406C_9A03_E5F1C219BB2E__INCLUDED_)
