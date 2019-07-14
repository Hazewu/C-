#ifndef _SCLASS2_20_CNODE_H_
#define _SCLASS2_20_CNODE_H_

#include<iostream>
using namespace std;

class CStack;                                   //ǰ����������

class CNode{                                    //����CNode��ջ��㣩��
    public:
        CNode(int iData,CNode *preNode){
            m_iDate=iData;
            m_preNode=preNode;                  //ָ�� m_preNode=preNode
        }

        friend class CStack;                    //����CNode��Ϊ��Ԫ�࣬�����������г�Ա������ΪCStack�����Ԫ����
    private:
        int m_iDate;                            //���ֵ
        CNode *m_preNode;                       //ָ��ǰһ����ָ��
};
#endif
