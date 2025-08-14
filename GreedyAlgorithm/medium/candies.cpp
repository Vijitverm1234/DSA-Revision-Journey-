class Solution {
public:
    int candy(vector<int>& arr) {
        int n=arr.size();

        vector<int> candies(n,1);
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]){
                candies[i]=1+candies[i-1];
            }
        }
        for(int i=n-1;i>0;i--){
            if(arr[i-1]>arr[i]){
                candies[i-1]=max(candies[i-1],1+candies[i]);
            }
        }
        int res=accumulate(candies.begin(),candies.end(),0);
        return res;
    }
};