#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(int &sum,int n){
    if(n==0){
        return ;
    }
    sum+=n;
    solve(sum,n-1);
}
int main(){
    int n=10;
    int sum=0;
    solve(sum,n);
    cout<<sum;
}