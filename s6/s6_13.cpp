/*容器配接器的概念

    //定义队列类模板
	tempalte<class Type,class Container=deque<type>>
	class queue{
	protected:
	//私有成员
	    Container c;                    //用于存储队列元素
	
	public:
	//公有函数模板
	    void push(const Type &e){       //元素e压入对尾 
	        c.push_back(e);             //实际上是调用deque的push_back()函数 
	    }
	    …… 
    };
    
  queue类是对基础容器类Container的再封装，而不是重新定义 
*/ 

/*
queue和stack容器 
1、构造函数模板
（1）queue(class Type,class Container=deque<Type>)：创建元素类型为Type的空队列，默认容器时deque
（2）stack(class Type,class Container=deque<Type>)：创建元素类型为Type的空栈，默认容器是deque
2、队列和栈共有函数模板
（1）bool empty()：如果队列（栈）为空返回true，否则返回false
（2）int size()：返回队列（栈）中元素个数
（3）void push(const Type &e)：把元素e压入队尾（栈顶）
（4）void pop()：在队列（栈）非空情况下，删除队头（栈顶）元素
3、队列独有函数模板
（1）Type &front()：在队列非空情况下，返回队头元素引用
（2）type &back()：在队列非空的情况下，返回队尾元素的引用
4、栈独有函数模板
Type &top()：在栈非空情况下，返回栈顶元素的引用 
*/ 

//stack使用示例 
#include<iostream>
#include<deque>
#include<stack>
using namespace std;

int main(){
	stack<int> s;                  //定义栈对象
	for(int i=1;i<=5;i++){
		//依次入栈
		s.push(i);                 //i入栈 
	} 
	
	cout<<"栈s：";                 //输出提示
	while(!s.empty()){
		//栈s非空
		cout<<s.top()<<" ";        //输出栈顶
		s.pop();                   //出栈 
	} 
	cout<<endl;
	
	system("PAUSE");
	return 0;
} 
