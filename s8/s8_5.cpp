/*
异常处理机制
管理异常的一种方法和流程。异常处理让程序在环境条件出现异常时，不会轻易死机或出现灾难性后果。
基本思想：将异常的检测和处理分开。
结构化方式就是throw、try、catch结构。
throw用来创建用户自定义类型的异常错误，用于抛出异常
try标识程序中异常语句块的开始，用于引发异常
catch标识异常错误处理模块的开始，用于捕获、处理异常
一般语法结构如下：
    throw <表达式>;
	
	try{
        //try语句块 
	}
	catch(类型1 参数1){
	    //针对类型1的异常处理 
	} 
	catch(类型2 参数2){
	    //针对类型2的异常处理 
	} 
	//……
	catch(类型n 参数n){
	    //针对类型n的异常处理 
	} 
*/

/*
标准异常
（1）一个基类：exception是所有C++异常的基类
    class exception{
	public:
	    exception() throw();                                //默认构造函数
		exception(const exception& rhs) throw();            //拷贝构造函数
		exception& operator=(const exception& rhs) throw(); //赋值运算符
		virtual ~exception() throw();                       //析构函数
		virtual const char *what() const throw();           //为抛出的异常提供描述字符串 
	}; 
（2）下面派生了两个异常类
    logic_error              //报告程序的逻辑错误，可在程序执行前被检测到
	runtime_error            //报告程序运行时的错误，只有在运行的时候才能检测到
	这两个派生类又分别有自己的派生类。
（3)由logic_error派生的异常类
    domain_error             //异常，用以报告域错误（domain error）
	invalid_argument         //异常，接收到一个无效的实参，抛出该异常
	length_error             //异常，通常用于报告空间不足
	out_of_bounds            //异常，通常用于表示下标错误
（4）由runtime_error派生的异常
    range_error              //异常，报告结果超出了有效表示范围
	overflow_error           //异常，报告算术溢出错误，运算结果超过了最大能够表示的数
	underflow_error          //异常，报告浮点运算错误，运算结果超过了最小能够表示的数
标准C++库中的这些异常类可以为编程人员，特别是自己类库的开发者提供一些经验
（5）bad_alloc异常
    通常在new.h文件中声明了bad_alloc类，它也继承自exception类。
	bad_alloc类用于处理内存分配错误。当new时未取得要求的内存分配可能引发该异常。
	bad_alloc                //当new()操作时不能分配所要求的存储区时，会抛出该异常   
*/ 

//异常示例
#include<iostream>
#include<string>
using namespace std;

void MyFunc(void);

class CMyException{                           //定义异常类 
public:
	CMyException(){ };
	~CMyException(){ };
	const char *ShowExceptionReason() const{  //显示异常原因 
	    return "CMyException Exception.";
	}
};

class CDemo{      //定义一个工作类，用以显示其执行与异常抛出的顺序 
public:
	CDemo();
	~CDemo();
};

CDemo::CDemo(){
	cout<<"Constructing CDemo."<<endl;
} 

CDemo::~CDemo(){
	cout<<"Destructing CDemo."<<endl;
}

//异常也可以多层封装，例如：在MyFunc()中封装throw、try、catch机制
//在这里捕获相关异常，然后在其调用层再捕获本层不能捕获的异常
//本示例程序，只在main()中进行了异常捕获处理
void MyFunc(){
	CDemo D;
	cout<<"\nIn MyFunc(). Throwing CMyException exception."<<endl;
	throw CMyException();                   //抛出异常 
} 

int main(){
	try{                                   //用try封装可能会出现异常的代码 
		cout<<"In try  block,calling MyFunc()."<<endl;
		MyFunc();
	}
	catch(CMyException E){                 //一路捕获并处理异常 
		cout<<"Caught: ";
		cout<<E.ShowExceptionReason()<<endl;
	}
	catch(string str){                     //二路捕获并处理异常 
		cout<<"Caught some other exception: "<<str<<endl; 
	}
	
	return 0;
}
