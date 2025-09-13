#include<iostream>
using namespace std;

bool foward=true;
int maxi=12;
void solve( int n){
   if(n==0){
    return;
   }
   if(n==12){
        foward=false;
    }
   if(foward){
    if(n<maxi);
    cout<<n<<" ";
    
    solve(n+2);
   }
   else{
      cout<<n<<" ";
      solve(n-4);
   }
}
int main(){
    solve(2);
    return 0;
}