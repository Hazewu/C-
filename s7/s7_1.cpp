/*
C++���ڴ���Ϊÿһ������������һ�����������ڴ�����е����ݡ�
ʹ��cout<<ʱ��ʵ�������Ƚ���Щ���ݴ��͵������е��������������������
ֱ��������������ˡ�����endl������Ѿ��������Ž��������е�ȫ�����ݴ��͵���ʾ������ʾ����
1����׼���������cout
cout��console output��Ӣ����д����ʾ�ڿ���̨���ն���ʾ�����������
cout���������ostream�Ķ���
2����������Ա����put()
����������ַ���������put()ʵ�֣�һ��ʹ�ø�ʽΪ��
���������.put(ch)������chΪҪ������ַ� 
*/

//����put()ʹ��ʾ��
#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char s[]="Hello, world!";           //�����ַ���
	
	for(int i=0;i<strlen(s);i++){       //strlen()������cstringͷ�ļ��� 
		cout.put(s[i]);                 //�����i+1���ַ� 
	} 
	cout<<endl;              
	
	system("PAUSE");
	return 0;
} 

 
