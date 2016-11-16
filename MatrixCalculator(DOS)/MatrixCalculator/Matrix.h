/*********************************************************************************\
*                             Matrix.h                                            *
*�����������                                                                     *
*Programer��ansleliu                         Date��2011-10-17&18&19&20&21&22      *                   
\*********************************************************************************/ 
#ifndef MATRIX_H
#define MATRIX_H
///////////////////////////////////////////////////////////////
class Matrix                                                 //
 { 
 private : 
     long double **ptr;//���ڶ�̬�������ռ��������ָ��    
 ////////////////////////////////////////////////////////////// 
 public:                                                     //
     Matrix(int R=0, int C=0);//���캯��,��̬�����ڴ�洢����Ԫ�� 
     Matrix(const Matrix &matrix);                 //�������캯�� 
     ~Matrix();                               //��������,�ͷ��ڴ� 
     ////////////////////////////////////
     void InPut();    //�������Ԫ��   //
     void Show()const;//��ʾ�������� 
	 ////////////////////////////////////////////////////////////////////////////////////////////////
     Matrix operator+(const Matrix &matrix)const;   //���ز����� '+' ʵ�������������             ///
     Matrix operator-(const Matrix &matrix)const;   //���ز����� '-' ʵ������������� 
     Matrix operator*(const Matrix &matrix)const;   //���ز����� '*' ʵ�������������
	 Matrix operator *( const double a) const;          //���ز����� '*' ʵ�־�������
     Matrix& operator=(const Matrix &matrix); //���ظ�ֵ������ '=' ʵ�־���֮��ĸ�ֵ 
     /////////////////////////////////////////////////////////////////////////////////////////////////
	 friend Matrix Transpose(const Matrix &matrix);                                //����ת�ú���   //
	 friend Matrix Exponentiation(const Matrix &matrix , int n);           //���ó���Ԫ����������
	 friend Matrix Cofactor(const Matrix &matrix,int,int);                 //���ó���Ԫ��������ʽ
	 friend long double AlgebraCofactor(const Matrix &matrix,int ,int);//���ó���Ԫ�����������ʽ 
	 friend long double Det(Matrix &matrix);                         //���ó���Ԫ�ĵݹ�������ʽֵ
     friend Matrix Inv(Matrix &matrix);                                  //���ó���Ԫ����������
	 friend Matrix Rref(Matrix &matrix);                           //���ó���Ԫ�ľ���ĳ����б任
	 friend int Rank(Matrix &matrix);                                      //���ó���Ԫ�ľ�������
 ////////////////////////////////////////////////////////////
 public:                                                   //
	 int row;                 //��������� 
     int col;                 //��������� 
 };
#endif // MATRIX_H 