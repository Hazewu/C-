#ifndef _SCLASS4_4_STUDENT_H_
#define _SCLASS4_4_STUDENT_H_

#include<iostream>
#include<string>
using namespace std;

//����CPerson��
class CPerson{
	public:
		CPerson(int age,string name);              //���������
		//��Show()�����趨Ϊ�麯���ͷ��麯���ֱ����г���
		virtual void Show(int age) const;          //��ʾ�˵����䡢���� 
		virtual void Show() const;                 //��ʾ�˵�����	
	protected:
	    int m_age;
		string m_name; 
}; 

//����CStudent��
class CStudent:public CPerson{
	public:
		CStudent(int age,string name,string grade); //���䡢�������꼶
		void Show(int age) const;                   //��ʾѧ�������䣬�������꼶
	protected:
	    string m_grade;                             //�꼶���� 
}; 

//CPerson���캯��
CPerson::CPerson(int age,string name):m_age(age),m_name(name){
	;
}

//��ʾѧ�������䡢����
void CPerson::Show(int age) const{
    cout<<"CPerson::Show(age):"<<m_age<<",name:"<<m_name<<"."<<endl;
}

//��ʾ�˵�����
void CPerson::Show() const{
	cout<<"CPerson::Show(no age):"<<"name:"<<m_name<<endl;
} 

//CStudent���캯��
CStudent::CStudent(int age,string name,string grade):CPerson(age,name),m_grade(grade){
	;
} 

//��ʾѧ�������䣬�������꼶
void CStudent::Show(int age) const{
    cout<<"CStudent::Show(age):"<<m_age<<",name:"<<m_name<<",grade:"<<m_grade<<"."<<endl;
} 

#endif
