/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
class Solution {
public:
    vector<int> st;
    void solve(TreeNode* root,int level){
        if(root==NULL){
            return;
        }
        if(st.size()==level){
            st.push_back(root->val);
        }
        if(root->right)
        solve(root->right,level+1);
        if(root->left)
        solve(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        solve(root,0);
        return st;
    }
};