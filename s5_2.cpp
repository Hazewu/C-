//���к���ģ���ͬ�����غ�����ƥ�����
#include<iostream>
#include<string>
using namespace std;

//����ȫ�����غ���
int GetMax(int a,int b)                 //�����������͵����ֵ
{
    cout<<"����GetMax(int,int):";       //������ʾ�����õĺ���
    return (a>b)?a:b;
}

//����ȫ�����غ���
char GetMax(char a,char b)             //�������ַ������͵����ֵ
{
    cout<<"����GetMax(char,char):";
    return (a>b)?a:b;
}

//���庯��ģ��1�������غ���ģ��
template<class Type1,class Type2>
Type1 GetMax(Type1 x,Type2 y)
{
    cout<<"���ú���ģ��1����";
    return x>y?x:y;                     //�Զ�ת��Ϊ�������ٱȽ�
}

//���庯��ģ��2�������غ���ģ��
template<class Type1,class Type2,class Type3>
Type1 GetMax(Type1 a,Type2 b,Type3 c)
{
    Type1 t;
    t=a>b?a:b;
    cout<<"���ú���ģ��2����";
    return t>c?t:c;
}
//ʹ�ò�ͬ��Type1��Type2��Type3��ʹ�������Ϳ��Բ�һ�� 
int main() 
{
    cout<<"\t"<<GetMax(10,20)<<endl;                   //�������غ���,ֻ��Ϊ����ʾ�� 
    cout<<"\t"<<GetMax('A','i')<<endl;

    cout<<"\t"<<GetMax(1.0,2.0)<<endl;                 //���ú���ģ��1
    cout<<"\t"<<GetMax('A',100)<<endl;

    cout<<"\t"<<GetMax(10,5.0)<<endl;                  //���ú���ģ��1
    cout<<"\t"<<GetMax(11.1,5)<<endl;
    cout<<"\t"<<GetMax(22,10L)<<endl;
    cout<<"\t"<<GetMax(2L,'A')<<endl;
    cout<<"\t"<<GetMax(1.0,200L)<<endl;

    cout<<"\t"<<GetMax(10,20,30)<<endl;                //���ú���ģ��2
    cout<<"\t"<<GetMax(10L,20,30)<<endl;
    cout<<"\t"<<GetMax(1.1,2.2,3)<<endl;
    cout<<"\t"<<GetMax(99.9,8,'A');

    cin.get();
    return 0;
}
