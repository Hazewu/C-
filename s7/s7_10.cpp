/*
用文件流类成员函数read()和write()读/写二进制文件，一般格式：
    文件流对象.read(字符指针，长度);
	文件流对象.write(字符指针，长度); 
*/ 

//有一个整型数组含6个整数，将这些数据存入到一个二进制文件中
//然后再从这个文件中读出这些数据并显示再显示器上

#include<iostream>
#include<fstream>
using namespace std;

int main(){
	int a[]={1,5,8,10,18,98},n=6,x;         //定义数组与整型变量
	fstream f;                              //定义文件对象
	
	f.open("test.dat",ios::out|ios::binary);//以输出方式打开文件
	if(f.fail()){
		//打开文件失败
		cout<<"打开文件失败！"<<endl;
		exit(1); 
	} 
	for(int i;i<n;i++){
		f.write((char *)&a[i],sizeof(int)); //写数据到文件中 
	}
	f.close();                              //关闭文件
	//f.write((char *)&a[0],sizeof(a));     //一次写入一批数据，更简捷 
	
	f.open("test.dat",ios::in|ios::binary); //以输入方式打开文件
	if(f.fail()){
		//打开文件失败
		cout<<"打开文件失败！"<<endl;
		exit(2); 
	} 
	f.read((char *)&x,sizeof(int));         //从文件中读出数据到x
	while(!f.eof()){
		cout<<x<<" ";                       //输出x到显示器 
		f.read((char *)&x,sizeof(int));     //从文件中读出数据到x 
	} 
	cout<<endl;
	f.close();
	
	system("PAUSE");
	return 0; 
} 
