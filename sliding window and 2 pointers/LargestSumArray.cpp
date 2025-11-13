#include<iostream>
#include<vector>
#include<map>
using namespace std;
/**
 * 
arr = [1, 2, 1, 1, 1, 3, 2, 1], K = 5
Longest subarray = [2, 1, 1, 1] → length 4

 */
int main(){
    vector<int> arr = {1, 2, 1, 1, 1, 3, 2, 1};
    int k=5;
    int l=0;
    int r=0;
    int n=arr.size();
    int maxlen=0;
    int sum=0;
    // while(r<n){
    //     sum+=arr[r];
    //     while(sum>k && l<r){
    //         sum-=arr[l];
    //         l++;
    //     }
    //     if(sum==k){
    //         maxlen=max(maxlen,r-l+1);
    //     }
    //     r++;
    // }
     int prefix=0;
     map<int,int> mapp;
     for(int i=0;i<arr.size();i++){
        prefix+=arr[i];
        if(prefix==k){
            maxlen=i+1;
        }
        if(mapp.find(prefix-k)!=mapp.end()){
            maxlen=max(maxlen,i-mapp[prefix-k]);
        }
        if(mapp.find(prefix)==mapp.end()){
            mapp[prefix]=i;
        }
     }
    cout<<"Length being : "<<maxlen;
}