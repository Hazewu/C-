#include"sclass4_6_cstudent.h"

//�����Ժ��� 
int main(){
	CPerson *poCP=new CStudent;      //����һ��CStudent�Ķ�̬���󣬻���ָ��ָ����
	if(NULL==poCP){                  //���new����ʧ�ܣ����˳�
	    exit(0);                     //����0��ʾ�������˳����� 
	} 
	delete poCP;                     //ͨ������ָ���������������
	cout<<"ͨ��delete����new����������Ķ��������\n"<<endl;
	CStudent oCSt;                   //����һ��CStudent���󣬲�����deleteʱ�������ܹ���ȷ����
	return 0;
	
	//����� sclass4_6_cstudent.h����Ļ�����������ǰ���virtualȥ�������в�ͬ�Ľ����new�����Ķ������ٲ���ȫ 
}
