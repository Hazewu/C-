/*
无论是否使用关键字static进行修饰，重载了的new和delete均为类的静态成员函数
运算符new重载的一般形式为： 
   void *operator new(size_t,<arg_list>);
new应返回一个void型的指针，且至少有一个类型为size_t的参数。
若new重载函数带有多于一个的参数，则其第一个参数的类型必须为size_t。
size_t是与计算机有关的无符号整型

运算符delete重载的一半形式为：
   void *operator delete(void *,<size_t>);
delete应返回一个void型指针，且至少有一个类型为void的指针参数。
delete重载函数最多可以带两个参数，若有第二个参数，其类型必须为size_t。

常见的动态内存错误
1、动态内存分配失败却继续操作，要检查if(p==NULL)
2、动态内存空间未初始化就进行读操作
3、动态内存空间越界使用，数组越界
4、内存泄漏，new，一定要用delete释放 
5、继续使用已经释放了的动态内存空间 
*/ 

//指针和数组的使用差异示例
//数组与指针的比较
#include<iostream>
#include<cstring>
using namespace std;

//测试函数
int main(){
	//数组定义：内存中有数组空间，没有字符串常量
	char a1[]="Hello Iron Man!";           //定义数组并初始化
	a1[14]='2';                            //数组的元素值是可以改变的
	cout<<a1<<endl;                        //显示：Hello Iron Man2
	
	//指针变量定义并初始化：内存中有指针变量，并在静态存储区还有一个字符串常量
	//内存中分配两个空间：指针变量空间；字符串常量空间
	char *p1="Hello World!";               //注意p1指向常量字符串
	//p1[0]不可以修改而a1[0]可以修改，因为p1指向的是常量，不能修改常量
	//a1[0]是变量，可修改
	//p1[0]='X';                           //该语句编译器不能发现错误，但运行时会发现
	cout<<p1<<endl;                        //显示：Hello World
	
	//字符数组赋值的方法
	char a2[]="Hello Baby!";               //数组初始化表示，内存中没有常量字符串
	char b2[81];
	strcpy(b2,a2);                         //赋值数组的方法。不能用b2=a2，会发生编译错误
	cout<<b2<<endl;                        //显示：Hello World
	
	//赋值指针所指向的字符串的方法
	int len=strlen(a2);
	char *p2=new char[len+1];              //注意空间大小，思考为什么要+1？
	if(p2==NULL){
		exit(0);
	} 
	strcpy(p2,a2);                         //赋值操作，不要用p2=a2，该语句只让p2指向了数组a2
	cout<<p2<<endl;                        //显示：Hello World
	
	//字符指针变量的长度和该指针所指向的字符串的长度的区别
	cout<<sizeof(a2)<<endl;                //12字节，a2是一个字符数组 
	cout<<sizeof(p2)<<endl;                //4字节，p2是一个字符指针变量
	delete []p2;
	p2=NULL;                               //为了安全，这种操作是必须的
	
	return 0; 
} 
