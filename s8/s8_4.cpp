/*
������ת���������﷨Ϊ��
    operator <��������������>(){
        //����
		return <�����������͵�ֵ>; 
	}
����������ת������ʱ��Ӧע���������㣺
��1��������ת����������ķǾ�̬��Ա������
��2��������ת����������ʱ�������з���ֵ������˵����Ҳû���βΣ�����ʵ�β��롣 
*/

//�ù��캯����ɻ������͵������͵�ת����ֻ�ܴ�һ����Ĭ�ϲ���
//��������ת��������������ת��Ϊ������������

#include<iostream>
#include<assert.h>
using namespace std;                 //���ԣ��ṩ��assert�Ķ��� 

//����������CFigure
class CFigure{
public:
	//ֻ��һ��������ע��һ���������Բ��ô�Ĭ��ֵ��������������ת��λ������
	CFigure(double d=0):m_value(d){  //���캯��1 
		m_name="anonymity";
	} 
	//ֻ����һ����Ĭ�ϲ�����������������Ĭ��ֵ������ɻ������͵������͵�ת��
	CFigure(int a,string name="pseudonym"):m_value(a),m_name(name){
		;                            //���캯��2            
	} 
	//��������ת��Ϊһ��int����
	operator int(){                  //������ת������ 
		return m_value;
	} 
	//��������ת��Ϊһ��double����
	operator double(){
		return m_value;
	} 
	
	void print(){
		cout<<m_name<<":"<<m_value<<endl;
	}

private:
	double m_value;                  //�����ֵ
	string m_name;                   //������ 
}; 

//���Ժ���
int main(){
	int a;
	double b;
	CFigure oCF(5);                  //���ù��캯��2������һ������
	oCF.print();                     //�����pseudonym��5
	oCF=10;                          //���ù��캯��2����һ������ת��Ϊһ������
	oCF.print();                     //�����pseudonym��10
	a=int(oCF);                      //����operator int()���ɲ���ǿ������ת��
	cout<<"a="<<a<<endl;             //�����a=10
	oCF=12.128;                      //���ù��캯��1����һ��������ת��Ϊһ������
	oCF.print();                     //�����anonymity��12.128
	b=oCF;                           //����operator double()��δʹ��ǿ������ת��
	cout<<"a="<<a<<",b="<<b<<endl;   //�����a=12��b=12.128
	
	return 0; 
} 
