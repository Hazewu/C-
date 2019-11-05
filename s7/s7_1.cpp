/*
C++在内存中为每一个数据流开辟一个缓存区用于存放流中的数据。
使用cout<<时，实际上是先将这些数据传送到程序中的输出缓冲区保存起来，
直到输出缓冲区满了、遇到endl或程序已经结束，才将缓冲区中的全部数据传送到显示器上显示出来
1、标准输出流对象cout
cout是console output的英文缩写，表示在控制台（终端显示器）的输出。
cout是输出流类ostream的对象。
2、输出流类成员函数put()
当输出单个字符，可以用put()实现，一般使用格式为：
输出流对象.put(ch)，其中ch为要输出的字符 
*/

//函数put()使用示例
#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char s[]="Hello, world!";           //定义字符串
	
	for(int i=0;i<strlen(s);i++){       //strlen()函数在cstring头文件中 
		cout.put(s[i]);                 //输出第i+1个字符 
	} 
	cout<<endl;              
	
	system("PAUSE");
	return 0;
} 

 
