#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    cout<<"enter string with #s :";
     string st;
     cin>>st;
     string temp1="";
     string temp2="";
     for(int i=0;i<st.size();i++){
        if(st[i]=='#'){
            temp1+='#';
        }
        else{
            temp2+=st[i];
        }
     }
     cout<<"Output: "<<temp1+temp2;
}