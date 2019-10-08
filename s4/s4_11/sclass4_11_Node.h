//拷贝构造函数，凡是包含动态分配成员或包含指针成员的类 

//类声明文件
#ifndef _SCLASS4_11_NODE_H_
#define _SCLASS4_11_NODE_H_

#include<iostream>
#include<string>
using namespace std;

const int LEN=20;           //数组指针的数组长度，可设置大一些，如1000个结点
class CNodeArray;           //向前声明结点数组，以便于在CNode类中声明为友元类时使用

/************************************************************************************
//声明为结点类，这里只声明了结点名字和结点编号两种数据成员
//为了说明拷贝构造函数及部分运算符重载的重要性，将结点名字定义为string类型指针
//在结点类中定义了拷贝构造函数等
//练习时可用一个类族代替CNode设计复杂的结点结构
************************************************************************************/

class CNode{
	friend CNodeArray;       //CNodeArray是CNode的友元，方便访问私有成员
	friend ostream& operator<<(ostream& cout,CNode& obj);    //重载<<
	friend istream& operator>>(istream& cin,CNode& obj);     //重载>>
	static int sNodeNum;     //静态成员，每生成一个结点对象自动加1
	
	public:
	    CNode(string str);                              //构造函数，结点编号通过调用CreateNumber()函数取得
		CNode(const CNode &oCN);                        //拷贝构造函数
		virtual ~CNode();                               //虚析构函数
		CNode &operator=(const CNode &oCN);             //重载赋值运算符
		const CNode &operator,(const CNode &oCN);       //重载","，逗号运算符 
		int GetNumber(void);                            //返回当前sNodeNum，并自加1
		string *GetStr();                               //返回指向结点名字的字符串指针
		int &GetNodeNum();                              //返回结点的编号
		
	private:
	    string *m_pStr;           //字符串对象指针，可以指向一个字符串对象
		int m_nodeNum;            //结点编号，代表雇员编号等，该编号要具有唯一性 
}; 


/************************************************************************************
//声明结点数组类，它主要用于管理众多结点。它的数据成员和函数成员设计主要基于
//方便管理众多结点的需要。为了操作简单，在本例中设计了一个长度为LEN的指针数组。
//数组的每一个成员都可以指向一个CNode结点对象。当系统生成一个结点后，
//就根据m_aIndex确定结点在数据中的位置。当结点销毁后，也不考虑收回与其对应的元素指针以作他用。
//练习时，可以从以下几个角度考虑扩展：
//1.考虑回收结点删除后的数组指针以作后用；
//2.考虑设计一个比较小的数组（如长度为26），然后按照结点名字的首字母不同对应
//存放在不同的数组指针位置，名字首字母相同的结点按照链表方式存放其后。
//3.其他功能扩展。本程序的设计目的主要是为了方便观察程序的执行过程。 
************************************************************************************/ 
class CNodeArray{
	friend CNode;                         //互相为朋友？
	
	public:
	    CNodeArray(int aLength=LEN);             //构造函数，默认数组长度为LEN个
		virtual ~CNodeArray(void);               //虚析构函数
		CNode  operator[](int i);                //重载“[]”
		void *operator new(size_t size);         //重载new
		void operator delete(void *p);           //重载delete
		bool Insert(CNode &oCN);                 //在结点数组中插入一个结点
		bool Delete(int index);                  //在结点数组中删除一个结点
	private:
	    CNode *m_poCN[LEN];                      //结点指针数组，用来存放指向结点的指针
		int m_aLength;                           //指针数组长度
		int m_aIndex;                            //结点指针数组中数组的当前下标值 
};
#endif  //结束编译预处理 
