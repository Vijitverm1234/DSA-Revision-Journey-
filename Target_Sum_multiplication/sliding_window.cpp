#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={1, 2, 1, 1, 1, 3, 2};
    int target=3;
    int l=0;
    int r=0;
    int n=arr.size();
    int sum=0;
    int maxlen=0;
    while(r<n){
      sum+=arr[r];
      while(sum>target){
          if(l<r){
            sum-=arr[l];
            l++;
          }
      }
      maxlen=max(maxlen,r-l+1);
     r++;
    }
    cout<<"Answer : "<<maxlen;

}