#include<iostream>
using namespace std;

int main(){
    int i=10;
    int &j=i;              //quote, and no storage space will be allocated to j
    cout<<"i="<<i<<endl;
    cout<<"j="<<j<<endl;
    j++;
    i++;
    cout<<"i="<<i<<endl;
    cout<<"j="<<j<<endl;
    return 0;
}
