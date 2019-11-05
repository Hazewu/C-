#ifndef _SCLASS_CTRANSLATOR_H_
#define _SCLASS_CTRANSLATOR_H_

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//译码器类
class CTranslator{
private:
//数据成员 
	ifstream fin;                 //输入文件
	ofstream fout;                //输出文件
	string indent;                //缩进字符串

//辅助函数
    void SkipSapces();            //sapce空格，跳过空白（包括空格、制表符、换行符）
	bool GetToken(string &token); //读取标记，如文件已结束则返回false，否则返回true
	string IntToStr(int i);       //将整数i转化为长度为4的串
	void ForEach();               //处理foreach循环

public:
//构造函数、析构函数与方法
    CTranslator(const string &infName,const string &outfName);//构造函数
	virtual ~CTranslator(){       //析构函数 
		fin.close();              //关闭文件 
		fout.close();             //关闭文件 
	}  
	void Run();                   //运行译码器 
}; 

#endif
