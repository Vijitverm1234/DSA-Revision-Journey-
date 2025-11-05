#include<bits/stdc++.h>
using namespace std;
class Solution{
   public:
    void lcs(string x,string y){
        int n=x.size();
        int m=y.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
       }
       cout<<"Common char : "<<dp[n][m]<<endl;
       int i=n;
       int j=m;
       string ans;
       while(i>0 && j>0){
          if(x[i-1]==y[j-1]){
            ans.push_back(x[i-1]);
             i--;
             j--;
          }
          else if(dp[i-1][j]>=dp[i][j-1]){
            i--;
          }
          else{
            j--;
          }
       }

       cout<<"LCS string : "<<ans<<endl;
    }
};
int main(){
    string x="ABCBDAB";
    string y="BDCABA";
    Solution s;
    s.lcs(x,y);
}