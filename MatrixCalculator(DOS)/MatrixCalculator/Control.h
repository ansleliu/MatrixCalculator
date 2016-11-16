//=================================================================================
//                             Control.h                                           
// 描述： 控制类的声明                                                             
//       它继承于Matrix类，是Matrix类的public子类                                 
//Programer：L                                                       
//================================================================================= 
#ifndef CONTROL_H
#define CONTROL_H
//---------------------------------------------------------------------------------
class Control :public Matrix
 { 
 //--------------------------------------------------------------------------------
 public:                                              //---------------------------
	  friend Matrix CreateMainMatrix();//创建主矩阵
	  friend void OutputMenuOption();//输出菜单选项
      //---------------------------------------------------------------------------
	                                                                        //
	  friend Matrix Addition(const Matrix &matrix);         //实现矩阵加法运算的操作
      friend Matrix Subtraction(const Matrix &matrix);      //实现矩阵减法运算的操作
	  friend Matrix Multiplication(const Matrix &matrix);   //实现矩阵乘法运算的操作
	  friend Matrix NumMultiplication(const Matrix &matrix);//实现矩阵数乘运算的操作
	  friend Matrix Transposetion(const Matrix &matrix);    //实现矩阵转置运算的操作
	  friend Matrix Exponentiation(const Matrix &matrix);     //实现矩阵幂运算的操作
	  //----------------------------------------------------------------------------
                                                                       //
	  friend void Inverse(Matrix &matrix);                           //实现矩阵求逆运算的操作
	  friend void FindAlgebraCofactor(const Matrix &matrix);               //求代数余子式操作
	  friend void Determinant( Matrix &matrix);                //实现求矩阵行列式值运算的操作
	  friend void ElementaryTransformation(Matrix &matrix);//实现矩阵初等变换、求秩运算的操作
};
#endif // CONTROL_H 