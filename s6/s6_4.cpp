#include<iostream>
using namespace std;

//定义累加求和类Sum
template<class Type>
class Sum{
private:
//数据成员 
	Type sum;                            //用于累加求和
public:
//公有成员
    Sum():sum(0){}                       //构造函数模板
	void operator()(Type e){             //重载函数模板运算符 
		sum=sum+e;                       //sum累加e 
	} 
	Type GetSum() const{                 //求累加和 
	    return sum;
	}
}; 

template<class It,class Fun>               
Fun &ForEach(const It &begin,const It &end,Fun f){//遍历算法 
	for(It it=begin;it!=end;it++){
		//依次调用
		f(*it);                          //调用f() 
	}
	return f;                            //返回f 
}

int main(){
	int a[]={1,2,3,4,5,6};               //定义数组a
	int n=6;                             //元素个数
	int *begin=a;
	int *end=a+n;
	
	Sum<int> &objSum=ForEach(begin,end,Sum<int>());
	                                     //定义函数对象引用，并调用遍历算法 
    cout<<"sum="<<objSum.GetSum()<<endl; //输出累加和
	system("PAUSE");
	return 0; 
}
//在引用这一点，与s6_3.cpp有同样的问题 
