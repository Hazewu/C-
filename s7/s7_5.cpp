//����peek()�����޸���7.4
#include<iostream>
using namespace std;

char GetChar(istream &in=cin){             //��������in�������ո��ȡһ�ַ� 
	char ch;                               //�ַ�����
	
	while(in.peek()!=EOF                   //���˴��б䶯 
	    &&(ch=in.get())==' ');             //������ַ�Ϊ�ո񣬿��Բ���ո�
	
	return ch;                             //�����ַ� 
} 

int main(){
	char ch;                               //�ַ�����
	
	cout<<"������һ���ַ���"<<endl;        //������ʾ
	ch=GetChar();                          //�����ַ����Զ������ո�
	while(ch!='\n'&&ch!=EOF){
		cout.put(ch);                      //����ַ� 
		ch=GetChar();                      //�����ַ����Զ������ո� 
	} 
	cout<<endl;
	
	system("PAUSE");
	return 0;
}
