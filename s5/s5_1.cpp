//ͨ������ģ��ʵ����3����ͬ������������������һ��

#include<iostream>
#include<string>
using namespace std;

template <class Type>           //��������ģ��1
Type GetMax(Type a,Type b,Type c);

//������
int main(){
	string str1("Rong Ji"),str2("Zhe Ming"),str3("Jing Tao");
	//ʹ�ú���ģ��1
	cout<<"int:10,30,21,max="<<GetMax(10,30,21) <<endl;
	cout<<"double:51.8,20.8,31.6,max="<<GetMax(51.8,20.8,31.6)<<endl;
	cout<<"char:'A','b','Z',max="<<GetMax('A','b','Z')<<endl;
	cout<<"string:str1(\"Rong Ji\"),str2(\"Zhe Ming\"),str3(\"Jing Tao\"),max="<<GetMax(str1,str2,str3)<<endl;
            //ע���Ƚ������ַ�������Ĵ�С 
    cin.get(); 
}

//����ģ�庯��1
template <class Type>
Type GetMax(Type a,Type b,Type c){
	Type t;
	t=a>b?a:b;           //��a��b�Ľϴ���
	return t>c?t:c;      //����a��b��c������� 
} 
