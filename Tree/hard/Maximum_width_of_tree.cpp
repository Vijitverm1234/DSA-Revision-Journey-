#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val): val(val),left(nullptr),right(nullptr){}
}Node;
int main(){
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    queue<pair<Node*,int>> q;
    vector<vector<pair<int,int>>>res; 
    q.push({root,0});
    int ans=INT_MIN;
    while(!q.empty()){
        int size=q.size();
        
        int first;
        int last;
        for(int i=0;i<size;i++){
            auto pair=q.front();
            Node* node=pair.first;
            int id=pair.second;
            q.pop();
            if(i==0){
              first=id;
            }
            if(i==size-1){
              last=id;
            }
            if(node->left){
                q.push({node->left,id*2+1});
            }
            if(node->right){
                q.push({node->right,id*2+2});
            }
        }
        ans=max(ans,last-first+1);
    }
    cout<<"Width : "<<ans;
}