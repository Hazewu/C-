#include<iostream>
using namespace std;

//�����ۼ������
class Sum{
private:
//���ݳ�Ա 
	int sum;                   //���ڴ洢�ۼӺ�
	
public:
//���г�Ա
    Sum():sum(0){}             //���캯��
	void operator()(int e){    //���غ�������� 
		sum=sum+e;
	} 
	int GetSum()const{         //���ۼӺ� 
	    return sum;            //�����ۼӺ�sum 
	}
}; 

template<class It,class Fun>
Fun &ForEach(const It &begin,const It &end,Fun f){   //�����㷨 
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
	
	Sum &objSum=ForEach(begin,end,Sum());//���庯���������ã��������㷨�������� 
	cout<<"sum="<<objSum.GetSum()<<endl;  //����ۼӺ�
	
	system("PAUSE");
	return 0; 
}

//�������� ����������
//[Error] invalid initialization of non-const reference of type 'Sum&' from an rvalue of type 'Sum'
