#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

int main() {
    // Create the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    queue<Node*> q;
    vector<int> lview;
    vector<int> rview;

    if (root) {
        q.push(root);
    }

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node* node = q.front();
            q.pop();

            // Left view: first node at each level
            if (i == 0) {
                lview.push_back(node->val);
            }

            // Right view: last node at each level
            if (i == n - 1) {
                rview.push_back(node->val);
            }

            // Push both children if they exist
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }

    // Print left view
    cout << "Left view: ";
    for (int val : lview) {
        cout << val << " ";
    }
    cout << endl;

    // Print right view
    cout << "Right view: ";
    for (int val : rview) {
        cout << val << " ";
    }
    cout << endl;

    // Optional: Clean up memory (implement tree deletion if needed)
    return 0;
}