#ifndef _SCLASS4_9_CCIRCLE_H_
#define _SCLASS4_9_CCIRCLE_H_

#include<iostream>
using namespace std;

//����CCircle��
class CCircle{
	public:
		void Reference();                   //���ڳ�Ա���� 
}; 

void Reference();                           //���⣬ȫ�����غ���
void Reference(CCircle &roCC);               //���⣬ȫ�����غ���

//���ʵ��

//��Ա����Reference()��ʵ��
void CCircle::Reference(){
	cout<<"���ǳ�Ա����."<<endl;
} 

//ȫ�����غ���Reference()��ʵ��
void Reference(){
	cout<<"����ȫ�����غ���Reference()."<<endl;
} 

//ȫ�����غ���Reference(CCircle &roCC)��ʵ��
void Reference(CCircle &roCC){
	cout<<"����ȫ�����غ���Reference(CCircle &roCC)."<<endl;
}

#endif
