#include <iostream>
class HanXin {
	public:
		void line3(int n);
		void line5(int n);
		void line7(int n);
		void showMany();
	private:
		int num;
};

void HanXin::line3(int n) {
	num=n*70;///70%3==1
}

void HanXin::line5(int n) {
	num+=n*21;//21%5==1
}

void HanXin::line7(int n) {
	num+=n*15;//15%7==1
}

void HanXin::showMany() {
	while(num>105)//105=3*5*7
	    num-=105;
	if(num>100||num<10)
	    std::cout<<"Impossible"<<std::endl;
	else
	    std::cout<<num<<std::endl;
}
int main() {
    int n, n1, n2,n3;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> n1 >> n2 >> n3;
        HanXin hx;  //韩信
        hx.line3(n1);  //3人一排
        hx.line5(n2);   //5人一排
        hx.line7(n3);   //7人一排
        hx.showMany();
    }
}

