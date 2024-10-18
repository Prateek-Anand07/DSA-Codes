// Reuse the nodes, all nodes right should point according to preorder and all left should point to NULL
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        val = data;
        left = right = NULL;
    }
};
// Recursive approach
// Time complexity: O(N)
// Space complexity: O(N)
TreeNode* Prev = NULL;
void flattenRecursive(TreeNode* root) {
    if(root == NULL)
        return;
    flattenRecursive(root->right);
    flattenRecursive(root->left);
    root->right = Prev;
    root->left = NULL;
    Prev = root;
}
// Iterative approach
// Time complexity: O(N)
// Space complexity: O(N)
void flattenIterative(TreeNode* root) {
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();
        if(curr->right)
            st.push(curr->right);
        if(curr->left)
            st.push(curr->left);
        if(!st.empty())
            curr->right = st.top();
        curr->left = NULL;
    }
}
// Using Morris traversal approach
// Time complexity: O(N)
// Space complexity: O(1)
void flatten_MorrisTraversal(TreeNode* root) {
    TreeNode* curr = root;
    while(curr) {
        if(curr->left != NULL) {
            TreeNode* prev = curr->left;
            while(prev->right) {
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
int main() {
    return 0;
}