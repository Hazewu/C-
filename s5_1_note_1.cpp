#include<iostream>
using namespace std;
int main()
{
	char a,b;
	a=cin.get();     //获取键入的值，包括空格、回车符 ，包括回车符，回车符 
	cin.get(b);      //输入 空格、字符；字符、空格；字符、回车符……看结果 
	cout<<a<<b<<endl;
	system("pause");
	return 0;
}
