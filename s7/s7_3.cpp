//��getline()����һ���ַ�
#include<iostream>
using namespace std;

int main(){
	char s[256];                  //�ַ���
	
	cout<<"����һ���ַ���"<<endl; //������ʾ
	cin.getline(s,8);             //����һ���ַ�
	cout<<s<<endl;                //����һ���ַ�
	
	system("PAUSE");
	return 0; 
} 
