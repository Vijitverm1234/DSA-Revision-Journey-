#include<iostream>
using namespace std;


void call_by_Value(int a,int b){
    a=a+b;
    b=a-b;
    a=a-b;
}
void call_by_Reference(int& a,int& b){
    a=a+b;
    b=a-b;
    a=a-b;
}

int main(){
    int a=5,b=10;
    cout<<"Original : "<<a<<" "<<b<<endl;
    call_by_Value(a,b);
    cout<<"Call By Value : "<<a<<" "<<b<<endl;
    call_by_Reference(a,b);
    cout<<"Call By Reference : "<<a<<" "<<b<<endl;
}