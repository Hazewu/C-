#include"sclass2_11_rectangle.h"

int main(void){
    Rectangle *rp=new Rectangle(10,5);
    rp->Print();
    rp->SetSize(45,20);
    cout<<"�ı��������"<<rp->GetArea()<<endl;
    delete rp;
    return 0;
}
