// MatrixCalculatorDlg.h : header file
//

#if !defined(AFX_MATRIXCALCULATORDLG_H__AF1DF430_3ADB_495B_8406_632A3555D076__INCLUDED_)
#define AFX_MATRIXCALCULATORDLG_H__AF1DF430_3ADB_495B_8406_632A3555D076__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMatrixCalculatorDlg dialog

class CMatrixCalculatorDlg : public CDialog 
{
// Construction
public:
	CMatrixCalculatorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMatrixCalculatorDlg)
	enum { IDD = IDD_MATRIXCALCULATOR_DIALOG };
	CEdit	m_CEdit1;
	CEdit	m_CEdit;
	CString	m_strMatrix1;
	CString	m_strMatrix;
	CString	m_strMatrix2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMatrixCalculatorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMatrixCalculatorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCancelMode();
	afx_msg void OnButton1();
	afx_msg void OnButton12();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton9();
	afx_msg void OnButton10();
	afx_msg void OnButton11();
	afx_msg void OnButton13();
	afx_msg void OnViewAboutbox();
	afx_msg void OnViewHelp();
	afx_msg void OnMenuitem32779();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATRIXCALCULATORDLG_H__AF1DF430_3ADB_495B_8406_632A3555D076__INCLUDED_)
