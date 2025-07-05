#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;

int main(){
int n;
cout<<"\nEnter n : ";
cin>>n;
vector<int> greed(n);
for(int i=0;i<n;i++){
    cin>>greed[i];
}
int m;
cout<<"\nenter m : ";
cin>>m;
vector<int>s(m);
for(int i=0;i<m;i++){
    cin>>s[i];
}
int i=0,j=0;
int count=0;
while(i<n && j<m){
    if(greed[i]<=s[j]){
        j++;
        i++;
        count++;
    }
    else{
        j++;
    }
}
cout<<"Satisfied children : "<<count;
}