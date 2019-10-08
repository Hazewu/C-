#ifndef _SCLASS4_3_CSHAPE_H_
#define _SCLASS4_3_CSHAPE_H_

#include<iostream>
using namespace std;

//����CShape��
class CShape{
	public:
		CShape(double x,double y,double z);      //��������
		virtual void Show() const;               //����˹ؼ���virtual��ʾ�麯��
	protected:
	    double m_x;
		double m_y;
		double m_z;
		double m_area; 
}; 

//����CCircle��
class CCircle:public CShape{                      //CCircle��̳�CShape 
	public:
		CCircle(double x,double y,double z,double radius);//Բ����������Ͱ뾶
		void Show() const;                        //��ʾԲ����������Ͱ뾶
	protected:
	    double m_radius; 
}; 

//����CRectangle��
class CRectangle:public CShape{                   //CRectangle��̳�CShape�� 
    public:
    	CRectangle(double x,double y,double z,double length,double weight);//�����ε��������꣬���Ϳ�
		void Show() const; 
	protected:
		double m_length;
		double m_weight;
};

//����CSquare��
class CSquare:public CShape{                     //CSquare��̳�CSahpe�� 
	public:
		CSquare(double x,double y,double z,double edge);//�����ε���������ͱ߳�
		void Show() const;
	protected:
	    double m_edge; 
}; 

//CShape���캯��
CShape::CShape(double x,double y,double z):m_x(x),m_y(y),m_z(z){
	;
} 

//��ʾ��������
void CShape::Show() const{
    cout<<"x="<<m_x<<",y="<<m_y<<",z="<<m_z<<"."<<endl;
} 

//CCircle���캯��
CCircle::CCircle(double x,double y,double z,double radius):CShape(x,y,z),m_radius(radius){
	;                                                     //���û���Ĺ��캯�� 
} 

//��ʾԲ�����������Բ�İ뾶
void CCircle::Show() const{
    cout<<"x="<<m_x<<",y="<<m_y<<",z="<<m_z<<",radius="<<m_radius<<"."<<endl;
} 

//CRectangle���캯��
CRectangle::CRectangle(double x,double y,double z,double length,double weight):CShape(x,y,z),m_length(length),m_weight(weight){
	;
}

//��ʾ�����ε��������꼰�䳤�Ϳ�
void CRectangle::Show() const{
    cout<<"x="<<m_x<<",y="<<m_y<<",z="<<m_z<<",length="<<m_length<<",weight="<<m_weight<<"."<<endl;
} 

//CSquare���캯��
CSquare::CSquare(double x,double y,double z,double edge):CShape(x,y,z),m_edge(edge){
    ;
}

//��ʾ�����ε���������ͱ߳�
void CSquare::Show() const{
    cout<<"x="<<m_x<<",y="<<m_y<<",z="<<m_z<<",edge="<<m_edge<<"."<<endl;
}
 
#endif


