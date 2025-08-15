
// MyFirstPRGDlg.h : header file
//

#pragma once


// CMyFirstPRGDlg dialog
class CMyFirstPRGDlg : public CDialogEx
{
// Construction
public:
	CMyFirstPRGDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYFIRSTPRG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAButton();
	afx_msg void OnBnClickedBButton();
	afx_msg void OnBnClickedCButton();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int m_nA;
	int m_nB;
	int m_nResult;
	afx_msg void OnBnClickedCalculateButton();
};
