#include"sclass4_4_cstudent.h"

int main(){
	CPerson *poCP;                                //定义指向基类对象的指针
	CStudent oCS(8,"Clinton","Grade Two");        //创建一个派生类对象
	poCP=&oCS;
	oCS.Show(1);
	//oCS.Show();
	poCP->Show();
	poCP->Show(1);
	
	return 0; 
}
