#ifndef _SCLASS4_7_CSHAPE_H_
#define _SCLASS4_7_CSHAPE_H_

#include<iostream>
using namespace std;

//声明CShape类
class CShape{
	public:
		virtual double CalculateArea() const=0;  //声明纯虚函数
	protected:
	    double m_area; 
}; 

//声明CCircle类
class CCircle:public CShape{                     //CCircle类继承CShape类 
	public:
		CCircle(double radius);                   
		double CalculateArea() const;            //声明成员函数
	protected:
	    double m_radius;                         //圆的半径 
}; 

//声明CRectangle类
class CRectangle:public CShape{                  //CRectangle类继承CShape类 
	public:
		CRectangle(double length,double width);
		double CalculateArea() const;            //声明成员函数
	protected:
	    double m_length;                         //长
		double m_width;                          //宽 
}; 

//声明CSquare类
class CSquare:public CShape{                     //CSquare类继承CShape类 
	public:
		CSquare(double edge);
		double CalculateArea() const;            //声明成员函数
	protected:
	    double m_edge;                           //正方形的边长 
}; 

void Reference(CShape &roCS);                    //基类的引用作为形参 

//类的实现

//CCircle构造函数
CCircle::CCircle(double radius):CShape(),m_radius(radius){ //调用基类的默认构造函数 
	;
} 

//计算圆的面积
double CCircle::CalculateArea() const{
    cout<<"CCircle::"<<3.14*m_radius*m_radius<<"."<<endl;
    return 3.14*m_radius*m_radius;
} 

//CRectangle构造函数
CRectangle::CRectangle(double length,double width):CShape(),m_length(length),m_width(width){
	;
} 

//计算长方形的面积
double CRectangle::CalculateArea() const{
    cout<<"CRectangle::"<<m_length*m_width<<"."<<endl;
    return m_length*m_width;
} 

//CSquare构造函数
CSquare::CSquare(double edge):CShape(),m_edge(edge){
	;
} 

//计算正方形的面积
double CSquare::CalculateArea() const{
    cout<<"CSquare::"<<m_edge*m_edge<<endl;
    return m_edge*m_edge;
} 

//测试引用参数
void Reference(CShape &roCS){ //基类的引用作为形参，由于要修改引用对象，不能使用const 
	roCS.CalculateArea();
} 

#endif
