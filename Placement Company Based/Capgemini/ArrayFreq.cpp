#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int main(){
    vector<int>temp={1,2,3,3,4,1,4,5,1,2};
    map<int,int>mapp;
    for(auto it : temp){
        mapp[it]++;
    }
    for(auto it : mapp){
        cout<<it.first<<" appears "<<it.second<<" Times"<<endl;
    }
}