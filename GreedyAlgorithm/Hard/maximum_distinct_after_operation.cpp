#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
      int curr=INT_MIN;
      int count=0;
      for(auto it : nums){
        int low=it-k;
        int high=it+k;
        if(curr+1<=high){
            int assigned=max(curr+1,low);
            curr=assigned;
            count+=1;
        }
      }  
      return count;
    }
};
int main(){
    Solution s;
    vector<int> arr={1,2,2,3,3,4};
    int res=s.maxDistinctElements(arr,2);
    cout<<"result : "<<res;
}