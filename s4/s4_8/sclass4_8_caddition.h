#ifndef _SCLASS4_8_ADDITION_H_
#define _SCLASS4_8_ADDITION_H_

#include<iostream>
#include<string>
using namespace std;

//����CAddition��
class CAddition{
	public:
		int Add(int a,int b);                     //�����������
		string Add(string s1,string s2);          //�����ַ����������
		int Add(double d1,double d2);             //����˫���ȸ�������� 
		//double Add(double d1,double d2);        //�������أ�����һ��������������ֵ���Ͳ�ͬ 
}; 

//���ʵ��

//Add(int a,int b)������ʵ��
int CAddition::Add(int a,int b){
	int c=(a+b)%250;
	cout<<"���������ĺͶ�250ȡ�ࣺ="<<c<<endl;
	return c;
} 

//Add(string s1,string s2)������ʵ��
string CAddition::Add(string s1,string s2){
	string s=s1+s2;
	cout<<"��Ի����"<<s<<endl;
	return s;
} 

//Add(double d1,double d2)������ʵ��
int CAddition::Add(double d1,double d2){
	int d=d1+d2;
	cout<<"����˫���ȸ�����֮��ȡ����="<<d<<endl;
	return d;
} 

#endif
