//queue使用示例
#include<iostream>
#include<list>
#include<queue>
using namespace std;

int main(){
	queue<int,list<int> > q;         //定义队列对象
	for(int i=1;i<=5;i++){
		//依次入队 
		q.push(i);                  //i入队 
	} 
	
	cout<<"队列q：";                //输出提示
	while(!q.empty()){
		//队列q非空
		cout<<q.front()<<" ";       //输出队列
		q.pop();                    //出队 
	} 
	cout<<endl;
	
	system("PAUSE");
	return 0;
} 
