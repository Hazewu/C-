#include"sclass4_2_cshape.h"

//�������ú���
void Reference(const CShape &roCS){           //�����������Ϊ�β� 
	roCS.Show();
} 
int main(){
	CShape oCS(1.1,2.0,3.0);              //����һ��CShape��Ķ���
	CCircle oCC(10.0,20.1,30.0,100);      //����һ��CCircle��Ķ���
	Reference(oCS);
	Reference(oCC);
	cin.get();                            //�ȴ�����������ʵ����ͣ 
	return 0;
}

//ͨ�����ã��޷������������Show()���� 
