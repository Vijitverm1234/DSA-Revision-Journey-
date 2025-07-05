#include<iostream>
using namespace std;
class Solution {
public:
    void solve(int i,vector<string>&ans,unordered_map<int,vector<char>>hash,string temp,string s){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        for(auto it : hash[s[i]-'0']){
            temp+=it;
            solve(i+1,ans,hash,temp,s);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string s) {
       vector<string>ans;
       unordered_map<int,vector<char>>hash;
       hash[2]={'a','b','c'};
       hash[3]={'d','e','f'};
       hash[4]={'g','h','i'};
       hash[5]={'j','k','l'};
       hash[6]={'m','n','o'};
       hash[7]={'p','q','r','s'};
       hash[8]={'t','u','v'};
       hash[9]={'w','x','y','z'};
       string temp="";
       if(s.size()==0){
        return {};
       }
       solve(0,ans,hash,temp,s);
       return ans;
    }
};