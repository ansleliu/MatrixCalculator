// MatrixCalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MatrixCalculator.h"
#include "MatrixCalculatorDlg.h"
#include<CString>
#include"Matrix.h" 
#include "HelpDialg.h"
//////////////////////////////////////////////
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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()                                                                          /////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
// CMatrixCalculatorDlg dialog                                                   //////

CMatrixCalculatorDlg::CMatrixCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMatrixCalculatorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMatrixCalculatorDlg)
	m_strMatrix1 = _T("");
	m_strMatrix = _T("");
	m_strMatrix2 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMatrixCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMatrixCalculatorDlg)
	DDX_Control(pDX, IDC_EDIT3, m_CEdit1);
	DDX_Control(pDX, IDC_EDIT1, m_CEdit);
	DDX_Text(pDX, IDC_EDIT2, m_strMatrix1);
	DDX_Text(pDX, IDC_EDIT1, m_strMatrix);
	DDX_Text(pDX, IDC_EDIT3, m_strMatrix2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMatrixCalculatorDlg, CDialog)
	//{{AFX_MSG_MAP(CMatrixCalculatorDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CANCELMODE()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	ON_COMMAND(ID_VIEW_ABOUTBOX, OnViewAboutbox)
	ON_COMMAND(ID_VIEW_HELP, OnViewHelp)
	ON_COMMAND(ID_MENUITEM32779, OnMenuitem32779)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMatrixCalculatorDlg message handlers

BOOL CMatrixCalculatorDlg::OnInitDialog()
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

void CMatrixCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMatrixCalculatorDlg::OnPaint() 
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
HCURSOR CMatrixCalculatorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMatrixCalculatorDlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CMatrixCalculatorDlg::OnButton12() 
{
	// TODO: Add your control notification handler code here
	Matrix matrix;
    Matrix matrix1;
    
	UpdateData(true);

	matrix.FromString(m_strMatrix);
    matrix1.FromString(m_strMatrix2);
	if(matrix.FromString(m_strMatrix)==0.0000 )
	{
		CString str="��û��������������������ٲ���!";
		AfxMessageBox(str, MB_OK|MB_ICONINFORMATION);
	}
	else
	{
		if(matrix1.FromString(m_strMatrix2)!=0.0000)
		{
			CString str1=">>�����������������Ϊ:";
			str1+="\r\n";
			str1+=matrix.ToString("   ");
			str1+="\r\n";
			str1+=">>����������㸨������Ϊ:";
			str1+="\r\n";
			str1+=matrix1.ToString("   ");
			m_strMatrix1 = str1;
		}
		else
		{
			CString str1=">>������ľ���Ϊ:";
			str1+="\r\n";
			str1+=matrix.ToString("   ");
			m_strMatrix1 = str1;
		}
	}
    
	UpdateData(false);
}


void CMatrixCalculatorDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	
	CString str1;
	Matrix matrix;
    Matrix matrix1;
	Matrix matrix2;

	UpdateData(true);

	matrix.FromString(m_strMatrix);
    matrix1.FromString(m_strMatrix2);

	if(matrix.FromString(m_strMatrix)==0.0000 )
	{
		CString str="��û������������������������ٲ���!";
		AfxMessageBox(str, MB_OK|MB_ICONINFORMATION);
	}
	else
	{
	    if(matrix1.FromString(m_strMatrix2)==0.0000)
		{
			str1="�����������Ϊ�գ��޷����мӷ�����!";
			AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
		}
		else if(matrix.GetNumColumns() !=matrix1.GetNumColumns() || matrix.GetNumRows() != matrix1.GetNumRows())
		{
			CString str1="��������������������������������ȣ��޷�������Ӳ���!";
			AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
		}
		else
		{
			matrix2=matrix+matrix1;
			str1=">>�����������������Ϊ:";
			str1+="\r\n";
			str1+=matrix.ToString("   ");
			str1+="\r\n";
			str1+=">>������ĸ����������Ϊ:";
			str1+="\r\n";
			str1+=matrix1.ToString("   ");
			str1+="\r\n";
			str1+=">>����������͸������������ӵĽ��Ϊ:";
			str1+="\r\n";
			str1+=matrix2.ToString("   ");
			m_strMatrix1=str1;
		}
	}

	UpdateData(false);
}


void CMatrixCalculatorDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CString str1;
	Matrix matrix;
    Matrix matrix1;
	Matrix matrix2;

	UpdateData(true);

	matrix.FromString(m_strMatrix);
    matrix1.FromString(m_strMatrix2);

	if(matrix.FromString(m_strMatrix)==0.0000 )
	{
		CString str="��û������������������������ٲ���!";
		AfxMessageBox(str, MB_OK|MB_ICONINFORMATION);
	}
	
	else
	{
		if(matrix1.FromString(m_strMatrix2)==0.0000)
		{
            str1="�����������Ϊ�գ��޷����м�������!";
			AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
		}
		else if(matrix.GetNumColumns() !=matrix1.GetNumColumns() || matrix.GetNumRows() != matrix1.GetNumRows())
		{
			CString str1="��������������������������������ȣ��޷������������!";
			AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
		}
		else
		{
			matrix2=matrix-matrix1;
			str1=">>�����������������Ϊ:";
			str1+="\r\n";
			str1+=matrix.ToString("   ");
			str1+="\r\n";
			str1+=">>������ĸ����������Ϊ:";
			str1+="\r\n";
			str1+=matrix1.ToString("   ");
			str1+="\r\n";
			str1+=">>��������������㸨����������Ľ��Ϊ:";
			str1+="\r\n";
			str1+=matrix2.ToString("   ");
			m_strMatrix1=str1;
		}
	}

	UpdateData(false);
}

void CMatrixCalculatorDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	CString str1;
	Matrix matrix;
    Matrix matrix1;
	Matrix matrix2;

	UpdateData(true);

	matrix.FromString(m_strMatrix);
    matrix1.FromString(m_strMatrix2);

	if(matrix.FromString(m_strMatrix)==0.0000 )
	{
		CString str="��û������������������������ٲ���!";
		AfxMessageBox(str, MB_OK|MB_ICONINFORMATION);
	}
	else
	{
		if(matrix1.FromString(m_strMatrix2)==0.0000)
		{
			str1="�����������Ϊ�գ��޷����г˷�����!";
			AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
            
		}
		else if (matrix.GetNumColumns() != matrix1.GetNumRows())
		{
			CString str1="������������������������������ƥ�䣬�޷�������˲���!";
			AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
		}
		else
		{
			matrix2=matrix*matrix1;
			str1=">>�����������������Ϊ:";
			str1+="\r\n";
			str1+=matrix.ToString("   ");
			str1+="\r\n";
			str1+=">>������ĸ����������Ϊ:";
			str1+="\r\n";
			str1+=matrix1.ToString("   ");
			str1+="\r\n";
			str1+=">>��������������㸨��������˵Ľ��Ϊ:";
			str1+="\r\n";
			str1+=matrix2.ToString("   ");
			m_strMatrix1=str1;
		}
	}

	UpdateData(false);
}

void CMatrixCalculatorDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	CString str1;
	CString str2;

	Matrix matrix;
	Matrix matrix1;
	Matrix matrix2;

	UpdateData(true);

	matrix.FromString(m_strMatrix);
    matrix1.FromString(m_strMatrix2);

	if(matrix.FromString(m_strMatrix)==0.0000 )
	{
		CString str="��û������������������������ٲ���!";
		AfxMessageBox(str, MB_OK|MB_ICONINFORMATION);
	}
	else
	{
		if(matrix1.FromString(m_strMatrix2)!=0.0000)
		{   
			double value=matrix1.GetElement(0,0);
			str2.Format("%f", value);

            matrix2=matrix*value;
			str1=">>�����������������Ϊ:";
			str1+="\r\n";
			str1+=matrix.ToString("   ");
			str1+="\r\n";
			str1+=">>������ĸ���������Ϊ:";
			str1+="\r\n";
			str1+=str2;
			str1+="\r\n";
			str1+=">>��������������㸨������˵Ľ��Ϊ:";
			str1+="\r\n";
			str1+=matrix2.ToString("   ");
			m_strMatrix1=str1;
		}
		else
		{
			str1="����������Ϊ�գ��޷��������˲���!";
			AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
		}
	}

	UpdateData(false);
}

void CMatrixCalculatorDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	CString str1;
	Matrix matrix;
	Matrix matrix1;

	UpdateData(true);

	matrix.FromString(m_strMatrix);

	if(matrix.FromString(m_strMatrix)==0.0000 )
	{
		CString str="��û������������������������ٲ���!";
		AfxMessageBox(str, MB_OK|MB_ICONINFORMATION);
	}
	else
	{
		matrix1 = matrix.Transpose();
		str1=">>�����������������Ϊ:";
		str1+="\r\n";
		str1+=matrix.ToString("   ");
		str1+="\r\n";
		str1+=">>����������ת�õĽ��Ϊ:";
		str1+="\r\n";
		str1+=matrix1.ToString("   ");
		m_strMatrix1=str1;
	}

	UpdateData(false);
}

void CMatrixCalculatorDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	CString str1;
	Matrix matrix;
	Matrix matrix1;

	UpdateData(true);

	matrix.FromString(m_strMatrix);

	if(matrix.FromString(m_strMatrix)==0.0000 )
	{
		CString str="��û������������������������ٲ���!";
		AfxMessageBox(str, MB_OK|MB_ICONINFORMATION);
	}
	else if (matrix.GetNumRows() != matrix.GetNumColumns())
	{
		CString str1="����������ͬ�����Ƿ���û����!";
		AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
	}
	else if (Det(matrix)==0.0)
	{
		CString str1="����ʽֵΪ�㣬�˾���û����!";
		AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
	}
	else
	{
		matrix1 = Inv(matrix);
		str1=">>�����������������Ϊ:";
		str1+="\r\n";
		str1+=matrix.ToString("   ");
		str1+="\r\n";
		str1+=">>��������������Ľ��Ϊ:";
		str1+="\r\n";
		str1+=matrix1.ToString("   ");
		m_strMatrix1=str1;
	}

	UpdateData(false);
}

void CMatrixCalculatorDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	CString str1;
	Matrix matrix;
	Matrix matrix1;
	Matrix matrix2;

	UpdateData(true);

	matrix.FromString(m_strMatrix);

	if(matrix.FromString(m_strMatrix)==0.0000 )
	{
		CString str="��û������������������������ٲ���!";
		AfxMessageBox(str, MB_OK|MB_ICONINFORMATION);
	}
	else
	{
		if(matrix1.FromString(m_strMatrix2)!=0.0000)
		{
			matrix1.FromString(m_strMatrix2);

			double value=matrix1.GetElement(0,0);
			CString str2;
			str2.Format("%f", value);

            matrix2=matrix.Exponentiation(value);
			str1=">>�����������������Ϊ:";
			str1+="\r\n";
			str1+=matrix.ToString("   ");
			str1+="\r\n";
			str1+=">>�����������Ϊ:";
			str1+="\r\n";
			str1+=str2;
			str1+="\r\n";
			str1+=">>�������������ݵĽ��Ϊ:";
			str1+="\r\n";
			str1+=matrix2.ToString("   ");
			m_strMatrix1=str1;
		}
		else
		{
			str1="����Ϊ�գ��޷��������ݲ���!";
			AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
		}
	}

	UpdateData(false);
}

void CMatrixCalculatorDlg::OnButton9() 
{
	// TODO: Add your control notification handler code here
	CString str1;
	
	Matrix matrix;

	UpdateData(true);

	matrix.FromString(m_strMatrix);

	if(matrix.FromString(m_strMatrix)==0.0000 )
	{
		CString str="��û������������������������ٲ���!";
		AfxMessageBox(str, MB_OK|MB_ICONINFORMATION);
	}
	else if (matrix.GetNumRows() != matrix.GetNumColumns())
	{
		CString str1="����������ͬ�����Ƿ���û������ʽֵ!";
		AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
	}
	else
	{
		CString str2;
		double value=Det(matrix);
		str2.Format("%f", value);

		str1=">>�����������������Ϊ:";
		str1+="\r\n";
		str1+=matrix.ToString("   ");
		str1+="\r\n";
		str1+=">>���������������ʽֵΪ:";
		str1+="\r\n";
		str1+=str2;
		m_strMatrix1=str1;
	}

	UpdateData(false);
}

void CMatrixCalculatorDlg::OnButton10() 
{
	// TODO: Add your control notification handler code here
	CString str1;
	Matrix matrix;
	Matrix matrix1;

	UpdateData(true);

	matrix.FromString(m_strMatrix);

	if(matrix.FromString(m_strMatrix)==0.0000 )
	{
		CString str="��û������������������������ٲ���!";
		AfxMessageBox(str, MB_OK|MB_ICONINFORMATION);
	}
	else
	{
		matrix1 = Rref(matrix);

		CString str2;
		double value=Rank(matrix1);
		str2.Format("%f", value);

		str1=">>�����������������Ϊ:";
		str1+="\r\n";
		str1+=matrix.ToString("   ");
		str1+="\r\n";
		str1+=">>��������������б任�Ľ��Ϊ:";
		str1+="\r\n";
		str1+=matrix1.ToString("   ");
		str1+="\r\n";
		str1+=">>�������������Ϊ:";
		str1+="\r\n";
        str1+=str2;
		m_strMatrix1=str1;
	}

	UpdateData(false);
}

void CMatrixCalculatorDlg::OnButton11() 
{
	// TODO: Add your control notification handler code here
	CString str1;
	Matrix matrix; 
	Matrix matrix1;

	UpdateData(true);

	matrix.FromString(m_strMatrix);
    
	if(matrix.FromString(m_strMatrix)==0.0000 )
	{
		CString str="��û������������������������ٲ���!";
		AfxMessageBox(str, MB_OK|MB_ICONINFORMATION);
	}
	else if (matrix.GetNumRows() != matrix.GetNumColumns())
	{
		CString str1="����ʵ�Գƾ����޷���������ֵ����������!";
		AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
	}
	else
	{
		str1=">>�����������������Ϊ:";
		str1+="\r\n";
		str1+=matrix.ToString("   ");

		double* ptr = new double[matrix.GetNumColumns()];
        
		if (matrix.FindEigenvaluesEigenvectors(ptr, matrix1))
		{
			CString str;

			str1+="\r\n";
			str1+=">>����ֵΪ\r\n";
			
			for (int i=0; i<matrix.GetNumColumns(); ++i)
			{
				str.Format("%d: %f\r\n", i+1, ptr[i]);
				str1 += str;
			}

			str1 += ">>��Ӧ����������Ϊ\r\n";
			for (int j=0; j<matrix.GetNumColumns(); ++j)
			{
				str.Format("%d: %s\r\n", j+1, matrix1.ColToString(j));
				str1 += str;
			}
			m_strMatrix1=str1;
		}
		else
		{
			str1 = ">>���ʧ��";
            AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
		}
		delete[] ptr;
	}

	UpdateData(false);
}

void CMatrixCalculatorDlg::OnButton13() 
{
	// TODO: Add your control notification handler code here
	CString str1;
    CString str2;
	CString str3;

	Matrix matrix;
	Matrix matrix1;
	Matrix matrix2;

	UpdateData(true);

	matrix.FromString(m_strMatrix);

	if(matrix.FromString(m_strMatrix)==0.0000 )
	{
		CString str="��û������������������������ٲ���!";
		AfxMessageBox(str, MB_OK|MB_ICONINFORMATION);
	}
	else
	{
		if(matrix1.FromString(m_strMatrix2)!=0.0000)
		{
			matrix1.FromString(m_strMatrix2);

			double value1=matrix1.GetElement(0,0);
			double value2=matrix1.GetElement(0,1);

			str2.Format("%f", value1);
			str3.Format("%f", value2); 
			
            double value3=AlgebraCofactor(matrix,value1,value2);
			CString str4;
			str4.Format("%f", value3);

			str1=">>�����������������Ϊ:";
			str1+="\r\n";
			str1+=matrix.ToString("   ");
			str1+="\r\n";
			str1+=">>����������������Ϊ:";
			str1+="\r\n";
			str1+=str2;
			str1+="   ";
            str1+=str3;
			str1+="\r\n";
			str1+=">>�������������������ʽ�Ľ��Ϊ:";
			str1+="\r\n";
			str1+=str4;
			m_strMatrix1=str1;
		}
		else
		{
			str1="�����Ϊ�գ��޷��������������ʽ����!";
			AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
		}
	}

	UpdateData(false);
}



void CMatrixCalculatorDlg::OnViewAboutbox() 
{
	// TODO: Add your command handler code here
	CAboutDlg m_dlg;
	m_dlg.DoModal();	
}

void CMatrixCalculatorDlg::OnViewHelp() 
{
	// TODO: Add your command handler code here
	HelpDialg m_dlg;
	m_dlg.DoModal();
}

void CMatrixCalculatorDlg::OnMenuitem32779() 
{
	// TODO: Add your command handler code here
	CString str;
	str="MatrixCalculator\r\n";
	str+="Microsoft ������Ӧ�ó���\r\n";
	str+="Version:1.0.0.1\r\n";
	str+="Programer��ansleliu\r\n";
	str+="Date:2011-11-11";
	MessageBox(str);
}
