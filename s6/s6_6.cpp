//��ϵ�����������������ʹ��
#include<iostream>
#include<functional>
using namespace std;

int main(){
	//���涨��һЩ��ϵ��������
	equal_to<int> objEqual;                //������ں�������
	not_equal_to<int> objNotEqual;         //���岻���ں�������
	greater<int> objGreat;                 //������ں�������
	greater_equal<int> objGreatEqual;      //������ڵ��ں�������
	less<int> objLess;                     //����С�ں�������
	less_equal<int> objLessEqual;          //����С�ڵ��ں������� 
	
	//�����������涨��ĺ�������ʵ����Ӧ�ĺ�������
	cout<<objEqual(2,6)<<endl;
	cout<<objNotEqual(2,6)<<endl;
	cout<<objGreat(2,6)<<endl;
	cout<<objGreatEqual(2,6)<<endl;
	cout<<objLess(2,6)<<endl;
	cout<<objLessEqual(2,6)<<endl;
	
	//����ֱ�������ɵ���ʱ��������ʵ����غ�������
	cout<<equal_to<int>() (2,6)<<endl;
	cout<<not_equal_to<int>() (2,6)<<endl;
	cout<<greater<int>() (2,6)<<endl;
	cout<<greater_equal<int>() (2,6)<<endl;
	cout<<less<int>() (2,6)<<endl;
	cout<<less_equal<int>() (2,6)<<endl;
	
	system("PAUSE");
	return 0;
} 
