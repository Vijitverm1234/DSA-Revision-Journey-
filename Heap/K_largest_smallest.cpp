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
    void mergeSort(vector<vector<int>> res){
        vector<int> temp;
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[0].size();j++){
                pq.push(res[i][j]);
            }
        }
        while(!pq.empty()){
            int el=pq.top();
            pq.pop();
            temp.push_back(el);
        }
        cout<<"Merged array"<<endl;
        for(auto it : temp){
            cout<<it<<" ";
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
   Sol s3;

   
   cout<<"For smallest "<<endl;
   s1.solve(arr,k);
   cout<<"For largest "<<endl;
   s2.solve(arr,n-k);
   cout<<"For Sorted List  "<<endl;
   vector<vector<int>> res={{1,2,3,4},{6,7,8,7},{9,10,34,5}};
   s3.mergeSort(res);
}