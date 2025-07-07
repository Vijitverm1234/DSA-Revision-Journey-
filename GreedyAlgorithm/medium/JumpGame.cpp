#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
     vector<int> arr={2, 1, 1, 0, 0};
    int n=arr.size();
    int check=0;
    for(int i=0;i<n;i++){
        if(i>check){
            cout<<"Not possible";
            
            break;
        }
        check=max(check,i+arr[i]);
    }
    cout<<"Possible";
}