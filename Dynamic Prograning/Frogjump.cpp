class Solution {
  public:
    int solve(int n,vector<int>& dp,vector<int> arr){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int right=INT_MAX;
        if(n>1){
            right= solve(n-2,dp,arr)+abs(arr[n]-arr[n-2]);
        }
        int left=solve(n-1,dp,arr)+abs(arr[n]-arr[n-1]);
        return dp[n]=min(left,right);
    }     
    int minCost(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> dp(n+1,-1);
        int res=solve(n-1,dp,arr);
        return res;
    }
};