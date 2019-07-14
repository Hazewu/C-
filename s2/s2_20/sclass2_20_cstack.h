#ifndef _SCLASS2_20_CSTACK_H_
#define _SCLASS2_20_CSTACK_H_

#include"sclass2_20_cnode.h"

class CStack{                              //����CStack��ջ����
    public:
        CStack(void){
            m_pTop=0;                      //���캯����ջ����ʼ��
        }
        void Push(int iDate);              //��ջ����
        int Pop(void);                     //��ջ����
    private:
        CNode *m_pTop;                     //ͷָ��
};
void CStack::Push(int iDate){              //��ע�Ͳ�������
    CNode *newNode=new CNode(iDate,m_pTop);//����һ���½��ָ��newNodeָ����������ΪiDate��ǰһ�����ָ��Ϊm_pTop
    m_pTop=newNode;                        //���� m_pTop
}

int CStack::Pop(void){
    CNode *tempNode=m_pTop;               //һ����ʱָ�룬ָ��m_pTop 
    if(m_pTop){                           //��ջ������ 
        m_pTop=m_pTop->m_preNode;         //ջ��ָ���ƶ�����һ�� 
        int tempDate=tempNode->m_iDate;   // tempDate��ʱ����Ҫ��ջ������ 
        delete tempNode;                  //deleteɾ��ָ�� 
        return tempDate;                  //����tempDate 
    }else{
        cout<<"ջ�ѿգ�"<<endl;
        return 0;
    }
}

#endif

