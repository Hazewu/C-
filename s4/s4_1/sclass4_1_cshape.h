#ifndef _SCLASS4_1_CSHAPE_H_
#define _SCLASS4_1_CSHAPE_H_

#include<iostream>
using namespace std;

//声明CShape类
class CShape{
	public:
		CShape(double x,double y,double z);      //重心坐标
		void Show() const;                       //显示重心坐标
	protected:
	    double m_x;
		double m_y;
		double m_z;
		double m_area;                           //形状的面积 
};

//声明CCircle类
class CCircle:public CShape{                     //CCircle类继承CShape类
    public:
	    CCircle(double x,double y,double z,double radius); //圆的重心坐标和半径
		void Show() const;                       //显示圆的重心坐标和半径
	protected:
	    double m_radius;                         //圆的半径 
}; 

//CShape构造函数
CShape::CShape(double x,double y,double z):m_x(x),m_y(y),m_z(z){
	;
} 

//显示重心坐标
void CShape::Show() const{
    cout<<"x="<<m_x<<",y="<<m_y<<",z="<<m_z<<"."<<endl; 
} 

//CCircle的构造函数
CCircle::CCircle(double x,double y,double z,double radius):CShape(x,y,z),m_radius(radius){//初始化列表 
	;
} 

//显示圆的重心坐标和半径
void CCircle::Show() const{
    cout<<"x="<<m_x<<",y="<<m_y<<",z="<<m_z<<",radius="<<m_radius<<"."<<endl;
} 

#endif
