#ifndef _SCLASS4_3_CSHAPE_H_
#define _SCLASS4_3_CSHAPE_H_

#include<iostream>
using namespace std;

//声明CShape类
class CShape{
	public:
		CShape(double x,double y,double z);      //重心坐标
		virtual void Show() const;               //添加了关键字virtual表示虚函数
	protected:
	    double m_x;
		double m_y;
		double m_z;
		double m_area; 
}; 

//声明CCircle类
class CCircle:public CShape{                      //CCircle类继承CShape 
	public:
		CCircle(double x,double y,double z,double radius);//圆的重心坐标和半径
		void Show() const;                        //显示圆的重心坐标和半径
	protected:
	    double m_radius; 
}; 

//声明CRectangle类
class CRectangle:public CShape{                   //CRectangle类继承CShape类 
    public:
    	CRectangle(double x,double y,double z,double length,double weight);//长方形的重心坐标，长和宽
		void Show() const; 
	protected:
		double m_length;
		double m_weight;
};

//声明CSquare类
class CSquare:public CShape{                     //CSquare类继承CSahpe类 
	public:
		CSquare(double x,double y,double z,double edge);//正方形的重心坐标和边长
		void Show() const;
	protected:
	    double m_edge; 
}; 

//CShape构造函数
CShape::CShape(double x,double y,double z):m_x(x),m_y(y),m_z(z){
	;
} 

//显示重心坐标
void CShape::Show() const{
    cout<<"x="<<m_x<<",y="<<m_y<<",z="<<m_z<<"."<<endl;
} 

//CCircle构造函数
CCircle::CCircle(double x,double y,double z,double radius):CShape(x,y,z),m_radius(radius){
	;                                                     //调用基类的构造函数 
} 

//显示圆的重心坐标和圆的半径
void CCircle::Show() const{
    cout<<"x="<<m_x<<",y="<<m_y<<",z="<<m_z<<",radius="<<m_radius<<"."<<endl;
} 

//CRectangle构造函数
CRectangle::CRectangle(double x,double y,double z,double length,double weight):CShape(x,y,z),m_length(length),m_weight(weight){
	;
}

//显示长方形的重心坐标及其长和宽
void CRectangle::Show() const{
    cout<<"x="<<m_x<<",y="<<m_y<<",z="<<m_z<<",length="<<m_length<<",weight="<<m_weight<<"."<<endl;
} 

//CSquare构造函数
CSquare::CSquare(double x,double y,double z,double edge):CShape(x,y,z),m_edge(edge){
    ;
}

//显示正方形的重心坐标和边长
void CSquare::Show() const{
    cout<<"x="<<m_x<<",y="<<m_y<<",z="<<m_z<<",edge="<<m_edge<<"."<<endl;
}
 
#endif


