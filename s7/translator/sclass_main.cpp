#include"sclass_ctranslator.h"
#include<iostream>
using namespace std;

int main(){
	string infName,outfName;               //�ļ���
	char ch;                               //�ַ�����
	
	cout<<"�������ļ�����Ĭ��:experiment.exp����";
	if((ch=cin.get())=='\n'){
		infName="experiment.exp";          //ֱ������س�����ʾĬ���ļ��� 
	}else{
		cin.putback(ch);                   //�������ַ�ch����������
		cin>>infName;                      //�����ļ��� 
	} 
	
	cout<<"�������ļ�����Ĭ�ϣ�experiment.cpp����";
	if((ch=cin.get())=='\n'){
		outfName="experiment.cpp";         //ֱ������س�����ʾĬ���ļ��� 
	}else{
		cin.putback(ch);                   //�������ַ�ch����������
		cin>>outfName;                     //�����ļ��� 
	}
	
	CTranslator objTrans(infName,outfName);//���������� 
	objTrans.Run();                        //����������
	
	system("PAUSE");
	return 0; 
} 

//�ô������ڴ����ճ�����û����⣬��Ҫϸ��������δʵ��Ŀ�� 
