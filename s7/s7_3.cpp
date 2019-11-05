//用getline()输入一行字符
#include<iostream>
using namespace std;

int main(){
	char s[256];                  //字符串
	
	cout<<"输入一行字符："<<endl; //输入提示
	cin.getline(s,8);             //输入一行字符
	cout<<s<<endl;                //输入一行字符
	
	system("PAUSE");
	return 0; 
} 
