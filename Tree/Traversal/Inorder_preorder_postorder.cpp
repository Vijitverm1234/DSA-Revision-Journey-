#include<iostream>
#include<algorithm>
#include<vector>
using  namespace std;
typedef struct Node{
int val;
Node* left;
Node* right;
Node(int val) : val(val), left(nullptr), right(nullptr) {}
}Node;
vector<int> in;
vector<int> postorder;
vector<int> preorder;
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    in.push_back(root->val);
    inorder(root->right);
}
void printOrder(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    inorder(root);
    printOrder(in);
}