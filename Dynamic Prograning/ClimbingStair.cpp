int solve(int n,vector<int>& dp){
    if(n==0){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=(solve(n-1,dp)+solve(n-2,dp))%1000000007;
}
int countDistinctWays(int n) {
    //  Write your code here.
    vector<int>dp(n+1,-1);
    
    int res=solve(n,dp);
    return res;

}