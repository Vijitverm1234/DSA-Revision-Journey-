#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
   vector<int>arr={89,23,34,12,10};
   int n=arr.size();
   for(int i=1;i<n;i++){
    int j=i-1;
    int temp=arr[i];
    while(j>=0 && temp<arr[j]){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=temp;
   }
   for(auto it: arr){
    cout<<it<<" ";
   }
}