class Solution {
  public:
    int solve(int i,vector<int> arr,vector<int>& dp){
        int n=arr.size();
        
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int pick=solve(i+2,arr,dp)+arr[i];
        int nonpick=solve(i+1,arr,dp);
        return dp[i]=max(pick,nonpick);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
       int n=arr.size();
       vector<int> dp(n+1,-1);
       int res=solve(0,arr,dp);
       return res;
    }
};