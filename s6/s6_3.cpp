#include<iostream>
using namespace std;

//定义累加求和类
class Sum{
private:
//数据成员 
	int sum;                   //用于存储累加和
	
public:
//公有成员
    Sum():sum(0){}             //构造函数
	void operator()(int e){    //重载函数运算符 
		sum=sum+e;
	} 
	int GetSum()const{         //求累加和 
	    return sum;            //返回累加和sum 
	}
}; 

template<class It,class Fun>
Fun &ForEach(const It &begin,const It &end,Fun f){   //遍历算法 
	for(It it=begin;it!=end;it++){  
		//依次调用f()
		f(*it);                     //调用算法 
	}
	return f;                       //返回f 
}

int main(){
	int a[]={1,2,3,4,5,6};          //定义数组a
	int n=6;                        //元素个数
	int *begin=a;                   //开始 
	int *end=a+n;                   //结束
	
	Sum &objSum=ForEach(begin,end,Sum());//定义函数对象引用，并遍历算法，有问题 
	cout<<"sum="<<objSum.GetSum()<<endl;  //输出累加和
	
	system("PAUSE");
	return 0; 
}

//又有问题 ，差评差评
//[Error] invalid initialization of non-const reference of type 'Sum&' from an rvalue of type 'Sum'
