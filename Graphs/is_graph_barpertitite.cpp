#include<bits/stdc++.h>
using namespace std;
bool solve(int n,vector<vector<int>>edges){
    vector<vector<int>>adj(n);
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
    }
    vector<int>color(n,-1);
    queue<int>q;
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            q.push(i);
            color[i]=0;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(auto v : adj[u]){
                    
                    if(color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if(color[u]==color[v]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main(){
   vector<vector<int>>edges= {{0,1},{1,2},{2,3}};
   int n=4;
   bool res=solve(n,edges);
   if(res){
    cout<<"Yes it is"<<endl;
   }
   else{
    cout<<"No its not "<<endl;
   }
}