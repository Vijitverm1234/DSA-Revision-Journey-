#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> arr,int m){
    int low=0;
    int ans=-1;
    int high=m-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==1){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<vector<int>>arr={
        {0,1,1,1}, {0,0,1,1}, {1,1,1,1}, {0,0,0,0}
    };
    int n=arr.size();
    int m=arr[0].size();
    int ans=-1;
    int maxione=0;
    for(int i=0;i<n;i++){
        int firstIndex=solve(arr[i],m);
        if(firstIndex!=-1 && maxione<(m-firstIndex)){
            maxione=m-firstIndex;
            ans=i;
        }
    }
    cout<<"Maximum 1 Rows  is "<<ans;
}