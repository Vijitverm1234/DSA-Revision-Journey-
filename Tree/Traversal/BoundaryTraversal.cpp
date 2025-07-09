#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val): val(val),left(NULL),right(NULL){}
}Node;

vector<int> res;
bool isLeaf(Node* node){
    return (node->left==NULL) &&(node->right==NULL);
}
void addLeft(Node* root){
    Node* curr=root->left;
    while(curr){
        if(!isLeaf(curr)){
            res.push_back(curr->val);
        }
        if(curr->left){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
}
void addLeaf(Node* root){
    if(isLeaf(root)){
        res.push_back(root->val);
        return;
    }
    if(root->left){
        addLeaf(root->left);
    }
    if(root->right){
        addLeaf(root->right);
    }
}
void addRight(Node* root){
     Node* curr=root->right;
     vector<int> temp;
    while(curr){
        if(!isLeaf(curr)){
            temp.push_back(curr->val);
        }
        if(curr->right){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }

}
int main(){
  Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    if(root!=NULL){
        res.push_back(root->val);
    }
    addLeft(root);
    cout<<"added left nodes"<<endl;
    addLeaf(root);
    cout<<"Added Leaf nodes"<<endl;
    addRight(root);
    cout<<"Added Right nodes"<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}