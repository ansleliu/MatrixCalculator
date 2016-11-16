//=================================================================================
//                用C++实现对矩阵的操作-----矩阵计算器                             
//  基本功能：                                                                     
//            *矩阵的输入;                   *矩阵的输出;                              
//            *矩阵的加法;                   *矩阵的减法;                          
//            *矩阵的求逆：                  *矩阵的转置;                          
//            *矩阵的行列式值;               *矩阵的求秩;                          
//            *矩阵的数乘;                   *矩阵的乘法;                          
//            *矩阵的行列式指定行和列的代数余子式                                  
//  Programer：ansleliu                                         
//=================================================================================
 #include<iostream>
 #include<windows.h>
 #include"Matrix.h"
 #include"Control.h" 
 using namespace std; 
//---------------------------------------------------------------------------------

//=================================================================================
//                                MAIN                                          
//=================================================================================
 void main() 
 { 
	 system("color FD");//设置控制台窗口背景颜色和字体颜色
	 //-----------------------------------------------------------------------------------
	 cout<<"************************************************************************"<<endl
		 <<"*                     *** MatrixCalculator***                          *"<<endl
		 <<"************************************************************************"<<endl
		 <<"*                   本程序可以进行基本的线性代数运算                   *"<<endl
		 <<"*                                                                      *"<<endl              
         <<"*                                                                      *"<<endl
		 <<"************************************************************************"<<endl
		 <<endl;
     //------------------------------------------------------------------------------------
         
logo1:  char Options;
    //--------------------------------------------------------------------------------------  
		Matrix matrix(0,0);
		matrix=CreateMainMatrix();//创建主矩阵
        
    //--------------------------------------------------------------------------------------
	 OutputMenuOption();//输出菜单选项

	 //------------------------------------------------------------------------------------                                                                
	 while(1)                                                         
	 {
	    //---------------------------------------------------------------------------------
	    cout<<">>请输入您想要进行的运算 ：";
		cin>>Options;
        //---------------------------------------------------------------------------------	
    	switch(Options)
		{
		    case'+': Addition(matrix).Show();//实现矩阵加法运算的操作
					 break;
           
		    case'-': Subtraction(matrix).Show();//实现矩阵减法运算的操作
					 break;
           
		    case'*': Multiplication(matrix).Show();//实现矩阵乘法运算的操作
				   	 break;

            case'n':
            case'N': NumMultiplication(matrix).Show();//实现矩阵数乘运算的操作
				     break;
           //-------------------------------------------------------------------------------
			case't':
			case'T': Transpose(matrix).Show();//实现矩阵转置运算的操作
					 break;
           
			case'e':
			case'E': Exponentiation(matrix).Show();//实现矩阵幂运算的操作
				     break;
            
            case'f':
			case'F': FindAlgebraCofactor(matrix);//实现求代数余子式操作
				     break;
		    
			case'd':
			case'D': Determinant(matrix);//实现求矩阵行列式值运算的操作
				     break;
           
		    case'i':
			case'I': Inverse(matrix);//实现矩阵求逆运算的操作
				     break;
           
		    case'r':
			case'R': ElementaryTransformation(matrix);//实现矩阵初等变换和求秩运算的操作
				     break;
           //-------------------------------------------------------------------------------
		    case'a':
			case'A': cout<<endl;
				     goto logo1;
			         break;
					 
		    case'o':
			case'O': cout<<endl;
				     goto logo2;
					 break;
           //-------------------------------------------------------------------------------
		    default: cout<<">>!您的输入有误，请重新输入！"<<endl;  	   
		}
	 }	
//------------------------------------------------------------------------------------------
logo2:cout<<"************************************************************************"<<endl
		  <<"*                            感谢您的使用                              *"<<endl
		  <<"*                                再见 ！                               *"<<endl              
          <<"*                                                Programmer:  L        *"<<endl
		  <<"************************************************************************"<<endl;
	system("pause");

}
