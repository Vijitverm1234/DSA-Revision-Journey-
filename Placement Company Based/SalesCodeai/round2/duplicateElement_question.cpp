#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr={1,1,2,2,4,3,3,4,9,9,10};
    int n=arr.size();
    int ans=0;
    for(int i=0;i<n;i++){
        ans^=arr[i];
    }
    cout<<"Unique Element :"<<ans;
}