//�������ļ�����COperator�����������������
#ifndef _SCLASS4_10_OPERATOR_H_
#define _SCLASS4_10_OPERATOR_H_

#include<iostream>
using namespace std;

//�����������
class COperator{
	public:
		COperator(int b=0);                  //���캯��
		
		int operator++(int i);               //���غ�׺++
		int operator++();                    //����ǰ׺++
		int operator()();                    //���غ�������������ܣ�ȡm_v��ֵ
		
		COperator operator=(int a);          //���ظ�ֵ�����
		COperator operator+(COperator ob);   //�������������������+����
		
		bool operator>(COperator ob);        //���رȽ������������>����
		bool operator<=(COperator ob);        //���رȽ������������<=���� 
		
	public:
		int m_v;
}; 

//���캯��
COperator::COperator(int b):m_v(b){
	;
} 

int COperator::operator++(int i){            //���غ�׺++����ȡֵ�����Լ� 
	int iRV=m_v;                             //����һ����ʱ���������������ԭ����ֵ
	if(m_v<65535)
	    m_v++;                               //�˴�++ΪϵͳĬ�Ϻ��壻��Ϊm_v�ǻ�����������
    else
	    m_v=0;
	return iRV;                              //���ض���ԭֵ��Ҳ�����޸�ǰ��ֵ 
}

int COperator::operator++(){                 //����ǰ׺++�����Լӣ���ȡֵ 
	if(m_v<65535) 
	    m_v++;
	else
	    m_v=0;
	return m_v;
}

int COperator::operator()(){                 //���غ�������������ܣ�ȡm_v��ֵ 
	return m_v;
}

COperator COperator::operator=(int a){       //���ظ�ֵ�������������ֵ������������ݳ�Ա 
	m_v=a;
	return *this; 
} 

COperator COperator::operator+(COperator ob){//�������������������+���� 
	m_v=m_v+ob.m_v;                          //�����������m_vֵ��ӣ���Ϊ���ض����ֵ
	if(m_v>65535)
	    m_v=m_v-65535;
	return *this;
} 

bool COperator::operator>(COperator ob){     //���رȽ������������>���� 
	if(m_v>ob.m_v)
	    return true;
	else
	    return false;
}

bool COperator::operator<=(COperator ob){    //���رȽ������������<=���� 
	if(m_v<=ob.m_v)
	    return true;
	else
	    return false;
} 

#endif 
