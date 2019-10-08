#ifndef _SCLASS4_5_STUDENT_H_
#define _SCLASS4_5_STUDENT_H_

#include<iostream>
#include<string>
using namespace std;

//����CPerson��
class CPerson{
	public:
		CPerson(int age,char sex,string name);       //���䡢�Ա�����
		virtual void Show() const;                   //����virtual���Ǹ��ǣ�ȥ����������
	protected:
	    int m_age;
		char m_sex;
	    string m_name; 
}; 

//����CStudent��
class CStudent:virtual public CPerson{               //CPerson����CStudent�������࣬����̳У�
                                                     //����࣬����������
													 //�麯����ʹ�����ָ����Է����������еĺ���
    public:
	    CStudent(int age,char sex,string name,string grade);
		void Show() const;
	protected:
	    string m_grade; 
}; 

//����CClerk��
class CClerk:virtual public CPerson{                 //CPerson����CClerk�������� 
	public:
		CClerk(int age,char sex,string name,double salary);
		void Show() const;
	protected:
		double m_salary;
}; 

//COnJobStudent�������
class COnJobStudent:public CStudent,public CClerk{   //������࣬��̳�
    public:
    	COnJobStudent(int age,char sex,string name,string grade,double salary);
    	void Show() const;
};

//�������ͨ��������
void Reference(const CPerson &roCP);

//���ʵ��

//CPerson���캯��
CPerson::CPerson(int age,char sex,string name):m_age(age),m_sex(sex),m_name(name){ //��ʼ���б� 
	;
} 

//��ʾ�˵����䣬����
void CPerson::Show() const{
    cout<<"CPerson::age"<<m_age<<",name:"<<m_name<<"."<<endl;
} 

//CStudent���캯��
CStudent::CStudent(int age,char sex,string name,string grade):CPerson(age,sex,name),m_grade(grade){ //��ʼ���б�
    ; 
} 

//��ʾѧ�������䣬�������꼶
void CStudent::Show() const{
    cout<<"CStudent::age:"<<m_age<<",name:"<<m_name<<",grade:"<<m_grade<<"."<<endl;
} 

//CClerk���캯��
CClerk::CClerk(int age,char sex,string name,double salary):CPerson(age,sex,name),m_salary(salary){  //��ʼ���б�
    ; 
} 

//��ʾְ�������䣬�����͹���
void CClerk::Show() const{
    cout<<"CClerk::age:"<<m_age<<",name:"<<m_name<<",salary:"<<m_salary<<"."<<endl;
} 

//COnJobStudent���캯��
COnJobStudent::COnJobStudent(int age,char sex,string name,string grade,
    double salary):CStudent(age,sex,name,grade),CClerk(age,sex,name,salary),CPerson(age,sex,name){  //��ʼ���б� 
	;
}

//��ʾְ�������䣬�������꼶�͹���
void COnJobStudent::Show() const{
    cout<<"COnJobStudent::age:"<<m_age<<",name:"<<m_name<<",grade:"<<m_grade<<",salary:"<<m_salary<<"."<<endl;
} 

//�������õ�����
void Reference(const CPerson &roCP){     //�����������Ϊ�β� 
	roCP.Show();
}

#endif  //��������Ԥ���� 
