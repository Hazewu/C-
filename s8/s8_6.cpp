/*
使用命名空间，先定义，后使用。
定义命名空间的语法格式如下：
   namespace namespace_name{
        //各种名字（包括类型名、变量名和函数名）的声明或者定义 
   } 
两种使用方法，其语法格式如下：
   命名空间名字：：命名空间成员
   using namespace <名字空间名字>;
   
没有名字的命名空间
可以定义：
   namespace{                    //这里命名空间没有具体的名字 
       int Function(){
	         //
	   }
   } 
*/

//命名空间的使用
#include<iostream>
using namespace std;

int iNum=10000;                  //全局变量

//MyNameSpace.h
namespace MyNameSpace{           //定义命名空间MyNameSpace 
	int iNum=2000;               //MyNameSpace空间中的变量
	int Add(int iNum){           //MyNameSpace空间中的函数Add() 
		iNum=iNum+iNum;          //访问的是Add内的局部变量
		return iNum; 
	} 
} 

//YourNameSpace.h
namespace YourNameSpace{         //定义命名空间YourNameSpace 
	int iNum=300000;             //YourNameSpace空间中的变量
	int Add(int iNum){           //YourNameSpace空间中的函数 
		iNum=::iNum+iNum;        //::iNum访问全局iNum
		return iNum; 
	} 
}

//测试程序
int main(){
	cout<<MyNameSpace::Add(1)+::iNum<<endl;  //使用全局iNum
	cout<<MyNameSpace::Add(1)+iNum<<endl;    //使用全局iNum
	
	namespace N2=YourNameSpace;              //定义YourNameSpace的别名
	cout<<N2::Add(1)+N2::iNum<<endl;         //表示使用的是YourNameSpace命名空间
	
	using namespace YourNameSpace;           //使用using关键字
	cout<<Add(1)+MyNameSpace::iNum<<endl;    //由于有全局iNum，所以要使用作用域限定符，
	//而无全局Add()，所以这里无需限定，系统知道调用的是YourNameSpace空间中的Add()
	//cout<<iNum<<endl;                      //该语句编译错误，iNum出现二义性
	
	return 0; 
} 
