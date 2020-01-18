// CvTo01Dlg.h : header file
//

#if !defined(AFX_CVTO01DLG_H__790B751D_881F_4101_9FC3_D37014B783AE__INCLUDED_)
#define AFX_CVTO01DLG_H__790B751D_881F_4101_9FC3_D37014B783AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCvTo01Dlg dialog

class CCvTo01Dlg : public CDialog
{
// Construction
public:
	CCvTo01Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCvTo01Dlg)
	enum { IDD = IDD_CVTO01_DIALOG };
	CString	m_file_name;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCvTo01Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCvTo01Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CVTO01DLG_H__790B751D_881F_4101_9FC3_D37014B783AE__INCLUDED_)
