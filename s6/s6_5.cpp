//�����������������ʹ�� 
#include<iostream> 
#include<functional>
using namespace std;

int main(){
	//���涨��һЩ������������
	plus<int> objPlus;               //����ӷ���������
	minus<int> objMinus;             //���������������
	multiplies<int> objMul;          //����˷���������
	divides<int> objDiv;             //���������������
	modulus<int> objMod;             //����������������
	negate<int> objNeg;              //����ȡ����������
	
	//�����������涨��ĺ�������ʵ����Ӧ�ĺ�������
	cout<<objPlus(2,6)<<endl;
	cout<<objMinus(2,6)<<endl;
	cout<<objMul(2,6)<<endl;
	cout<<objDiv(2,6)<<endl;
	cout<<objMod(2,6)<<endl;
	cout<<objNeg(2)<<endl;
	
	//����ֱ�������ɵ���ʱ��������ʵ����غ�������
	cout<<plus<int>() (2,6)<<endl;
	cout<<minus<int>() (2,6)<<endl;
	cout<<multiplies<int>() (2,6)<<endl;
	cout<<divides<int>() (2,6)<<endl;
	cout<<modulus<int>() (2,6)<<endl;
	cout<<negate<int>() (2)<<endl;
	
	system("PAUSE");
	return 0; 
}
