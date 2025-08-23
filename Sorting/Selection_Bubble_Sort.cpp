#include<iostream>
#include<vector>
using namespace std;
class Sort{
    public:
      void SelectionSort(vector<int> arr,int n){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                    swap(arr[i],arr[j]);
                }
            }
        }
        for(auto it: arr){
            cout<<it<<" ";
        }
      }
       void BubbleSort(vector<int> arr,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j+1]<arr[j]){
                    swap(arr[j+1],arr[j]);
                }
            }
        }
        for(auto it: arr){
            cout<<it<<" ";
        }
      }
};
int main(){
   Sort s;
   vector<int>arr={23,12,1,45,64};
//    s.BubbleSort(arr,5);
   
}