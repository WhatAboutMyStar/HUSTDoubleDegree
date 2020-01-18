// CvTo01Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "CvTo01.h"
#include "CvTo01Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCvTo01Dlg dialog

CCvTo01Dlg::CCvTo01Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCvTo01Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCvTo01Dlg)
	m_file_name = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCvTo01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCvTo01Dlg)
	DDX_Text(pDX, IDC_FILE_NAME, m_file_name);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCvTo01Dlg, CDialog)
	//{{AFX_MSG_MAP(CCvTo01Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCvTo01Dlg message handlers

BOOL CCvTo01Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCvTo01Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCvTo01Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCvTo01Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCvTo01Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CFileDialog	fileDlg(true, "*.exe|*.*", "*.exe", OFN_READONLY, "*.exe", this);
	
	if (fileDlg.DoModal() == IDOK)
	{
		m_file_name = fileDlg.m_ofn.lpstrFile;
		UpdateData(FALSE);
	}
}

void CCvTo01Dlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	char	file_name[256];
	byte	one_byte;
	FILE*	fp_read;
	FILE*	fp_write;
	
	UpdateData(TRUE);

	strcpy(file_name, m_file_name);
	fp_read = fopen(file_name, "r+b");

	strcat(file_name, ".txt");
	fp_write = fopen(file_name, "w+b");

	while (!feof(fp_read))
	{
		fread(&one_byte, 1, 1, fp_read);

		if (one_byte^0x01)
			fwrite("1", 1, 1, fp_write);
		else
			fwrite("0", 1, 1, fp_write);

		if (one_byte^0x02)
			fwrite("1", 1, 1, fp_write);
		else
			fwrite("0", 1, 1, fp_write);

		if (one_byte^0x04)
			fwrite("1", 1, 1, fp_write);
		else
			fwrite("0", 1, 1, fp_write);

		if (one_byte^0x08)
			fwrite("1", 1, 1, fp_write);
		else
			fwrite("0", 1, 1, fp_write);

		if (one_byte^0x10)
			fwrite("1", 1, 1, fp_write);
		else
			fwrite("0", 1, 1, fp_write);

		if (one_byte^0x20)
			fwrite("1", 1, 1, fp_write);
		else
			fwrite("0", 1, 1, fp_write);

		if (one_byte^0x40)
			fwrite("1", 1, 1, fp_write);
		else
			fwrite("0", 1, 1, fp_write);

		if (one_byte^0x80)
			fwrite("1", 1, 1, fp_write);
		else
			fwrite("0", 1, 1, fp_write);
	}

	fclose(fp_write);
	fclose(fp_read);

	MessageBox("转换完成！", "01转换", MB_ICONINFORMATION|MB_OK);
}
