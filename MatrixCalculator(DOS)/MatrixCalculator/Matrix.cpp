/*********************************************************************************\
*                                   Matrix.cpp                                    *
*  �������������Ա�����Ķ���                                                     *
*                                                                                 *    
*  Programer��ansleliu                       Date��2011-10-18                     *                   
\*********************************************************************************/
 #include<iostream>
 #include<iomanip>
 #include<stdlib.h>
 #include"Matrix.h" 
 using namespace std; 
//=================================================================================
//                            ���캯��                                            =
//                     ��̬�����ڴ�洢����Ԫ��                                   =
//date:2011-10-17                                                                 =
//=================================================================================
 Matrix::Matrix(int R, int C) 
 { 
     row = R; 
     col = C; 
	 /////////////////////////////////////////////////////////////
     ptr = new long double*[row];//����row��long double*�ռ� 
     ///////////////////////////////////////////////////////////////
	if(ptr == NULL) //�жϿռ�����Ƿ�ɹ� 
     { 
         cerr <<">>!�ռ����ʧ��!" <<endl;//cerrֻ���������׼����� ,�������ض���
         exit(EXIT_FAILURE);
		 //EXIT_FAILURE��Ϊexit()�Ĳ���ʹ�ñ�ʾû�гɹ���ִ��һ������ 
     } 
	////////////////////////////////////////////////////////////////
     for(int i=0; i <row; i++) 
     { 
         ptr[i] = new long double[col];//��ÿһ�е�ָ��ָ��һ��col��С�Ŀռ� 
         if(ptr[i] == NULL) 
         { 
             cerr <<">>!�ռ����ʧ��!" <<endl; 
             exit(EXIT_FAILURE); 
         } 
     } 
     ////////////////////////////////////////////////////////
     for(  i=0; i <row; i++)//������Ԫ��Ĭ��ֵ����Ϊ0 
         for(int j=0; j <col; j++) 
             ptr[i][j] = 0;                                                     
 }                                                                          
//=================================================================================
//                         �������캯��                                           =
// date:2011-10-17                                                                =
//=================================================================================  
 Matrix::Matrix(const Matrix &matrix) 
 { 
     row = matrix.row; 
     col = matrix.col; 
	 
     ptr = new long double*[row];//����row��int*�ռ� 
     if(ptr == NULL) //�жϿռ�����Ƿ�ɹ� 
     { 
         cerr <<">>!�ռ����ʧ��!" <<endl; 
         exit(EXIT_FAILURE); 
     } 
     for(int i=0; i <row; i++) 
     { 
         ptr[i] = new long double[col];//��ÿһ�е�ָ��ָ��һ��col��С�Ŀռ� 
         if(ptr[i] == NULL) 
         { 
             cerr <<">>!�ռ����ʧ��!" <<endl; 
             exit(EXIT_FAILURE); 
         } 
     } 
  
     for( i=0; i <row; i++)//���ƾ���Ԫ�� 
         for(int j=0; j <col; j++) 
             ptr[i][j] = matrix.ptr[i][j]; 
 } 
//=================================================================================
//                           ��������                                             =
//                           �ͷ��ڴ�                                             =
//date:2011-10-17                                                                 =
//=================================================================================  
 Matrix::~Matrix() 
 { 
     for(int i=0; i <row; i++) 
         delete []ptr[i]; 
     delete []ptr; 
 } 
//=================================================================================
//                            �������Ԫ��                                        =
// date:2011-10-17                                                                =
//================================================================================= 
 void Matrix::InPut() 
 { 
     cout <<">>����һ�� " <<row <<" �� " <<col <<" �еľ���." <<endl; 
     cout <<">>���������Ԫ��."<<endl<<
		"  ���������֣��Կո������֣��Իس�����.\r\n  �����ַ��ᵼ�´���! " <<endl;
     for(int i=0; i <row; i++)
	 {
		 cout <<"��" <<i+1<<"(����"<<"1-"<<col<<") :";
         for(int j=0; j <col; j++) 
         {  
             cin>>ptr[i][j]; 
         }
	 }
 } 
//=================================================================================
//                           ��ʾ��������                                         =
//date:2011-10-17                                                                 =
//================================================================================= 
 void Matrix::Show() const 
 { 
     for(int i=0; i <row; i++) 
     { 
         for(int j=0; j <col; j++) 
             cout/*<<noshowpoint*/<<setprecision(4)/*<<setiosflags(ios::fixed)*/
			 <<setiosflags(ios::right)<<setw(10)<<setfill(' ')
			 <<ptr[i][j]; 
         cout<<endl; 
     } 
 } 
//=================================================================================
//                              ���ز����� '+'                                    =
//                             ʵ�������������                                   =
//date:2011-10-18                                                                 =
//=================================================================================
 Matrix Matrix::operator +(const Matrix &matrix) const 
 { 
     if(row != matrix.row || col != matrix.col) 
     { 
         cout <<">>!���������С��һ��,�ӷ�����ʧ��!" <<endl; 
         return Matrix(); 
     } 
  
     Matrix temp(row,col);//������ʱ����洢������ĺ� 
     for(int i=0; i <row; i++) 
         for(int j=0; j <col; j++) 
             temp.ptr[i][j] = ptr[i][j] + matrix.ptr[i][j]; 
     return temp; 
 } 
//=================================================================================
//                              ���ز����� '-'                                    =
//                             ʵ�������������                                   =
//date:2011-10-18                                                                 =
//================================================================================= 
 Matrix Matrix::operator -(const Matrix &matrix)const 
 { 
     if(row != matrix.row || col != matrix.col) 
     { 
         cout <<">>!���������С��һ��,��������ʧ��!" <<endl; 
         return Matrix(); 
     } 
  
     Matrix temp(row,col);//������ʱ����洢������Ĳ� 
     for(int i=0; i <row; i++) 
         for(int j=0; j <col; j++) 
             temp.ptr[i][j] = ptr[i][j] - matrix.ptr[i][j]; 
     return temp; 
 } 
//=================================================================================
//                                ���ز����� '*'                                  =
//                               ʵ�������������                                 =
//date:2011-10-18                                                                 =
//=================================================================================
 Matrix Matrix::operator *(const Matrix &matrix) const 
 { 
     if(col != matrix.row) 
     { 
         cout <<">>!�����������в�ƥ��,�˷�����ʧ��!" <<endl; 
         return Matrix(); 
     } 
  
     Matrix temp(row,matrix.col);//������ʱ����洢������Ļ� 
     for(int i=0; i <row; i++) 
         for(int j=0; j <matrix.col; j++) 
         { 
             long double sum = 0; 
             for(int k=0; k <col; k++) 
                 sum += ptr[i][k] * matrix.ptr[k][j]; 
             temp.ptr[i][j] = sum; 
         } 
  
     return temp; 
 } 
//=================================================================================
//                                ���ز����� '*'                                  =
//                                ʵ�־��������                                  =
//date:2011-10-18                                                                 =
//=================================================================================
 Matrix Matrix::operator *( const double a) const 
 { 
     Matrix temp(row,col);//������ʱ����洢��������� 
     for(int i=0; i <row; i++) 
         for(int j=0; j <col; j++) 
         { 
               temp.ptr[i][j] = ptr[i][j]*a;       
         } 
  
     return temp; 
 } 
//=================================================================================
//                               ���ظ�ֵ������ '='                               =
//                               ʵ�־���֮��ĸ�ֵ                               =
//date:2011-10-18                                                                 =
//================================================================================= 
 Matrix& Matrix::operator =(const Matrix &matrix) 
 { 
     if(this == &matrix)     //��ֹ����ֵ 
         return *this; 
  
     for( int i=0; i <row; i++)//�ͷ�ԭ����ռ� 
         delete []ptr[i]; 
     delete []ptr; 
     ///////////////////////////////////////////////////
     row = matrix.row; 
     col = matrix.col; 
     ptr = new long double*[row];   //����row��int*�ռ� 
     if(ptr == NULL) //�жϿռ�����Ƿ�ɹ� 
     { 
         cerr <<">>!�ռ����ʧ��!" <<endl; 
         exit(EXIT_FAILURE); 
     } 
	 ///////////////////////////////////////////////////////////////////////
     for( i=0; i <row; i++) 
     { 
         ptr[i] = new long double[col];//��ÿһ�е�ָ��ָ��һ��col��С�Ŀռ� 
         if(ptr[i] == NULL) 
         { 
             cerr <<">>!�ռ����ʧ��!" <<endl; 
             exit(EXIT_FAILURE); 
         } 
     } 
     //////////////////////////////////////////////
     for( i=0; i <row; i++)   //���ƾ���Ԫ�� 
         for(int j=0; j <col; j++) 
             ptr[i][j] = matrix.ptr[i][j]; 
  
     ///////////////////////////////////////////////
     return *this; 
 } 
//=================================================================================
//                              ����ת�ú���                                      =
//date:2011-10-18                                                                 =
//=================================================================================  
 Matrix Transpose(const Matrix &matrix) 
 { 
     int temp_R = matrix.col;//�洢������� 
     int temp_C = matrix.row; //�洢������� 
     
	 Matrix temp(temp_R,temp_C); //������ʱ����洢�����ת�� 
     ////////////////////////////////////////////////////////
	 for(int i=0; i <matrix.row; i++) 
         for(int j=0; j <matrix.col; j++) 
             temp.ptr[j][i] = matrix.ptr[i][j]; 
     ////////////////////////////////////////////////////////
     return temp;
 } 
//=================================================================================
//                               ������������                                     =
// date��2011-10-30                                                               =
//=================================================================================
 Matrix Exponentiation(const Matrix &matrix ,int n)
 {
	int temp_R = matrix.row;//�洢������� 
    int temp_C = matrix.col; //�洢�������  
	Matrix temp(temp_R,temp_C); //������ʱ����洢���������ʽ
	
	temp=matrix;
   //////////////////////////////////////////////////////////
    if(n <= 0)
	{
		cerr<<">>!�˺�����֧�� n < = 0������"<<endl;
		return matrix;
//		exit(EXIT_FAILURE);
	}
	else if(n == 1)
	{
		return temp;
	}
	else 
	{
		for(int i=1 ; i<n ; i++)
		{
			temp =temp*temp;
		}
		return temp;
	}
 }
//=================================================================================
//                                ������ʽ                                        =
// ��long double Det(Matrix &matrix)�ڲ�����                                      =
// ��Matrix Inv( Matrix &matrix)�ڲ�����                                          =
// date:2011-10-19                                                                =
//=================================================================================
 Matrix Cofactor(const Matrix &matrix, int Specifiedrow, int Specifiedcol)
 { 
	//���Specifiedrow��Specifiedcol��Ԫ�ص�����ʽ 
	int temp_R = matrix.row-1;//�洢������� 
    int temp_C = matrix.col-1; //�洢�������

	//////////////////////////////////////////////////////////////
	Matrix temp(temp_R,temp_C); //������ʱ����洢���������ʽ
    //////////////////////////////////////////////////////////////
	for (int i = 0; i < Specifiedrow; i++)
	{
		for (int j = 0; j < Specifiedcol; j++)
		{
			temp.ptr[i][j] = matrix.ptr[i][j];
		}
		////////////////////////////////////////////////////////
		for (int k = Specifiedcol + 1; k < matrix.col; k++)
		{
			temp.ptr[i][k-1] = matrix.ptr[i][k];
		}
	}
   //////////////////////////////////////////////////////////////
	for (int m = Specifiedrow + 1; m < matrix.row; m++)
	{
		for (int j = 0; j < Specifiedcol; j++)
		{
			temp.ptr[m-1][j] = matrix.ptr[m][j];
		}
		/////////////////////////////////////////////////////// 
		for (int k = Specifiedcol + 1; k <matrix.col; k++)
		{
			temp.ptr[m-1][k-1] = matrix.ptr[m][k];
		}
	}
    ///////////////////////////////////////////////////////////
	Det(temp);
	return temp;
 }
//=================================================================================
//                              ���������ʽ                                      =
//date:2011-11-05                                                                 =
//=================================================================================
 long double AlgebraCofactor(const Matrix &matrix,int Specifiedrow,int Specifiedcol) 
 {
      long double M = 0;
	  int m=Specifiedrow;
	  int n=Specifiedcol;
      /////////////////////////////////////////
      int temp_R = matrix.row-1;//�洢������� 
      int temp_C = matrix.col-1; //�洢�������
      Matrix temp(temp_R,temp_C); //������ʱ����洢���������ʽ
	  //////////////////////////////////////////////////////////
	  if((m+n)%2==0)
	      M=Det(Cofactor(matrix, m, n));
	  else
		  M=-Det(Cofactor(matrix, m, n));
      //////////////////////////////////////
      return M;
 }
//=================================================================================
//                           �ݹ�������ʽֵ                                       =
//date:2011-10-19                                                                 =
//=================================================================================
 long double Det(Matrix &matrix)  
 {
      long double det = 0;
//      if (matrix.row != matrix.col)
//	  {
//		   cerr<<">>!���Ƿ���û������ʽ!"<<endl;
//		   cerr<<">>������ʽ�˳�"<<endl;
//		   exit(EXIT_FAILURE);
//	  }
//   else if (matrix.col == 1)
	  if (matrix.col == 1)
	  {
          det = matrix.ptr[0][0];
          return det;
	  }
     else
	 {
          for (int i = 0; i <matrix.col; i++)
		  {
               if (i%2==0)
                det += matrix.ptr[i][0] * Det(Cofactor(matrix, i, 0));
               else 
                det -= matrix.ptr[i][0] * Det(Cofactor(matrix, i, 0));
		  }
	 }
     return det;
 }
//=================================================================================
//                                ��������                                      =
//date:2011-10-19                                                                 =
//=================================================================================
 Matrix Inv( Matrix &matrix) 
 {
     int temp_R = matrix.row;//�洢������� 
     int temp_C = matrix.col;//�洢�������  
	 Matrix temp(temp_R,temp_C); //������ʱ����洢���������ʽ 
     //������� = ������� / ����ʽ
     long double det = Det(matrix);
     
     for (int i = 0; i < temp.row; i++)
	 {
         for (int j = 0; j < temp.col; j++)
		 {
              if ((i + j) % 2 == 0)
              temp.ptr[j][i] = Det(Cofactor(matrix, i, j)) / det;
              else
              temp.ptr[j][i] = -Det(Cofactor(matrix, i, j)) / det;
		 }
	 }
     return temp;
 }
//=================================================================================
//                             ����ĳ����б任                                   =
//date:2011-10-20 & 21 & 22                                                       =
//=================================================================================
 Matrix Rref(Matrix &matrix)
 {
	 //////////////////////////////////////
	 int temp_R = matrix.row;//�洢������� 
     int temp_C = matrix.col;//�洢�������
     //////////////////////////////////////////////////////////////////
	 Matrix temp0(temp_R,temp_C); //������ʱ����洢����ĳ��ȱ任���
	 Matrix temp(temp_R,temp_C); //������ʱ����洢����ĳ��ȱ任���
     /////////////////////////////////////////////////////////////////
	 temp0=matrix;
    ////////////////////////////////////////////////////////////////////////////////
	for(int a=0 , b=0; a<temp0.row && b<temp0.col; a++,b++ )                ////////
	{                                                                       ////////
		 int flag=0;
		 /////////////////////////////
		 if(b>=temp0.col)
			 b=temp0.col-1;
		 ////////////////////////////////////////////////////
    	do                                              /////         
		{
		    flag=0;
			//////////////////////////////
			for(int r=a;r<temp0.row;++r)
			{
				if(temp0.ptr[r][b]==0)
					flag++;
			}
			///////////////////////////////////////////
			if(flag==temp0.row-a)                  ////
			{
				b+=1;
				if(b>=temp0.col) 
					b=temp0.col-1;
			}
		}
		while(flag==temp0.row-a && b<temp0.col-1);                     ////
		///////////////////////////////////////////////////////////////////
			flag=0;                                                    ////
		/////////////////////////////////
			for(int i=a;i<temp0.row;i++)
			{
				if(temp0.ptr[i][b]==0)
				 {
					for(int p=a+1; p<temp0.row; p++)
					{
						if(temp0.ptr[p][b]!=0)
						{
							for(int q=b; q<temp0.col; q++)
							{
								temp.ptr[p-1][q]=temp0.ptr[p-1][q];
								temp0.ptr[p-1][q]=temp0.ptr[p][q];
								temp0.ptr[p][q]=temp.ptr[p-1][q];
							}
						}
					}
				}
			}                                                   //////
		//////////////////////////////////////////////////////////////
			for(int t=a+1; t<matrix.row; t++)                   //////
			{
				if(temp0.ptr[t][b]!=0)
				{
					long double logo1=temp0.ptr[a][b];
					long double logo2=temp0.ptr[t][b];
					for(int m=b; m<temp0.col; m++)
					{
						temp.ptr[a][m]=temp0.ptr[a][m];
						temp.ptr[a][m]=temp.ptr[a][m]*logo2;
						temp0.ptr[t][m]=temp0.ptr[t][m]*logo1;
						temp0.ptr[t][m]=temp0.ptr[t][m]-temp.ptr[a][m];
					}
				}
			}                                                                //////
	}                                                                        //////
	///////////////////////////////////////////////////////////////////////////////
	for(int s=0 ; s<temp0.row; s++ )                                         /////
	   for(int t=0; t<temp0.col; t++)                                        /////
	   {
		   if(temp0.ptr[s][t]!=0)
		   {
				for(int w = temp0.col-1; w>=t ; w--)
					temp0.ptr[s][w]=temp0.ptr[s][w]/temp0.ptr[s][t];
				break;
		   }
	   }
    ///////////////////////////////////////////////////////////////////////////////	                                                                    
	for(int c=1; temp0.row<=temp0.col?c<temp0.row:c<temp0.col; c++ )         //////
		for(int d=0; d<temp0.col ; d++)                                      //////
		{
			if(temp0.ptr[c][d]!=0)
			{
				for(int e=c-1; e>=0; e--)
				{
					if(temp0.ptr[e][d]!=0)
					{
						long double logo3=temp0.ptr[c][d];
						long double logo4=temp0.ptr[e][d];
					    //////////////////////////////////////////	
						for(int f=0;f<temp0.col; f++)
						{
							temp.ptr[c][f]=temp0.ptr[c][f];
							temp.ptr[c][f]=temp.ptr[c][f]*logo4;
							temp0.ptr[e][f]=temp0.ptr[e][f]*logo3;
						}
					    //////////////////////////////////////////////
						for(int g=d; g<temp0.col; g++)
							temp0.ptr[e][g]=temp0.ptr[e][g]-temp.ptr[c][g];
					}
				}
				break;
			}                                                                      ///////
		}                                                                          ///////
    //////////////////////////////////////////////////////////////////////////////////////                                                                  
    //////////////////////////////////////////////////////////////////////////////
    for(int x=0 ; x<temp0.row; x++ )                                         /////
	   for(int y=0; y<temp0.col; y++)                                        /////
	   {
		   if(temp0.ptr[x][y]!=0)
		   {
				for(int z = temp0.col-1; z>=y ; z--)
					temp0.ptr[x][z]=temp0.ptr[x][z]/temp0.ptr[x][y];
				break;
		   }
	   }
	/////////////////////////////////////////////////////////
	temp = temp0;
	return temp;
 }
//=================================================================================
//                                     ��������                                   =
//date:2011-10-22                                                                 =
//=================================================================================
int Rank(Matrix &matrix)
{
	int temp_R = matrix.row;//�洢������� 
    int temp_C = matrix.col;//�洢�������
	int rank = 0;
	int flag1=0;
	int flag2=0;
    /////////////////////////////////////////////////////////////////
	Matrix temp(temp_R,temp_C); //������ʱ����洢����ĳ��ȱ任���
    ////////////////////////////////////////////////////////////////
	temp=Rref(matrix);
	cout<<endl<<">>�Ծ�����г����б任�Ľ��Ϊ��"<<endl;
	temp.Show();
	cout<<endl;
    //////////////////////////////////////
	for(int i=0; i<temp.row; i++)      ///
	{
		for(int j=0 ; j<temp.col; j++)
		{
			if(temp.ptr[i][j]==0)
				flag1+=1;
		}
		/////////////////////////
		if(flag1==temp.col)
		{
			flag2+=1;
			flag1=0;
		}
		/////////////////
		else
			flag1=0;
	}
	///////////////////////
	rank=(temp.row)-flag2;

	return rank;                                                                      /////////////
}                                                                                    ////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
