//queueʹ��ʾ��
#include<iostream>
#include<list>
#include<queue>
using namespace std;

int main(){
	queue<int,list<int> > q;         //������ж���
	for(int i=1;i<=5;i++){
		//������� 
		q.push(i);                  //i��� 
	} 
	
	cout<<"����q��";                //�����ʾ
	while(!q.empty()){
		//����q�ǿ�
		cout<<q.front()<<" ";       //�������
		q.pop();                    //���� 
	} 
	cout<<endl;
	
	system("PAUSE");
	return 0;
} 
