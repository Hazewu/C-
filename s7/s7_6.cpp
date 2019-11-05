//编程输入一行双精度实型数，不同数之间用空格隔开，
//假设每个实数均以十进制数字开始
#include<iostream>
using namespace std;

char GetChar(istream &in=cin){     //从输入流in中跳过空格获取一字符 
	char ch;                       //字符变量 
	while(in.peek()!=EOF           //未遇到文件结束符 
	    &&((ch=in.get())==' '));   //输入的字符为空格
	return ch;                     //返回字符 
} 

int main(){
	char ch;                       //字符变量
	double x;                      //双精度实型变量
	
	ch=GetChar();                  //跳过空格输入一个字符
	while(ch!='\n'&&ch!=EOF){
		if(ch>='0'&&ch<='9'){      //ch只能读一个字符，仅作判断当前字符是否为 实数开始字符 
			//是实数的开始字符
			cin.putback(ch);       //将ch回送到输入流对象cin中,但并没有出现在显示屏上 
			cin>>x;                //输入双精度实数x，x可以读入/输出一个实数 
			cout<<x<<" ";          //输出双精度实数x 
		}else{
			//非法字符
			cout<<"出现非法字符！"<<endl;
			exit(1);                //退出程序 
		} 
		ch=GetChar();               //跳过空格输入一个字符 
	} 
	cout<<endl;
	
	system("PAUSE");
	return 0;
}
