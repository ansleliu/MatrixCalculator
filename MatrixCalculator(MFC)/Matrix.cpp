/*********************************************************************************\
*                                   Matrix.cpp                                    *
*  �������������Ա�����Ķ���                                                     *
*                                                                                 *    
*  Programer��ansleliu                       Date��2011-11-12                     *                   
\*********************************************************************************/
 #include "stdafx.h"
 #include<stdlib.h>
 #include<CString>
 #include"Matrix.h" 
 /////////////////////////////////////////
 #ifdef _DEBUG
 #define new DEBUG_NEW
 #undef THIS_FILE
 static char THIS_FILE[] = __FILE__;
 #endif
//=================================================================================
//                             �������캯��                                       =    
//=================================================================================
Matrix::Matrix()
{
	m_nNumColumns = 1;
	m_nNumRows = 1;
	m_pData = NULL;
	bool bSuccess = Initialization(m_nNumRows, m_nNumColumns);
	ASSERT(bSuccess);
}
//================================================================================
//                         ָ�����й��캯��                                      =
// ������                                                                        =
//  1. int nRows - ָ���ľ�������           2. int nCols - ָ���ľ�������        =            
//================================================================================
Matrix::Matrix(int nRows, int nCols)
{
	m_nNumRows = nRows;
	m_nNumColumns = nCols;
	m_pData = NULL;
	bool bSuccess = Initialization(m_nNumRows, m_nNumColumns);
	ASSERT(bSuccess);
}
//===============================================================================
//                         �������캯��                                         =                     
// ������                                                                       =
// 1. const Matrix& other - Դ����                                              =
//===============================================================================
Matrix::Matrix(const Matrix& other)
{
	m_nNumColumns = other.GetNumColumns();
	m_nNumRows = other.GetNumRows();
	m_pData = NULL;
	bool bSuccess = Initialization(m_nNumRows, m_nNumColumns);
	ASSERT(bSuccess);
	memcpy(m_pData, other.m_pData, sizeof(double)*m_nNumColumns*m_nNumRows);
}
//=============================================================================
//                            ��������                                        =
//=============================================================================
Matrix::~Matrix()
{
	if (m_pData)
	{
		delete[] m_pData;
		m_pData = NULL;
	}
}
//=============================================================================
//                           ��ʼ������                                       =                           
// ������                                                                     =
// 1. int nRows - ָ���ľ�������     2. int nCols - ָ���ľ�������            =
// ����ֵ��bool �ͣ���ʼ���Ƿ�ɹ�                                            =
//=============================================================================
bool Matrix::Initialization(int nRows, int nCols)
{
	if (m_pData)
	{
		delete[] m_pData;
		m_pData = NULL;
	}
    ///////////////////////////////
	m_nNumRows = nRows;
	m_nNumColumns = nCols;
	int nSize = nCols*nRows;
	if (nSize < 0)
		return FALSE;
    ///////////////////////////////
	// �����ڴ�
	m_pData = new double[nSize];
	///////////////////////////////////////////////////
	if (m_pData == NULL)
		return FALSE;					// �ڴ����ʧ��
	if (IsBadReadPtr(m_pData, sizeof(double) * nSize))
		return FALSE;
    ///////////////////////////////////////////////////
	// ����Ԫ��ֵ��0
	memset(m_pData, 0, sizeof(double) * nSize);

	return TRUE;
}
//=============================================================================
//                    ���ַ���ת��Ϊ�����ֵ                                  =
// ������                                                                     =
// 1. CString s - ���ֺͷָ������ɵ��ַ���                                    =
// 2. const CString& sDelim - ����֮��ķָ�����Ĭ��Ϊ�ո�                    =
// 3. bool bLineBreak - ������֮���Ƿ��лس����з���Ĭ��Ϊ                    =
//   ��(�л��з�)���ò���ΪFALSEʱ������Ԫ��ֵ����һ�������룬                =
//   �ַ����ĵ�һ�� ��ֵӦΪ������������ڶ�����ֵӦΪ���������              =
// ����ֵ��bool �ͣ�ת���Ƿ�ɹ�                                              =
//=============================================================================
bool Matrix::FromString(CString s, const CString& sDelim , bool bLineBreak)
{
	if (s.IsEmpty())
		return FALSE;
   //////////////////////////////////////
	// ���д���
	if (bLineBreak)
	{
		CTokenizer tk(s, "\r\n");

		CStringList ListRow;
		CString sRow;
		while (tk.Next(sRow))
		{
			sRow.TrimLeft();
			sRow.TrimRight();
			if (sRow.IsEmpty())
				break;

			ListRow.AddTail(sRow);
		}
        /////////////////////////////////////////
		// ����
		m_nNumRows = ListRow.GetCount();

		sRow = ListRow.GetHead();
		CTokenizer tkRow(sRow, sDelim);
		CString sElement;
		/////////////////////////////////////////
		// ����
		m_nNumColumns = 1;
		while (tkRow.Next(sElement))
		{
			m_nNumColumns++;
		}
		m_nNumColumns-=1;
        ///////////////////////////////////////////
		// ��ʼ������
		if (! Initialization(m_nNumRows, m_nNumColumns))
			return FALSE;
        ///////////////////////////////////////////
		// ����ֵ
		POSITION pos = ListRow.GetHeadPosition();
		for (int i=0; i<m_nNumRows; i++)
		{
			sRow = ListRow.GetNext(pos);
			int j = 0;
			CTokenizer tkRow(sRow, sDelim);
			while (tkRow.Next(sElement))
			{
				sElement.TrimLeft();
				sElement.TrimRight();
				double v = atof(sElement);
				SetElement(i, j++, v);
			}
		}
        ////////////////////////////////////////
		return TRUE;
	}
	return TRUE;
}
//=============================================================================
//                        �������Ԫ�ص�ֵת��Ϊ�ַ���                        =        
// ������                                                                     =
// 1. const CString& sDelim - ����֮��ķָ�����Ĭ��Ϊ�ո�                    =
// 2 bool bLineBreak - ������֮���Ƿ��лس����з���Ĭ��Ϊ��(�л��з�)         =
// ����ֵ��CString �ͣ�ת���õ����ַ���                                       =
//=============================================================================
CString Matrix::ToString(const CString& sDelim, bool bLineBreak) const
{
	CString s="";

	for (int i=0; i<m_nNumRows; ++i)
	{
		for (int j=0; j<m_nNumColumns; ++j)
		{
			CString ss;
			ss.Format("%f", GetElement(i, j));
			s += ss;
            ////////////////////////////////////////
			if (bLineBreak)
			{
				if (j != m_nNumColumns-1)
					s += sDelim;
			}
			//////////////////////////////////////////////////
			else
			{
				if (i != m_nNumRows-1 || j != m_nNumColumns-1)
					s += sDelim;
			}
		}
		//////////////////////////////
		if (bLineBreak)
			if (i != m_nNumRows-1)
				s += "\r\n";
	}
    //////////////////////////////////////////
	return s;
}                                                                                        //////
///////////////////////////////////////////////////////////////////////////////////////////////
///////                           ��������                                               //////
///////                                                                                  //////
//=============================================================================
//                   ������ָ�����и�Ԫ�ص�ֵת��Ϊ�ַ���                     =
// ������                                                                     =
// 1. int nCol - ָ���ľ����У�nCol = 0��ʾ��һ��                             =
// 2. const CString& sDelim - ����֮��ķָ�����Ĭ��Ϊ�ո�                    =
// ����ֵ��CString �ͣ�ת���õ����ַ���                                       =
//=============================================================================
CString Matrix::ColToString(int nCol, const CString& sDelim ) const
{
	CString s = "";

	if (nCol >= m_nNumColumns)
		return s;
    /////////////////////////////////////
	for (int i=0; i<m_nNumRows; ++i)
	{
		CString ss;
		ss.Format("%f", GetElement(i, nCol));
		s += ss;
		if (i != m_nNumRows-1)
			s += sDelim;
	}
    /////////////////////////////////////
	return s;
}
//=============================================================================
//                          ����ָ��Ԫ�ص�ֵ                                  =                         
// ������                                                                     =
// 1. int nRows - ָ���ľ�������                                              =
// 2. int nCols - ָ���ľ�������                                              =
// 3. double value - ָ��Ԫ�ص�ֵ                                             =
// ����ֵ��bool �ͣ�˵�������Ƿ�ɹ�                                          =
//=============================================================================
bool Matrix::SetElement(int nRow, int nCol, double value)
{
	if (nCol < 0 || nCol >= m_nNumColumns || nRow < 0 || nRow >= m_nNumRows)
		return FALSE;
	if (m_pData == NULL)
		return FALSE;
	///////////////////////////////////////////////
	m_pData[nCol + nRow * m_nNumColumns] = value;

	return TRUE;
}

//=============================================================================
//                            ��ȡָ��Ԫ�ص�ֵ                                =
// ������                                                                     =
// 1. int nRows - ָ���ľ�������                                              =
// 2. int nCols - ָ���ľ�������                                              =
// ����ֵ��double �ͣ�ָ��Ԫ�ص�ֵ                                            =
//=============================================================================
double Matrix::GetElement(int nRow, int nCol) const
{
	return m_pData[nCol + nRow * m_nNumColumns] ;
}

//=============================================================================
//                           ��ȡ���������                                   =
// ����ֵ��int �ͣ����������                                                 =
//=============================================================================
int	Matrix::GetNumColumns() const
{
	return m_nNumColumns;
}
//=============================================================================
//                          ��ȡ���������                                    =
// ����ֵ��int �ͣ����������                                                 =
//=============================================================================
int	Matrix::GetNumRows() const
{
	return m_nNumRows;
}                                                                                        //////
///////////////////////////////////////////////////////////////////////////////////////////////
///////                              ����                                                //////
///////                                                                                  //////
//=============================================================================
//                        ���������=��������ֵ                             =
// ������                                                                     =
// 1. const Matrix& other - ���ڸ�����ֵ��Դ����                            =
// ����ֵ��Matrix�͵����ã������õľ�����other���                            =
//=============================================================================
Matrix& Matrix::operator=(const Matrix& other)
{
	if (&other != this)
	{
		bool bSuccess = Initialization(other.GetNumRows(), other.GetNumColumns());
		ASSERT(bSuccess);
		memcpy(m_pData, other.m_pData, sizeof(double)*m_nNumColumns*m_nNumRows);
	}
	return *this ;
}
//=============================================================================
//                      ���������+��ʵ�־���ļӷ�                           =
// ������                                                                     =
// 1. const Matrix& other - ��ָ��������ӵľ���                              =
// ����ֵ��Matrix�ͣ�ָ��������other���֮��                                  =
//=============================================================================
Matrix	Matrix::operator+(const Matrix& other) const
{
	// ���ȼ���������Ƿ����
	if(m_nNumColumns != other.GetNumColumns() || m_nNumRows != other.GetNumRows())
	{
		CString str1=">>��������������������������������ȣ��޷�������Ӳ���!\r\n������ԭ����������!";
		AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
		return *this;
	}
    else
	{
		// ����������
		Matrix	result(*this) ;		// ��������
		// ����ӷ�
		for (int i = 0 ; i < m_nNumRows ; ++i)
		{
			for (int j = 0 ; j <  m_nNumColumns; ++j)
				result.SetElement(i, j, result.GetElement(i, j) + other.GetElement(i, j)) ;
		}
		return result ;
	}
}
//=============================================================================
//                    ���������-��ʵ�־���ļ���                             =
// ������                                                                     =
// 1. const Matrix& other - ��ָ����������ľ���                              =
// ����ֵ��Matrix�ͣ�ָ��������other���֮��                                  =
//=============================================================================
Matrix	Matrix::operator-(const Matrix& other) const
{
	// ���ȼ���������Ƿ����
	if(m_nNumColumns != other.GetNumColumns() || m_nNumRows != other.GetNumRows())
	{
		CString str1=">>��������������������������������ȣ��޷������������!\r\n������ԭ����������!";
		AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
		return *this;
	}
    else
	{
		// ����Ŀ�����
		Matrix	result(*this) ;		// copy ourselves
		// ���м�������
		for (int i = 0 ; i < m_nNumRows ; ++i)
		{
			for (int j = 0 ; j <  m_nNumColumns; ++j)
				result.SetElement(i, j, result.GetElement(i, j) - other.GetElement(i, j)) ;
		}
	    return result ;
	}
}
//=============================================================================
//                    ���������*��ʵ�־��������                             =
// ������                                                                     =
// 1. double value - ��ָ��������˵�ʵ��                                     =
// ����ֵ��Matrix�ͣ�ָ��������value���֮��                                  =
//=============================================================================
Matrix	Matrix::operator*(double value) const
{
	// ����Ŀ�����
	Matrix	result(*this) ;	
	// ��������
	for (int i = 0 ; i < m_nNumRows ; ++i)
	{
		for (int j = 0 ; j <  m_nNumColumns; ++j)
			result.SetElement(i, j, result.GetElement(i, j)*value) ;
	}
	return result ;
}

//=============================================================================
//                          ���������*��ʵ�־���ĳ˷�                       =
// ������                                                                     =
// 1. const Matrix& other - ��ָ��������˵ľ���                              =
// ����ֵ��Matrix�ͣ�ָ��������other���֮��                                  =
//=============================================================================
Matrix	Matrix::operator*(const Matrix& other) const
{
	// ���ȼ���������Ƿ����Ҫ��
	if (m_nNumColumns != other.GetNumRows())
	{
		CString str1=">>������������������������������ƥ�䣬�޷�������˲���!\r\n������ԭ����������!";
		AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
		return *this;
	}
    else
	{   // ����Ŀ�����
		Matrix	result(m_nNumRows, other.GetNumColumns()) ;

		double	value ;
		for (int i = 0 ; i < result.GetNumRows() ; i++)
		{
			for (int j = 0 ; j < other.GetNumColumns() ; j++)
			{
				value = 0.0 ;
				for (int k = 0 ; k < m_nNumColumns ; k++)
				{
					value += GetElement(i, k) * other.GetElement(k, j) ;
				}
				result.SetElement(i, j, value) ;
			}
		}

		return result ;
	}
}
//=============================================================================
//                          �����ת��                                        =                           
// ����ֵ��CMatrix�ͣ�ָ������ת�þ���                                        =
//=============================================================================
Matrix Matrix::Transpose() const
{
	// ����Ŀ�����
	Matrix	Trans(m_nNumColumns, m_nNumRows);

	// ת�ø�Ԫ��
	for (int i = 0 ; i < m_nNumRows ; ++i)
	{
		for (int j = 0 ; j < m_nNumColumns ; ++j)
			Trans.SetElement(j, i, GetElement(i, j)) ;
	}
	return Trans;
}
//=================================================================================
//                               ������������                                     =
// ������                                                                         =
// 1. int n - ���������                                                          =
// ����ֵ��Matrix�ͣ���������������������                                       =
//=================================================================================
Matrix Matrix::Exponentiation(int n)
{
	// ����Ŀ�����
	Matrix Expon(*this);
   //////////////////////////////////////////////////////////
    if(n <= 0)
	{
		CString str1=">>����������Ϊ������������ԭ��������������������!";
		AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
		return *this;
	}
	/////////////////////////////////
	else if(n == 1)
	{
		return *this;
	}
	///////////////////////////////////
	else 
	{
		for(int i=1 ; i<n ; i++)
		{
			Expon=Expon*Expon;
		}
		return Expon;
	}
}
//=================================================================================
//                               ����������ʽ                                     =
// ������                                                                         =
//      1. const Matrix &matrix����������                                         =
//      2. int Specifiedrow  ָ����                                               =
//      3. int Specifiedcol  ָ����                                               =
// ����ֵ��                                                                       =
//         double�ͣ�����������������ʽ���                                       =
// ���ã�                                                                         =
//      1.��double Det(Matrix &matrix)�ڲ�����                                    =
//      2.��Matrix Inv( Matrix &matrix)�ڲ�����                                   =
// date:2011-10-19                                                                =
//=================================================================================
 Matrix Cofactor(const Matrix &matrix, int Specifiedrow, int Specifiedcol)
 {
	int temp_R = matrix.GetNumRows()-1;//�洢������� 
    int temp_C = matrix.GetNumColumns()-1; //�洢�������

	/////////////////////////////////////////////////////////
	Matrix temp(temp_R,temp_C); //������ʱ����洢���������ʽ
    /////////////////////////////////////////////////////////
	for (int i = 0; i < Specifiedrow; i++)
	{
		for (int j = 0; j < Specifiedcol; j++)
		{
			temp.SetElement(i,j,matrix.GetElement(i,j));
		}
		////////////////////////////////////////////////////////
		for (int k = Specifiedcol + 1; k < matrix.GetNumColumns(); k++)
		{
			temp.SetElement(i,k-1,matrix.GetElement(i,k));
		}
	}
   //////////////////////////////////////////////////////////////
	for (int m = Specifiedrow + 1; m < matrix.GetNumRows(); m++)
	{
		for (int j = 0; j < Specifiedcol; j++)
		{
			temp.SetElement(m-1,j,matrix.GetElement(m,j));
		}
		/////////////////////////////////////////////////////// 
		for (int k = Specifiedcol + 1; k <matrix.GetNumColumns(); k++)
		{
			temp.SetElement(m-1,k-1,matrix.GetElement(m,k));
		}
	}
    ///////////////////////////////////////////////////////////
	Det(temp);
	return temp;
 }
//=================================================================================
//                              �������������ʽ                                  =
// ������                                                                         =
//      1. const Matrix &matrix����������                                         =
//      2. int Specifiedrow  ָ����                                               =
//      3. int Specifiedcol  ָ����                                               =
// ����ֵ��                                                                       =
//         double�ͣ�����������������ʽ���                                       =
//=================================================================================
double AlgebraCofactor(const Matrix &matrix,int Specifiedrow,int Specifiedcol) 
 {
      double M = 0;
	  int m=Specifiedrow;
	  int n=Specifiedcol;
	  ///////////////////////////
	  if((m+n)%2==0)
	      M=Det(Cofactor(matrix, m, n));
	  else
		  M=-Det(Cofactor(matrix, m, n));
      //////////////////////////////////////
      return M;
 }
//=================================================================================
//                           �ݹ�������ʽֵ                                       =
// ������                                                                         =
//      1. const Matrix &matrix����������                                         =
// ����ֵ��                                                                       =
//         double�ͣ�����������������ʽֵ���                                     =
//=================================================================================
double Det(Matrix &matrix)  
{
     double det = 0;
     if (matrix.GetNumRows() != matrix.GetNumColumns())
	  {
		  CString str1="����������ͬ�����Ƿ���û������ʽֵ!\r\n������NULL";
		  AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
          return NULL;
	  }
	  else if (matrix.GetNumColumns() == 1)
	  {
          det = matrix.GetElement(0,0);
          return det;
	  }
     else
	 {
          for (int i = 0; i <matrix.GetNumRows(); i++)
		  {
               if (i%2==0)
                det += matrix.GetElement(i,0) * Det(Cofactor(matrix, i, 0));
               else 
                det -= matrix.GetElement(i,0) * Det(Cofactor(matrix, i, 0));
		  }
		  return det;
	 }
     
}
//=================================================================================
//                                ��������                                      =
// ������                                                                         =
//     1.Matrix &matrix  �������ľ���                                             =
// ����ֵ��                                                                       =
//       Matrix�ͣ���������Ľ��                                                 =
//=================================================================================
Matrix Inv( Matrix &matrix) 
{
     int temp_R = matrix.GetNumRows();//�洢������� 
     int temp_C = matrix.GetNumColumns();//�洢�������  
	 Matrix temp(temp_R,temp_C); //������ʱ����洢���������ʽ 
     //������� = ������� / ����ʽ
     double det = Det(matrix);
     //////////////////////////////////////////////////////////
	 if (det == 0)  //�������ʽ��ֵΪ0����û����
		{
			CString str1="����ʽֵΪ�㣬�˾���û����!\r\n�������������������!";
		    AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
			return matrix;
		}
	 else
	 {
		 for (int i = 0; i < temp.GetNumRows(); i++)
		 {
			 for (int j = 0; j < temp.GetNumColumns(); j++)
			 {
				  if ((i + j) % 2 == 0)
				  temp.SetElement(j,i,Det(Cofactor(matrix, i, j)) / det);
				  else
				  temp.SetElement(j,i,-Det(Cofactor(matrix, i, j)) / det);
			 }
		 }
		 return temp;
	 }
}
 
//=================================================================================
//                             ����ĳ����б任                                   =
// ������                                                                         =
//     1.Matrix &matrix  �������ľ���                                             =
// ����ֵ��                                                                       =
//       Matrix�ͣ������б任�Ľ��                                               =
//date:2011-10-20 & 21 & 22                                                       =
//=================================================================================
Matrix Rref(Matrix &matrix)
{
	 int temp_R = matrix.GetNumRows();//�洢������� 
     int temp_C = matrix.GetNumColumns();//�洢�������  
	 //////////////////////////////////////////////////////////////////
	 Matrix temp0(temp_R,temp_C); //������ʱ����洢���������ʽ
	 Matrix temp(temp_R,temp_C); //������ʱ����洢����ĳ��ȱ任���
     /////////////////////////////////////////////////////////////////
	 temp0=matrix;
    ////////////////////////////////////////////////////////////////////////////////////////
	for(int a=0 , b=0; a<temp0.GetNumRows() && b<temp0.GetNumColumns(); a++,b++ )   ////////
	{                                                                               ////////
		 int flag=0;
		 /////////////////////////////
		 if(b>=temp0.GetNumColumns())
			 b=temp0.GetNumColumns()-1;
		 ////////////////////////////////////////////////////
    	do                                              /////         
		{
		    flag=0;
			//////////////////////////////
			for(int r=a;r<temp0.GetNumRows();++r)
			{
				if(temp0.GetElement(r,b)==0)
					flag++;
			}
			///////////////////////////////////////////
			if(flag==temp0.GetNumRows()-a)                  ////
			{
				b+=1;
				if(b>=temp0.GetNumColumns()) 
					b=temp0.GetNumColumns()-1;
			}
		}
		while(flag==temp0.GetNumRows()-a && b<temp0.GetNumColumns()-1);       ////
		/////////////////////////////////////////////////////////////////////////
			flag=0;                                                    ////
		/////////////////////////////////
			for(int i=a;i<temp0.GetNumRows();i++)
			{
				if(temp0.GetElement(i,b)==0)
				 {
					for(int p=a+1; p<temp0.GetNumRows(); p++)
					{
						if(temp0.GetElement(p,b)!=0)
						{
							for(int q=b; q<temp0.GetNumColumns(); q++)
							{
								temp.SetElement(p-1,q,temp0.GetElement(p-1,q));
								temp0.SetElement(p-1,q,temp0.GetElement(p,q));
								temp0.SetElement(p,q,temp.GetElement(p-1,q));
							}
						}
					}
				}
			}                                                   //////
		///////////////////////////////////////////////////////////////////////
			for(int t=a+1; t<matrix.GetNumRows(); t++)                   //////
			{
				if(temp0.GetElement(t,b)!=0)
				{
					double logo1=temp0.GetElement(a,b);
					double logo2=temp0.GetElement(t,b);
					for(int m=b; m<temp0.GetNumColumns(); m++)
					{
						temp.SetElement(a,m,temp0.GetElement(a,m));
						temp.SetElement(a,m,temp.GetElement(a,m)*logo2);
						temp0.SetElement(t,m,temp0.GetElement(t,m)*logo1);
						temp0.SetElement(t,m,temp0.GetElement(t,m)-temp.GetElement(a,m));
					}
				}
			}                                                                //////
	}                                                                        //////
	///////////////////////////////////////////////////////////////////////////////////////////////
	for(int s=0 ; s<temp0.GetNumRows(); s++ )                                                 /////
	   for(int t=0; t<temp0.GetNumColumns(); t++)                                             /////
	   {
		   if(temp0.GetElement(s,t)!=0)
		   {
				for(int w = temp0.GetNumColumns()-1; w>=t ; w--)
					temp0.SetElement(s,w,temp0.GetElement(s,w)/temp0.GetElement(s,t));
				break;                                                                      
		   }                                                                                ///////
	   }                                                                                    ///////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	                                                                    
	for(int c=1; temp0.GetNumRows()<=temp0.GetNumColumns()?c<temp0.GetNumRows():c<temp0.GetNumColumns(); c++ )         //////
		for(int d=0; d<temp0.GetNumColumns() ; d++)                                                                    //////
		{
			if(temp0.GetElement(c,d)!=0)
			{
				for(int e=c-1; e>=0; e--)
				{
					if(temp0.GetElement(e,d)!=0)
					{
						double logo3=temp0.GetElement(c,d);
						double logo4=temp0.GetElement(e,d);
					    //////////////////////////////////////////	
						for(int f=0;f<temp0.GetNumColumns(); f++)
						{
							temp.SetElement(c,f,temp0.GetElement(c,f));
							temp.SetElement(c,f,temp.GetElement(c,f)*logo4);
							temp0.SetElement(e,f,temp0.GetElement(e,f)*logo3);
						}
					    //////////////////////////////////////////////
						for(int g=d; g<temp0.GetNumColumns(); g++)
							temp0.SetElement(e,g,temp0.GetElement(e,g)-temp.GetElement(c,g));
					}
				}
				break;
			}                                                                      ///////
		}                                                                          ///////
    //////////////////////////////////////////////////////////////////////////////////////                                                                  
    //////////////////////////////////////////////////////////////////////////////
    for(int x=0 ; x<temp0.GetNumRows(); x++ )                                /////
	   for(int y=0; y<temp0.GetNumColumns(); y++)                            /////
	   {
		   if(temp0.GetElement(x,y)!=0)
		   {
				for(int z = temp0.GetNumColumns()-1; z>=y ; z--)
					temp0.SetElement(x,z,temp0.GetElement(x,z)/temp0.GetElement(x,y));
				break;
		   }
	   }
	/////////////////////////////////////////////////////////
	temp = temp0;
	return temp;
}
//=================================================================================
//                                     ��������                                   =
// ������                                                                         =
//     1.Matrix &matrix  �������ľ��󣬾���Rref�󴫵ݹ�����������               =
// ����ֵ��                                                                       =
//      int�ͣ��������                                                           =
//date:2011-10-22                                                                 =
//=================================================================================
int Rank(Matrix &matrix)
{
	int temp_R = matrix.GetNumRows();//�洢������� 
    int temp_C = matrix.GetNumColumns();//�洢�������
	int rank = 0;
	int flag1=0;
	int flag2=0;
    /////////////////////////////////////////////////////////////////
	Matrix temp(temp_R,temp_C); //������ʱ����洢����ĳ��ȱ任���
    ////////////////////////////////////////////////////////////////
	temp=matrix;
    //////////////////////////////////////
	for(int i=0; i<temp.GetNumRows(); i++)      ///
	{
		for(int j=0 ; j<temp.GetNumColumns(); j++)
		{
			if(temp.GetElement(i,j)==0)
				flag1+=1;
		}
		/////////////////////////
		if(flag1==temp.GetNumColumns())
		{
			flag2+=1;
			flag1=0;
		}
		/////////////////
		else
			flag1=0;
	}
	///////////////////////
	rank=(temp.GetNumRows())-flag2;

	return rank;
}
//=================================================================================
//                         ��ʵ�Գƾ�������ֵ����������                           =
// ������                                                                         =
// 1. double dblEigenValue[] - һά���飬����Ϊ����Ľ���������ʱ�������ֵ       =
// 2. CMatrix& mtxEigenVector - ����ʱ������������������е�i��Ϊ��             =
//    ����dblEigenValue�е�j������ֵ��Ӧ����������                                =
// 3. double eps - ���㾫�ȣ�Ĭ��ֵΪ0.000001                                     =
// ����ֵ��BOOL�ͣ�����Ƿ�ɹ�                                                   =
//=================================================================================
bool Matrix::FindEigenvaluesEigenvectors(double dblEigenValue[], Matrix& mtxEigenVector, double eps)
{ 
	int i,j,p,q,u,w,t,s;
    double ff,fm,cn,sn,omega,x,y,d;
    
	if (! mtxEigenVector.Initialization(m_nNumColumns, m_nNumColumns))
		return FALSE;
    //////////////////////////////////////////////
	for (i=0; i<=m_nNumColumns-1; i++)
    { 
		mtxEigenVector.m_pData[i*m_nNumColumns+i]=1.0;
        for (j=0; j<=m_nNumColumns-1; j++)
			if (i!=j) 
				mtxEigenVector.m_pData[i*m_nNumColumns+j]=0.0;
    }
    ////////////////////
	ff=0.0;
	////////////////////////////////////////////
    for (i=1; i<=m_nNumColumns-1; i++)
	{
		for (j=0; j<=i-1; j++)
		{ 
			d=m_pData[i*m_nNumColumns+j]; 
			ff=ff+d*d; 
		}
	}
    ///////////////////////////////////////
    ff=sqrt(2.0*ff);
///////////////////////////////////////////////////////////////////
logo0:                                                      ///////
    
	ff=ff/(1.0*m_nNumColumns);
//////////////////////////////////////////
logo1:                              //////

    for (i=1; i<=m_nNumColumns-1; i++)
	{
		for (j=0; j<=i-1; j++)
        { 
			d=fabs(m_pData[i*m_nNumColumns+j]);
            if (d>ff)
            { 
				p=i; 
				q=j;
                goto logo2;
            }
        }
	}
    ///////////////////////////////////////////////    
	if (ff<eps) 
	{
		for (i=0; i<m_nNumColumns; ++i)
			dblEigenValue[i] = GetElement(i,i);
		return TRUE;
	}
    
	goto logo0;
///////////////////////////////////////////////
logo2:                                    /////
		
	u=p*m_nNumColumns+q; 
	w=p*m_nNumColumns+p; 
	t=q*m_nNumColumns+p; 
	s=q*m_nNumColumns+q;
	///////////////////////////////
    x=-m_pData[u]; 
	y=(m_pData[s]-m_pData[w])/2.0;
	///////////////////////////////
    omega=x/sqrt(x*x+y*y);
    if (y<0.0) 
		omega=-omega;
    ////////////////////////////////
	sn=1.0+sqrt(1.0-omega*omega);
    sn=omega/sqrt(2.0*sn);
    cn=sqrt(1.0-sn*sn);
    fm=m_pData[w];
	//////////////////////////////////////////////////////
    m_pData[w]=fm*cn*cn+m_pData[s]*sn*sn+m_pData[u]*omega;
    m_pData[s]=fm*sn*sn+m_pData[s]*cn*cn-m_pData[u]*omega;
    m_pData[u]=0.0; m_pData[t]=0.0;
    //////////////////////////////////////////////////////
	for (j=0; j<=m_nNumColumns-1; j++)
	{
		if ((j!=p)&&(j!=q))
		{ 
			u=p*m_nNumColumns+j; 
			w=q*m_nNumColumns+j;
			fm=m_pData[u];
			m_pData[u]=fm*cn+m_pData[w]*sn;
			m_pData[w]=-fm*sn+m_pData[w]*cn;
		}
	}
    //////////////////////////////////////////////////////
    for (i=0; i<=m_nNumColumns-1; i++)
    {
		if ((i!=p)&&(i!=q))
        { 
			u=i*m_nNumColumns+p; 
			w=i*m_nNumColumns+q;
			fm=m_pData[u];
			m_pData[u]=fm*cn+m_pData[w]*sn;
			m_pData[w]=-fm*sn+m_pData[w]*cn;
        }
	}
    /////////////////////////////////////////////////////
	for (i=0; i<=m_nNumColumns-1; i++)          /////////
    { 
		u=i*m_nNumColumns+p; 
		w=i*m_nNumColumns+q;
        fm=mtxEigenVector.m_pData[u];
        mtxEigenVector.m_pData[u]=fm*cn+mtxEigenVector.m_pData[w]*sn;
        mtxEigenVector.m_pData[w]=-fm*sn+mtxEigenVector.m_pData[w]*cn;
	}

	goto logo1;
                                                                                     //////////////
}                                                                                    ///////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////