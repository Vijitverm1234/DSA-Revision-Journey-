#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
   void solve(int i,vector<int> &curr,vector<int> arr,vector<vector<int>> &ans,int target){
    if(i==arr.size() ){
        if(target==0)
        ans.push_back(curr);
        return;
    }
    if(arr[i]<=target){
        curr.push_back(arr[i]);
        solve(i,curr,arr,ans,target-arr[i]);
        curr.pop_back();
    }
    // int nextIndex = index + 1;
    //     while (nextIndex < arr.size() && arr[nextIndex] == arr[index]) {
    //         nextIndex++; // Skip duplicates
    //     }
    //     solve(nextIndex, ans, ds, arr, target);
    // } for having unique in array 
    
     solve(i+1,curr,arr,ans,target);
   }
};
int main(){
    int tar;
    cout<<"\nEnter the Target : ";
    cin>>tar;
    vector<vector<int>> ans;
    vector<int>curr;
     vector<int> arr {2,3,5};
     Solution s;
     s.solve(0,curr,arr,ans,tar);
    for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
    
}