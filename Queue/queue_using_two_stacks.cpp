#include<bits/stdc++.h>
using namespace std;
class MyQueue{
   stack<int> s1,s2;
   public:
   void push(int x){
     s1.push(x);
     cout<<"Stack pushed"<<endl;
   }
   int pop(){
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    if(s2.empty()){
        return -1;
    }
    int el=s2.top();
    s2.pop();
    cout<<"pop element"<<endl<<el<<endl;
    return el;
   }
    int peek(){
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    if(s2.empty()){
        return -1;
    }
    int el=s2.top();
    cout<<"Element peeked"<<el<<endl;
    return el;
   }
};
int main(){
    MyQueue q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(5);
    q.pop();
    q.peek();
}