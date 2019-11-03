//求整数数组各元素的和、最大值和最小值的实例
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//定义GetInfo
class GetInfo{
private:
//数据成员 
	int sum;                          //和
	int max;                          //最大值
	int min;                          //最小值
	int count;                        //元素个数
public:
//公有函数
    GetInfo():sum(0),count(0){}       //构造函数
	int GetSum()const{                //获得和 
	    return sum;
	}
	int GetMax()const{                //获得最大值 
	    return max;
	} 
	int GetMin()const{                //获得最小值 
	    return min;
	}
	void operator()(int e){           //重载单参数的函数运算符 
		count++;                      //元素个数自加1 
		sum=sum+e;                    //累加求和 
		if(count==1){
			//e为第一个元素
			max=min=e;                //只有一个元素时，最大值与最小值都为e 
		}else{
			//有多个元素
			if(max<e){
				//e为当前输入的值，max为当前已求的最大值
				max=e;                //将e赋值给max 
			} else if(min>e){
				//e为房前输入的值，min为当前已求的最小值
				min=e;                //将e赋值给min 
			}
		}
	}
}; 

int main(){
	int a[]={1,4,2,8,5,6};            //定义数组
	int n=sizeof(a)/sizeof(int);      //数组元素个数
	int *begin=a;                     //开始 
	int *end=a+n;                     //结束
	
	GetInfo objGetInfo=for_each(begin,end,GetInfo());
	                                  //定义函数对象，通过for_each()算法进行初始化
	cout<<"总和是："<<objGetInfo.GetSum()<<endl;
	cout<<"最大值："<<objGetInfo.GetMax()<<endl;
	cout<<"最小值；"<<objGetInfo.GetMin()<<endl;
	
	system("PAUSE");
	return 0; 
}
