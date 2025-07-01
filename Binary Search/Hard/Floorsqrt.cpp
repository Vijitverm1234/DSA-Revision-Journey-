#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"\nenter : ";
    cin>>n;
    int low=1;
    int high=n;
    while(low<=high){
        long long mid=(low+high)/2;
        if(mid*mid<=n){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<"\nRequired sqaure-root  : "<<high;

}