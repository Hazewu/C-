//�Ӽ���������һ���ַ����뵽һ���ı��ļ��У�Ȼ���ٴ�����ļ�����������ַ��� 
//��ͳ�����е�Ӣ��Сд��ĸ�ĸ���

#include<iostream>
#include<fstream>
using namespace std; 

int main(){
	char ch;                       //�ַ�����
	ofstream outFile("test.txt");  //��������ļ�����Ĭ���������ʽ���ļ�
	if(outFile.fail()){
		//���ļ�ʧ��
		cout<<"���ļ�ʧ�ܣ�"<<endl;
		exit(1); 
	} 
	cout<<"����һ�����֣�"<<endl;
	ch=cin.get();                  //����һ���ַ�ch
	while(ch!='\n'){
		outFile.put(ch);           //��ch���뵽�ļ���
		ch=cin.get();              //����һ���ַ�ch 
	} 
	outFile.close();               //�ر��ļ�
	
	int letters=0;                 //��ĸ����
	ifstream inFile("test.txt");   //���������ļ�����Ĭ�������뷽ʽ���ļ�
	if(inFile.fail()){
		//���ļ�ʧ��
		cout<<"���ļ�ʧ�ܣ�"<<endl;
		exit(2); 
	} 
	ch=inFile.get();               //���ļ�������һ���ַ�ch
	while(!inFile.eof()){
		//�ļ�δ����
		if(ch>='a'&&ch<='z'){ 
			letters++;             //��Ӣ��Сд��ĸ���м��� 
		} 
		ch=inFile.get();
	}
	cout<<"����Ӣ��Сд��ĸ"<<letters<<"��"<<endl;
	inFile.close();
	
	system("PAUSE");
	return 0; 
} 
