#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,int> mapp;
    int sum=0;
    int i=0;
    int ans=0;
    vector<int> arr={10, 5, 2, 7, 1, 9};
    int target=15;
    int n=arr.size();
    while(i<n){
        sum+=arr[i];
        if(mapp.find(sum)==mapp.end()){
            mapp[sum]=i;
        }
       if(mapp.find(sum-target)!=mapp.end()){
        ans=max(ans,i-mapp[sum-target]);
       }
        i++;
    }
    cout<<"ans being "<<ans;
}