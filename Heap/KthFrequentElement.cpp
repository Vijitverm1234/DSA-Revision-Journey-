#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void topKFreq(vector<int> &arr, int k) {
        // Code here
     int n=arr.size();
     map<int,int> mapp;
     for(auto it : arr){
         mapp[it]++;
     }
     priority_queue<pair<int,int>>pq;
     vector<int> ans;
     for(auto it : mapp){
         pq.push({it.second,it.first});
     }
     while(k--){
         ans.push_back(pq.top().second);
         pq.pop();
     }
    for(auto it: ans){
        cout<<" "<<it;
    }
    }
};

int main(){
    Solution s;
    vector<int> ans={3, 1, 4, 4, 5, 2, 6, 1};
    s.topKFreq(ans,2);
  
}