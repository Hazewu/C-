#include"sclass4_7_cshape.h"

//主测试函数 
int main(){
	//CShape oCPerson();                     //不能创建抽象类CShape的对象
	CShape *poCS;                            //可以定义一个基类的指针
	CCircle oCC(10.0);                       //创建一个CCircle类的对象 
	CRectangle oCR(6.18,5.0);                //创建一个CRectangle类的对象 
	CSquare oCS(11.1);                       //创建一个CSquare类的对象 
	
	poCS=&oCC;                               //让抽象类指针指向oCC对象
	poCS->CalculateArea();                   //通过指针调用oCC的成员函数 
	poCS=&oCR;                               //让抽象类指针指向oCR对象
	poCS->CalculateArea();                   //通过指针调用oCR的成员函数 
	poCS=&oCS;                               //让抽象类指针指向oCS对象
	poCS->CalculateArea();                   //通过指针调用oCS的成员函数
	
	Reference(oCC);                          //以派生类对象oCC作引用参数 
	Reference(oCR);                          //以派生类对象oCR作引用参数 
	Reference(oCS);                          //以派生类对象oCS作引用参数
	
	return 0; 
}
