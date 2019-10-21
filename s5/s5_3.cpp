#include<iostream>
#include<string>
using namespace std;

//TClass是类模板，是CInterger类和CFloat类的抽象描述
//用类模板可以生成具体的模板类，模板类则可以用于创建对象
//声明类模板
template<class Type>
class TClass{
	public:
		TClass(Type);              //使用默认的析构函数
		void SetItem(Type);
		Type GetItem(); 
	private:
		Type m_item;
}; 

//定义类模板构造函数
template<class Type>
TClass<Type>::TClass(Type item){
	m_item=item;
} 

//定义类模板成员函数
template<class Type>
void TClass<Type>::SetItem(Type item){
	m_item=item;
} 

//定义类模板成员函数
template<class Type>
Type TClass<Type>::GetItem(){
	return m_item;
} 

//测试程序
int main(){
	TClass<int> Obj1(128);             //声明一个TClass<int>模板类对象
	cout<<Obj1.GetItem()<<endl;
	Obj1.SetItem(218);
	cout<<Obj1.GetItem()<<endl;
	TClass<float> Obj2(0.128);         //声明一个TClaa<int>模板类对象
	cout<<Obj2.GetItem()<<endl;
	Obj2.SetItem(0.218);
	cout<<Obj2.GetItem()<<endl;
	
	return 0; 
} 
