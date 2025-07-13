#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val): val(val),left(nullptr),right(nullptr){}
}Node;
Node* solve(Node* root,int p,int q){
    if(root==NULL || root->val==p || root->val==q){
        return root;
    }
    Node* left=solve(root->left,p,q);
    Node* right=solve(root->right,p,q);
    if(left==NULL){
       return right;
    }
    else if(right==NULL){
        return left;
    }
    else{
        return root;
    }
}
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
     int x,y;
     cout<<"\nEnter x: ";
     cin>>x;
     cout<<"\nEnter y: ";
     cin>>y;
     Node* temp=solve(root,x,y);
     cout<<"\nAncestor : "<<temp->val;
}