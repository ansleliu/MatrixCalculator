/*********************************************************************************\
*                                 Control.cpp                                     *
*  描述：控制类成员函数定义                                                       *
*  Programer：L                      Date：2011-11-03                     *                   
\*********************************************************************************/
#include<iostream>
#include"Matrix.h"
#include"Control.h"  
using namespace std; //
/////////////////////// 

//=================================================================================
//                                   创建主矩阵                                   =
//date:2011-11-03                                                                 =
//=================================================================================                                                                        
Matrix CreateMainMatrix()
 {  
	int m ,n;
	cout<<">>请输入主运算矩阵matrix（main）的行、列数: ";       
	cin>>m>>n;                                                
	Matrix matrix1(m,n);
	cout <<">>请为matrix（main）输入元素:" <<endl;
	matrix1.InPut(); 
    cout <<">>matrix（main）=" <<endl;
	matrix1.Show();
	return matrix1;
}
//=================================================================================
//                                 输出菜单选项                                   =
//date:2011-11-03                                                                 =
//=================================================================================            
void OutputMenuOption()
{
	cout<<"************************************************************************"<<endl
		<<"*                请选择您想要对主矩阵进行的运算                        *"<<endl
		<<"************************************************************************"<<endl
		<<"*             一.输入 + 计算两个矩阵的和;                              *"<<endl
		<<"*             二.输入 - 计算两个矩阵的差;                              *"<<endl
		<<"*             三.输入 * 计算两个矩阵的积;                              *"<<endl
		<<"*             四.输入 T 输出矩阵的转置;                                *"<<endl
		<<"*             五.输入 E 计算矩阵的幂运算;                              *"<<endl
		<<"*             六.输入 F 计算矩阵的行列式代数余子式;                    *"<<endl
		<<"*             七.输入 D 计算矩阵的行列式值;                            *"<<endl
		<<"*             八.输入 I 计算矩阵的逆;                                  *"<<endl
		<<"*             九.输入 N 计算矩阵的数乘;                                *"<<endl
		<<"*             十.输入 R 矩阵的初等行变换求秩;                          *"<<endl
		<<"*           十一.输入 A 重新执行程序;                                  *"<<endl
		<<"*             零.输入 O 结束执行程序;                                  *"<<endl
		<<"************************************************************************"<<endl;
}
//=================================================================================
//                         实现矩阵加法运算的操作                                 =
//date:2011-11-03                                                                 =
//=================================================================================            
Matrix Addition(const Matrix &matrix)
{   int m=matrix.row;
    int n=matrix.col;
	Matrix matrix2(m,n);
	Matrix matrix3(m,n);
	cout <<">>请为matrix（+）输入元素:"<<endl; 
	matrix2.InPut(); 
    cout <<">>matrix（+）=" <<endl;
	matrix2.Show();
	matrix3=matrix+matrix2;
	cout<<">>matrix（main）和matrix（+）的和为："
		<<endl<<">>Matrix(+)="<<endl;
	return matrix3;
}
//=================================================================================
//                       实现矩阵减法运算的操作                                   =
//date:2011-11-03                                                                 =
//=================================================================================            
Matrix Subtraction(const Matrix &matrix)
{
	int m=matrix.row;
    int n=matrix.col;
	Matrix matrix4(m,n);
	Matrix matrix5(m,n);
	cout <<">>请为matrix（-）输入元素:"<<endl; 
	matrix4.InPut(); 
	cout <<">>matrix（-）:" <<endl; 
	matrix4.Show();
	matrix5=matrix-matrix4;
	cout<<">>matrix（main）和matrix（-）的差为："
		<<endl<<">>Matrix（-）="<<endl;
	return matrix5;
}
//=================================================================================
//                       实现矩阵乘法运算的操作                                   =
//date:2011-11-03                                                                 =
//=================================================================================            
Matrix Multiplication(const Matrix &matrix)
{
	int m=matrix.row;
    int n=matrix.col;
	int q ;
	cout<<">>请输入与主矩阵相乘的矩阵matrix（*）的>列数<：";
	cin>>q;
	Matrix matrix6(n,q);
	Matrix matrix7(m,q);
	cout <<">>请为matrix（*）输入元素:" <<endl; 
	matrix6.InPut();
	cout <<">>matrix（*）:" <<endl; 
	matrix6.Show();
	matrix7=matrix*matrix6;
	cout<<">>matrix（main）和matrix（*）的乘积为："
		<<endl<<">>Matrix（*）="<<endl;
	return matrix7;
}
//=================================================================================
//                           实现矩阵数乘运算的操作                               =
//date:2011-11-04                                                                 =
//=================================================================================            
Matrix NumMultiplication(const Matrix &matrix)
{
	int m=matrix.row;
    int n=matrix.col;
	double number;
	cout<<">>请输入与主矩阵相乘的数 number ：";
	cin>>number;
	Matrix matrix8(m,n);
	matrix8=matrix*number;
	cout<<">>主矩阵matrix（main）与数"<<n<<"相乘的结果为："<<endl;
	return matrix8;
}
//=================================================================================
//                        实现矩阵转置运算的操作                                  =
//date:2011-11-04                                                                 =
//=================================================================================            
Matrix Transposetion(const Matrix &matrix)
{
	int m=matrix.row;
    int n=matrix.col;
	cout<<">>matrix（main）的转置为："<<endl;
	return Transpose(matrix);
}
//=================================================================================
//                            实现矩阵幂运算的操作                                =
//date:2011-11-04                                                                 =
//=================================================================================            
Matrix Exponentiation(const Matrix &matrix)
{
	int n;
	cout<<">>请输入幂运算次数：";
	cin>>n;
	cout<<">>主矩阵matrix（main）的"<<n<<"次幂为："<<endl;
	return Exponentiation(matrix , n);
}
//=================================================================================
//                           实现矩阵求逆运算的操作                               =
//date:2011-11-04                                                                 =
//=================================================================================
void Inverse( Matrix &matrix)
{
	int m=matrix.row;
    int n=matrix.col;
	if (m != n)
	{
		cerr<<">>!不是方阵，没有逆!"<<endl;
//		cout<<"该运算返回主矩阵matrix（main）."
//		return matrix;
	}
	else 
	{
		long double det = Det(matrix);
		if (det == 0)  //如果行列式的值为0，则没有逆
		{
			cerr<<">>!此矩阵没有逆!"<<endl;
//			return matrix;
//		    cerr<<">>!求矩阵逆退出!";
		}
		else
		{
			cout<<">>主矩阵matrix（main）的逆为："<<endl;
			Inv(matrix).Show();
		}
	}
}
//=================================================================================
//                            求代数余子式操作                                    =
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
		cerr<<">>!不是方阵，不能求其行列式的代数余子式!"<<endl;
	else 
	{
logo:	cout<<">>请您输入要划去的行的行数和列的列数：";
	    cin>>Specifiedrow>> Specifiedcol;
		if(Specifiedrow>m || Specifiedcol>n || Specifiedrow<0 || Specifiedcol<0)
		{
			cout<<">>！您的输入有错误！"<<endl;
			goto logo;
		}
		/////////////////////////////////////////////////////////////////////////
		else
		M=AlgebraCofactor(matrix,Specifiedrow,Specifiedcol);
	}
    ////////////////////////////////////////////////////////////////
	cout<<">>主矩阵matrix（main）的行列式指定行和列的代数余子式为："
		<<M<<endl;
}
//=================================================================================
//                       实现求矩阵行列式值运算的操作                             =
//date:2011-11-04                                                                 =
//=================================================================================            
void Determinant( Matrix &matrix)
{
	int m=matrix.row;
    int n=matrix.col;
	long double D;
	if (m != n)
	{
        cerr<<">>!不是方阵，没有行列式!"<<endl;
	}
	else
	{
		D=Det(matrix);
		cout<<">>主矩阵matrix（main）的行列式值为："
            <<D<<endl;
	}
}
//=================================================================================
//                    实现矩阵初等变换和求秩运算的操作                            =
//date:2011-11-04                                                                 =
//=================================================================================            
void ElementaryTransformation( Matrix &matrix)
{
	int R;
//	cout<<"主矩阵matrix（main）的行阶梯最简形式为："<<endl;
//	Rref(matrix1).Show();
	R=Rank(matrix);
    cout<<">>主矩阵matrix（main）的秩："<<R<<endl;
}
