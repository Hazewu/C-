#ifndef _SCLASS4_7_CSHAPE_H_
#define _SCLASS4_7_CSHAPE_H_

#include<iostream>
using namespace std;

//����CShape��
class CShape{
	public:
		virtual double CalculateArea() const=0;  //�������麯��
	protected:
	    double m_area; 
}; 

//����CCircle��
class CCircle:public CShape{                     //CCircle��̳�CShape�� 
	public:
		CCircle(double radius);                   
		double CalculateArea() const;            //������Ա����
	protected:
	    double m_radius;                         //Բ�İ뾶 
}; 

//����CRectangle��
class CRectangle:public CShape{                  //CRectangle��̳�CShape�� 
	public:
		CRectangle(double length,double width);
		double CalculateArea() const;            //������Ա����
	protected:
	    double m_length;                         //��
		double m_width;                          //�� 
}; 

//����CSquare��
class CSquare:public CShape{                     //CSquare��̳�CShape�� 
	public:
		CSquare(double edge);
		double CalculateArea() const;            //������Ա����
	protected:
	    double m_edge;                           //�����εı߳� 
}; 

void Reference(CShape &roCS);                    //�����������Ϊ�β� 

//���ʵ��

//CCircle���캯��
CCircle::CCircle(double radius):CShape(),m_radius(radius){ //���û����Ĭ�Ϲ��캯�� 
	;
} 

//����Բ�����
double CCircle::CalculateArea() const{
    cout<<"CCircle::"<<3.14*m_radius*m_radius<<"."<<endl;
    return 3.14*m_radius*m_radius;
} 

//CRectangle���캯��
CRectangle::CRectangle(double length,double width):CShape(),m_length(length),m_width(width){
	;
} 

//���㳤���ε����
double CRectangle::CalculateArea() const{
    cout<<"CRectangle::"<<m_length*m_width<<"."<<endl;
    return m_length*m_width;
} 

//CSquare���캯��
CSquare::CSquare(double edge):CShape(),m_edge(edge){
	;
} 

//���������ε����
double CSquare::CalculateArea() const{
    cout<<"CSquare::"<<m_edge*m_edge<<endl;
    return m_edge*m_edge;
} 

//�������ò���
void Reference(CShape &roCS){ //�����������Ϊ�βΣ�����Ҫ�޸����ö��󣬲���ʹ��const 
	roCS.CalculateArea();
} 

#endif
