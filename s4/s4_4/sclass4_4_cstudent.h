#ifndef _SCLASS4_4_STUDENT_H_
#define _SCLASS4_4_STUDENT_H_

#include<iostream>
#include<string>
using namespace std;

//声明CPerson类
class CPerson{
	public:
		CPerson(int age,string name);              //年龄和姓名
		//将Show()函数设定为虚函数和非虚函数分别运行程序
		virtual void Show(int age) const;          //显示人的年龄、姓名 
		virtual void Show() const;                 //显示人的姓名	
	protected:
	    int m_age;
		string m_name; 
}; 

//声明CStudent类
class CStudent:public CPerson{
	public:
		CStudent(int age,string name,string grade); //年龄、姓名和年级
		void Show(int age) const;                   //显示学生的年龄，姓名和年级
	protected:
	    string m_grade;                             //年级对象 
}; 

//CPerson构造函数
CPerson::CPerson(int age,string name):m_age(age),m_name(name){
	;
}

//显示学生的年龄、姓名
void CPerson::Show(int age) const{
    cout<<"CPerson::Show(age):"<<m_age<<",name:"<<m_name<<"."<<endl;
}

//显示人的姓名
void CPerson::Show() const{
	cout<<"CPerson::Show(no age):"<<"name:"<<m_name<<endl;
} 

//CStudent构造函数
CStudent::CStudent(int age,string name,string grade):CPerson(age,name),m_grade(grade){
	;
} 

//显示学生的年龄，姓名和年级
void CStudent::Show(int age) const{
    cout<<"CStudent::Show(age):"<<m_age<<",name:"<<m_name<<",grade:"<<m_grade<<"."<<endl;
} 

#endif
