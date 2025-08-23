#include<iostream>
#include<vector>
using namespace std;
class Sort{
    public:
    //taking the pivot element as the last one 
     int merge(vector<int>&arr,int low,int high){
        int pivot=arr[high];
        int i=low-1;
        for(int j=low;j<high;j++){
            if(arr[j]<pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[high]);
        return i+1;
     }
     void MergeSort(vector<int> &arr,int low,int high){
        if(low>high){
            return ;
        }
        if(low<=high){
         int mid=(low+high)/2;
         MergeSort(arr,low,mid);
         MergeSort(arr,mid+1,high);
         merge(arr,low,mid,high);
        }
     }
};
int main(){
   Sort s;
   vector<int>arr={23,12,1,45,64};
   s.MergeSort(arr,0,4);
   for(auto it : arr){
    cout<<it<<" ";
   }
   
}