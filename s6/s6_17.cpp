/*
��ѯ�㷨find()
ԭ�����£�
   template<class It,class Type>
   It find(It first,It last,const Type &e)
�Բ���˵�����£�
��1��It������ָ�����ͻ������
��2��first��ʾ�������ʼԪ�ػ������
��3��last��ʾ����βָ�������������������һ��Ԫ�أ�������֮��
��4��TypeΪģ�����Ͳ���
���ܣ���ѯ[first,last)���Ӧ��Ԫ��ֵ�Ƿ��е���e�ģ������򷵻���ָ�������������ޣ��򷵻�last 
*/

//��ѯ�㷨ʹ��ʾ��
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int a[]={1,4,2,8,5,6};                  //��������
	int n=sizeof(a)/sizeof(int);            //����Ԫ�ظ���
	int *begin=a;                           //��ʼ 
	int *end=a+n;                           //����
	int e=8;                                //Ԫ��ֵ 
	
	int *p=find(begin,end,e);               //ָ���״�Ԫ��ֵΪe�������ָ��
	cout<<"Ԫ��ֵΪ"<<e<<"��Ԫ�ص��±�Ϊ"<<p-a<<endl;
	                                        //��������Ϣ
	system("PAUSE");
	return 0; 
} 
