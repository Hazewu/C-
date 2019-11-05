/*
���ļ������Ա����read()��write()��/д�������ļ���һ���ʽ��
    �ļ�������.read(�ַ�ָ�룬����);
	�ļ�������.write(�ַ�ָ�룬����); 
*/ 

//��һ���������麬6������������Щ���ݴ��뵽һ���������ļ���
//Ȼ���ٴ�����ļ��ж�����Щ���ݲ���ʾ����ʾ����

#include<iostream>
#include<fstream>
using namespace std;

int main(){
	int a[]={1,5,8,10,18,98},n=6,x;         //�������������ͱ���
	fstream f;                              //�����ļ�����
	
	f.open("test.dat",ios::out|ios::binary);//�������ʽ���ļ�
	if(f.fail()){
		//���ļ�ʧ��
		cout<<"���ļ�ʧ�ܣ�"<<endl;
		exit(1); 
	} 
	for(int i;i<n;i++){
		f.write((char *)&a[i],sizeof(int)); //д���ݵ��ļ��� 
	}
	f.close();                              //�ر��ļ�
	//f.write((char *)&a[0],sizeof(a));     //һ��д��һ�����ݣ������ 
	
	f.open("test.dat",ios::in|ios::binary); //�����뷽ʽ���ļ�
	if(f.fail()){
		//���ļ�ʧ��
		cout<<"���ļ�ʧ�ܣ�"<<endl;
		exit(2); 
	} 
	f.read((char *)&x,sizeof(int));         //���ļ��ж������ݵ�x
	while(!f.eof()){
		cout<<x<<" ";                       //���x����ʾ�� 
		f.read((char *)&x,sizeof(int));     //���ļ��ж������ݵ�x 
	} 
	cout<<endl;
	f.close();
	
	system("PAUSE");
	return 0; 
} 
