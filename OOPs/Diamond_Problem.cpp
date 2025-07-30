#include<iostream>
#include<algorithm>
using namespace std;
class Vehicle{
    public:
    void display(){
        cout<<"base class display method"<<endl;
    }
};
class Car:virtual public Vehicle{

};
class Truck:virtual public Vehicle{

};
class Pick:public Car, public Truck{

};
int main(){
    Pick p;
    p.display();
}
