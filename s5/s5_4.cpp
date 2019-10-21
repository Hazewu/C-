#include<iostream>
#include<string>
using namespace std;

class CNode;                                //CNode类前向声明，以便在TLinkList中使用

//声明一般链表的类模板——在该链表中的结点是无序的
template<class Type>
class TLinkList{
	public:
		TLinkList();                        //构造函数 
		virtual ~TLinkList();               //析构函数
		 
		virtual bool Insert(Type value);    //在链表中插入一个结点，仅在表头插入
		bool Delete(Type value);            //从链表中删除值为value的结点
		bool Search(Type value);            //判断链表中是否包含值为value的结点
		bool Modify(Type v1,Type v2);       //查找结点值为v1的结点，并修改为v2
		virtual void Print();               //按照链表顺序输出链表中的结点值
	
	public:
	    CNode *m_pHead;                     //设置链表的头结点指针         
}; 

//声明有序链表的模板——在该链表中的结点是有序排列的
template<class Type>
class TOrderedLinkList:public TLinkList<Type>{
	public:
		TOrderedLinkList();                  //构造函数
		virtual ~TOrderedLinkList();                 //析构函数
		
	public:
	    virtual bool Insert(Type value);     //有序插入
		virtual void Print();                //按照链表顺序输出链表中的结点值 
	public:
		CNode *m_pHead;
}; 

//声明结点结构类
class CNode{
	friend class TLinkList<int>;             //声明模板类为CNode的友元
	friend class TOrderedLinkList<int>;      //声明模板类为CNode的友元
	
	public:
	    CNode(int value);
	    ~CNode();
	
	private:
		int m_value;                         //结点值
		CNode *m_pNext;                      //结点后继，指向下一个结点
		CNode *m_pPre;                       //结点前驱，指向上一个结点 
}; 

//结点类构造函数
CNode::CNode(int value){
	m_value=value;                           //结点值
	m_pNext=NULL;                            //结点后继
	m_pPre=NULL;                             //结点前驱 
} 

//结点类析构函数
CNode::~CNode() {
	;
}

//TLinkList类模板的构造函数
template<class Type>
TLinkList<Type>::TLinkList(){
	m_pHead=NULL;                             //链表头 
} 

//TLinkList类模板的析构函数============================标记一下，应该可以换种方法 
template<class Type>
TLinkList<Type>::~TLinkList(){
	CNode *p=m_pHead;                         //p指向第一个结点 
	for( ;p!=NULL; ){                         //直到下一个结点不为空 
		m_pHead=p->m_pNext;                   //头指针指向下一个结点
		delete p;                             //释放p所指向的结点，而不是释放p？
		p=m_pHead;                            //p指向新的头结点 
	}
} 

//创建一个新结点，并只在头指针后面插入
template<class Type>
bool TLinkList<Type>::Insert(Type value){
	CNode *pTemp=new CNode(value);            //创建一个新结点，CNode(value)一个结点类对象，其中m_value=value
	if(pTemp==NULL){                          //内存空间申请不成功 
		exit(0);                              //停止执行程序 
	} 
	
	if(m_pHead==NULL){                        //表头为空时，插入过程有所不同 
		pTemp->m_pNext=NULL;                  //1.结点后继为空
		pTemp->m_pPre=NULL;                   //2.结点前驱为空
		m_pHead=pTemp;                        //3.头指针指向该新结点 
	}else{                                    //表头不为空时 
		pTemp->m_pNext=m_pHead;               //1.将原结点设置为新头结点的后继
		pTemp->m_pPre=NULL;                   //2.将新头结点的前驱设置为NULL
		m_pHead->m_pPre=pTemp;                //3.将新头结点设置为原头结点的前驱
		m_pHead=pTemp;                        //4.将新头结点设置为新的表头 
	}
	
	return true; 
}

//删除值为value的所有结点
//删除算法如下：首先创建一个临时结点（结点值随便设定）插入到链表头作为新的临时头结点，
//然后用p1指向新的头结点，p2指向其后继（原始头结点）。然后查找p2所指是否应该删除，
//如果应该删除，则删除，删除后p1不动，p2指向其后继；如果不应该删除，则p1和p2指向其后继。
//如此反复知道p2指向NULL。最后让m_pHead指向临时头结点。
template<class Type>
bool TLinkList<Type>::Delete(Type value){
	bool flag=false;                           //0表示没有删除任何结点，1表示删除了
	//在链表头设置一个临时表头
	CNode oCN(0);                              //生成一个新结点以插入到表头作为临时头结点
	oCN.m_pNext=m_pHead;                       //将原头结点设置为临时头结点的后继
	oCN.m_pPre=NULL;                           //将临时头结点的前驱设置为NULL
	m_pHead->m_pPre=&oCN;                      //将临时头结点设置为原头结点的前驱
	m_pHead=&oCN;                              //将临时头结点设置为新的表头
	//删除值为value的所有结点
	CNode *p1=m_pHead,*p2=m_pHead->m_pNext;    //p1指向新表头结点，p2指向其后继
	for( ;p2!=NULL; ){                         //p2为空说明链表已经遍历完全了 
        if(p2->m_value==value){                //如p2所指向的结点正是要删除的结点 
        	p1->m_pNext=p2->m_pNext;           //p2的后继赋值给p1的后继
			(p2->m_pNext)->m_pPre=p1;          //p1赋值给p2的后继的前驱地址
			delete p2;                         //删除p2所指向结点（调析构函数）
			flag=true;                         //说明有结点被删除 
		}else{                                 //如果p2所指的不是要删除的结点 
			p1=p2;                             //p1指向p2 
			p2=p2->m_pNext;                    //p2指向p2的后继 
		} 
	}
	//将临时表头删除。注：oCN不是new的对象，无需删除
	m_pHead=oCN.m_pNext;
	(oCN.m_pNext)->m_pPre=NULL;
	
	return flag; 
}

//查找链表中是否包含结点为值value的结点，有，返回true，没有返回false
template<class Type>
bool TLinkList<Type>::Search(Type value){
	for(CNode *p=m_pHead;p!=NULL;p=p->m_pNext){
		if(p->m_value==value){                 //找到该结点，返回true 
			return true;
		}
	}
	return false; 
} 

//将链表中结点值为v1的结点全部修改为v2，修改成功返回true，否则false
template<class Type>
bool TLinkList<Type>::Modify(Type v1,Type v2){
	bool flag=false;                           //0表示没有任何修改，1表示有修改
	for(CNode *p=m_pHead;p!=NULL;p=p->m_pNext){
		if(p->m_value==v1){                    //找到该结点，修改为v2并返回true 
			p->m_value=v2;
			true=1;
		}
	} 
	return flag;
} 

//按照链表顺序从表头开始取出结点值并显示
template<class Type>
void TLinkList<Type>::Print(){
	cout<<"从TLinkList表头开始结点的值依次为：\n";
	//变脸链表以读出每一个结点的值，并在终端显示
	for(CNode *p=m_pHead;p!=NULL;p=p->m_pNext){
		cout<<p->m_value<<", ";                //显示结点值 
	} 
	cout<<endl;                                //结束输出流 
}

//TOrderedLinkList类模板的构造函数
template<class Type>
TOrderedLinkList<Type>::TOrderedLinkList():TLinkList<Type>(){
	;
} 

//TOrderedLinkList类模板的析构函数
template<class Type>
TOrderedLinkList<Type>::~TOrderedLinkList(){
	;
} 

//TOrderedLinkList的结点插入方法与TLinkList的唯一不同就是做有序插入，
//也就是说插入位置不一定在表头。这里做排序插入，表头值小，表尾值大。
//首先在表头和表尾分别插入一个最小值和一个最大值，
//其次在表头和表尾之间用后面的for循环寻找插入位置插入，最后删除表头和表尾
template<class Type>
bool TOrderedLinkList<Type>::Insert(Type value){
	CNode *p1,*p2;                             //定义两个指针，插入操作时使用
	CNode *pTemp=new CNode(value);             //定义pTemp指向new的待插入结点
	if(pTemp==NULL){                           //内存空间申请不成功 
		exit(0);                               //停止执行程序 
	} 
	
	if(m_pHead==NULL){                         //表头为空时插入为第一个结点 
		pTemp->m_pNext=NULL;                   //1.新结点的后继为NULL
		pTemp->m_pPre=NULL;                    //2.新结点的前驱为NULL
		m_pHead=pTemp;                         //3.头指针指向新结点 
	}else{                                     //当表头不为空时，首先要寻找插入位置，然后才能插入结点 
		if(value<m_pHead->m_value){            //在表的头结点前插入 
			pTemp->m_pNext=m_pHead;            //1.将原头结点设置为新头结点的后继
			pTemp->m_pPre=NULL;                //2.将新头结点的前驱设置为NULL
			m_pHead->m_pPre=pTemp;             //3.将新头结点设置为原头结点的前驱
			m_pHead=pTemp;                     //4.将新头结点设置为新的表头 
		}else{                                 //不是在头结点前插入 
			//让p2指向p1的前驱（主要考虑表尾部的插入）
			for(p2=m_pHead,p1=m_pHead->m_pNext;p1!=NULL;p2=p1,p1=p1->m_pNext){
				if(value<p1->m_value){          //在链表中间插入 
					(p1->m_pPre)->m_pNext=pTemp;//1.p1的前驱的后继指向新结点
					pTemp->m_pPre=p1->m_pPre;   //2.新结点的前驱指向p1的前驱
					pTemp->m_pNext=p1;          //3.新结点的后继指向p2
					p1->m_pPre=pTemp;           //4.p1的前驱指向新结点
					break; 
				}
			}
			if(p1==NULL){                       //在链表末尾插入 
				pTemp->m_pNext=NULL;            //1.新结点的后继设置为NULL
				pTemp->m_pPre=p2;               //2.新结点的前驱指向p2
				p2->m_pNext=pTemp;              //3.p2的后继指向新结点 
			}
		}
	} 
	return true; 
} 

//按照链表顺序从表头开始取出结点值并显示
template<class Type>
void TOrderedLinkList<Type>::Print(){
	cout<<"从TOrderedLinkList表头开始，结点的值依次为：\n";
	//遍历链表以读出每一个结点的值并在终端显示
	for(CNode *p=m_pHead;p!=NULL;p=p->m_pNext){
		cout<<p->m_value<<", ";                  //显示结点值 
	} 
	cout<<endl;                                  //结束输出流 
} 

//主测试程序
int main(){
	TLinkList<int> oILL;
	oILL.Insert(12);
	oILL.Insert(24);                             //在链表oILL中，两次插入24
	oILL.Insert(48);                             //在链表oILL中，两次插入48
	oILL.Insert(96);
	oILL.Insert(24);
	oILL.Insert(48);
	oILL.Insert(96);
	oILL.Insert(35);
	oILL.Print();                                //删除前显示
	oILL.Delete(24);                             //删除值为24的结点
	oILL.Print();                                //删除后显示
 
	TOrderedLinkList<int> oDLL;
	oDLL.Insert(12);
	oDLL.Insert(24);                             //在集合oDLL中，两次插入24
	oDLL.Insert(48);                             //在集合oDLL中，两次插入48
	oDLL.Insert(96);
	oDLL.Insert(24);
	oDLL.Insert(48);
	oDLL.Insert(96);
	oDLL.Insert(35);
	oDLL.Print();                                //删除前显示
	oDLL.Delete(24);                             //删除值为24的结点
	oDLL.Print();                                //删除后显示
	
	return 0;  
} 
	//出现问题？内存原因吗，只有第一个Print能在终端显示，其余操作失效
