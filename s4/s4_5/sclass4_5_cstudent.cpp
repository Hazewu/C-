#include"sclass4_5_cstudent.h"

//�����Գ���
int main(){
	CPerson oCP(7,'m',"�ȶ�.�Ǵ�");                             //����һ��CPerson��Ķ���
	CStudent oCS(8,'f',"ϣ����.���ֶ�","Grade Tow");            //����һ��CStudent��Ķ���
	CClerk oCC(9,'m',"л����.����",5000.1);                     //����һ��CClerk��Ķ���
	COnJobStudent oCO(10,'m',"����.����","Grade One",4999.9);   //����һ����ְѧ������
	
	cout<<"\n1:-ͨ����������õ��ò�ͬ��Show():"<<endl;
	Reference(oCP);           //�Ի������oCP�����ò��� 
	Reference(oCS);           //�Ի������oCS�����ò���
	Reference(oCC);           //�Ի������oCC�����ò��� 
	Reference(oCO);           //�Ի������oCO�����ò��� 
	
	cout<<"\n2:-ͨ������ָ����ò�ͬ��Show():"<<endl;
	CPerson *poCP;            //����һ������ָ�� 
	poCP=&oCP;                //ָ�����CPerson����� 
	poCP->Show();              //����CPerson���Show() 
	poCP=&oCS;                //ָ��������CStudent����� 
	poCP->Show();              //����CStudent���Show() 
	poCP=&oCC;                //ָ��������CClerk����� 
	poCP->Show();              //����CClerk���Show() 
	poCP=&oCO;                //ָ��������������oCO 
	poCP->Show();              //����COnJobStudent���Show();
	                          //˵��ͨ������ָ��ɵ��ö����������麯�������麯�����д�����
	
	cout<<"\n3:-ͨ��һ��������ָ����ö����������Show():"<<endl;
	CStudent *poCS=&oCO;      //��һ��ָ��ָ����һ�������
	poCS->Show();             //����COnJobStudent���Show();
	COnJobStudent *poCO=&oCO; //����ָ��ָ�������
	poCO->Show();             //����COnJobStudent���Show();
	
	cin.get();
	return 0; 
} 
