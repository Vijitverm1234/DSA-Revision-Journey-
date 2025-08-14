class Solution {
  public:
    long long solve(vector<int>& arr) {
        // code here
        int n=arr.size();
        long long res=0;
        sort(arr.begin(),arr.end());
        int t=0;
        for(int i=0;i<n;i++){
            res+=t;
            t+=arr[i];
        }
        return res/n;
    }
};