#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistinctElements(vector<int>& arr, int k) {
     
       map<int,int> mapp;
       for(auto it: arr){
        mapp[it]++;
       } 
      
     priority_queue<int,vector<int>,greater<int>>pq;
     for(auto it : mapp){
        pq.push(it.second);
     }
     while(k>0){
        k-=pq.top();
        if(k>=0){
           pq.pop();
        }
        
     }
     return pq.size();
    }
};
int main(){
    Solution s;
    vector<int> arr={4,3,1,1,3,3,2};
    int res=s.maxDistinctElements(arr,3);
    cout<<"Res : "<<res;
}