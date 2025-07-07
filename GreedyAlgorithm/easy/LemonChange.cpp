#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool solve(vector<int> arr){
   int count1=0;
   int count2=0;
   int count3=0;
  for(int i=0;i<arr.size();i++){
    if(arr[i]==5){
       count1+=1;
    }
    else if(arr[i]==10){
       if(count1==0){
        return false;
       }
       count2+=1;
    }
    else{
        if(count1 && count2){
            count1-=1;
            count2-=1;
        }
        else if(count1>=3){
            count1-=3;
        }
        else{
            return false;
        }
    }
  }
  return true;
}
int main(){
int n;
cout<<"\nEnter n : ";
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
bool ans=solve(arr);
if(ans){
    cout<<"Possible";
}
else{
    cout<<"Impossible";
}
}