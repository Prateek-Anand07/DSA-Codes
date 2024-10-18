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
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    TreeNode* curr = root;
    while(curr) {
        if(curr->left == NULL) {
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else {
            TreeNode* prev = curr->left;
            while(prev->right && prev->right!=curr) {
                prev = prev->right;
            }
            if(prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            }
            else {
                prev->right = NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return inorder;
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preorder;
    TreeNode* curr = root;
    while(curr) {
        if(curr->left == NULL) {
            preorder.push_back(curr->val);
            curr = curr->right;
        }
        else {
            TreeNode* prev = curr->left;
            while(prev->right && prev->right!=curr) {
                prev = prev->right;
            }
            if(prev->right == NULL) {
                prev->right = curr;
                preorder.push_back(curr->val);
                curr = curr->left;
            }
            else {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}
// Both of them have complexities as:
    // Time complexity: O(N)
    // Space complexity: O(1)
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(7);
    vector<int> preorder = preorderTraversal(root);
    for(auto x: preorder) 
        cout<<x<<" ";
    vector<int> inorder = inorderTraversal(root);
    cout<<endl;
    for(auto x: inorder)
        cout<<x<<" ";
    return 0;
}