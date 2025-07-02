#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    void solve(int n,vector<string>&res,string st,int open,int close){
      if(st.size()==n*2){
         res.push_back(st);
        return;
      }
      if(open<n){
        solve(n,res,st+'(',open+1,close);
      }
      if(open>close){
        solve(n,res,st+')',open,close+1);
      }
    }

};
int main(){
    Solution s1;
    int n;
    cout<<"\n enter size : ";
    cin>>n;
    vector<string> res;
    s1.solve(n,res,"",0,0);
    for(auto it : res){
        cout<<" "<<it;
    }
}