


// friend class can access the private attribute of assoiciated class

#include<iostream>
using namespace std;
class Account{
    private:
    double balance;
    public:
    Account(double bal):balance(bal){}
    friend class Transaction;
    void display(){
        cout<<"Current Balance : "<<balance<<endl;
    }
};
class Transaction{
    public:
    void withDraw(Account acc,int bal){
        if(acc.balance<bal){
            cout<<"Not Possible"<<endl;
        }
        else{
            acc.balance=acc.balance-bal;
            cout<<"remaining balance : "<<acc.balance;
        }
    }
};
int main(){
   Account acc(500);
   Transaction t;
   t.withDraw(acc,100);
}