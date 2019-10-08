#ifndef _SCLASS4_1_CSHAPE_H_
#define _SCLASS4_1_CSHAPE_H_

#include<iostream>
using namespace std;

//����CShape��
class CShape{
	public:
		CShape(double x,double y,double z);      //��������
		void Show() const;                       //��ʾ��������
	protected:
	    double m_x;
		double m_y;
		double m_z;
		double m_area;                           //��״����� 
};

//����CCircle��
class CCircle:public CShape{                     //CCircle��̳�CShape��
    public:
	    CCircle(double x,double y,double z,double radius); //Բ����������Ͱ뾶
		void Show() const;                       //��ʾԲ����������Ͱ뾶
	protected:
	    double m_radius;                         //Բ�İ뾶 
}; 

//CShape���캯��
CShape::CShape(double x,double y,double z):m_x(x),m_y(y),m_z(z){
	;
} 

//��ʾ��������
void CShape::Show() const{
    cout<<"x="<<m_x<<",y="<<m_y<<",z="<<m_z<<"."<<endl; 
} 

//CCircle�Ĺ��캯��
CCircle::CCircle(double x,double y,double z,double radius):CShape(x,y,z),m_radius(radius){//��ʼ���б� 
	;
} 

//��ʾԲ����������Ͱ뾶
void CCircle::Show() const{
    cout<<"x="<<m_x<<",y="<<m_y<<",z="<<m_z<<",radius="<<m_radius<<"."<<endl;
} 

#endif
