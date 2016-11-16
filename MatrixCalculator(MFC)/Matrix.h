/*********************************************************************************\
*                             Matrix.h                                            *
*矩阵类的声明                                                                     *
*Programer：ansleliu                               Date：2011-11-10&11&12&13      *                   
\*********************************************************************************/ 
#ifndef MATRIX_H
#define MATRIX_H
//////////////////////////////////
#include "stdafx.h"
#include "MatrixCalculator.h"
#include "MatrixCalculatorDlg.h"
////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_MATRIX_H__ACEC32EA_5254_4C23_A8BD_12F9220EF43A__INCLUDED_)
#define AFX_MATRIX_H__ACEC32EA_5254_4C23_A8BD_12F9220EF43A__INCLUDED_
////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
///////////////////////////
#include <math.h>
///////////////////////////
#if !defined(_BITSET_)
#include <bitset>                                                                    ///////
#endif // !defined(_BITSET_)                                                         ///////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                   ///////
//(-- class CTokenizer                                                               ///////
//
class CTokenizer
{
/////////////////////////////////////////////////////////////////////////
public:                                                          ////////
	CTokenizer(const CString& cs, const CString& csDelim) : m_cs(cs), m_nCurPos(0)
	{
		SetDelimiters(csDelim);
	}
	void SetDelimiters(const CString& csDelim)
	{
		for(int i = 0; i < csDelim.GetLength(); ++i)
			m_sDelimiter.set(static_cast<BYTE>(csDelim[i]));
	}
    ////////////////////////////////////////////////////////////////////////
	bool Next(CString& cs)                                           ///////
	{
		cs.Empty();

		while(m_nCurPos < m_cs.GetLength() && m_sDelimiter[static_cast<BYTE>(m_cs[m_nCurPos])])
			++m_nCurPos;

		if(m_nCurPos >= m_cs.GetLength())
			return FALSE;

		int nStartPos = m_nCurPos;
		while(m_nCurPos < m_cs.GetLength() && !m_sDelimiter[static_cast<BYTE>(m_cs[m_nCurPos])])
			++m_nCurPos;
		
		cs = m_cs.Mid(nStartPos, m_nCurPos - nStartPos);

		return TRUE;
	}
    ////////////////////////////////////////////////////////////////
	CString	Tail() const                                       /////
	{
		int nCurPos = m_nCurPos;

		while(nCurPos < m_cs.GetLength() && m_sDelimiter[static_cast<BYTE>(m_cs[nCurPos])])
			++nCurPos;

		CString csResult;

		if(nCurPos < m_cs.GetLength())
			csResult = m_cs.Mid(nCurPos);

		return csResult;
	}
////////////////////////////////////////////////////////
private:                                         ///////
	CString m_cs;
	std::bitset<256> m_sDelimiter;
	int m_nCurPos;
};
//                                                                                             ///////
//--) // class CTokenizer                                                                      ///////
//                                                                                             ///////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                             ///////
//(-- class Matrix                                                                             ///////
//                                                                                             ///////
class Matrix  
{
public:
	///////////////////////////////////////////////////////////////////////////
	// 构造与析构                                                       ///////
	Matrix();										// 基础构造函数
	Matrix(int nRows, int nCols);					// 指定行列构造函数
	Matrix(const Matrix& other);					// 拷贝构造函数
	bool Initialization(int nRows, int nCols);		// 初始化矩阵	
	virtual ~Matrix();								// 析构函数
	////////////////////////////////////////////////////////////////////////////////
	// 输入与显示                                                            ///////
	// 将字符串转换为矩阵数据
	bool FromString(CString s, const CString& sDelim = " ", bool bLineBreak = TRUE);	
	// 将矩阵转换为字符串
	CString ToString(const CString& sDelim = " ", bool bLineBreak = TRUE) const;
	// 将矩阵的指定列转换为字符串
	CString ColToString(int nCol, const CString& sDelim = " ") const;

	////////////////////////////////////////////////////////////////////////////////////
	// 元素与值操作                                                                /////
	bool	SetElement(int nRow, int nCol, double value);	// 设置指定元素的值
	double	GetElement(int nRow, int nCol) const;			// 获取指定元素的值
	int		GetNumColumns() const;							// 获取矩阵的列数
	int		GetNumRows() const;								// 获取矩阵的行数

	//////////////////////////////////////////////////////////////////////
	// 数学操作                                                      /////
	Matrix& operator=(const Matrix& other);
	Matrix	operator+(const Matrix& other) const;
	Matrix	operator-(const Matrix& other) const;
	Matrix	operator*(double value) const;
	Matrix	operator*(const Matrix& other) const;	
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	// 运算                                                                                           //////
	Matrix Transpose() const;                                                                  // 矩阵的转置	
	Matrix Exponentiation (int n);                                                           // 矩阵的幂运算
	friend Matrix Cofactor(const Matrix &matrix,int,int);                             //设置成友元的求余子式
	friend double AlgebraCofactor(const Matrix &matrix,int ,int);                 //设置成友元的求代数余子式
	friend double Det(Matrix &matrix);                                          //设置成友元的递归求行列式值
	friend Matrix Inv(Matrix &matrix);                                              //设置成友元的求矩阵的逆
	friend Matrix Rref(Matrix &matrix);                                       //设置成友元的矩阵的初等行变换
	friend int Rank(Matrix &matrix);                                                  //设置成友元的矩阵求秩
	//////////////////////////////////////////////////////////////求实对称矩阵特征值与特征向量的雅可比过关法
	bool FindEigenvaluesEigenvectors(double dblEigenValue[], Matrix& mtxEigenVector, double eps = 0.000001);
/////////////////////////////////////////////////////////
// 保护性数据成员                                    ////
protected:
	int	m_nNumColumns;			// 矩阵列数
	int	m_nNumRows;				// 矩阵行数
	double*	m_pData;			// 矩阵数据缓冲区
};
//                                                                                                      /////
//--) // class Matrix                                                                                   /////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // MATRIX_H 
#endif // !defined(AFX_MATRIX_H__ACEC32EA_5254_4C23_A8BD_12F9220EF43A__INCLUDED_)