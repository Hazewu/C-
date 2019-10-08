//类声明文件：在COperator类中声明重载运算符
#ifndef _SCLASS4_10_OPERATOR_H_
#define _SCLASS4_10_OPERATOR_H_

#include<iostream>
using namespace std;

//声明运算符类
class COperator{
	public:
		COperator(int b=0);                  //构造函数
		
		int operator++(int i);               //重载后缀++
		int operator++();                    //重载前缀++
		int operator()();                    //重载函数运算符，功能：取m_v的值
		
		COperator operator=(int a);          //重载赋值运算符
		COperator operator+(COperator ob);   //重载算术运算符：对象+对象
		
		bool operator>(COperator ob);        //重载比较运算符：对象>对象
		bool operator<=(COperator ob);        //重载比较运算符：对象<=对象 
		
	public:
		int m_v;
}; 

//构造函数
COperator::COperator(int b):m_v(b){
	;
} 

int COperator::operator++(int i){            //重载后缀++，先取值，后自加 
	int iRV=m_v;                             //创建一个临时对象，用来保存对象原来的值
	if(m_v<65535)
	    m_v++;                               //此处++为系统默认含义；因为m_v是基本数据类型
    else
	    m_v=0;
	return iRV;                              //返回对象原值，也就是修改前的值 
}

int COperator::operator++(){                 //重载前缀++，先自加，后取值 
	if(m_v<65535) 
	    m_v++;
	else
	    m_v=0;
	return m_v;
}

int COperator::operator()(){                 //重载函数运算符，功能：取m_v的值 
	return m_v;
}

COperator COperator::operator=(int a){       //重载赋值运算符，将整型值赋给对象的数据成员 
	m_v=a;
	return *this; 
} 

COperator COperator::operator+(COperator ob){//重载算术运算符：对象+对象 
	m_v=m_v+ob.m_v;                          //将两个对象的m_v值相加，作为返回对象的值
	if(m_v>65535)
	    m_v=m_v-65535;
	return *this;
} 

bool COperator::operator>(COperator ob){     //重载比较运算符：对象>对象 
	if(m_v>ob.m_v)
	    return true;
	else
	    return false;
}

bool COperator::operator<=(COperator ob){    //重载比较运算符：对象<=对象 
	if(m_v<=ob.m_v)
	    return true;
	else
	    return false;
} 

#endif 
