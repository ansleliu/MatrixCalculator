/*********************************************************************************\
*                             Matrix.h                                            *
*�����������                                                                     *
*Programer��ansleliu                               Date��2011-11-10&11&12&13      *                   
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
	// ����������                                                       ///////
	Matrix();										// �������캯��
	Matrix(int nRows, int nCols);					// ָ�����й��캯��
	Matrix(const Matrix& other);					// �������캯��
	bool Initialization(int nRows, int nCols);		// ��ʼ������	
	virtual ~Matrix();								// ��������
	////////////////////////////////////////////////////////////////////////////////
	// ��������ʾ                                                            ///////
	// ���ַ���ת��Ϊ��������
	bool FromString(CString s, const CString& sDelim = " ", bool bLineBreak = TRUE);	
	// ������ת��Ϊ�ַ���
	CString ToString(const CString& sDelim = " ", bool bLineBreak = TRUE) const;
	// �������ָ����ת��Ϊ�ַ���
	CString ColToString(int nCol, const CString& sDelim = " ") const;

	////////////////////////////////////////////////////////////////////////////////////
	// Ԫ����ֵ����                                                                /////
	bool	SetElement(int nRow, int nCol, double value);	// ����ָ��Ԫ�ص�ֵ
	double	GetElement(int nRow, int nCol) const;			// ��ȡָ��Ԫ�ص�ֵ
	int		GetNumColumns() const;							// ��ȡ���������
	int		GetNumRows() const;								// ��ȡ���������

	//////////////////////////////////////////////////////////////////////
	// ��ѧ����                                                      /////
	Matrix& operator=(const Matrix& other);
	Matrix	operator+(const Matrix& other) const;
	Matrix	operator-(const Matrix& other) const;
	Matrix	operator*(double value) const;
	Matrix	operator*(const Matrix& other) const;	
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ����                                                                                           //////
	Matrix Transpose() const;                                                                  // �����ת��	
	Matrix Exponentiation (int n);                                                           // �����������
	friend Matrix Cofactor(const Matrix &matrix,int,int);                             //���ó���Ԫ��������ʽ
	friend double AlgebraCofactor(const Matrix &matrix,int ,int);                 //���ó���Ԫ�����������ʽ
	friend double Det(Matrix &matrix);                                          //���ó���Ԫ�ĵݹ�������ʽֵ
	friend Matrix Inv(Matrix &matrix);                                              //���ó���Ԫ����������
	friend Matrix Rref(Matrix &matrix);                                       //���ó���Ԫ�ľ���ĳ����б任
	friend int Rank(Matrix &matrix);                                                  //���ó���Ԫ�ľ�������
	//////////////////////////////////////////////////////////////��ʵ�Գƾ�������ֵ�������������ſɱȹ��ط�
	bool FindEigenvaluesEigenvectors(double dblEigenValue[], Matrix& mtxEigenVector, double eps = 0.000001);
/////////////////////////////////////////////////////////
// ���������ݳ�Ա                                    ////
protected:
	int	m_nNumColumns;			// ��������
	int	m_nNumRows;				// ��������
	double*	m_pData;			// �������ݻ�����
};
//                                                                                                      /////
//--) // class Matrix                                                                                   /////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // MATRIX_H 
#endif // !defined(AFX_MATRIX_H__ACEC32EA_5254_4C23_A8BD_12F9220EF43A__INCLUDED_)