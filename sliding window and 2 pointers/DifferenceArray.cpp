class Solution {
  public:
    vector<int> diffArray(vector<int>& arr, vector<vector<int>>& opr) {
        // code here
        int n=arr.size();
          vector<int>diff(n+1,0);
        for(auto it : opr){
            int l=it[0];
            int r=it[1];
          
            int val=it[2];
            diff[l]+=val;
            
                diff[r+1]-=val;
            
        }
        int temp=0;
        for(int i=0;i<n;i++){
            temp+=diff[i];
            arr[i]+=temp;
            
        }
        return arr;
    }
};