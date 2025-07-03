
n-> target
k->size of target vector

void combinationSum3(vector<int> arr,vector<int>&temp,vector<vector<int>>&ans,int i,int n,int k){
   if(target==0 && temp.size()==k){
    ans.temp_back(temp);
     return;
   }
  if(i>=arr.size() || target<0 || temp.size()>k{
    return;
  }
temp.push_back(arr[i]);
solve(arr,temp,ans,i+1,n-arr[i],k);
temp.pop_back(arr[i]);
solve(arr,temp,ans,i+1,n,k);
}
