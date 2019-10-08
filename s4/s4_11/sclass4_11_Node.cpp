#include<iostream>
#include<stdlib.h>
#include"sclass4_11_Node.h"

/************************************************************************************/  
//CNode的带参构造函数
CNode::CNode(string str){                  //结点构造函数 
	m_pStr=new string(str);                //new字符串对象空间，村结点名
	if(m_pStr==NULL){
		cout<<"内存分配失败。"<<endl;
		exit(0);                           //内存分配失败，退出 
	} 
	m_nodeNum=GetNumber();                 //取得结点编号，并赋值给m_nodeNum
	cout<<"CNode全新创建结点No:"<<m_nodeNum<<",Name:"<<*m_pStr<<endl; 
} 

//CNode的拷贝构造函数
CNode::CNode(const CNode &oCN){
	m_pStr=new string(*oCN.m_pStr);        //new字符串对象空间，存结点名
	if(m_pStr==NULL){
		cout<<"内存分配失败。"<<endl;
		exit(0);                           //内存分配失败，退出 
	} 
	m_nodeNum=GetNumber();                 //取得结点编号，并赋值给m_nodeNum
	cout<<"CNode拷贝创建结点No:"<<m_nodeNum<<",Name:"<<*m_pStr<<endl;  
} 

//CNode的析构函数
CNode::~CNode(){
	cout<<"~CNode销毁结点,No:"<<m_nodeNum<<",Name"<<*m_pStr<<endl;
	delete m_pStr;                         //自动销毁m_pStr指向的string对象 
} 

//重载CNode的赋值运算符（允许结点名、结点编号相同对象存在）
CNode &CNode::operator=(const CNode &oCN){
	if(this==&oCN){                        //判断是否自己赋值自己 
		return *this;                      //如果是，不必复制，返回 
	}
	delete m_pStr;                         //释放赋值运算符左边对象的字符串对象指针所指对象
	m_pStr=new string(*oCN.m_pStr);        //new字符串对象空间，存结点名
	if(m_pStr==NULL){
		cout<<"内存分配失败。"<<endl;
		exit(0);                           //内存分配失败，退出 
	} 
	//注：此处只能考虑赋值，以体现赋值运算符的本意。但m_nodeNum出现重复。
	m_nodeNum=oCN.m_nodeNum;               //取得结点编号，并赋值给m_nodeNum
	cout<<"CNode赋值了对象，No:"<<m_nodeNum<<",Name:"<<*m_pStr<<endl;
	return *this; 
} 

//重载CNode的“，”运算符重载
const CNode &CNode::operator,(const CNode &oCN){
	return oCN;                            //直接返回第二操作数？ 
} 

//重载CNode的输出运算符,scout等同于cout 
ostream& operator<<(ostream& scout,CNode& obj){
	scout<<"Node Name:"<<*(obj.GetStr())<<",";
	scout<<"Node Number:"<<obj.GetNodeNum()<<"."<<endl;
	return scout; 
} 

//重载CNode的输入运算符
istream& operator>>(istream& scin,CNode& obj){
	char s[81];                            //设置81仅仅为了编程方便
	cout<<"Please Enter Node Name:";       
	scin.getline(s,81,'\n');               //getline(scin,*(obj.GetStr());
	*(obj.GetStr())=s;                     //s转换为string对象后再赋值
	cout<<"Please Enter Node Number:";
	scin>>obj.GetNodeNum();                //此处对输入对象的结点编号大小未予限制
	return scin; 
}  

//返回当前sNodeNum，并自增1
int CNode::GetNumber(void){
	return sNodeNum<LEN ? sNodeNum++:(sNodeNum=0);   //确保小于LEN 
} 

//返回指向结点名字的字符串指针
string *CNode::GetStr(){
	return m_pStr;
} 

//返回结点的编号，也是m_nodeNum
int &CNode::GetNodeNum(){
	return m_nodeNum;
} 

//CNodeArray类的构造函数
CNodeArray::CNodeArray(int aLength){
	for(int i=0;i<aLength;i++){
		m_poCN[i]=NULL;                 //指针数组初始化，全部指向NULL 
	}
	m_aLength=aLength;                  //数组长度设置
	m_aIndex=0;                         //当前结点下标设置为0
	cout<<"CNodeArray，创建一个结点数组对象，length=:"<<m_aLength<<endl; 
} 

//~CNodeArray析构函数，确认m_poCN指向的对象的指针所指向的空间是否析构了
CNodeArray::~CNodeArray(void){
	for(int i=0;i<m_aLength;i++){
		if(m_poCN[i]!=NULL){           //m_poCN[i]指向对象时，才调用delete运算符 
			delete m_poCN[i];           //如果 m_poCN[i]指向对象，会自动调用~CNode()
			cout<<"delete:m_poCN["<<i<<"]."<<endl; 
		}
	}
	cout<<"~CNodeArray:析构完成。"<<endl;
} 

//这里设计了很简单的结点插入功能，即只是让数组的CNode指针指向新结点而已。
//为了安全，先对插入位置做出判断，如果原来有结点，报插入失败，返回。
//也可以销毁原结点，强制插入。
bool CNodeArray::Insert(CNode &oCN){
	if(m_aIndex>=m_aLength){
		cout<<"对不起，超过了数组最大下标，不可再插入！"<<endl;
		return false;
	}
	
	//将要插入的结点赋值到结点数组中
	if(m_poCN[m_aIndex]!=NULL){
		cout<<"此位置已有结点，不可再插入！"<<endl;
		return false; 
	} 
	
	m_poCN[m_aIndex]=&oCN;
	cout<<"插入新结点，Pos:"<<m_aIndex<<",No:"<<oCN.GetNodeNum()<<",Name:"<<*oCN.GetStr()<<endl;
	m_aIndex++;
	return true;
} 

//这里不是链表操作，相当于delete一个结点，并让指针为空即可
bool CNodeArray::Delete(int index){
	if(m_poCN[index]==NULL){
		cout<<"Pos:"<<index<<"=NULL,无需调用delete运算符."<<endl;
		return false;
	}
	delete m_poCN[index];          //释放当前结点
	m_poCN[index]=NULL;
	cout<<"delete:m_poCN["<<index<<"],Pos:"<<index<<",此位置指向的结点delete成功！"<<endl;
	return true; 
} 

//CNodeArray的“[]”允素福重载。这里返回了一个对象，当[]被调用时
//可以观察到CNode的拷贝构造函数和析构函数的调用过程。
CNode CNodeArray::operator[](int i){
	if((i<m_aIndex)&&(i>=0)){
		return *m_poCN[i];         //返回第i各结点指针所指向的对象 
	}else{
		if(m_poCN[i]==NULL){
			cout<<"没有元素，出错。"<<endl;
			exit(0);
		}
		cout<<"数组越界"<<endl;
		exit(0);
	}
} 

//重载CNodeArray的new运算符
void *CNodeArray::operator new(size_t size){
	cout<<"调用CNodeArray自定义的new创建对象。"<<endl;
	return malloc(size);
} 

//重载CNodeArray的delete运算符
void CNodeArray::operator delete(void*p){
	cout<<"调用CNodeArray自定义的delete销毁对象。"<<endl;
	free(p);
} 

//主函数：本例的设计思想主要是为了便于学习和观察相关C++机制！！
//调整作用域运行程序，仔细观察、体会可加深对相关概念的理解
int CNode::sNodeNum=0;
 
int main(){
	cout<<"1==============================================."<<endl;
	//第一段作用域，主要观察拷贝构造函数和new、delete运算符的作用
	{
		CNodeArray oCNA1;                                //创建一个结点管理类对象
		//内部作用域，去掉注释可观察到oCN1和oCN2的析构位置
		{
			int i;
			char s[81];                                  //暂时存放获取的结点名字
			string str;                                  //创建一个string对象
			CNode oCN1("Zhang San"),oCN2("Li Si");       //创建两对象
			oCN2=oCN1;                                   //调用重载的赋值运算符
			CNode *poCN1,*poCN2;                          //定义一个CNode指针
			for(i=0;i<5;i++){
				cout<<"Input a Node Name or word \"stop\":";
				cin.getline(s,81,'\n');                  //输入字符串作为结点名
				str=s;                                   //字符串转换为字符串对象
				if(str=="stop")                          //如果输入字符串为“stop”，则退出
				    break;
				poCN1=new CNode(str);                    //调用一般构造函数新建对象
				poCN2=new CNode(*poCN1);                 //调用拷贝构造函数新建对象
				oCNA1.Insert(*poCN1);                    //结点数组指针指向该对象
				oCNA1.Insert(*poCN2);                    //结点数组指针指向该对象 
			} 
		} 
		cout<<"====START==================================."<<endl;
//为什么有问题？		cout<<oCNA1[0];                                  //观察重载的“<<”和“[]”运算符
		cout<<"====END====================================."<<endl;
		for(int i=0;i<5;i++){
			oCNA1.Delete(i);                             //注释掉本语句可观察到delete的作用 
		} 
	}
	cout<<"2=============================================."<<endl;
	//第二段作用域，主要观察重载的new和delete的调用
	{
		CNode oCN1("Genghis khan");                      //元太祖，名铁木真
		CNodeArray *poCN3=new CNodeArray;                //调用重载“new”
		delete poCN3;                                    //调用重载delete，通过::delete可调系统delete 
	}
	cout<<"3=============================================."<<endl;
	//第三段作用域，主要观察重载的“<<、>>、，、=”运算符的调用
	{
		CNode oCN1("Genghis khan"),oCN2("11"),oCN3(oCN1);//元太祖，名铁木真
		cin>>oCN3;                                       //可用重载的“>>”运算符 
		cout<<oCN3;                                      //可用重载的“<<”运算符 
		oCN3=oCN2,oCN1;                                  //可用重载的“,”和“=”运算符 
		cout<<oCN3;                                       //可用重载的“>>”运算符 
	}
	return 0; 
} 
