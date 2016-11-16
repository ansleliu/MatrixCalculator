/*********************************************************************************\
*                             Matrix.h                                            *
*矩阵类的声明                                                                     *
*Programer：ansleliu                         Date：2011-10-17&18&19&20&21&22      *                   
\*********************************************************************************/ 
#ifndef MATRIX_H
#define MATRIX_H
///////////////////////////////////////////////////////////////
class Matrix                                                 //
 { 
 private : 
     long double **ptr;//用于动态分配矩阵空间所定义的指针    
 ////////////////////////////////////////////////////////////// 
 public:                                                     //
     Matrix(int R=0, int C=0);//构造函数,动态分配内存存储矩阵元素 
     Matrix(const Matrix &matrix);                 //拷贝构造函数 
     ~Matrix();                               //析构函数,释放内存 
     ////////////////////////////////////
     void InPut();    //输入矩阵元素   //
     void Show()const;//显示矩阵内容 
	 ////////////////////////////////////////////////////////////////////////////////////////////////
     Matrix operator+(const Matrix &matrix)const;   //重载操作符 '+' 实现两个矩阵相加             ///
     Matrix operator-(const Matrix &matrix)const;   //重载操作符 '-' 实现两个矩阵相减 
     Matrix operator*(const Matrix &matrix)const;   //重载操作符 '*' 实现两个矩阵相乘
	 Matrix operator *( const double a) const;          //重载操作符 '*' 实现矩阵数乘
     Matrix& operator=(const Matrix &matrix); //重载赋值操作符 '=' 实现矩阵之间的赋值 
     /////////////////////////////////////////////////////////////////////////////////////////////////
	 friend Matrix Transpose(const Matrix &matrix);                                //矩阵转置函数   //
	 friend Matrix Exponentiation(const Matrix &matrix , int n);           //设置成友元的求幂运算
	 friend Matrix Cofactor(const Matrix &matrix,int,int);                 //设置成友元的求余子式
	 friend long double AlgebraCofactor(const Matrix &matrix,int ,int);//设置成友元的求代数余子式 
	 friend long double Det(Matrix &matrix);                         //设置成友元的递归求行列式值
     friend Matrix Inv(Matrix &matrix);                                  //设置成友元的求矩阵的逆
	 friend Matrix Rref(Matrix &matrix);                           //设置成友元的矩阵的初等行变换
	 friend int Rank(Matrix &matrix);                                      //设置成友元的矩阵求秩
 ////////////////////////////////////////////////////////////
 public:                                                   //
	 int row;                 //矩阵的行数 
     int col;                 //矩阵的列数 
 };
#endif // MATRIX_H 