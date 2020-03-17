// C10To16Dlg.h : header file
//
//{{AFX_INCLUDES()
#include "vcf1.h"
//}}AFX_INCLUDES

#if !defined(AFX_C10TO16DLG_H__3494AD84_9B3F_4BCF_91AD_D9991E4017A9__INCLUDED_)
#define AFX_C10TO16DLG_H__3494AD84_9B3F_4BCF_91AD_D9991E4017A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CC10To16Dlg dialog

class CC10To16Dlg : public CDialog
{
// Construction
public:
	CC10To16Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CC10To16Dlg)
	enum { IDD = IDD_C10TO16_DIALOG };
	long	m_10;
	CVCF1	m_step;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC10To16Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CC10To16Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConvert();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C10TO16DLG_H__3494AD84_9B3F_4BCF_91AD_D9991E4017A9__INCLUDED_)
