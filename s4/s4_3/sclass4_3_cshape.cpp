#include"sclass4_3_cshape.h"

//�������ò��� 
void Reference(const CShape &roCS){                //�����������Ϊ���� 
	roCS.Show();
}

//�����Գ���
int main(){
	CShape oCS(1.1,2.0,3.0);                       //����һ��CShape��Ķ���
	CCircle oCC(10.0,20.1,30.0,100.0);             //����һ��CCircle��Ķ���
	CRectangle oCR(1.1,1.2,1.3,5.4,5.5);           //����һ��CRectangle��Ķ���
	CSquare oCSq(2.2,2.3,2.4,10.8);                 //����һ��CSquare��Ķ���
	
	cout<<"\n 1:-ͨ����������õ����麯������������-----."<<endl;
	Reference(oCS);
	Reference(oCC);
	Reference(oCR);
	Reference(oCSq);
	
	cout<<"\n 2:-ͨ�������ָ������麯������������----."<<endl;
	CShape *poCS;
	poCS=&oCS;
	poCS->Show();
	poCS=&oCC;
	poCS->Show();
	poCS=&oCR;
	poCS->Show();
	poCS=&oCSq;
	poCS->Show();
	
	cout<<"\n 3:-ͨ��������ò����������ԣ���������ȷ----."<<endl;
	oCS.Show();
	oCC.Show();
	oCR.Show();
	oCSq.Show();
	
	cin.get();
	return 0; 
} 
