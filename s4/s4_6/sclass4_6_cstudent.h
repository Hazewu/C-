#ifndef _SCLASS4_6_STUDENT_H_
#define _SCLASS4_6_STUDENT_H_

#include<iostream>
#include<string>
using namespace std;

//����CPerson��
class CPerson{
	public:
		virtual ~CPerson();     //�����virtual������Ϊ�麯����������delete���ٶ���ʱ�����
	protected:
	    int m_age;
		string m_name; 
}; 

//����CStudent��
class CStudent:public CPerson{  //CStudent��̳���CPerson�� 
	public:
		~CStudent();            //��������������Ҳ��ü���virtual
	protected:
	    string m_grade; 
}; 

//���ʵ��

//CPerson��������
CPerson::~CPerson(){
	cout<<"~CPerson!"<<endl;
} 

//CStudent��������
CStudent::~CStudent(){
	cout<<"~CStudent!"<<endl;
} 

#endif        //��������Ԥ���� 
