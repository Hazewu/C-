#include<iostream>
using namespace std;

//定义结点类模板
template<class Type>
struct Node{                          //用结构体？不是类吗？打错了？ 
//数据成员
    Type data;                        //数据
	Node<Type> *next;                 //指针 
}; 

//定义链表类模板
template<class Type>
class Link{
private:
//数据成员 
	Node<Type> *head;                 //表头 
	Node<Type> *tail;                 //表尾（为了后面迭代器的需要，不是指向最后一个元素
	                                  //而是此元素的后面,此处将表尾定义为NULL）
	Node<Type> *prev;                 //表尾前驱（prev->next==tail)

public:
//公有函数模板
    Link(){                           //构造函数模板 
    	head=prev=tail=NULL;          //初始化空链表 
	} 
	virtual ~Link(){                  //析构函数模板 
		while(head->next!=NULL){
			//链表非空
			Node<Type> *p=head->next; //p指向第一个链表元素结点
			head->next=p->next;       //删除p所指结点，只是指该结点脱离链表了
			delete p;                 //释放p所指存储空间 
		}
	}
	void Append(const Type &e){       //向末尾追加元素 ,&e，是引用，会根本性地变化 
		Node<Type> *p=new Node<Type>; //分配存储空间
		p->data=e;                    //数据元素值为e
		p->next=NULL;                 //新加入地结点后继为空
		if(head==NULL){
			//空链表
			head=prev=p;              //head与prev都指向新结点
			tail=prev->next;          //tail为prev地后继NULL 
		} else{
			//非空链表
			prev->next=p;             //新结点追加在末尾
			prev=p;                   //p为新表尾
			tail=prev->next;          //tail为prev地后继NULL 
		}
	} 
	Node<Type> *Begin(){
		return head;                  //返回开始 
	}
	Node<Type> *End(){                //返回结束 
		return tail; 
	}
}; 

//定义链表迭代器类模板
template<class Type>
class LinkIterator{
private:
//数据成员 
	Type *itPtr;                      //迭代器本质是对Type *地封装

public:
//公有函数模板
    LinkIterator(Type *p):itPtr(p){}  //构造函数模板
	bool operator!=(const LinkIterator &it) const{
	                                  //重载“！=”关系运算符
		return this->itPtr!=it.itPtr; //返回值 
	} 
	void operator++(int){
		itPtr=itPtr->next;            //itPtr指向下一元素，不能用itPtr++，因为链表存储地址不连续 
	}
	Type operator*(){                 //重载“*”指针间接引用运算符 
		return *itPtr;                //返回itPtr指向地值 
	}
}; 

template<class Type>
ostream &operator<<(ostream &out,const Node<Type> &nd){
	                                  //重载“<<”输出运算符 
	out<<nd.data;                     //输出结点地数据元素
	return out;                       //返回out 
}

template<class It>
void Show(It begin,It end){           //泛型显示 
	for(It it=begin;it!=end;it++){
		//依次显示各元素
		cout<<*it<<" "; 
	}
	cout<<endl;
}

int main(){
	int a[]={1,2,3,4,5,6};            			//定义c数组a
	int n=6;                          			//元素个数
	Link<int> la;                     			//定义链表对象
	int i;                            			//定义临时变量
	
	for(i=0;i<n;i++){                 			//向末尾追加元素 
		la.Append(a[i]);
	} 
	             //<>填地是 Node<int>，所以里面地itPtr实际上是Node<int>型地 
	LinkIterator<Node<int> > begin(la.Begin());	//定义begin
	LinkIterator<Node<int> > end(la.End());      //定义end 
	cout<<"链表元素：";                         //输出提示
	Show(begin,end);                            //显示链表
	
	system("PAUSE");                            //调用库函数system()，输出系统提示信息
	return 0;                                   //返回值0，返回操作系统 
}
