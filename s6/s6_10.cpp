//�������Ա�ʾ��
#include<iostream>
#include<list>
using namespace std;

int main(){
	list<int> la;                  //�����������
	
	for(int i=1;i<=6;i++){
		//���������Ա��в���ֵ
		la.push_back(i);           //�������β׷��i 
	} 
	
	//������ʾ����
	for(list<int>::iterator it=la.begin();it!=la.end();it++){
		//���������Ԫ�ص�ֵ
		cout<<*it<<" "; 
	} 
	cout<<endl;
	
	//������ʾ����
	for(list<int>::reverse_iterator rit=la.rbegin();rit!=la.rend();rit++){
		//���������Ԫ�ص�ֵ
		cout<<*rit<<" "; 
	} 
	cout<<endl;
	
	system("PAUSE");
	return 0;
} 
