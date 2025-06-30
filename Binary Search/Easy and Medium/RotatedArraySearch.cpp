#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int search(vector<int> arr, int n,int k){
    int low=0;
    int high=n-1;
    while(low<=high){
     int mid=low+(high-low)/2;
     if(arr[mid]==k){
        return mid;
     }


//    Edge case when the array contains the dupliacates   
//    if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
//             low = low + 1;
//             high = high - 1;
//             continue;
//         }

     if(arr[low]<=arr[mid]){
        if(arr[low]<=k && k<=arr[high]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
     }
     else{
            if(arr[mid]<=k && k<=arr[high]){
              low=mid+1;  
            }
            else{
                high=mid-1;
            }
     }
    }
    return -1;
}
int main(){
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k=1;
    
    int ans = search(arr,n,k);
    
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}