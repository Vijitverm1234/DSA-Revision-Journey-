#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    void solve(int n,vector<string>&res,string st){
        if(st.size()==n){
            res.push_back(st);
            return ;
        }
        solve(n,res,st+'0');
        // if(st.back()!='1')  for not allowing the adjacent's 1 
        solve(n,res,st+'1');

    }

};
int main(){
    Solution s1;
    int n;
    cout<<"\n enter size : ";
    cin>>n;
    vector<string> res;
    s1.solve(n,res,"");
    for(auto it : res){
        cout<<" "<<it;
    }
}