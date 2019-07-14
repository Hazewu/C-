#ifndef _SCLASS2_20_CSTACK_H_
#define _SCLASS2_20_CSTACK_H_

#include"sclass2_20_cnode.h"

class CStack{                              //定义CStack（栈）类
    public:
        CStack(void){
            m_pTop=0;                      //构造函数，栈顶初始化
        }
        void Push(int iDate);              //入栈操作
        int Pop(void);                     //出栈操作
    private:
        CNode *m_pTop;                     //头指针
};
void CStack::Push(int iDate){              //需注释操作分析
    CNode *newNode=new CNode(iDate,m_pTop);//申请一个新结点指针newNode指向它，内容为iDate，前一个结点指针为m_pTop
    m_pTop=newNode;                        //更新 m_pTop
}

int CStack::Pop(void){
    CNode *tempNode=m_pTop;               //一个临时指针，指向m_pTop 
    if(m_pTop){                           //若栈顶不空 
        m_pTop=m_pTop->m_preNode;         //栈顶指针移动到上一个 
        int tempDate=tempNode->m_iDate;   // tempDate临时保存要出栈的内容 
        delete tempNode;                  //delete删除指针 
        return tempDate;                  //返回tempDate 
    }else{
        cout<<"栈已空！"<<endl;
        return 0;
    }
}

#endif

