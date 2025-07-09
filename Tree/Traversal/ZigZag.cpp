#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef struct Node{
int val;
Node* left;
Node* right;
Node(int val) : val(val), left(nullptr), right(nullptr) {}
}Node;


int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> ans;
    while(!q.empty()){
       
        int n=q.size();
        vector<int>level;
        for(int i=0;i<n;i++){
             Node* node=q.front();
              q.pop();
            level.push_back(node->val);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        ans.push_back(level);
        }
        for(auto row: ans){
            for(auto it:row){
                cout<<it<<" ";
            }
            cout<<" ";
        }
}