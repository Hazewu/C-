#include"sclass4_9_ccircle.h"

//主测试函数
int main(){
	CCircle oCC;                 //调默认构造函数创建oCC对象
	Reference();                 //调用全局重载函数Reference()
	Reference(oCC);              //调用全局重载函数Reference(CCircle &roCC)
	oCC.Reference();             //调用oCC的成员函数
	
	return 0; 
} 
