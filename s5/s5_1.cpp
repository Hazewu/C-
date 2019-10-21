//通过函数模板实现求3个不同数据类型数据中最大的一个

#include<iostream>
#include<string>
using namespace std;

template <class Type>           //声明函数模板1
Type GetMax(Type a,Type b,Type c);

//主函数
int main(){
	string str1("Rong Ji"),str2("Zhe Ming"),str3("Jing Tao");
	//使用函数模板1
	cout<<"int:10,30,21,max="<<GetMax(10,30,21) <<endl;
	cout<<"double:51.8,20.8,31.6,max="<<GetMax(51.8,20.8,31.6)<<endl;
	cout<<"char:'A','b','Z',max="<<GetMax('A','b','Z')<<endl;
	cout<<"string:str1(\"Rong Ji\"),str2(\"Zhe Ming\"),str3(\"Jing Tao\"),max="<<GetMax(str1,str2,str3)<<endl;
            //注：比较三个字符串对象的大小 
    cin.get(); 
}

//定义模板函数1
template <class Type>
Type GetMax(Type a,Type b,Type c){
	Type t;
	t=a>b?a:b;           //求a和b的较大者
	return t>c?t:c;      //返回a，b，c的最大者 
} 
