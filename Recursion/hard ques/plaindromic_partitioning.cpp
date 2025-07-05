#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 bool ispalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
void solve(int i,string &temp,vector<string>&ans,string s){
   
    if (i == s.size()) {
        ans.push_back(temp);
        return;
    }
    for (int ind = i; ind < s.size(); ind++) {
        if (ispalindrome(s, i, ind)) {
            temp+=s.substr(i, ind - i + 1); 
            solve(ind + 1, temp, ans, s); 
            temp.pop_back();
        }
    }
}

int main(){
    string s="aaab";
    
    vector<string> ans;
    string temp="";
    solve(0,temp,ans,s);
    for(int i=0;i<ans.size();i++){
       cout<<ans[i]<<" ";
    }
}