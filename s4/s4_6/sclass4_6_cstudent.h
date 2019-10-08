#ifndef _SCLASS4_6_STUDENT_H_
#define _SCLASS4_6_STUDENT_H_

#include<iostream>
#include<string>
using namespace std;

//声明CPerson类
class CPerson{
	public:
		virtual ~CPerson();     //必须加virtual，声明为虚函数，否则用delete销毁对象时会出错
	protected:
	    int m_age;
		string m_name; 
}; 

//声明CStudent类
class CStudent:public CPerson{  //CStudent类继承自CPerson类 
	public:
		~CStudent();            //派生类析构函数也最好加上virtual
	protected:
	    string m_grade; 
}; 

//类的实现

//CPerson析构函数
CPerson::~CPerson(){
	cout<<"~CPerson!"<<endl;
} 

//CStudent析构函数
CStudent::~CStudent(){
	cout<<"~CStudent!"<<endl;
} 

#endif        //结束编译预处理 
