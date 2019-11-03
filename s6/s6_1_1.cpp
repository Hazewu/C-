#include<iostream>
using namespace std;

void Show(int *begin,int *end){                   //显示函数 
	for(int *it=begin;it!=end;it++){
		//依次显示各元素
		cout<<*it<<" "; 
	}
	cout<<endl;                                   //换行 
}

int main(){
	int a[]={1,2,3,4,5,6};                        //定义c数组a
	int n=6;                                      //元素个数
	int *begin=a;                                 //开始
	int *end=a+n;                                 //结束
	
	Show(begin,end);                              //显示
	
	system("PAUSE");                              //调用库函数system()，输出系统提示并返回操作系统
	return 0;                                     //返回值0，返回操作系统 
}
