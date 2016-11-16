/*********************************************************************************\
*                                   Matrix.cpp                                    *
*  描述：矩阵类成员函数的定义                                                     *
*                                                                                 *    
*  Programer：ansleliu                       Date：2011-11-12                     *                   
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
//                             基本构造函数                                       =    
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
//                         指定行列构造函数                                      =
// 参数：                                                                        =
//  1. int nRows - 指定的矩阵行数           2. int nCols - 指定的矩阵列数        =            
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
//                         拷贝构造函数                                         =                     
// 参数：                                                                       =
// 1. const Matrix& other - 源矩阵                                              =
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
//                            析构函数                                        =
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
//                           初始化函数                                       =                           
// 参数：                                                                     =
// 1. int nRows - 指定的矩阵行数     2. int nCols - 指定的矩阵列数            =
// 返回值：bool 型，初始化是否成功                                            =
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
	// 分配内存
	m_pData = new double[nSize];
	///////////////////////////////////////////////////
	if (m_pData == NULL)
		return FALSE;					// 内存分配失败
	if (IsBadReadPtr(m_pData, sizeof(double) * nSize))
		return FALSE;
    ///////////////////////////////////////////////////
	// 将各元素值置0
	memset(m_pData, 0, sizeof(double) * nSize);

	return TRUE;
}
//=============================================================================
//                    将字符串转化为矩阵的值                                  =
// 参数：                                                                     =
// 1. CString s - 数字和分隔符构成的字符串                                    =
// 2. const CString& sDelim - 数字之间的分隔符，默认为空格                    =
// 3. bool bLineBreak - 行与行之间是否有回车换行符，默认为                    =
//   真(有换行符)当该参数为FALSE时，所有元素值都在一行中输入，                =
//   字符串的第一个 数值应为矩阵的行数，第二个数值应为矩阵的列数              =
// 返回值：bool 型，转换是否成功                                              =
//=============================================================================
bool Matrix::FromString(CString s, const CString& sDelim , bool bLineBreak)
{
	if (s.IsEmpty())
		return FALSE;
   //////////////////////////////////////
	// 分行处理
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
		// 行数
		m_nNumRows = ListRow.GetCount();

		sRow = ListRow.GetHead();
		CTokenizer tkRow(sRow, sDelim);
		CString sElement;
		/////////////////////////////////////////
		// 列数
		m_nNumColumns = 1;
		while (tkRow.Next(sElement))
		{
			m_nNumColumns++;
		}
		m_nNumColumns-=1;
        ///////////////////////////////////////////
		// 初始化矩阵
		if (! Initialization(m_nNumRows, m_nNumColumns))
			return FALSE;
        ///////////////////////////////////////////
		// 设置值
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
//                        将矩阵各元素的值转化为字符串                        =        
// 参数：                                                                     =
// 1. const CString& sDelim - 数字之间的分隔符，默认为空格                    =
// 2 bool bLineBreak - 行与行之间是否有回车换行符，默认为真(有换行符)         =
// 返回值：CString 型，转换得到的字符串                                       =
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
///////                           辅助函数                                               //////
///////                                                                                  //////
//=============================================================================
//                   将矩阵指定列中各元素的值转化为字符串                     =
// 参数：                                                                     =
// 1. int nCol - 指定的矩阵行，nCol = 0表示第一列                             =
// 2. const CString& sDelim - 数字之间的分隔符，默认为空格                    =
// 返回值：CString 型，转换得到的字符串                                       =
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
//                          设置指定元素的值                                  =                         
// 参数：                                                                     =
// 1. int nRows - 指定的矩阵行数                                              =
// 2. int nCols - 指定的矩阵列数                                              =
// 3. double value - 指定元素的值                                             =
// 返回值：bool 型，说明设置是否成功                                          =
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
//                            获取指定元素的值                                =
// 参数：                                                                     =
// 1. int nRows - 指定的矩阵行数                                              =
// 2. int nCols - 指定的矩阵列数                                              =
// 返回值：double 型，指定元素的值                                            =
//=============================================================================
double Matrix::GetElement(int nRow, int nCol) const
{
	return m_pData[nCol + nRow * m_nNumColumns] ;
}

//=============================================================================
//                           获取矩阵的列数                                   =
// 返回值：int 型，矩阵的列数                                                 =
//=============================================================================
int	Matrix::GetNumColumns() const
{
	return m_nNumColumns;
}
//=============================================================================
//                          获取矩阵的行数                                    =
// 返回值：int 型，矩阵的行数                                                 =
//=============================================================================
int	Matrix::GetNumRows() const
{
	return m_nNumRows;
}                                                                                        //////
///////////////////////////////////////////////////////////////////////////////////////////////
///////                              运算                                                //////
///////                                                                                  //////
//=============================================================================
//                        重载运算符=，给矩阵赋值                             =
// 参数：                                                                     =
// 1. const Matrix& other - 用于给矩阵赋值的源矩阵                            =
// 返回值：Matrix型的引用，所引用的矩阵与other相等                            =
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
//                      重载运算符+，实现矩阵的加法                           =
// 参数：                                                                     =
// 1. const Matrix& other - 与指定矩阵相加的矩阵                              =
// 返回值：Matrix型，指定矩阵与other相加之和                                  =
//=============================================================================
Matrix	Matrix::operator+(const Matrix& other) const
{
	// 首先检查行列数是否相等
	if(m_nNumColumns != other.GetNumColumns() || m_nNumRows != other.GetNumRows())
	{
		CString str1=">>辅助运算矩阵的行列数与主操作矩阵不相等，无法进行相加操作!\r\n将返回原主操作矩阵!";
		AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
		return *this;
	}
    else
	{
		// 构造结果矩阵
		Matrix	result(*this) ;		// 拷贝构造
		// 矩阵加法
		for (int i = 0 ; i < m_nNumRows ; ++i)
		{
			for (int j = 0 ; j <  m_nNumColumns; ++j)
				result.SetElement(i, j, result.GetElement(i, j) + other.GetElement(i, j)) ;
		}
		return result ;
	}
}
//=============================================================================
//                    重载运算符-，实现矩阵的减法                             =
// 参数：                                                                     =
// 1. const Matrix& other - 与指定矩阵相减的矩阵                              =
// 返回值：Matrix型，指定矩阵与other相减之差                                  =
//=============================================================================
Matrix	Matrix::operator-(const Matrix& other) const
{
	// 首先检查行列数是否相等
	if(m_nNumColumns != other.GetNumColumns() || m_nNumRows != other.GetNumRows())
	{
		CString str1=">>辅助运算矩阵的行列数与主操作矩阵不相等，无法进行相减操作!\r\n将返回原主操作矩阵!";
		AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
		return *this;
	}
    else
	{
		// 构造目标矩阵
		Matrix	result(*this) ;		// copy ourselves
		// 进行减法操作
		for (int i = 0 ; i < m_nNumRows ; ++i)
		{
			for (int j = 0 ; j <  m_nNumColumns; ++j)
				result.SetElement(i, j, result.GetElement(i, j) - other.GetElement(i, j)) ;
		}
	    return result ;
	}
}
//=============================================================================
//                    重载运算符*，实现矩阵的数乘                             =
// 参数：                                                                     =
// 1. double value - 与指定矩阵相乘的实数                                     =
// 返回值：Matrix型，指定矩阵与value相乘之积                                  =
//=============================================================================
Matrix	Matrix::operator*(double value) const
{
	// 构造目标矩阵
	Matrix	result(*this) ;	
	// 进行数乘
	for (int i = 0 ; i < m_nNumRows ; ++i)
	{
		for (int j = 0 ; j <  m_nNumColumns; ++j)
			result.SetElement(i, j, result.GetElement(i, j)*value) ;
	}
	return result ;
}

//=============================================================================
//                          重载运算符*，实现矩阵的乘法                       =
// 参数：                                                                     =
// 1. const Matrix& other - 与指定矩阵相乘的矩阵                              =
// 返回值：Matrix型，指定矩阵与other相乘之积                                  =
//=============================================================================
Matrix	Matrix::operator*(const Matrix& other) const
{
	// 首先检查行列数是否符合要求
	if (m_nNumColumns != other.GetNumRows())
	{
		CString str1=">>辅助运算矩阵的行列数与主操作矩阵不匹配，无法进行相乘操作!\r\n将返回原主操作矩阵!";
		AfxMessageBox(str1, MB_OK|MB_ICONINFORMATION);
		return *this;
	}
    else
	{   // 构造目标矩阵
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
//                          矩阵的转置                                        =                           
// 返回值：CMatrix型，指定矩阵转置矩阵                                        =
//=============================================================================
Matrix Matrix::Transpose() const
{
	// 构造目标矩阵
	Matrix	Trans(m_nNumColumns, m_nNumRows);

	// 转置各元素
	for (int i = 0 ; i < m_nNumRows ; ++i)
	{
		for (int j = 0 ; j < m_nNumColumns ; ++j)
			Trans.SetElement(j, i, GetElement(i, j)) ;
	}
	return Trans;
}
//=================================================================================
//                               矩阵求幂运算                                     =
// 参数：                                                                         =
// 1. int n - 矩阵的幂数                                                          =
// 返回值：Matrix型，主操作矩阵求幂运算结果                                       =
//=================================================================================
Matrix Matrix::Exponentiation(int n)
{
	// 构造目标矩阵
	Matrix Expon(*this);
   //////////////////////////////////////////////////////////
    if(n <= 0)
	{
		CString str1=">>幂数不可以为负数，将返回原主操作矩阵，请重新输入!";
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
//                               矩阵求余子式                                     =
// 参数：                                                                         =
//      1. const Matrix &matrix被操作矩阵                                         =
//      2. int Specifiedrow  指定行                                               =
//      3. int Specifiedcol  指定列                                               =
// 返回值：                                                                       =
//         double型，被操作矩阵求余子式结果                                       =
// 作用：                                                                         =
//      1.被double Det(Matrix &matrix)内部调用                                    =
//      2.被Matrix Inv( Matrix &matrix)内部调用                                   =
// date:2011-10-19                                                                =
//=================================================================================
 Matrix Cofactor(const Matrix &matrix, int Specifiedrow, int Specifiedcol)
 {
	int temp_R = matrix.GetNumRows()-1;//存储矩阵的行 
    int temp_C = matrix.GetNumColumns()-1; //存储矩阵的列

	/////////////////////////////////////////////////////////
	Matrix temp(temp_R,temp_C); //创建临时对象存储矩阵的余子式
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
//                              矩阵求代数余子式                                  =
// 参数：                                                                         =
//      1. const Matrix &matrix被操作矩阵                                         =
//      2. int Specifiedrow  指定行                                               =
//      3. int Specifiedcol  指定列                                               =
// 返回值：                                                                       =
//         double型，被操作矩阵求余子式结果                                       =
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
//                           递归求行列式值                                       =
// 参数：                                                                         =
//      1. const Matrix &matrix被操作矩阵                                         =
// 返回值：                                                                       =
//         double型，被操作矩阵求行列式值结果                                     =
//=================================================================================
double Det(Matrix &matrix)  
{
     double det = 0;
     if (matrix.GetNumRows() != matrix.GetNumColumns())
	  {
		  CString str1="行列数不相同，不是方阵，没有行列式值!\r\n将返回NULL";
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
//                                求矩阵的逆                                      =
// 参数：                                                                         =
//     1.Matrix &matrix  被操作的矩阵                                             =
// 返回值：                                                                       =
//       Matrix型，矩阵求逆的结果                                                 =
//=================================================================================
Matrix Inv( Matrix &matrix) 
{
     int temp_R = matrix.GetNumRows();//存储矩阵的行 
     int temp_C = matrix.GetNumColumns();//存储矩阵的列  
	 Matrix temp(temp_R,temp_C); //创建临时对象存储矩阵的余子式 
     //矩阵的逆 = 伴随矩阵 / 行列式
     double det = Det(matrix);
     //////////////////////////////////////////////////////////
	 if (det == 0)  //如果行列式的值为0，则没有逆
		{
			CString str1="行列式值为零，此矩阵没有逆!\r\n结果将返回主操作矩阵!";
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
//                             矩阵的初等行变换                                   =
// 参数：                                                                         =
//     1.Matrix &matrix  被操作的矩阵                                             =
// 返回值：                                                                       =
//       Matrix型，初等行变换的结果                                               =
//date:2011-10-20 & 21 & 22                                                       =
//=================================================================================
Matrix Rref(Matrix &matrix)
{
	 int temp_R = matrix.GetNumRows();//存储矩阵的行 
     int temp_C = matrix.GetNumColumns();//存储矩阵的列  
	 //////////////////////////////////////////////////////////////////
	 Matrix temp0(temp_R,temp_C); //创建临时对象存储矩阵的余子式
	 Matrix temp(temp_R,temp_C); //创建临时对象存储矩阵的初等变换结果
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
//                                     矩阵求秩                                   =
// 参数：                                                                         =
//     1.Matrix &matrix  被操作的矩阵，经过Rref后传递过来的最简矩阵               =
// 返回值：                                                                       =
//      int型，矩阵的秩                                                           =
//date:2011-10-22                                                                 =
//=================================================================================
int Rank(Matrix &matrix)
{
	int temp_R = matrix.GetNumRows();//存储矩阵的行 
    int temp_C = matrix.GetNumColumns();//存储矩阵的列
	int rank = 0;
	int flag1=0;
	int flag2=0;
    /////////////////////////////////////////////////////////////////
	Matrix temp(temp_R,temp_C); //创建临时对象存储矩阵的初等变换结果
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
//                         求实对称矩阵特征值与特征向量                           =
// 参数：                                                                         =
// 1. double dblEigenValue[] - 一维数组，长度为矩阵的阶数，返回时存放特征值       =
// 2. CMatrix& mtxEigenVector - 返回时存放特征向量矩阵，其中第i列为与             =
//    数组dblEigenValue中第j个特征值对应的特征向量                                =
// 3. double eps - 计算精度，默认值为0.000001                                     =
// 返回值：BOOL型，求解是否成功                                                   =
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