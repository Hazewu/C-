//�߼����������÷�ʾ��
#include<iostream>
#include<functional>
using namespace std;

int main(){
	//���涨��һЩ�߼���������
	logical_and<int> objAnd;                   //�����߼��뺯������
	logical_or<int> objOr;                     //�����߼���������
	logical_not<int> objNot;                   //�����߼��Ǻ�������
	
	//�����������涨��ĺ�������ʵ����Ӧ�ĺ�������
	cout<<objAnd(true,true)<<endl;
	cout<<objOr(true,false)<<endl;
	cout<<objNot(true)<<endl;
	
	//����ֱ�������ɵ���ʱ����ʵ����غ�������
	cout<<logical_and<int>() (true,true)<<endl;
	cout<<logical_or<int>() (true,false)<<endl;
	cout<<logical_not<int>() (true)<<endl;
	
	system("PAUSE");
	return 0;
} 
