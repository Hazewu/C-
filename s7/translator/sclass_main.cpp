#include"sclass_ctranslator.h"
#include<iostream>
using namespace std;

int main(){
	string infName,outfName;               //文件名
	char ch;                               //字符变量
	
	cout<<"请输入文件名（默认:experiment.exp）：";
	if((ch=cin.get())=='\n'){
		infName="experiment.exp";          //直接输入回车，表示默认文件名 
	}else{
		cin.putback(ch);                   //将其他字符ch回送输入流
		cin>>infName;                      //输入文件名 
	} 
	
	cout<<"请输入文件名（默认：experiment.cpp）：";
	if((ch=cin.get())=='\n'){
		outfName="experiment.cpp";         //直接输入回车，表示默认文件名 
	}else{
		cin.putback(ch);                   //将其他字符ch回送输入流
		cin>>outfName;                     //输入文件名 
	}
	
	CTranslator objTrans(infName,outfName);//译码器对象 
	objTrans.Run();                        //运行译码器
	
	system("PAUSE");
	return 0; 
} 

//该代码属于纯粹照抄，还没有理解，需要细看，并且未实现目标 
