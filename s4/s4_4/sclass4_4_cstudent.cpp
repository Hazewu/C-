#include"sclass4_4_cstudent.h"

int main(){
	CPerson *poCP;                                //����ָ���������ָ��
	CStudent oCS(8,"Clinton","Grade Two");        //����һ�����������
	poCP=&oCS;
	oCS.Show(1);
	//oCS.Show();
	poCP->Show();
	poCP->Show(1);
	
	return 0; 
}
