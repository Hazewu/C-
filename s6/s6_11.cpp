//sort()��reverse()��Ա����ģ��ʹ��ʾ��
#include<iostream>
#include<list>
using namespace std;

int main(){
	list<int> la;                  //�����������
	list<int>::iterator it;        //���������
	int a[]={1,6,3,5,3,2},n=6;     //�������鼰���ͱ���
	
	for(int i=0;i<n;i++){
		//���������Ա��в���a[i] 
		la.push_back(a[i]);        //�������β׷��a[i] 
	} 
	
	for(it=la.begin();it!=la.end();it++){
		//���������Ԫ�ص�ֵ 
		cout<<*it<<" ";        
	}
	cout<<endl;
	
	la.reverse();                  //��ת����Ԫ��˳��
	for(it=la.begin();it!=la.end();it++){
		//���������Ԫ�ص�ֵ
		cout<<*it<<" "; 
	} 
	cout<<endl;
	
	la.sort();                     //������������
	for(it=la.begin();it!=la.end();it++){
		//���������Ԫ�ص�ֵ
		cout<<*it<<" "; 
	} 
	cout<<endl;
	
	system("PAUSE");
	return 0;
} 
