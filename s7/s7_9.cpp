//���ʵ����ʾһ���ı��ļ�������

#include<iostream>
#include<fstream>
using namespace std;

int main(){
	char s[318],fName[20];     //�ַ���
	ifstream f;                //�ļ�������
	
	cout<<"�������ļ�����";    
	cin>>fName;                //�����ļ���
	f.open(fName);             //���ļ�
	if(f.fail()){
		//���ļ�ʧ��
		cout<<"���ļ�ʧ�ܣ�"<<endl;
		exit(1); 
	} 
//	f.getline(s,318);          //���ļ�������һ���ַ�,�ļ������ݲ���ʱ����ֱ�Ӷ��꣬f.eof()���� 
	while(!f.eof()){
		//�ļ�δ����
		f.getline(s,318);      //���ļ�������һ���ַ�
		cout<<s<<endl;         //���һ���ַ� 
	} 
	f.close();
	
	system("PAUSE");
	return 0;
} 
