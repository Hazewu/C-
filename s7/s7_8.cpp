//从键盘上输入一行字符存入到一个文本文件中，然后再从这个文件中输入各个字符， 
//并统计其中的英文小写字母的个数

#include<iostream>
#include<fstream>
using namespace std; 

int main(){
	char ch;                       //字符变量
	ofstream outFile("test.txt");  //定义输出文件对象，默认以输出方式打开文件
	if(outFile.fail()){
		//打开文件失败
		cout<<"打开文件失败！"<<endl;
		exit(1); 
	} 
	cout<<"输入一行文字："<<endl;
	ch=cin.get();                  //输入一个字符ch
	while(ch!='\n'){
		outFile.put(ch);           //将ch输入到文件中
		ch=cin.get();              //输入一个字符ch 
	} 
	outFile.close();               //关闭文件
	
	int letters=0;                 //字母个数
	ifstream inFile("test.txt");   //定义输入文件对象，默认以输入方式打开文件
	if(inFile.fail()){
		//打开文件失败
		cout<<"打开文件失败！"<<endl;
		exit(2); 
	} 
	ch=inFile.get();               //从文件中输入一个字符ch
	while(!inFile.eof()){
		//文件未结束
		if(ch>='a'&&ch<='z'){ 
			letters++;             //对英文小写字母进行计数 
		} 
		ch=inFile.get();
	}
	cout<<"共有英文小写字母"<<letters<<"个"<<endl;
	inFile.close();
	
	system("PAUSE");
	return 0; 
} 
