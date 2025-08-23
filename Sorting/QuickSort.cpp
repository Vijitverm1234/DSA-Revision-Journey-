#include<iostream>
#include<vector>
using namespace std;
class Sort{
    public:
    //taking the pivot element as the last one 
     int partition(vector<int>&arr,int low,int high){
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
     void quickSort(vector<int> &arr,int low,int high){
        if(low<high){
            int pi=partition(arr,low,high);
            quickSort(arr,low,pi-1);
            quickSort(arr,pi+1,high);
        }
     }
};
int main(){
   Sort s;
   vector<int>arr={23,12,1,45,64};
   s.quickSort(arr,0,4);
   for(auto it : arr){
    cout<<it<<" ";
   }
   
}