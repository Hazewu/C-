/*
new 
new运算符的基本使用格式：
   <指针名>=new<类型>(<实参表>);
当系统无法满足动态内存分配的请求时，它将返回NULL，必须判断返回的指针是否为NULL。
如果对一个没有成功申请的指针进行相关的内存操作将可能引起系统崩溃。
使用new运算符创建数组时，不能为该数组赋初值。

有两种方法对对象数组中的元素进行初始化：
（1）不定义构造函数，而在类中定义一个成员函数完成初始化工作
（2）在类中定义不带参数或带默认参数的构造函数

如果在类中声明定义了构造函数，但没有定义不带参数的构造函数，且没有定义带全部默认参数的构造函数，
那么该类将不能用new创建对象数组。 
*/ 

/*
delete
delete运算符的基本使用格式：
   delete<指针名>;             //释放一般对象或变量
   delete []<指针名>;          //释放整个数组，[]内无需有值，delete知道数组的大小
delete执行后，指针所指向的内存空间就被释放了，而指向该动态内存区域的指针变量本身并不会
因为delete有任何改变。指针依然指向其原动态内存空间，改变的只是指针所指向的动态空间的内容。
被释放掉的动态内存空间随时有可能被分配给别的任何变量，所以此后通过指针变量对该动态内存的任何
操作都有可能引发系统崩溃。一般，delete以后，将指针变量的值设置为NULL，让它不再指向任何动态内存空间

预防“野指针”：
（1）定义指针变量的同时初始化，如不初始化就一定将其设置为NULL
（2）delete指针以后，第一时间将其设置为NULL，养成好的编程习惯
（3）当指针指向数组时，一定谨防指针操作越界
（4）避免用指针传递栈内存，避免返回一个即将自动消失的局部变量或局部对象的地址
（5）注意区分指针变量和指针指向的内存空间之间的差异
    void Func(void){
	    char *pChar=new char[100];
    }
    退出函数时，pChar是局部变量，会自动消失，但长度为100的动态内存空间中的字符串数组仍然存在，
	没有释放。每次调用都会造成新的内存泄露 
（6）理解两点：指针消亡了，并不表示它所指向的动态内存会被自动释放、自动消亡；
               动态内存被释放了，并不表示指向该动态内存的指针变量会消亡或自动变成NULL指针 
*/ 

//new和delete的基本用法
#include<iostream>
#include<string>
using namespace std;
const int LEN=5;                       //定义一个常量

class CNode{                           //声明CNode类 
public:
	CNode(int value=0);                //构造函数，默认参数value=0
	void Print() const;
	
private:
    int m_value;                       //结点值 
}; 

CNode::CNode(int value):m_value(value){//构造函数 
	;
} 

void CNode::Print() const{             //显示常成员函数 
    cout<<"CNode value:"<<m_value<<endl; 
}

//测试函数
int main(){
	CNode *poCN=new CNode[LEN];        //创建对象数组，自动调用默认或午餐构造函数
	if(poCN==NULL){                    //判断动态内存申请是否成功 
		exit(0);                       //内存申请不成功则退出 
	} 
//	poCN->Print();                     //只打印出，mCNode value：0，一个值 
	delete []poCN;                     //释放对象数组，去掉[]数组将释放不完全
	poCN=NULL;                         //让poCN指针指向NULL。否则，它依然指向原动态空间
	
	poCN=new CNode(5);
//	poCN->Print();            
	if(poCN==NULL){                    //判断动态内存申请是否成功 
		exit(0);
	} 
	delete poCN;                       //释放单个对象
	poCN=NULL;
	
	int *p1,*p2,(*p3)[3];              //p1，p2为一般整数指针，p3为行指针
	p1=new int;                        //new一个整数
	p2=new int(200);                   //new一个整数，其初值为200
	p3=new int[2][3];                  //new一个关于一维数组的数组（该一位数组具有3各整型元素）
	delete p1;                         //释放一个int数据 
	delete p2;                         //释放一个int数据 
	delete []p3;                       //释放一个关于一维数组的数组 
	p1=NULL;
	p2=NULL;
	p3=NULL; 
	
	//oCP1，oCP2为在栈（注意不是堆）中分配的对象，无需delete，系统自动释放
	CNode oCP1(1);                     //生成一般对象，就是对象变量，其值可以改变
	const CNode oCP2(3);               //生成一个常对象，对象常量，其值不可改变
	
	system("PAUSE");
	return 0; 
} 
