/*
对于二进制文件，允许对指针进行控制，使它按用户的意图移动到所需的位置，以便在该位置上进行读写

文件流与文件指针有关的常用成员函数
tellg()                    返回输入文件指针的当前位置          g——get 
seekg(位置)                将输入文件中指针移到指定的位置 
seekg(位移量,参照位置)     以参照位置为基础移动若干个字节    
tellp()                    返回输出文件指针当前位置            p——put 
seekp(位置)                将输出文件中指针移到指定的位置 
seekp(位移量,参照位置)     以参照位置为基础移动若干个字节 

位移量，当其为正数时，表示向后移；为负数时，表示向前移
参照位置，可以是下面三种之一：
    ios::beg       文件开头，这是默认值 
	ios::cur       当前的位置 
	ios::end       文件末尾 
*/ 

//有三个学生的数据，要求：
//（1）把它们存到磁盘文件中
//（2）将第2个学生的成绩改为99分后存回磁盘文件中的原有位置
//（3）从磁盘文件读出三个学生的数据并在显示器上加以显示

#include<iostream>
#include<fstream>
using namespace std;

struct Student{                       //学生结构 
	int num;                          //学号 
	char name[16];                    //姓名
	float score;                      //成绩 
};

int main(){
	Student stu[3]={                  //定义数组 
	    {2009101,"李倩",68},
	    {2009102,"刘杰",89},
	    {2009103,"王强",98}
	};
	
	fstream f("stu.dat",ios::out|ios::binary);     //定义文件对象，如果文件不存在将建立一个空文件
	f.close();                                     //关闭文件
	f.open("stu.dat",ios::in|ios::out|ios::binary);//再以输入/输出方式打开文件 
	if(f.fail()){
		//打开文件失败
		cout<<"打开文件失败！"<<endl;
		exit(1); 
	}
	
	f.write((char *)&stu[0],sizeof(stu));            //写数据到文件中
	
	Student s;                                       //用于存储第2个学生信息
	f.seekp((2-1)*sizeof(Student),ios::beg);         //定位于第2个学生数据的其实位置
	f.read((char *)&s,sizeof(Student));              //读出第2个学生的信息
	s.score=99;                                      //修改第2个学生的信息
	f.seekp((2-1)*sizeof(Student),ios::beg);         //定位于第2个学生数据的起始位置
	f.write((char *)&s,sizeof(Student));             //写入第2个学生的信息
	
	f.seekg(0);                                      //重新定位于文件开始处
	f.read((char *)&s,sizeof(Student));            	 //读出学生的信息
	while(!f.eof()){
		//文件未结束
		cout<<s.num<<" "<<s.name<<" "<<s.score<<endl;//显示学生信息
		f.read((char *)&s,sizeof(Student));          //读出学生的信息 
	} 
	f.close();
	
	system("PAUSE");
	return 0;
} 
