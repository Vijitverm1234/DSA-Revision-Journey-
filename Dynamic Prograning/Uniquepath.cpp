#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    long long MOD=1000000007;
    int solve(vector<vector<int>>&dp,int m,int n, int i,int j){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=solve(dp,m,n,i+1,j)%MOD+solve(dp,m,n,i,j+1)%MOD;
    }
    int numberOfPaths(int m, int n) {
        // Code Here
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(dp,m,n,0,0);
    }
};

int main(){
    Solution s;
    int res=s.numberOfPaths(3,3);
    cout<<res;
}