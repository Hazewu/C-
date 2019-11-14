//利用指针、指针的引用和函数返回指针传递内存
//内存的三种传递、分配方法

#include<iostream>
#include<cstring>
using namespace std;

//利用指针传值
char *TestPointerForwardValue(char *pChar2){
	char *pChar=new char[strlen(pChar2)+1];    //注意与sizeof(pChar)区别
	if(pChar==NULL){
		exit(0);
	} 
	strcpy(pChar,pChar2);
	cout<<pChar<<endl;
	return pChar;
} 

//利用指针的引用传值
char *TestReferencePointer(char *&rpChar){
	char *pChar=new char[strlen(rpChar)+1];    //注意与sizeof(rpChar)区别
	if(pChar==NULL){
		exit(0);
	} 
	strcpy(pChar,rpChar);
	cout<<pChar<<endl;
	return pChar;
} 

//利用返回指针传值：传递动态内存，如传递栈内存会出错
char *TestReturnDynamicMemory(char a[]){
	char b[100];
	char *pConst="Sichuan University!";
	char *pChar=new char[strlen(a)+strlen(pConst)+1];
	if(pChar==NULL){
		exit(0);
	}
	strcpy(b,a);
	cout<<b<<endl;           //输出复制到栈内存中的字符串
	strcpy(pChar,a);
	strcat(pChar,pConst);
	return pChar;            //如改成return b，则返回了栈内存，最后的输出是无效内容 
} 

//利用返回指针传值：传递静态存储区内存空间
char *TestReturnStaticMemory(){
	char *p="Diaoyu islands is Chinese inherent territory.";
	cout<<p<<endl;
	return p;
} 

//测试函数
int main(){
	char a1[]="Hello,Sichuan University!";
	char *p1=a1;
	char a2[]="Hello,College of Computer!";
	char *p2=a2;
	char *p=NULL;
	cout<<sizeof(a1)<<";"<<strlen(p1)<<endl;  //注意前后长度的差异
	p=TestPointerForwardValue(p1);           
	cout<<p<<endl;                            //打印返回动态内存区域中的字符串
	delete []p;
	p=TestReferencePointer(p2);
	cout<<p<<endl;                            //打印返回的动态内存区域中的字符串
	delete []p;
	p=TestReturnDynamicMemory(a2); 
	cout<<p<<endl;                            //打印返回的动态内存区域中的字符串
	delete []p;
	p=TestReturnStaticMemory();
	cout<<p<<endl;                            //打印返回的静态存储区域中的字符串
	
	return 0; 
	} 
