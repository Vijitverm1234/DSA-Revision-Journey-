// User function Template for C++

class Solution {
  public:
    Node * prev=NULL;
    void flatten(Node *node) {
        // code here
        if(node==NULL){
            return;
        }
        flatten(node->right);
        flatten(node->left);
        node->right=prev;
        node->left=NULL;
        prev=node; 
    }
};