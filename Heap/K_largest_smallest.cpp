#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using  namespace std;
class Sol{
    public:
    priority_queue<int,vector<int>,greater<int>> pq;

    void solve(vector<int> arr,int k){
        for(auto it : arr){
            pq.push(it);
        }
        int n=arr.size();
        if(k>n){
            cout<<"\nNot possible Operation";
        }
        else{
            int ans=1;;
            while(k--){
                ans=pq.top();
                pq.pop();
            }
            cout<<"Answer : "<<ans<<endl;
        }
    }

};
int main(){
   vector<int> arr={1,2,6,4,5,3};
   int n=arr.size();
   int k;
   cout<<"Enter K : ";
   cin>>k;
   Sol s1;
   Sol s2;
   cout<<"For smallest "<<endl;
   s1.solve(arr,k);
   cout<<"For largest "<<endl;
   s2.solve(arr,n-k);
}