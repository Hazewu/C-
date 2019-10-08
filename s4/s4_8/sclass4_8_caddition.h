#ifndef _SCLASS4_8_ADDITION_H_
#define _SCLASS4_8_ADDITION_H_

#include<iostream>
#include<string>
using namespace std;

//声明CAddition类
class CAddition{
	public:
		int Add(int a,int b);                     //两个整数相加
		string Add(string s1,string s2);          //两个字符串对象相加
		int Add(double d1,double d2);             //两个双精度浮点数相加 
		//double Add(double d1,double d2);        //不能重载，与上一个函数仅仅返回值类型不同 
}; 

//类的实现

//Add(int a,int b)函数的实现
int CAddition::Add(int a,int b){
	int c=(a+b)%250;
	cout<<"两个整数的和对250取余：="<<c<<endl;
	return c;
} 

//Add(string s1,string s2)函数的实现
string CAddition::Add(string s1,string s2){
	string s=s1+s2;
	cout<<"子曰：："<<s<<endl;
	return s;
} 

//Add(double d1,double d2)函数的实现
int CAddition::Add(double d1,double d2){
	int d=d1+d2;
	cout<<"两个双精度浮点数之和取整：="<<d<<endl;
	return d;
} 

#endif
