//eof()函数使用示例
#include<iostream>
using namespace std;

char GetChar(istream &in=cin){             //从输入流in中跳过空格获取一字符 
	char ch;                               //字符变量
	
	while(!in.eof()&&(ch=in.get())==' ');  //输入的字符为空格，可以捕获空格？
	
	return ch;                             //返回字符 
} 

int main(){
	char ch;                               //字符变量
	
	cout<<"请输入一行字符："<<endl;        //输入提示
	ch=GetChar();                          //输入字符，自动跳过空格
	while(ch!='\n'&&ch!=EOF){
		cout.put(ch);                      //输出字符 
		ch=GetChar();                      //输入字符，自动跳过空格 
	} 
	cout<<endl;
	
	system("PAUSE");
	return 0;
}
