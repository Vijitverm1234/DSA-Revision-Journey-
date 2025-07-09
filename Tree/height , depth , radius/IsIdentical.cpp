#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val): val(val),left(NULL),right(NULL){}
}Node;

bool solve(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
     if(root1==NULL || root2==NULL){
        return false;
    }
    return (root1->val==root2->val) && solve(root1->left,root2->left) && solve(root1->right,root2->right);
}

int main(){
     Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

    // Node2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    bool ans= solve(root1,root2);
    if(ans){
        cout<<"Identical";
    }
    else{
        cout<<"Non Identical";
    }
}