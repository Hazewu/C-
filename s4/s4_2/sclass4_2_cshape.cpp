#include"sclass4_2_cshape.h"

//测试引用函数
void Reference(const CShape &roCS){           //基类的引用作为形参 
	roCS.Show();
} 
int main(){
	CShape oCS(1.1,2.0,3.0);              //创建一个CShape类的对象
	CCircle oCC(10.0,20.1,30.0,100);      //创建一个CCircle类的对象
	Reference(oCS);
	Reference(oCC);
	cin.get();                            //等待键盘输入以实现暂停 
	return 0;
}

//通过引用，无法调用派生类的Show()函数 
