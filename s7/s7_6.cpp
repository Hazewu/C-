//�������һ��˫����ʵ��������ͬ��֮���ÿո������
//����ÿ��ʵ������ʮ�������ֿ�ʼ
#include<iostream>
using namespace std;

char GetChar(istream &in=cin){     //��������in�������ո��ȡһ�ַ� 
	char ch;                       //�ַ����� 
	while(in.peek()!=EOF           //δ�����ļ������� 
	    &&((ch=in.get())==' '));   //������ַ�Ϊ�ո�
	return ch;                     //�����ַ� 
} 

int main(){
	char ch;                       //�ַ�����
	double x;                      //˫����ʵ�ͱ���
	
	ch=GetChar();                  //�����ո�����һ���ַ�
	while(ch!='\n'&&ch!=EOF){
		if(ch>='0'&&ch<='9'){      //chֻ�ܶ�һ���ַ��������жϵ�ǰ�ַ��Ƿ�Ϊ ʵ����ʼ�ַ� 
			//��ʵ���Ŀ�ʼ�ַ�
			cin.putback(ch);       //��ch���͵�����������cin��,����û�г�������ʾ���� 
			cin>>x;                //����˫����ʵ��x��x���Զ���/���һ��ʵ�� 
			cout<<x<<" ";          //���˫����ʵ��x 
		}else{
			//�Ƿ��ַ�
			cout<<"���ַǷ��ַ���"<<endl;
			exit(1);                //�˳����� 
		} 
		ch=GetChar();               //�����ո�����һ���ַ� 
	} 
	cout<<endl;
	
	system("PAUSE");
	return 0;
}
