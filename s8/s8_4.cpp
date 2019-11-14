/*
类类型转换函数的语法为：
    operator <基本数据类型名>(){
        //……
		return <基本数据类型的值>; 
	}
定义类类型转换函数时，应注意下列两点：
（1）类类型转换函数是类的非静态成员函数。
（2）类类型转换函数定义时，不进行返回值的类型说明，也没有形参，但有实参参与。 
*/

//用构造函数完成基本类型到类类型的转换，只能带一个非默认参数
//用类类型转换函数将类类型转换为基本数据类型

#include<iostream>
#include<assert.h>
using namespace std;                 //断言，提供宏assert的定义 

//声明并定义CFigure
class CFigure{
public:
	//只带一个参数（注：一个参数可以不用带默认值），将基本类型转换位类类型
	CFigure(double d=0):m_value(d){  //构造函数1 
		m_name="anonymity";
	} 
	//只带有一个非默认参数（其余参数必须带默认值），完成基本类型到类类型的转换
	CFigure(int a,string name="pseudonym"):m_value(a),m_name(name){
		;                            //构造函数2            
	} 
	//将类类型转化为一个int类型
	operator int(){                  //类类型转换函数 
		return m_value;
	} 
	//将类类型转化为一个double类型
	operator double(){
		return m_value;
	} 
	
	void print(){
		cout<<m_name<<":"<<m_value<<endl;
	}

private:
	double m_value;                  //对象的值
	string m_name;                   //对象名 
}; 

//测试函数
int main(){
	int a;
	double b;
	CFigure oCF(5);                  //调用构造函数2，创建一个对象
	oCF.print();                     //输出：pseudonym：5
	oCF=10;                          //调用构造函数2，将一个整数转化为一个对象
	oCF.print();                     //输出：pseudonym：10
	a=int(oCF);                      //调用operator int()，可不用强制类型转换
	cout<<"a="<<a<<endl;             //输出：a=10
	oCF=12.128;                      //调用构造函数1，将一个浮点数转化为一个对象
	oCF.print();                     //输出：anonymity：12.128
	b=oCF;                           //调用operator double()，未使用强制类型转换
	cout<<"a="<<a<<",b="<<b<<endl;   //输出：a=12，b=12.128
	
	return 0; 
} 
