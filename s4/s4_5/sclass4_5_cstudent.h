#ifndef _SCLASS4_5_STUDENT_H_
#define _SCLASS4_5_STUDENT_H_

#include<iostream>
#include<string>
using namespace std;

//声明CPerson类
class CPerson{
	public:
		CPerson(int age,char sex,string name);       //年龄、性别、姓名
		virtual void Show() const;                   //加上virtual就是覆盖，去掉就是隐藏
	protected:
	    int m_age;
		char m_sex;
	    string m_name; 
}; 

//声明CStudent类
class CStudent:virtual public CPerson{               //CPerson类是CStudent类的虚基类，虚拟继承？
                                                     //虚基类，消除二义性
													 //虚函数，使基类的指针可以访问派生类中的函数
    public:
	    CStudent(int age,char sex,string name,string grade);
		void Show() const;
	protected:
	    string m_grade; 
}; 

//声明CClerk类
class CClerk:virtual public CPerson{                 //CPerson类是CClerk类的虚基类 
	public:
		CClerk(int age,char sex,string name,double salary);
		void Show() const;
	protected:
		double m_salary;
}; 

//COnJobStudent类的声明
class COnJobStudent:public CStudent,public CClerk{   //多个基类，多继承
    public:
    	COnJobStudent(int age,char sex,string name,string grade,double salary);
    	void Show() const;
};

//类外的普通函数声明
void Reference(const CPerson &roCP);

//类的实现

//CPerson构造函数
CPerson::CPerson(int age,char sex,string name):m_age(age),m_sex(sex),m_name(name){ //初始化列表 
	;
} 

//显示人的年龄，姓名
void CPerson::Show() const{
    cout<<"CPerson::age"<<m_age<<",name:"<<m_name<<"."<<endl;
} 

//CStudent构造函数
CStudent::CStudent(int age,char sex,string name,string grade):CPerson(age,sex,name),m_grade(grade){ //初始化列表
    ; 
} 

//显示学生的年龄，姓名和年级
void CStudent::Show() const{
    cout<<"CStudent::age:"<<m_age<<",name:"<<m_name<<",grade:"<<m_grade<<"."<<endl;
} 

//CClerk构造函数
CClerk::CClerk(int age,char sex,string name,double salary):CPerson(age,sex,name),m_salary(salary){  //初始化列表
    ; 
} 

//显示职工的年龄，姓名和工资
void CClerk::Show() const{
    cout<<"CClerk::age:"<<m_age<<",name:"<<m_name<<",salary:"<<m_salary<<"."<<endl;
} 

//COnJobStudent构造函数
COnJobStudent::COnJobStudent(int age,char sex,string name,string grade,
    double salary):CStudent(age,sex,name,grade),CClerk(age,sex,name,salary),CPerson(age,sex,name){  //初始化列表 
	;
}

//显示职工的年龄，姓名，年级和工资
void COnJobStudent::Show() const{
    cout<<"COnJobStudent::age:"<<m_age<<",name:"<<m_name<<",grade:"<<m_grade<<",salary:"<<m_salary<<"."<<endl;
} 

//测试引用的作用
void Reference(const CPerson &roCP){     //基类的引用作为形参 
	roCP.Show();
}

#endif  //结束编译预处理 
