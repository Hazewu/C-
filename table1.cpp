#include<iostream>
#include <string>
#include <sstream>
using namespace std;

string a[100][100];

class Table{
	protected:
		int row;
		int column;
	public:
		Table();
		Table(int a,int b); 
		void show();
		void addRow();
		void addColumn();
		void set(int x,int y,int z);
		void set(int x,int y,string z);
		void delRow(int i);
		void delColumn(int i);
};
 
Table::Table(){
	row=1;
	column=1;
}
Table::Table(int a,int b){
	row=a;
	column=b;
}
void Table::show(){
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
	    	cout<<a[i][j]<<" ";
		}
	cout<<"\n";
	}
	cout<<"\n";	
}
void Table::addRow(){
	row=row++;
}
void Table::delRow(int n){
	for(int j=n;j<row-1;j++){
		string *p=a[j];
		*a[j]=*a[j+1];
		*a[j+1]=*p;
	}
	row--;
}
void Table::addColumn(){
	column=column++;
}
void Table::delColumn(int n){
	for(int j=n;j<column-1;j++){
		for(int k=0;k<row-1;k++){
			string p=a[j][k];
			a[j][k]=a[j][k+1];
			a[j][k+1]=p;
		}
	}
	column--;
}
void Table::set(int x ,int y,string z){
	a[x][y]=z;
}
void Table::set(int x,int y,int z){
	stringstream ss;
	string u;
	ss<<z;
	ss>>u;
	a[x][y]=u;
}
int main() {
  Table tb;
  tb.show();
  tb.addRow();
  tb.show();
  tb.addColumn();
  tb.show();
  Table tb1(5,5);
  tb1.show();
  tb1.set(1,1,30);
  tb1.set(2,2,"hello");
  tb1.show();
  tb1.delRow(1);
  tb1.show();
  tb1.delColumn(1);
  tb1.show();
  return 0;
}
