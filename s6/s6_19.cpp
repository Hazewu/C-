/*
�����㷨sort()
����ԭ�ͣ�
   template<class It>
   void sort(It first,It last)
   
   template<class It,class Pred>
   void sort(It first,It last,Pred pr)
�Բ�����˵�����£�
��1��It������ָ�����ͻ��������
��2��first��ʾ��ʼָ�������� 
��3��last��ʾ����βָ�������������������һ��Ԫ�أ�������֮��
��4��Predָ��ͨȫ�ֺ�����Ԫ�������Ԫ�������������Ͳ���
���ܣ���һ������ģ�����ڽ�[first,last)���������ָ��ָʾ��Ԫ������Ĭ����������
      �ڶ�������ģ�嶨���˱ȽϺ���pr(x,y)����operator<(x,y)�����������Ƶ� 
*/ 

//����sort���������������������
#include<iostream>
#include<algorithm>
using namespace std;

template<class It>
void Show(const It &begin,const It &end){         //������ʾ 
	for(It it=begin;it!=end;it++){
		//������ʾ��Ԫ��
		cout<<*it<<" "; 
	}
	cout<<endl;
} 

int main(){
	int a[]={1,8,6,9,5,18};                       //��������
	int n=sizeof(a)/sizeof(int);                  //Ԫ�ظ���
	int *begin=a;
	int *end=a+n;
	
	cout<<"����ǰ��";                             //�����ʾ
	Show(begin,end);                              //�������Ԫ��ֵ
	sort(begin,end);                              //����
	cout<<"�����";                             //�����ʾ
	Show(begin,end);                              //�������Ԫ��ֵ
	
	system("PAUSE");
	return 0; 
}
