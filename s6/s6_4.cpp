#include<iostream>
using namespace std;

//�����ۼ������Sum
template<class Type>
class Sum{
private:
//���ݳ�Ա 
	Type sum;                            //�����ۼ����
public:
//���г�Ա
    Sum():sum(0){}                       //���캯��ģ��
	void operator()(Type e){             //���غ���ģ������� 
		sum=sum+e;                       //sum�ۼ�e 
	} 
	Type GetSum() const{                 //���ۼӺ� 
	    return sum;
	}
}; 

template<class It,class Fun>               
Fun &ForEach(const It &begin,const It &end,Fun f){//�����㷨 
	for(It it=begin;it!=end;it++){
		//���ε���
		f(*it);                          //����f() 
	}
	return f;                            //����f 
}

int main(){
	int a[]={1,2,3,4,5,6};               //��������a
	int n=6;                             //Ԫ�ظ���
	int *begin=a;
	int *end=a+n;
	
	Sum<int> &objSum=ForEach(begin,end,Sum<int>());
	                                     //���庯���������ã������ñ����㷨 
    cout<<"sum="<<objSum.GetSum()<<endl; //����ۼӺ�
	system("PAUSE");
	return 0; 
}
//��������һ�㣬��s6_3.cpp��ͬ�������� 
