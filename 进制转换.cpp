#include <iostream>

class Number {
	public:
		Number(int n,int scale);//构造函数 
		int converto(int scale);//转换进制 
		void show();//展示 
	private:
		int num;
};

Number::Number(int n,int scale=10) {
	num=n;
}

int Number::converto(int scale) {
	int temp,i,newn=0,length;
	int a[20]={0};      //用数组存放 
	for(i=0;num>0;i++) {
		a[i]=num%scale;
		num=num/scale;
	}
	length=i;
	for(i=length;i>=0;i--)
	newn=newn*10+a[i];   //新的进制数 
	return newn;
}

void Number::show() {
	std::cout<<num<<std::endl;
}

int main() {
    int n, n1, n2;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> n1 >> n2;
        Number no1(n1, 10);     //n1是10进制正整数
        Number no3 = no1.converto(n2);  //no3是n2进制的正整数
        no3.show();     //输出结果
    }
    return 0;
}

