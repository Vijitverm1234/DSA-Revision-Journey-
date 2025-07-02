#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    void solve(vector<string>&res,string st,string &temp,int i){
     if(i==st.size()){
        res.push_back(temp);
        return;
     }
     temp+=st[i];
     solve(res,st,temp,i+1);
     temp.pop_back();
     solve(res,st,temp,i+1);

    }

};
int main(){

     Solution st;
    vector<string> res;
    string temp="";
    string str="abcd";
    st.solve(res,str,temp,0);
    for(auto it : res){
        cout<<" "<<it;
    }
}