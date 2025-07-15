#include<iostream>
#include<unordered_map>
int kDistinctChars(int k, string &s)
{
    // Write your code here
    int n=s.size();
    unordered_map<char,int> mapp;
    int left=0;
    int right=0;
    int res=-1;
    while(right<n){
        mapp[s[right]]++;
        while(mapp.size()>k && left<right){
            mapp[s[left]]--;
            if(mapp[s[left]]==0){
                mapp.erase(s[left]);
            }
            left++;
        }
        if(mapp.size()<=k){
            res=max(res,right-left+1);
        }
        right++;
    }
    return res;
}


