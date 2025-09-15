#include<bits/stdc++.h>
using namespace std;
class Node{
 public:
   int data;
   Node* left;
   Node* right;
   Node(int val){
    data=val;
    left=NULL;
    right=NULL;
   }
};
Node* buildTree(vector<int> arr){
    if(arr[0]==-1){
        return NULL;
    }
    int i=1;
    Node* root=new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    while(!q.empty() && i<arr.size()){
       auto node=q.front();
       q.pop();
       if(i<arr.size() && arr[i]!=-1){
        node->left=new Node(arr[i]);
        q.push(root->left);
       }
       i++;
       if(i<arr.size() && arr[i]!=-1){
        node->right=new Node(arr[i]);
        q.push(root->right);
       }
       i++;
    }
    return root;
}
void levelOrderTraversal(Node* root){
    if(root==NULL){
        cout<<"Not Possible";
    }
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> res;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << "\n"; // new level
    }


}
int main(){
    vector<int> arr= {1, 2, 3, -1, 4, -1, 5};
    int n=arr.size();
    Node* root=buildTree(arr);
    levelOrderTraversal(root);
}