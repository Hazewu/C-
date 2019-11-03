//根据学号查询学生信息
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//定义学生类
class Student{
private:
//数据成员 
	int num;                 //学号
	string name;             //姓名
	int age;                 //年龄
	string sex;              //性别
public:
//共公有成员
    Student(int n,const string &nm,int ag,const string &sx):num(n),name(nm),age(ag),sex(sx){}
	                         //构造函数
	int GetNum() const{      //返回学号 
	    return num;
	} 
	string GetName() const{  //返回姓名
	    return name;
	} 
	int GetAge() const{      //返回年龄 
	    return age;
	}
	string GetSex() const{   //返回性别 
	    return sex;
	}
	bool operator==(int n){  //重载相等运算符“==” 
		return num==n;       //转化为学号的比较 
	}
}; 

int main(){
	vector<Student> v;           //定义向量对象,类也可以作为一种类型，struct也可以 
	
	v.push_back(Student(20120101,"张杰明",18,"男"));
	                             //向v尾插入一个学生信息
	v.push_back(Student(20120102,"吴晓珊",20,"女"));
	                             //向v尾插入一个学生信息
	v.push_back(Student(20120103,"吴洪倩",19,"女")); 
	                             //向v尾插入一个学生信息
	
	vector<Student>::iterator begin,end,it;
	                             //定义迭代器
	begin=v.begin();             //开始
	end=v.end();                 //结束
	
	int findNum=20120102;        //查询条件是学号=20120102
	it=find(begin,end,findNum);  //查询条件是学号=20120102的迭代器
	
	cout<<"学号为"<<findNum<<"的学生的信息："<<endl; 
	                             //输出提示
	if(it!=end){
		//查询成功
		cout<<"学号："<<it->GetNum()<<endl;
		cout<<"姓名："<<it->GetName()<<endl;
		cout<<"年龄："<<it->GetAge()<<endl;
		cout<<"性别："<<it->GetSex()<<endl; 
	}else{
		//查询失败
		cout<<"没有该学号的学生！"<<endl;  
	}
	
	system("PAUSE");
	return 0; 
}
