//=================================================================================
//                             Control.h                                           
// ������ �����������                                                             
//       ���̳���Matrix�࣬��Matrix���public����                                 
//Programer��L                                                       
//================================================================================= 
#ifndef CONTROL_H
#define CONTROL_H
//---------------------------------------------------------------------------------
class Control :public Matrix
 { 
 //--------------------------------------------------------------------------------
 public:                                              //---------------------------
	  friend Matrix CreateMainMatrix();//����������
	  friend void OutputMenuOption();//����˵�ѡ��
      //---------------------------------------------------------------------------
	                                                                        //
	  friend Matrix Addition(const Matrix &matrix);         //ʵ�־���ӷ�����Ĳ���
      friend Matrix Subtraction(const Matrix &matrix);      //ʵ�־����������Ĳ���
	  friend Matrix Multiplication(const Matrix &matrix);   //ʵ�־���˷�����Ĳ���
	  friend Matrix NumMultiplication(const Matrix &matrix);//ʵ�־�����������Ĳ���
	  friend Matrix Transposetion(const Matrix &matrix);    //ʵ�־���ת������Ĳ���
	  friend Matrix Exponentiation(const Matrix &matrix);     //ʵ�־���������Ĳ���
	  //----------------------------------------------------------------------------
                                                                       //
	  friend void Inverse(Matrix &matrix);                           //ʵ�־�����������Ĳ���
	  friend void FindAlgebraCofactor(const Matrix &matrix);               //���������ʽ����
	  friend void Determinant( Matrix &matrix);                //ʵ�����������ʽֵ����Ĳ���
	  friend void ElementaryTransformation(Matrix &matrix);//ʵ�־�����ȱ任����������Ĳ���
};
#endif // CONTROL_H 