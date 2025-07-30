#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    cout<<"enter string :";
     string st;
     cin>>st;
     string temp="";
     int n=st.size();
     int i=0;
     while(i<n){
        char c=st[i];
        int count=1;
        int j=i;
        while(j<n && st[j]==st[j+1]){
            count++;
            j++;
        }
        i=j;
        temp+=c+to_string(count);
        i++;
     }
     cout<<"result being : "<<temp;
}