#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        for(int i=0;i<path.size();i++){
           
            if(path[i]=='/'){
                continue;
            }
             string temp;
            while(i<path.size() && path[i]!='/'){
                temp+=path[i];
                i++;
            }
            if(temp=="." || temp.size()==0){
                continue;
            }
            else if(temp==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(temp);
            }
        }
        string res;
        while(!st.empty()){
            res='/'+st.top()+res;
            st.pop();
        }
        if(res.size()==0){
            return "/";
        }
        return res;
    }
};
int main(){
    string path="/home/user/Documents/../Pictures";
    Solution s;
    string res=s.simplifyPath(path);
    cout<<res;
}