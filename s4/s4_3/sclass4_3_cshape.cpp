#include"sclass4_3_cshape.h"

//测试引用参数 
void Reference(const CShape &roCS){                //基类的引用作为形象 
	roCS.Show();
}

//主测试程序
int main(){
	CShape oCS(1.1,2.0,3.0);                       //创建一个CShape类的对象
	CCircle oCC(10.0,20.1,30.0,100.0);             //创建一个CCircle类的对象
	CRectangle oCR(1.1,1.2,1.3,5.4,5.5);           //创建一个CRectangle类的对象
	CSquare oCSq(2.2,2.3,2.4,10.8);                 //创建一个CSquare类的对象
	
	cout<<"\n 1:-通过基类的引用调用虚函数具有虚特性-----."<<endl;
	Reference(oCS);
	Reference(oCC);
	Reference(oCR);
	Reference(oCSq);
	
	cout<<"\n 2:-通过基类的指针调用虚函数具有虚特性----."<<endl;
	CShape *poCS;
	poCS=&oCS;
	poCS->Show();
	poCS=&oCC;
	poCS->Show();
	poCS=&oCR;
	poCS->Show();
	poCS=&oCSq;
	poCS->Show();
	
	cout<<"\n 3:-通过对象调用不具有虚特性，但调用正确----."<<endl;
	oCS.Show();
	oCC.Show();
	oCR.Show();
	oCSq.Show();
	
	cin.get();
	return 0; 
} 
