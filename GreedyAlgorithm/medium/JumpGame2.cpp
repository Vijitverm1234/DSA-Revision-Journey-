#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> arr={2,3,0,1,4};
    int n=arr.size();
    int l=0;
    int r=0;
    int far=0;
    int count=0;
    while(r<n-1){
        far=0;
        for(int i=l;i<=r;i++){
            far=max(far,arr[i]+i);
        }
        l=r+1;
        r=far;
      count+=1;
    }
    cout<<"Jump Count : "<<count;
}