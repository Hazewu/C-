#ifndef _SCLASS2_20_CNODE_H_
#define _SCLASS2_20_CNODE_H_

#include<iostream>
using namespace std;

class CStack;                                   //前向引用声明

class CNode{                                    //定义CNode（栈结点）类
    public:
        CNode(int iData,CNode *preNode){
            m_iDate=iData;
            m_preNode=preNode;                  //指针 m_preNode=preNode
        }

        friend class CStack;                    //由于CNode类为友元类，所以它的所有成员函数成为CStack类的友元函数
    private:
        int m_iDate;                            //结点值
        CNode *m_preNode;                       //指向前一结点的指针
};
#endif
