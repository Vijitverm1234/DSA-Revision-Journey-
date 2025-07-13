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
vector<int> ans;
bool solve(Node* root,int x){
    if(!root){
        return false;
    }
    ans.push_back(root->val);
    if(root->val==x){
        return true;
    }
    if(solve(root->left,x) || solve(root->right,x)){
        return true;
    }
    ans.pop_back();
    return false;
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
    int x;
    cout<<"Enter value : "<<endl;
    cin>>x;
    solve(root,x);
    cout<<"\nPATH : "<<endl;
    for(auto it : ans){
        cout<<it<<" ";
    }
}