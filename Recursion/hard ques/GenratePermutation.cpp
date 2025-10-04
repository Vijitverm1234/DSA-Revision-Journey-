class Solution {
public:
 void solve(vector<int> arr, int ind,set<vector<int>>&st){
       if(ind==arr.size()-1){
           st.insert(arr);
           return;
       }
       int n=arr.size();
       for(int i=ind;i<n;i++){
           swap(arr[ind],arr[i]);
           solve(arr,ind+1,st);
           swap(arr[ind],arr[i]);
       }
   }
    vector<vector<int>> permute(vector<int>& nums) {
        set<vector<int>> st;
           solve(nums,0,st);
        vector<vector<int>> result(st.begin(),st.end());
        sort(result.begin(),result.end());
        return result;
    }
};
