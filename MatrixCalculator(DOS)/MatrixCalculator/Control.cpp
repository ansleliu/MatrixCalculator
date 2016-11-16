/*********************************************************************************\
*                                 Control.cpp                                     *
*  �������������Ա��������                                                       *
*  Programer��L                      Date��2011-11-03                     *                   
\*********************************************************************************/
#include<iostream>
#include"Matrix.h"
#include"Control.h"  
using namespace std; //
/////////////////////// 

//=================================================================================
//                                   ����������                                   =
//date:2011-11-03                                                                 =
//=================================================================================                                                                        
Matrix CreateMainMatrix()
 {  
	int m ,n;
	cout<<">>���������������matrix��main�����С�����: ";       
	cin>>m>>n;                                                
	Matrix matrix1(m,n);
	cout <<">>��Ϊmatrix��main������Ԫ��:" <<endl;
	matrix1.InPut(); 
    cout <<">>matrix��main��=" <<endl;
	matrix1.Show();
	return matrix1;
}
//=================================================================================
//                                 ����˵�ѡ��                                   =
//date:2011-11-03                                                                 =
//=================================================================================            
void OutputMenuOption()
{
	cout<<"************************************************************************"<<endl
		<<"*                ��ѡ������Ҫ����������е�����                        *"<<endl
		<<"************************************************************************"<<endl
		<<"*             һ.���� + ������������ĺ�;                              *"<<endl
		<<"*             ��.���� - ������������Ĳ�;                              *"<<endl
		<<"*             ��.���� * ������������Ļ�;                              *"<<endl
		<<"*             ��.���� T ��������ת��;                                *"<<endl
		<<"*             ��.���� E ��������������;                              *"<<endl
		<<"*             ��.���� F ������������ʽ��������ʽ;                    *"<<endl
		<<"*             ��.���� D ������������ʽֵ;                            *"<<endl
		<<"*             ��.���� I ����������;                                  *"<<endl
		<<"*             ��.���� N ������������;                                *"<<endl
		<<"*             ʮ.���� R ����ĳ����б任����;                          *"<<endl
		<<"*           ʮһ.���� A ����ִ�г���;                                  *"<<endl
		<<"*             ��.���� O ����ִ�г���;                                  *"<<endl
		<<"************************************************************************"<<endl;
}
//=================================================================================
//                         ʵ�־���ӷ�����Ĳ���                                 =
//date:2011-11-03                                                                 =
//=================================================================================            
Matrix Addition(const Matrix &matrix)
{   int m=matrix.row;
    int n=matrix.col;
	Matrix matrix2(m,n);
	Matrix matrix3(m,n);
	cout <<">>��Ϊmatrix��+������Ԫ��:"<<endl; 
	matrix2.InPut(); 
    cout <<">>matrix��+��=" <<endl;
	matrix2.Show();
	matrix3=matrix+matrix2;
	cout<<">>matrix��main����matrix��+���ĺ�Ϊ��"
		<<endl<<">>Matrix(+)="<<endl;
	return matrix3;
}
//=================================================================================
//                       ʵ�־����������Ĳ���                                   =
//date:2011-11-03                                                                 =
//=================================================================================            
Matrix Subtraction(const Matrix &matrix)
{
	int m=matrix.row;
    int n=matrix.col;
	Matrix matrix4(m,n);
	Matrix matrix5(m,n);
	cout <<">>��Ϊmatrix��-������Ԫ��:"<<endl; 
	matrix4.InPut(); 
	cout <<">>matrix��-��:" <<endl; 
	matrix4.Show();
	matrix5=matrix-matrix4;
	cout<<">>matrix��main����matrix��-���Ĳ�Ϊ��"
		<<endl<<">>Matrix��-��="<<endl;
	return matrix5;
}
//=================================================================================
//                       ʵ�־���˷�����Ĳ���                                   =
//date:2011-11-03                                                                 =
//=================================================================================            
Matrix Multiplication(const Matrix &matrix)
{
	int m=matrix.row;
    int n=matrix.col;
	int q ;
	cout<<">>����������������˵ľ���matrix��*����>����<��";
	cin>>q;
	Matrix matrix6(n,q);
	Matrix matrix7(m,q);
	cout <<">>��Ϊmatrix��*������Ԫ��:" <<endl; 
	matrix6.InPut();
	cout <<">>matrix��*��:" <<endl; 
	matrix6.Show();
	matrix7=matrix*matrix6;
	cout<<">>matrix��main����matrix��*���ĳ˻�Ϊ��"
		<<endl<<">>Matrix��*��="<<endl;
	return matrix7;
}
//=================================================================================
//                           ʵ�־�����������Ĳ���                               =
//date:2011-11-04                                                                 =
//=================================================================================            
Matrix NumMultiplication(const Matrix &matrix)
{
	int m=matrix.row;
    int n=matrix.col;
	double number;
	cout<<">>����������������˵��� number ��";
	cin>>number;
	Matrix matrix8(m,n);
	matrix8=matrix*number;
	cout<<">>������matrix��main������"<<n<<"��˵Ľ��Ϊ��"<<endl;
	return matrix8;
}
//=================================================================================
//                        ʵ�־���ת������Ĳ���                                  =
//date:2011-11-04                                                                 =
//=================================================================================            
Matrix Transposetion(const Matrix &matrix)
{
	int m=matrix.row;
    int n=matrix.col;
	cout<<">>matrix��main����ת��Ϊ��"<<endl;
	return Transpose(matrix);
}
//=================================================================================
//                            ʵ�־���������Ĳ���                                =
//date:2011-11-04                                                                 =
//=================================================================================            
Matrix Exponentiation(const Matrix &matrix)
{
	int n;
	cout<<">>�����������������";
	cin>>n;
	cout<<">>������matrix��main����"<<n<<"����Ϊ��"<<endl;
	return Exponentiation(matrix , n);
}
//=================================================================================
//                           ʵ�־�����������Ĳ���                               =
//date:2011-11-04                                                                 =
//=================================================================================
void Inverse( Matrix &matrix)
{
	int m=matrix.row;
    int n=matrix.col;
	if (m != n)
	{
		cerr<<">>!���Ƿ���û����!"<<endl;
//		cout<<"�����㷵��������matrix��main��."
//		return matrix;
	}
	else 
	{
		long double det = Det(matrix);
		if (det == 0)  //�������ʽ��ֵΪ0����û����
		{
			cerr<<">>!�˾���û����!"<<endl;
//			return matrix;
//		    cerr<<">>!��������˳�!";
		}
		else
		{
			cout<<">>������matrix��main������Ϊ��"<<endl;
			Inv(matrix).Show();
		}
	}
}
//=================================================================================
//                            ���������ʽ����                                    =
//date:2011-11-05                                                                 =
//=================================================================================       
void FindAlgebraCofactor(const Matrix &matrix)
{
    long double M;
	int m=matrix.row;
    int n=matrix.col;
	int Specifiedrow;
	int Specifiedcol;
	//////////////////////////////////////////////////////////
	if (m != n)
		cerr<<">>!���Ƿ��󣬲�����������ʽ�Ĵ�������ʽ!"<<endl;
	else 
	{
logo:	cout<<">>��������Ҫ��ȥ���е��������е�������";
	    cin>>Specifiedrow>> Specifiedcol;
		if(Specifiedrow>m || Specifiedcol>n || Specifiedrow<0 || Specifiedcol<0)
		{
			cout<<">>�����������д���"<<endl;
			goto logo;
		}
		/////////////////////////////////////////////////////////////////////////
		else
		M=AlgebraCofactor(matrix,Specifiedrow,Specifiedcol);
	}
    ////////////////////////////////////////////////////////////////
	cout<<">>������matrix��main��������ʽָ���к��еĴ�������ʽΪ��"
		<<M<<endl;
}
//=================================================================================
//                       ʵ�����������ʽֵ����Ĳ���                             =
//date:2011-11-04                                                                 =
//=================================================================================            
void Determinant( Matrix &matrix)
{
	int m=matrix.row;
    int n=matrix.col;
	long double D;
	if (m != n)
	{
        cerr<<">>!���Ƿ���û������ʽ!"<<endl;
	}
	else
	{
		D=Det(matrix);
		cout<<">>������matrix��main��������ʽֵΪ��"
            <<D<<endl;
	}
}
//=================================================================================
//                    ʵ�־�����ȱ任����������Ĳ���                            =
//date:2011-11-04                                                                 =
//=================================================================================            
void ElementaryTransformation( Matrix &matrix)
{
	int R;
//	cout<<"������matrix��main�����н��������ʽΪ��"<<endl;
//	Rref(matrix1).Show();
	R=Rank(matrix);
    cout<<">>������matrix��main�����ȣ�"<<R<<endl;
}
