//���ļ�
#include"sclass4_10_coperator.h"

//������
int main(){
	COperator oCO1,oCO2(10);
	oCO1=++oCO2;            //�˴�Ϊ���ص�ǰ׺++����Ϊ oCO2��COperator�Ķ���
	                        //oCO1()��������()����ΪoCO1��COperator�Ķ���
	cout<<"ǰ׺++��"<<oCO1()<<"="<<oCO2.m_v<<endl; 
	oCO1=oCO2++;            //�˴�Ϊ���غ�׺++����ΪoCO2��COperator�Ķ���
	cout<<"��׺++��"<<oCO1.m_v<<"<"<<oCO2.m_v<<endl;
	oCO1=10;                //�������������=����10��ֵ������
	cout<<"��ֵ=��"<<oCO1.m_v<<endl;
	oCO2=oCO2+oCO1;
	cout<<"����+����"<<oCO1.m_v<<";"<<oCO2.m_v<<endl;
	cout<<"����>����"<<(oCO2>oCO1)<<endl;
	cout<<"����<=����"<<(oCO2<=oCO1)<<endl;
	
	return 0; 
} 
