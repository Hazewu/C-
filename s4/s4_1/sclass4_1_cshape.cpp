#include"sclass4_1_cshape.h"

int main(){
	CShape oCS(1.1,2.0,3.0);              //����һ��CShape��Ķ���
	CShape *poCS;                         //�������CShape��ָ�����
	CCircle oCC(10.0,20.1,30.0,100);      //����һ��CCircle��Ķ���
	poCS=&oCS;                            //����ָ��ָ��������
	poCS->Show();                         //ͨ������ָ����û����Show()
	poCS=&oCC;                            //����ָ��ָ�����������
	poCS->Show();                         //ͨ������ָ������������Show()
	//���ݽ�������������ָ�룬ֻ�ܵ��ôӻ�������̳�����Show()�������޷������������Լ������Show()���� 
	return 0; 
}
