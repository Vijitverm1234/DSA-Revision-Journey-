#include<iostream> 
#include<stack>
using namespace std;
void insertStack(stack<int>&st,int x){
    if(st.empty() || x>=st.top()){
        st.push(x);
        return;
    }
    int el=st.top();
    st.pop();
    insertStack(st,x);
    st.push(el);
}
void sort(stack<int>&st){
    if(!st.empty()){
        int x=st.top();
        st.pop();
        sort(st);
        insertStack(st,x);
    }
}
void printStack(stack<int> st){
    cout<<"\nCurrent Stack : ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main(){
    stack<int> st;
    st.push(13);
    st.push(3);
    st.push(5);
    st.push(90);
    st.push(100);
    st.push(9);
    printStack(st);
    sort(st);
    printStack(st);
    
}