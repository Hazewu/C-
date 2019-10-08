#include"sclass4_6_cstudent.h"

//主测试函数 
int main(){
	CPerson *poCP=new CStudent;      //构造一个CStudent的动态对象，基类指针指向它
	if(NULL==poCP){                  //如果new操作失败，则退出
	    exit(0);                     //参数0表示非正常退出程序 
	} 
	delete poCP;                     //通过基类指针销毁派生类对象
	cout<<"通过delete析构new运算符创建的对象结束！\n"<<endl;
	CStudent oCSt;                   //构造一个CStudent对象，不适用delete时，对象都能够正确析构
	return 0;
	
	//如果将 sclass4_6_cstudent.h里面的基类析构函数前面的virtual去掉，会有不同的结果，new出来的对象销毁不完全 
}
