#include<iostream>
using namespace std;

void Print(const int &n);         //��ǰ����
int main(void){
    int i=10;
    Print(i);
}

void Print(const int &n){        //const int &n ������
    //n++;                       //nΪ�����ã�ֵ���ɸı� 
    cout<<n<<endl;
}
