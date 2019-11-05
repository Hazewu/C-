//编程实现显示一个文本文件的内容

#include<iostream>
#include<fstream>
using namespace std;

int main(){
	char s[318],fName[20];     //字符串
	ifstream f;                //文件流对象
	
	cout<<"请输入文件名：";    
	cin>>fName;                //输入文件名
	f.open(fName);             //打开文件
	if(f.fail()){
		//打开文件失败
		cout<<"打开文件失败！"<<endl;
		exit(1); 
	} 
//	f.getline(s,318);          //从文件中输入一行字符,文件里内容不多时，就直接读完，f.eof()非零 
	while(!f.eof()){
		//文件未结束
		f.getline(s,318);      //从文件中输入一行字符
		cout<<s<<endl;         //输出一行字符 
	} 
	f.close();
	
	system("PAUSE");
	return 0;
} 
