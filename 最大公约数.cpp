//第1行是一个整数T，表示随后有T组数据。每组数据占一行，包含两个整数，用空格隔开。
#include<iostream>

class Number {
	public:
		Number(int n);  //构造函数 
		int maxDivisor(Number dest);//最大公约数 
		void show();//展示 
	private:
		int num;
};

Number::Number(int n) {
	num=n;
}

int Number::maxDivisor(Number dest) {
	int b=dest.num,temp;
	while(b!=0) {
		temp=num%b;
		num=b;	
		b=temp;
	}
	return num;
}

void Number::show() {
	std::cout<<num<<std::endl;
}

int main() {
    int n, n1, n2;
	std::cin >> n;
    for(int i = 0; i < n; ++i) {
		std::cin >> n1 >> n2;
	    Number no1(n1), no2(n2);       
		Number no3 = no1.maxDivisor(no2);  //最大公约数,系统调用了拷贝构造函数，直接就类似于no3（n3），n3= no1.maxDivisor(no2)
		no3.show();
    }
	return 0;
}


