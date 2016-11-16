// MatrixCalculator.h : main header file for the MATRIXCALCULATOR application
//

#if !defined(AFX_MATRIXCALCULATOR_H__B22789D3_185E_4B8B_9B88_7A9EBD474CB5__INCLUDED_)
#define AFX_MATRIXCALCULATOR_H__B22789D3_185E_4B8B_9B88_7A9EBD474CB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMatrixCalculatorApp:
// See MatrixCalculator.cpp for the implementation of this class
//

class CMatrixCalculatorApp : public CWinApp
{
public:
	CMatrixCalculatorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMatrixCalculatorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMatrixCalculatorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATRIXCALCULATOR_H__B22789D3_185E_4B8B_9B88_7A9EBD474CB5__INCLUDED_)
