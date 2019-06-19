#include<iostream>
#include<string.h>
using namespace std; 
class Cell {
public:
  Cell(char con[]);
  ~Cell();//≤ª”√–¥ 

  void show();
private:
  char *content;
};
class Table:protected Cell {
public:
  Table();
  Table(int a,int b);
  void show();
  int addRow();
  void delRow(int n);
  int addColumn();
  void delColumn(int n);
  void set(int a,int b,char con[]);
  void set(int a,int b,int c);
private:
  Cell cells;
};

Cell::Cell(char con[]={"\0"}){
	strcpy(content,con);
}
void Cell::show(){
	cout<<content;
} 
Table::Table(){
	cells.Cell();
}
Table::Table(int a,int b){
}
void Table::show(){	
} 
int Table::addRow(){
}
void Table::delRow(int n){
}
int Table::addColumn(){
}
void Table::delColumn(int n){
}
void Table::set(int a ,int b,char con[]){
}
void Table::set(int a,int b,int c){
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
