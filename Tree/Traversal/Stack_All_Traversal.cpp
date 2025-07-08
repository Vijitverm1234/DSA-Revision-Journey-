#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using  namespace std;
typedef struct Node{
int val;
Node* left;
Node* right;
Node(int val) : val(val), left(nullptr), right(nullptr) {}
}Node;

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
     stack<pair<Node*,int>> st;
     vector<int> pre,in,post;
     st.push({root,1});
     while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
        
           pre.push_back(it.first->val);
        
          it.second=2;
          st.push(it);
          if(it.first->left){
            st.push({it.first->left,1});
          }
        }
        else if(it.second==2){
          in.push_back(it.first->val);
        
          it.second=3;
          st.push(it);
          if(it.first->right){
            st.push({it.first->right,1});
          }
        }
        else{
          post.push_back(it.first->val);
          
        }
     }
     printOrder(pre);
     cout<<endl;
     printOrder(in);
     cout<<endl;
     printOrder(post);
     cout<<endl;

}