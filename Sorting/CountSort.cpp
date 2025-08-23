#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr={23,21,56,32,12};
    int n=arr.size();
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    vector<int> count(maxi+1,0);
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=maxi;i++){
        count[i]+=count[i-1];
    }
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        ans[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}