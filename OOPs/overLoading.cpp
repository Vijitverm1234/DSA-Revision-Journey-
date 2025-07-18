#include<iostream>

using namespace std;
class A{
   public:
    A(int val){
        cout<<"Integer Constructor : "<<val<<endl;
    };
    A(float val){
        cout<<"Float Constructor : "<<val<<endl;
    };
};
int main(){
   A obj(12);
   A obj1(12.34f);
}