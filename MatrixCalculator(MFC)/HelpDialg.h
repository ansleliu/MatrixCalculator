#if !defined(AFX_HELPDIALG_H__60718F0D_2F0F_4D04_9209_76FC1D9F8E9C__INCLUDED_)
#define AFX_HELPDIALG_H__60718F0D_2F0F_4D04_9209_76FC1D9F8E9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HelpDialg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// HelpDialg dialog

class HelpDialg : public CDialog
{
// Construction
public:
	HelpDialg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(HelpDialg)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(HelpDialg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(HelpDialg)
	afx_msg void OnViewHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELPDIALG_H__60718F0D_2F0F_4D04_9209_76FC1D9F8E9C__INCLUDED_)
