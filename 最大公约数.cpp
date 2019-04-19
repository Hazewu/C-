//��1����һ������T����ʾ�����T�����ݡ�ÿ������ռһ�У����������������ÿո������
#include<iostream>

class Number {
	public:
		Number(int n);  //���캯�� 
		int maxDivisor(Number dest);//���Լ�� 
		void show();//չʾ 
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
		Number no3 = no1.maxDivisor(no2);  //���Լ��,ϵͳ�����˿������캯����ֱ�Ӿ�������no3��n3����n3= no1.maxDivisor(no2)
		no3.show();
    }
	return 0;
}


