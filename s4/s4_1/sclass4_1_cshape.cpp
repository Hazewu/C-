#include"sclass4_1_cshape.h"

int main(){
	CShape oCS(1.1,2.0,3.0);              //创建一个CShape类的对象
	CShape *poCS;                         //定义基类CShape的指针变量
	CCircle oCC(10.0,20.1,30.0,100);      //创建一个CCircle类的对象
	poCS=&oCS;                            //基类指针指向基类对象
	poCS->Show();                         //通过基类指针调用基类的Show()
	poCS=&oCC;                            //基类指针指向派生类对象
	poCS->Show();                         //通过基类指针调用派生类的Show()
	//根据结果分析，基类的指针，只能调用从基类那里继承来的Show()函数，无法调用派生类自己定义的Show()函数 
	return 0; 
}
