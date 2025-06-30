#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int solve1(vector<int> arr, int target){
    int first=-1;
    int low=0;
    int n=arr.size();
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            first=mid;
            high=mid-1;
        }
        if(arr[mid]<target){
            low=mid+1;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
    }
    return first;
}
int solve2(vector<int> arr, int target){
    int last=-1;
    int low=0;
    int n=arr.size();
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            last=mid;
            low=mid+1;
        }
        if(arr[mid]<target){
            low=mid+1;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
    }
    return last;
}
int main(){
    vector<int> arr = {12, 34, 13,13,56, 66, 90, 100};
    sort(arr.begin(), arr.end());
    int n = arr.size();
    cout << "\nEntered array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<"\nfirst and last index \n";
   int first= solve1(arr,100); // first index
    int last=solve2(arr,100); // last index
    if(first==-1 || last==-1){
        cout<<"\nElement does not exist";
    }
    else{
        cout<<"\nFirst Index : "<<first<<" Last Index : "<<last;
    }
}