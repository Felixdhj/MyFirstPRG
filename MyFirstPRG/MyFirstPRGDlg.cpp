
// MyFirstPRGDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MyFirstPRG.h"
#include "MyFirstPRGDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyFirstPRGDlg dialog



CMyFirstPRGDlg::CMyFirstPRGDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYFIRSTPRG_DIALOG, pParent)
	, m_nA(0)
	, m_nB(0)
	, m_nResult(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyFirstPRGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_A_EDIT, m_nA);
	DDX_Text(pDX, IDC_B_EDIT, m_nB);
	DDX_Text(pDX, IDC_RESULT_EDIT, m_nResult);
}

BEGIN_MESSAGE_MAP(CMyFirstPRGDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_A_BUTTON, &CMyFirstPRGDlg::OnBnClickedAButton)
	ON_BN_CLICKED(IDC_B_BUTTON, &CMyFirstPRGDlg::OnBnClickedBButton)
	ON_BN_CLICKED(IDC_C_BUTTON, &CMyFirstPRGDlg::OnBnClickedCButton)
	ON_BN_CLICKED(IDOK, &CMyFirstPRGDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMyFirstPRGDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CALCULATE_BUTTON, &CMyFirstPRGDlg::OnBnClickedCalculateButton)
END_MESSAGE_MAP()


// CMyFirstPRGDlg message handlers

BOOL CMyFirstPRGDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

void CMyFirstPRGDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyFirstPRGDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyFirstPRGDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMyFirstPRGDlg::OnBnClickedAButton()
{
	a = a + 3;
}

void CMyFirstPRGDlg::OnBnClickedBButton()
{
	b = b + 3;
}

void CMyFirstPRGDlg::OnBnClickedCButton()
{
	c = c + 3;
}

void CMyFirstPRGDlg::OnBnClickedOk()
{
	d = a + b + c;
	CString str;
	str.Format(_T("%d"), d);
	AfxMessageBox(str);
	//CDialogEx::OnOK();
}

void CMyFirstPRGDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}

void CMyFirstPRGDlg::OnBnClickedCalculateButton()
{
	UpdateData(TRUE);
	m_nResult = m_nA * m_nB;
	UpdateData(FALSE);
}
