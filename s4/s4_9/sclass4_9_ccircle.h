#ifndef _SCLASS4_9_CCIRCLE_H_
#define _SCLASS4_9_CCIRCLE_H_

#include<iostream>
using namespace std;

//声明CCircle类
class CCircle{
	public:
		void Reference();                   //类内成员函数 
}; 

void Reference();                           //类外，全局重载函数
void Reference(CCircle &roCC);               //类外，全局重载函数

//类的实现

//成员函数Reference()的实现
void CCircle::Reference(){
	cout<<"我是成员函数."<<endl;
} 

//全局重载函数Reference()的实现
void Reference(){
	cout<<"我是全局重载函数Reference()."<<endl;
} 

//全局重载函数Reference(CCircle &roCC)的实现
void Reference(CCircle &roCC){
	cout<<"我是全局重载函数Reference(CCircle &roCC)."<<endl;
}

#endif
