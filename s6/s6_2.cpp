#include<iostream>
using namespace std;

int sum=0;                          //���ڴ洢�ۼӺ�

void Sum(int e){                    //�ۼ���� 
	sum=sum+e;                      //sum�ۼ�e 
} 

template<class It,class Fun>
Fun &ForEach(const It &begin,const It &end,Fun &f){   //�����㷨 
	for(It it=begin;it!=end;it++){  
		//���ε���f()
		f(*it);                     //�����㷨 
	}
	return f;                       //����f 
}

int main(){
	int a[]={1,2,3,4,5,6};          //��������a
	int n=6;                        //Ԫ�ظ���
	int *begin=a;                   //��ʼ 
	int *end=a+n;                   //����
	
	ForEach(begin,end,Sum);         //���ñ����㷨
	cout<<"sum="<<sum<<endl;        //����ۼӺ�
	
	system("PAUSE");
	return 0; 
}
