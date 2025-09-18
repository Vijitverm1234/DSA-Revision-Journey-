#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int a, int b,string op){
        if(op=="+"){
            return a+b;
        }
        if(op=="-"){
            return a-b;
        }
        if(op=="*"){
            return a*b;
        }
        if(op=="/"){
            return a/b;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        map<string,int>mapp;
        mapp["+"]=1;
        mapp["-"]=1;
        mapp["/"]=1;
        mapp["*"]=1;
        stack<int> st;
        for(auto token: tokens){
            if(mapp.find(token)!=mapp.end()){
                int token2=st.top();
                st.pop();
                int token1=st.top();
                st.pop();
                st.push(solve(token1,token2,token));
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
int main(){
    vector<string> arr={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution s;
    int res=s.evalRPN(arr);
    cout<<"After Evalutaion "<<res;
}