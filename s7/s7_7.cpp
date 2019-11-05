/**
如果要对外存文件进行操作，应先定义一个文件流类的对象，然后通过文件流对象操作数据。
可以采用如下方式定义文件流对象：
    ofstream outFile;              //定义输出文件流对象outFile
	ifstream inFile;               //定义输入文件流对象inFile
	fstream file;                  //定义输入/输出文件流对象file 
*/ 
/*

常用的文件操作方式：
ios::in——以输出方式打开文件，如果文件不存在将出错，否则打开成功，
           是文件流类ifstream的默认打开方式，打开后文件指针当前位置在文件的开始处 
ios::out——以输出方式打开文件，如果文件不存在将建立一个新文件，否则清空文件，
            是文件流类ofstream的默认打开方式，打开后文件指针当前位置在文件的开始处  
ios::app——以追加方式打开文件，如果文件已存在则不清除原有内容，否则出现运行时错误，
            打开后文件的当前位置在文件指针的结尾处 
ios::binary——以二进制方式打开文件，如不指定此方式则默认为ASCII方式打开文件

两种方式打开文件
（1）  ofstream outFile;                       //定义一个输出流文件类ostream对象outFile 
       outFile.open("test.txt",ios::out);      //以输出方式打开一个文件，使文件流对象 
                                               //outFile与test.txt文件建立联系
（2）  ofstream outFile("test.txt",ios::out);  //定义文件流对象，并以输出方式打开一个文件
                                               //使文件流对象outFile与test.txt文件建立联系

如果打开操作失败，文件流成员函数fail()返回非0值，否则返回0.使用方式：
    文件流对象.fail()
关闭外存文件，使用方式：
    文件流对象.fail()
文件打开后的输入输出，使用方式：
     fstream f;                //定义文件对象
	 f>>x;                     //将文件里的内容，输入到x中 
	 f<<x;                     //将x里的内容，输出到文件中 
*/  

//有一个整型数组含6个整数，将这些数据存入到一个文本文件中 
//然后再从这个文件中读取数据并显示再显示屏上

#include<iostream>
#include<fstream>
using namespace std;

int main(){
	int a[]={1,5,8,10,18,98},n=6,x;      //定义数组与整型变量
	fstream f;                           //定义文件对象
	
	f.open("test.txt",ios::out);         //以输出方式打开文件
	if(f.fail()){
		//打开文件失败
		cout<<"打开文件失败！"<<endl;
		exit(1); 
	}  
	for(int i=0;i<n;i++){
		f<<a[i]<<" ";                    //输出数据到文件中 
	}
	f.close();                           //关闭文件
	
	f.open("test.txt",ios::in);          //以输入方式打开文件
	if(f.fail()){
		//打开文件失败
		cout<<"打开文件失败！"<<endl;
		exit(2); 
	} 
	while(!f.eof()){
		f>>x;                            //从文件中输入数据到x
		cout<<x<<" ";                    //输出x到显示器 
	}
	cout<<endl;
	f.close();
	
	system("PAUSE");
	return 0;
} 
