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
int dia=0;
int solve(Node* root){
    if(root==NULL){
        return 0;
    }
    int left=solve(root->left);
    int right=solve(root->right);
    dia=max(dia,left+right);
    return 1+max(left,right);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    int depth=solve(root);
    cout<<"depth : "<<depth<<endl;
    cout<<"Diameter : "<<dia<<endl; 
}