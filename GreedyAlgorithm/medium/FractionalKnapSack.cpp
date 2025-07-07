#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
 
    return (double)a.first * b.second > (double)b.first * a.second;
}
int main(){
    int c;
    cout<<"\nEnter Capcity :";
    cin>>c;
    int n;
    cout<<"\nEnter n : ";
    cin>>n;
    vector<int> profit(n);
    cout<<"\nEnter Profit :";
    for(int i=0;i<n;i++){
        cin>>profit[i];
    }
    vector<int> weight(n);
    cout<<"\nEnter Weight :";
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    vector<pair<int,int>>temp;
    for(int i=0;i<n;i++){
        temp.push_back({profit[i],weight[i]});
    }
    sort(temp.begin(),temp.end(),comp);
    double maxProfit=0.0;
    int remaining=c;
    for(auto it : temp){
          if(remaining>=it.second){
            maxProfit+=it.first;
            remaining-=it.second;
          }
          else{
            double fraction = (double)remaining / it.second;
            maxProfit+=fraction*it.first;
          }
    }
    cout<<"\nMaximum Profit Generated : "<<maxProfit;
}