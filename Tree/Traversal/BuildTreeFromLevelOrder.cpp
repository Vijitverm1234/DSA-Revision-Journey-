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
//Left and Right View of tree

void getLeftRightView(Node* root){
    if(root==NULL){
        cout<<"No Possible";
    }
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> temp;
    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            Node* node=q.front();
            q.pop();
            level.push_back(node->data);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        temp.push_back(level);
    }
    vector<int> leftview;
    vector<int> rightview;
    for(auto it : temp){
        leftview.push_back(it[0]);
        rightview.push_back(it[it.size()-1]);
    }
    cout<<"\nLeft View\n";
    for(auto it : leftview){
        cout<<it<<" ";
    }  
    cout<<"\nRight View\n";
    for(auto it : rightview){
        cout<<it<<" ";
    }
}

//Top view of the tree
void topView(Node* root){
  vector<int> ans;
  if(root==NULL){
    cout<<"Cannot be possible";
  }
  map<int,int> mapp;
  queue<pair<Node*,int>>q;
  q.push({root,0});
  while(!q.empty()){
      Node* node=q.front().first;
      int line=q.front().second;
   
      q.pop();
      if(mapp.find(line)==mapp.end()){
        mapp[line]=node->data;
      }
      if(node->left){
        q.push({node->left,line-1});
      }
      if(node->right){
        q.push({node->right,line+1});
      }
  }
  for(auto it: mapp){
    ans.push_back(it.second);
  }
  cout<<"\n Top View\n";
  for(auto it : ans){
    cout<<it<<" ";
  }
}

// LCA of tree

int main(){
    vector<int> arr= { 1 ,2 ,7 ,3 ,-1 ,-1 ,8 ,-1 ,4 ,9 ,-1 ,5 ,6 ,10 ,11};
    Node* root=buildTree(arr);
    addBoundaryTraversal(root);
    getLeftRightView(root);
    topView(root);
}
