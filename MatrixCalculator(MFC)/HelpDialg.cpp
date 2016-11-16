// HelpDialg.cpp : implementation file
//

#include "stdafx.h"
#include "MatrixCalculator.h"
#include "MatrixCalculatorDlg.h"
#include "HelpDialg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// HelpDialg dialog


HelpDialg::HelpDialg(CWnd* pParent /*=NULL*/)
	: CDialog(HelpDialg::IDD, pParent)
{
	//{{AFX_DATA_INIT(HelpDialg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void HelpDialg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(HelpDialg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(HelpDialg, CDialog)
	//{{AFX_MSG_MAP(HelpDialg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// HelpDialg message handlers
