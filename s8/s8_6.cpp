/*
ʹ�������ռ䣬�ȶ��壬��ʹ�á�
���������ռ���﷨��ʽ���£�
   namespace namespace_name{
        //�������֣��������������������ͺ����������������߶��� 
   } 
����ʹ�÷��������﷨��ʽ���£�
   �����ռ����֣��������ռ��Ա
   using namespace <���ֿռ�����>;
   
û�����ֵ������ռ�
���Զ��壺
   namespace{                    //���������ռ�û�о�������� 
       int Function(){
	         //
	   }
   } 
*/

//�����ռ��ʹ��
#include<iostream>
using namespace std;

int iNum=10000;                  //ȫ�ֱ���

//MyNameSpace.h
namespace MyNameSpace{           //���������ռ�MyNameSpace 
	int iNum=2000;               //MyNameSpace�ռ��еı���
	int Add(int iNum){           //MyNameSpace�ռ��еĺ���Add() 
		iNum=iNum+iNum;          //���ʵ���Add�ڵľֲ�����
		return iNum; 
	} 
} 

//YourNameSpace.h
namespace YourNameSpace{         //���������ռ�YourNameSpace 
	int iNum=300000;             //YourNameSpace�ռ��еı���
	int Add(int iNum){           //YourNameSpace�ռ��еĺ��� 
		iNum=::iNum+iNum;        //::iNum����ȫ��iNum
		return iNum; 
	} 
}

//���Գ���
int main(){
	cout<<MyNameSpace::Add(1)+::iNum<<endl;  //ʹ��ȫ��iNum
	cout<<MyNameSpace::Add(1)+iNum<<endl;    //ʹ��ȫ��iNum
	
	namespace N2=YourNameSpace;              //����YourNameSpace�ı���
	cout<<N2::Add(1)+N2::iNum<<endl;         //��ʾʹ�õ���YourNameSpace�����ռ�
	
	using namespace YourNameSpace;           //ʹ��using�ؼ���
	cout<<Add(1)+MyNameSpace::iNum<<endl;    //������ȫ��iNum������Ҫʹ���������޶�����
	//����ȫ��Add()���������������޶���ϵͳ֪�����õ���YourNameSpace�ռ��е�Add()
	//cout<<iNum<<endl;                      //�����������iNum���ֶ�����
	
	return 0; 
} 
