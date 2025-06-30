class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans=INT_MAX;
        if(n==1){
            return arr[0];
        }
        if(n==2){
            if(arr[0]==arr[1]){
                return arr[0];
            }
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[low]==arr[mid] && arr[mid]==arr[high]){
                ans=min(ans,arr[low]);
                low++;
                high--;
                continue;
            }
            if(arr[low]<=arr[mid]){
                ans=min(ans,arr[low]);
                low=mid+1;
            }
            else{
                ans=min(ans,arr[mid]);
                high=mid-1;
            }

        }
        return ans;
    }
};