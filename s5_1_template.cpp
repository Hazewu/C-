//ͨ������ģ��ʵ����3����ͬ��������������������һ�� 
#include<iostream>
#include<string>
using namespace std;

template<class Type>    //��������ģ��1
Type GetMax(Type a,Type b,Type c);

//������
int main()
{
    string str1("Rong Ji"),str2("Zhe Ming"),str3("Jing Tao");   //�˽���string����
    //ʹ��ģ�庯��1
    cout<<"int:10,30,21,max="<<GetMax(10,30,21)<<endl;
    cout<<"double:51.8,20.8,31.6,max="<<GetMax(51.8,20.8,31.6)<<endl;
    cout<<"char:'A','b','z',max="<<GetMax('A','b','z')<<endl;
    cout<<"string:str1(\"Rong Ji\"),str2(\"Zhe Ming\"),str3(\"Jing Tao\"),max="<<GetMax(str1,str2,str3)<<endl; //�Ƚ������ַ�������Ĵ�С

    cin.get();  //��ʲô��˼��
    /*   //�����򵥵�ʾ��s5_1_note_1.cpp
    #include<iostream>
    using namespace std;
	int main()
	{
	    char a,b;
	    a=cin.get();
	    cin.get(b);
	    cout<<a<<b<<endl;
	    system("pause");
	    return 0;
    }
	*/ 
    return 0;
}

//���庯��ģ��1
template<class Type>
Type GetMax(Type a,Type b,Type c)
{
    Type t;
    t=a>b?a:b;            //��a��b�Ľϴ���
    return t>c?t:c;       //����a��b��c�������
}
