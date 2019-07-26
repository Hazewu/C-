#ifndef _SCLASS3_9_FURNITURE_H_
#define _SCLASS3_9_FURNITURE_H_

#include<iostream>
using namespace std;

class Furniture{                      //������������
    public:
        Furniture(float w);           
        void SetWeight(float w);      //��������
        float GetWeight();            //��������
    protected:
        float weight;                 //����
};

class Bed:virtual public Furniture{   //��������������Ϊ�����
    public:
        Bed(float w):Furniture(w){}   //һ�������๹�캯���������ʼ��������������ݳ�Ա
        void Sleep(void) const;       //˯��
};

class Sofa:virtual public Furniture{  //�ڶ���һ��������ʱ���뽫������������Ϊ�����
    public:
        Sofa(float w):Furniture(w){}  //һ�������๹�캯���������ʼ��������������ݳ�Ա
        void WatchTV(void) const;     //������
};

class SofaBed:public Sofa,public Bed{
    public:
        SofaBed(float w):Furniture(w),Sofa(w),Bed(w){}   //�����๹�캯���Ĳ���������ʼ��3����������ݳ�Ա
        void FoldOut(void);                              //�۵�
};

Furniture::Furniture(float w){         //���๹�캯��
    weight=w;
}

void Furniture::SetWeight(float w){         //��������
    weight=w;
    cout<<"�˼Ҿ���"<<weight<<"ǧ��"<<endl;
}

float Furniture::GetWeight(){
    return weight;
}

void Bed::Sleep(void) const{               //˯��
    cout<<"��ʼ˯����"<<endl;
}

void Sofa::WatchTV(void) const{            //������
    cout<<"���ڿ����ӡ�"<<endl;
}

void SofaBed::FoldOut(void){               //�۵�
    cout<<"�����۵��ʹ򿪡�"<<endl;
}
#endif
