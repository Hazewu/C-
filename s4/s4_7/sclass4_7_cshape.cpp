#include"sclass4_7_cshape.h"

//�����Ժ��� 
int main(){
	//CShape oCPerson();                     //���ܴ���������CShape�Ķ���
	CShape *poCS;                            //���Զ���һ�������ָ��
	CCircle oCC(10.0);                       //����һ��CCircle��Ķ��� 
	CRectangle oCR(6.18,5.0);                //����һ��CRectangle��Ķ��� 
	CSquare oCS(11.1);                       //����һ��CSquare��Ķ��� 
	
	poCS=&oCC;                               //�ó�����ָ��ָ��oCC����
	poCS->CalculateArea();                   //ͨ��ָ�����oCC�ĳ�Ա���� 
	poCS=&oCR;                               //�ó�����ָ��ָ��oCR����
	poCS->CalculateArea();                   //ͨ��ָ�����oCR�ĳ�Ա���� 
	poCS=&oCS;                               //�ó�����ָ��ָ��oCS����
	poCS->CalculateArea();                   //ͨ��ָ�����oCS�ĳ�Ա����
	
	Reference(oCC);                          //�����������oCC�����ò��� 
	Reference(oCR);                          //�����������oCR�����ò��� 
	Reference(oCS);                          //�����������oCS�����ò���
	
	return 0; 
}
