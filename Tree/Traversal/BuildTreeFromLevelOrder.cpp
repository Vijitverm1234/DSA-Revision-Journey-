#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

Node* buildTree(vector<int> arr){
    if(arr[0]==-1) return NULL;
    int i=1;
    Node* root=new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    while(!q.empty() && i<arr.size()){
        auto node=q.front(); q.pop();
        if(i<arr.size() && arr[i]!=-1){
            node->left=new Node(arr[i]);
            q.push(node->left);   // ✅ fixed
        }
        i++;
        if(i<arr.size() && arr[i]!=-1){
            node->right=new Node(arr[i]);
            q.push(node->right);  // ✅ fixed
        }
        i++;
    }
    return root;
}

bool isLeaf(Node* root) {
    return root && !root->left && !root->right;
}

vector<int> res;

void leftBound(Node* root){
    Node* curr=root->left;
    while(curr){
        if (!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}

void addLeaves(Node* root){
    if(!root) return;
    if (isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if (root->left) addLeaves(root->left);
    if (root->right) addLeaves(root->right);
}

void rightBound(Node* root){
    Node* curr=root->right;
    vector<int> tmp;
    while(curr){
        if (!isLeaf(curr)) tmp.push_back(curr->data);
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    reverse(tmp.begin(), tmp.end()); // ✅ reverse before adding
    for(auto x: tmp) res.push_back(x);
}

void addBoundaryTraversal(Node* root){
    if(!root) return;
    if(!isLeaf(root)) res.push_back(root->data);
    leftBound(root);
    addLeaves(root);
    rightBound(root);
    cout<<"\nBoundary traversal:\n";
    for(auto it : res) cout<<it<<" ";
    cout<<"\n";
}

int main(){
    vector<int> arr= { 1 ,2 ,7 ,3 ,-1 ,-1 ,8 ,-1 ,4 ,9 ,-1 ,5 ,6 ,10 ,11};
    Node* root=buildTree(arr);
    addBoundaryTraversal(root);
}
