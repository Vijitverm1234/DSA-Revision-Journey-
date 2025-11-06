#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="babad";
    int maxlen=1;
    int n=s.size();
    int start=0;
    vector<vector<int>>dp(n,vector<int>(n,false));
    for(int i=0;i<n;i++){
        dp[i][i]=true;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
           if(s[i]==s[j] && (j-i==1 || dp[i+1][j-1] )){
              dp[i][j]=true;
              if(j-i+1>maxlen){
                start=i;
                maxlen=j-i+1;
              }
           }
        }
    }
    cout<<"Maxlen : "<<s.substr(start,maxlen);
}