#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> arr={900,945,955,1100,1500,1800};
    vector<int> dep={920,1200,1130,1150,1900,2000};
    int n=arr.size();
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int count=1;
    int i=1;
    int j=0;
    int maxi=1;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            i++;
            count+=1;
        }
        else{
            j++;
            count-=1;
        }
    maxi=max(maxi,count);
    }
    cout<<"Platform needed : "<<count;
}